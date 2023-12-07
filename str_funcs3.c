#include "main.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
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
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * **split_string - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @delimiters: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **split_string(char *str, char *delimiters) {
    int idx_str = 0, idx_words = 0, word_len = 0, num_words = 0;
    char **words;

    if (str == NULL || str[0] == '\0')
        return NULL;

    if (!delimiters)
        delimiters = " ";

    while (str[idx_str] != '\0') {
        if (!is_delimiter(str[idx_str], delimiters) &&
            (is_delimiter(str[idx_str + 1], delimiters) || !str[idx_str + 1]))
            num_words++;

        idx_str++;
    }

    if (num_words == 0)
        return NULL;

    words = malloc((1 + num_words) * sizeof(char *));
    if (!words)
        return NULL;

    for (idx_str = 0, idx_words = 0; idx_words < num_words; idx_words++) {
        while (is_delimiter(str[idx_str], delimiters))
            idx_str++;

        word_len = 0;
        while (!is_delimiter(str[idx_str + word_len], delimiters) && str[idx_str + word_len])
            word_len++;

        words[idx_words] = malloc((word_len + 1) * sizeof(char));
        if (!words[idx_words]) {
            for (int i = 0; i < idx_words; i++)
                free(words[i]);
            free(words);
            return NULL;
        }

        for (int m = 0; m < word_len; m++)
            words[idx_words][m] = str[idx_str++];
        words[idx_words][word_len] = '\0';
    }

    words[idx_words] = NULL;
    return words;
}
