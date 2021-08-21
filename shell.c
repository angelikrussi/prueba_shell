#include "shell.h"

/**
 * shell - this function start the shell
 * @argument_count: console writer argument numbers.
 * @argument_vector: is the array of arguments.
 * @environment: is the array of paths of the environment
 */

int main(int argument_count, char **argument_vector, char **environment)
{
	char **argument_array; /* array of pointers *pointer= [*ponterA, *pointerB, ...]*/
	char *line_input; /* character input by console */
	char *tmp_size = NULL; /* size of temporal memory */
	char *error = "Error"; /* this is a error */
	char *file_name; /* is the first parameter written for console */
	int route; /* program flow */
	int status = 1; /*  */

	while (status)
	{
		/**
		 * the function prompt is in extraneous.c file.
		 * this function print the character $ in console.
		 */
		prompt();

		/**
		 * the function _getline is in helper.c.
		 * this function read the line write by user
		 */
		line_input = _getline();

		/**
		 * the function split_line is in helper.c file.
		 * this function split a string and return a pointer to array
		 */
		argument_array = _split(line_input);

		/**
		 * this function is in bridge.c file.
		 * this function search the argument in struct.
		 * return 1 if user entered a path/builtin
		 * 2 if user entered a binary
		 */

		/* ls -> args[0] = ls, args=[ls] */
		route = bridge(argument_array[0], argument_array); /* 2 */

		/**
		 * pending
		 */
		if (route == 2)
		{
			file_name = argument_array[0];
			argument_array[0] = find_path(argument_array[0], tmp_size, error);
			if (argument_array[0] == error)
			{
				argument_array[0] = search_cwd(file_name, error);
				if (argument_array[0] == file_name)
					write(1, error, 5);
			}
		}

		/**
		 *
		 */
		if (argument_array[0] != error)
			status = execute_prog(argument_array, line_input, environment, route);

		free(line_input);
		free(argument_array);
	}
	while (status)
		;

	/* avoid errors with unused parameters */
	if (!argument_count)
		(void)argument_count;
	if (!argument_vector)
		(void)argument_vector;
	if (!environment)
		(void)environment;
	return (0);
}
