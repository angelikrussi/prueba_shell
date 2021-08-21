#include "shell.h"

/**
 * prompt - function that prints the $
 * character in the terminal.
 * Description: this function shows
 * the $ character in the console to
 * indicate that it is inside the shell
 * terminal
 */
void prompt(void)
{
	char *prompt = "$:";

	/**
	 * isatty(): Determines if a file descriptor, fildes,
	 * is associated with a terminal
	 * isatty() returns 1 if the given file descriptor
	 * is a terminal, or 0 otherwise.
	 */
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, getStringLength(prompt));
	}
}
