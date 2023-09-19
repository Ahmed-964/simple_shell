#include "shell.h"

/**
 * _strncpy_betty - Copies a string with a limit.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * Return: The concatenated string.
 */
char *_strncpy_betty(char *dest, char *src, int n)
{
    int i = 0, j;
    char *result = dest;

    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (result);
}

/**
 * _strncat_betty - Concatenates two strings with a limit.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used.
 *
 * Return: The concatenated string.
 */
char *_strncat_betty(char *dest, char *src, int n)
{
    int i = 0, j;
    char *result = dest;

    while (dest[i] != '\0')
        i++;
    j = 0;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (j < n)
        dest[i] = '\0';
    return (result);
}

/**
 * _strchr_betty - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the memory area s.
 */
char *_strchr_betty(char *s, char c)
{
    do {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');

    return (NULL);
}
