#include "shell.h"

/**
 * *_strcpy - copy string
 * including the  null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;
	while (src[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
		dest[i] = '\0';

	return (dest);
}
/**
 * _strlen - will calculate the string length
 * @s : the pointer to the string
 * Return: the length
 */
int _strlen(char *s)
{
	int n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}

	return (n);
}

/**
 * _strcat - this will concatenates two strings
 * @dest: to append to string
 * @src: to add string
 *
 * Return: will return a  pointer to the resule
 */
char *_strcat(char *dest, char *src)
{
	int n, m;

	n = 0;
	m = 0;

	while (dest[n] != '\0')
		n++;

	while (src[m] != '\0')
	{
		dest[n] = src[m];
		m++;
		n++;
	}

	dest[n] = '\0';

	return (dest);
}

/**
 * _strcmp - it will compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * *_strdup - copies the string parametre
 * @str: str to duplicate
 *
 * Return: pointer to the copied string on success
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int n, leng;

	n = 0;
	leng = 0;

	if (str == NULL)
		return (NULL);

	while (str[leng])
		leng++;

	dup = malloc(sizeof(char) * (leng + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[n] = str[n]) != '\0')
		n++;

	return (dup);
}
