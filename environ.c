#include <stdio.h>

extern char **environ;

char *getVariableFromEnviron(char *variableName)
{
	char *result;

	int i = 0;
	int j = 0;
	for (; environ[i] != NULL; i++)
	{
		for (j = 0; variableName[j] == environ[i][j]; j++)
		{
		}

		if (variableName[j] == '\0' && environ[i][j] == '=')
		{
			result = &environ[i][j + 1];
		}
	}

	return (result);
}
