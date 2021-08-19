#include "shell.h"

/**
 * prompt - function to print prompt
 *
 * Description: print prompt
 * Return: na
 */
void prompt(void)
{
	char *prompt = "$:";
	char *line;
	size_t lineSize = 0;
	int charactersRead = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, getStringLength(prompt));

		charactersRead = getline(&line, &lineSize, stdin);

		write(STDOUT_FILENO, line, charactersRead);
	}
}
