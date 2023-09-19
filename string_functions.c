#include "shell.h"

/**
 * This function returns the length of a string.
 * 
 * @param str The string whose length to check
 * @return The length of the string
 */
int get_string_length(char *str)
{
    int length = 0;

    if (!str)
        return 0;

    while (*str++)
        length++;
    return length;
}

/**
 * This function performs lexicographic comparison of two strings.
 * 
 * @param str1 The first string
 * @param str2 The second string
 * @return Negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
 */
int compare_strings(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    if (*str1 == *str2)
        return 0;
    else
        return (*str1 < *str2 ? -1 : 1);
}

/**
 * This function checks if a string starts with a specific substring.
 * 
 * @param str The string to search
 * @param substr The substring to find
 * @return Address of the next character of str if it starts with substr, or NULL otherwise
 */
char *check_start(const char *str, const char *substr)
{
    while (*substr)
    {
        if (*substr++ != *str++)
            return NULL;
    }
    return (char *)str;
}

/**
 * This function concatenates two strings.
 * 
 * @param dest The destination buffer
 * @param src The source buffer
 * @return Pointer to the destination buffer
 */
char *concatenate_strings(char *dest, char *src)
{
    char *result = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return result;
}
