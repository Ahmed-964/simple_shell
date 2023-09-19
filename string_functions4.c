#include "shell.h"

/**
 * **strtow_betty - Splits a string into words. Repeated delimiters are ignored.
 * @str: The input string.
 * @d: The delimiter string.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **strtow_betty(char *str, char *d)
{
    int i, j, k, m, numwords = 0;
    char **result;

    if (str == NULL || str[0] == '\0')
        return (NULL);

    if (!d)
        d = " ";

    for (i = 0; str[i] != '\0'; i++)
    {
        if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
            numwords++;
    }

    if (numwords == 0)
        return (NULL);

    result = malloc((numwords + 1) * sizeof(char *));
    if (!result)
        return (NULL);

    for (i = 0, j = 0; j < numwords; j++)
    {
        while (is_delim(str[i], d))
            i++;

        k = 0;
        while (!is_delim(str[i + k], d) && str[i + k])
            k++;

        result[j] = malloc((k + 1) * sizeof(char));
        if (!result[j])
        {
            for (k = 0; k < j; k++)
                free(result[k]);
            free(result);
            return (NULL);
        }

        for (m = 0; m < k; m++)
            result[j][m] = str[i++];

        result[j][m] = '\0';
    }

    result[j] = NULL;
    return (result);
}

/**
 * **strtow2_betty - Splits a string into words using a single delimiter.
 * @str: The input string.
 * @d: The delimiter character.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **strtow2_betty(char *str, char d)
{
    int i, j, k, m, numwords = 0;
    char **result;

    if (str == NULL || str[0] == '\0')
        return (NULL);

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] != d && str[i + 1] == d) ||
            (str[i] != d && !str[i + 1]) || str[i + 1] == d)
            numwords++;
    }

    if (numwords == 0)
        return (NULL);

    result = malloc((numwords + 1) * sizeof(char *));
    if (!result)
        return (NULL);

    for (i = 0, j = 0; j < numwords; j++)
    {
        while (str[i] == d && str[i] != d)
            i++;

        k = 0;
        while (str[i + k] != d && str[i + k] && str[i + k] != d)
            k++;

        result[j] = malloc((k + 1) * sizeof(char));
        if (!result[j])
        {
            for (k = 0; k < j; k++)
                free(result[k]);
            free(result);
            return (NULL);
        }

        for (m = 0; m < k; m++)
            result[j][m] = str[i++];

        result[j][m] = '\0';
    }

    result[j] = NULL;
    return (result);
}
