#include "shell.h"

/**
 * isfiledefault - checks if file exists in the paths /usr/bin/ or /bin/
 * @path: pointer to file name or pathname
 * Return: 0 if successfull -1 if not found
 */

int isfiledefault(const char *path)
{
	struct stat stats;
	int i = 0, s1 = 9, s2 = 5;
	char str1[100] = "/usr/bin/";
	char str2[100] = "/bin/";

	while (path[i] != '\0')
	{
		str1[s1] = path[i];
		str2[s2] = path[i];
		i++;
		s1++;
		s2++;
	}

	if ((stat(str1, &stats) < 0) && (stat(str2, &stats) < 0))
		return (-1);
	else
		return (0);
}
