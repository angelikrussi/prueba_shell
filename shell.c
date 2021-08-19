#include "shell.h"

void main()
{
	char *prompt = "$:";
	char *input;
	size_t input_size = 0;
	int characters_read = 0;
	pid_t process_id;

	while(1)
	{
		if(isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, getStringLength(prompt));

		characters_read = getline(&input, &input_size, stdin);

		process_id = fork();
		if(process_id == -1)
			exit(-1);
		
	}
}