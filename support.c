#include "shell.h"

/**
 *_strdup - create an array.
 *@str: size of int;
 * Return: Always 0.
 */
char *_strdup(char *str)
{
	int i;
	int count;
	char *s;

	count = 1;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		count++;
	}

	s = malloc(count);

	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < count + 1; i++)
	{
		s[i] = str[i];
	}
	return (s);
}

/**
 * _split - Entry point.
 * @dest: Variable which will hold the string.
 * @src: Variable which holds the string.
 *
 * Return: 0.
 */

int _split(char *string_console, char *delimiter)
{
	char *token;
	​
	token = strtok(string_console, delimiter);
	​while (token != NULL)
	{
		printf("%s\n", token);
		​token = strtok(NULL, DELIM);
	}
	​ return 0;
}

/**
 * _strlen - a function that returns the length of a string
 * @s: char input
 * Return: length of the input string
 */
int _strlen(char *s)
{
	int i = 1, sum = 0;
	char pl = s[0];

	while (pl != '\0')
	{
		sum++;
		pl = s[i++];
	}
	return (sum);
}



/* ------------------------------ */

/**
 * _getline - Gets line of user input
 * Return: Pointer to buffer of user input
 */
char *_getline(void)
{
	int temp;
	char *line = NULL;
	size_t size = 0;

	temp = getline(&line, &size, stdin);
	if (temp == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		exit(0);
	}
	return (line);
}

char *get_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	int test;

	test = getline(&buf, &bufsize, stdin);
	if (test == EOF)
	{
		write(1, "\n", 1);
		_exit(1);
	}
	return (buf);
}

/**
 * split_line - Splits line into args
 * @line: Line of user input
 * Return: Array of args of user input
 */
char **split_line(char *line)
{
	size_t buffer_size = TOKENS_BUFFER_SIZE;
	char **tokens = malloc(sizeof(char *) * buffer_size);
	char *token;
	int pos = 0;

	if (!tokens)
	{
		perror("Could not allocate space for tokens\n");
		exit(0);
	}
	token = strtok(line, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[pos] = token;
		token = strtok(NULL, TOKEN_DELIMITERS);
		pos++;
	}
	tokens[pos] = NULL;
	return (tokens);
}
/**
 * check_for_builtins - Checks for builtins
 * @args: Arguments passed from prompt
 * @line: Buffer with line of input from user
 * @env: Environment
 * Return: 1 if builtins exist, 0 if they don't
 */
int check_for_builtins(char **args, char *line, char **env)
{
	builtins_t list[] = {
		{"exit", exit_shell},
		{"env", env_shell},
		{NULL, NULL}};
	int i;

	for (i = 0; list[i].arg != NULL; i++)
	{
		if (_strcmp(list[i].arg, args[0]) == 0)
		{
			list[i].builtin(args, line, env);
			return (1);
		}
	}
	return (0);
}
/**
 * launch_prog - Forks and launches unix cmd
 * @args: Args for cmd
 * Return: 1 on success
 */
int launch_prog(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Failed to execute command\n");
			exit(0);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking\n");
		exit(0);
	}
	else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && WIFSIGNALED(status));
	}
	(void)wpid;
	return (1);
}
/**
 * builtins_checker - Checks for builtins
 * @args: Arguments passed from prompt
 * Return: 1 if builtins exist, 0 if they don't
 */

/* args=[ls] */
int builtins_checker(char **args)
{
	int i;
	builtins_t list[] = {
		{"exit", exit_shell},
		{"env", env_shell},
		{NULL, NULL}};

	for (i = 0; list[i].arg != NULL; i++)
	{
		if (_strcmp(list[i].arg, args[0]) == 0)
			return (1);
	}
	return (0);
}
