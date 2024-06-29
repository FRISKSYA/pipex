/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:04:02 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/14 15:35:30 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_tokens(char const *str, char c)
{
	size_t	count_tokens;

	count_tokens = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count_tokens++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count_tokens);
}

static char	*alloc_word(char *start_word, char *end_word)
{
	char	*tgt_word;
	size_t	i;

	tgt_word = (char *)malloc((end_word - start_word + 1) * sizeof(char));
	if (tgt_word == NULL)
		return (NULL);
	i = 0;
	while (start_word < end_word)
	{
		tgt_word[i] = *start_word;
		start_word++;
		i++;
	}
	tgt_word[i] = '\0';
	return (tgt_word);
}

static void	free_split_words(char **split_words, size_t i)
{
	if (split_words == NULL)
		return ;
	while (i > 0)
	{
		i--;
		free(split_words[i]);
	}
	free(split_words);
}

static void	fill_words(char **split_words, char *str, char c)
{
	char	*start_word;
	char	*end_word;
	size_t	i;

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		start_word = str;
		while (*str && *str != c)
			str++;
		end_word = str;
		if (start_word < end_word)
		{
			split_words[i] = alloc_word(start_word, end_word);
			if (split_words[i] == NULL)
			{
				free_split_words(split_words, i);
				return ;
			}
			i++;
		}
	}
	split_words[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	char	**split_words;

	if (s == NULL)
		return (NULL);
	num_words = count_tokens(s, c);
	if (num_words == 0)
		return (NULL);
	split_words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (split_words == NULL)
		return (NULL);
	fill_words(split_words, (char *)s, c);
	return (split_words);
}
