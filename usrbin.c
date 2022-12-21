#include "shell.h"

/**
 * _usrbin - returns default path of command
 * @path:  pointer to input cmd
 * Return: new path
 */

char *_usrbin(char *path)
{
	char str1[100] = "/usr/bin/";
	int i = 0, s1 = 9, s2 = 0;
	while (path[i] != '\0')
	{
		str1[s1] = path[i];
		i++;
		s1++;
	}
	while (str1[s2] != '\0')
	{
		path[s2] = str1[s2];
		s2++;
	}
	return (path);
}

/**
 * _usrbin2 - returns default path of command
 * @path:  pointer to input cmd
 * Return: new path
 */

char *_usrbin2(char *path)
{
	char str1[100] = "/bin/";
	int i = 0, s1 = 5, s2 = 0;
	while (path[i] != '\0')
	{
		str1[s1] = path[i];
		i++;
		s1++;
	}
	while (str1[s2] != '\0')
	{
		path[s2] = str1[s2];
		s2++;
	}
	return (path);
}

