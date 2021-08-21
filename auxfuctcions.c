#include "shell.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string.
 *@s: variable
 *
 * Return: Always 0.
 */

int _strlen(char *s)
{

	int l = 0;

	while (s[l] != '\0')
	{

		l++;

	}

	return (l);
}

/**
 *_strcpy - Copies the string pointed to by src, including the terminating null
 *@dest: variable character
 *@src: source to copy
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (*(src + x))
	{

		*(dest + x) = *(src + x);
		x++;
	}

	*(dest + x) = '\0';
	return (dest);

}



/**
 *_strcmp - function that copies a string
 *@s1: string
 *@s2: string
 *
 * Return: string
 */

int _strcmp(char *s1, char *s2)
{

	int x = 0;
	int y = 0;


	while ((s1[x] != '\0' && s2[y] != '\0') && s1[x] == s2[y])
	{
		x++;
		y++;
	}


	if (s1[x] == s2[y])

	{
		return (0);
	}

	else

	{
		return (s1[x] - s2[y]);
	}
}
