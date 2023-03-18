/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:36:34 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/18 13:36:37 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	length_until_char(char *str, char c)
{
	int	length;

	length = 0;
	while (str[length] && str[length]!= c)
		length++;
	return (length);
}

char *get_next_line(char *file_content, int line_length)
{
	char	*res;
	int	i;

	res = malloc((line_length + 1) * sizeof(char));
	i = 0;
	while(file_content[i] && file_content[i]!= '\n')
	{
		res[i] = file_content[i];
		i++;
	}
	res[line_length] = '\0';
	return (res);
}

char *read_file(char *file_path)
{
	int file_descriptor;
	char *file_content;
	ssize_t bytes_read;

	file_content = malloc(4096 * sizeof(char));
	file_descriptor = 0;
	file_descriptor = open(file_path, O_RDONLY);
	if(file_descriptor < 0)
		return "\0";
	bytes_read = read(file_descriptor, file_content, 4096);
	close(file_descriptor);
	file_content[bytes_read] = '\0';
	return (file_content);
}

struct s_number_dict fill_struct(char *line)
{
	char 		*number;
	char		*word;
	int		number_length;
	int		word_length;
	int		i;
	t_number_dict	res;

	i = 0;
	number_length = length_until_char(line, ' ');
	number = malloc((number_length + 1) * sizeof(char));		
	while(i < number_length)
	{
		number[i] = line[i];
		i++;
	}
	while(line[i] == ' ' || line[i] == ':')
		i++;
	line += i;
	word_length = length_until_char(line, '\0');
	word = malloc((word_length + 1) * sizeof(char));
	i = 0;
	while(line[i])
	{
		word[i] = line[i];
		i++;
	}
	res.number = atoi(number);
	res.word_en = word;
	return (res);
}

struct s_number_dict *get_numbers_dict(char **lines)
{
	t_number_dict	*tab;
	int		i;
	
	i = 0;
	tab = malloc(1000 * sizeof(t_number_dict));
	while(lines[i])
	{
		tab[i] = fill_struct(lines[i]);
		i++;
	}	
	return (tab);
}

int main()
{
	char		*file_content;
	int		line_length;
	int		i;
	int		j;
	char		**lines;
	t_number_dict	*numbers_dict;
	
	i = 0;
	j = 0;
	lines = malloc(10000 * sizeof(char*));
	file_content = read_file("numbers.dict");
	while(*file_content)
	{
		line_length = length_until_char(file_content, '\n');
		lines[i] = get_next_line(file_content, line_length);
		i++;
		file_content += line_length + 1;
	}
	numbers_dict = get_numbers_dict(lines);
	while (j < i)
	{
		printf("number : %d word : %s\n",numbers_dict[j].number,numbers_dict[j].word_en);
		j++;
	}
	return (0);
	
}
