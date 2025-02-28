/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbravo-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 04:22:59 by gbravo-f          #+#    #+#             */
/*   Updated: 2024/05/18 08:44:33 by gbravo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && str[i])
			word = 1;
		if (str[i] == c)
		{
			while (str[i] == c && str[i])
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count + word);
}

static	char	*put_word(char *str, char c)
{
	int		i;
	char	*arr;

	i = 0;
	arr = 0;
	while (str[i] && str[i] != c)
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, str, i + 1);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**array;

	i = -1;
	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (++i < words)
	{
		while (s[0] == c)
			s++;
		array[i] = put_word((char *)s, c);
		if (!array[i])
		{
			free(array);
			return (NULL);
		}
		s += ft_strlen(array[i]);
	}
	array[i] = 0;
	return (array);
}
/*

while (i > 0)
				free(array[i--]);

int main() 
{
	const	char *str = "Hello,World,,This,is,a,test";
	char	delimiter = ',';
	char	**result = ft_split(str, delimiter);

    if (result)
    {
	for (int i = 0; result[i] != NULL; i++) 
	{
		printf("Substring %d: '%s'\n", i, result[i]);
		free(result[i]);
        }
	free(result);
    } else 
	printf("Erro ao dividir a string.\n");
}
*/
