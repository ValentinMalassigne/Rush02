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

int	read_file(char *file_path, char *file_content)
{
	int file_descriptor;
	ssize_t bytes_read;

	file_descriptor = 0;
	file_descriptor = open(file_path, O_RDONLY);
	if(file_descriptor < 0)
		return (0);
	bytes_read = read(file_descriptor, file_content, 4096);
	close(file_descriptor);
	file_content[bytes_read] = '\0';
	return (1);
}

int	get_line_data(char *number, char *word, char *line, int number_length)
{
	int	i;
	
	i = 0;
	while(i < number_length)
	{
		number[i] = line[i];
		i++;
	}
	while(line[i] == ' ' || line[i] == ':')
		i++;
	line += i;
	
	i = 0;
	while(line[i])
	{
		word[i] = line[i];
		i++;
	}
	return (0);
}

int	verify_word(char *str)
{
	int length;

	length = 0; 
	while(str[length])
	{
		if(str[length] < 32 || str[length] > 126)
			return (0);
		length++;
	}
	if(length == 0)
		return (0);	
	return (1);
}

int verify_number(int number)
{
	int	correctValues[33];
	int	i;
	int	j;

	i = -1;
	while (++i < 21)
		correctValues[i] = i;
	j = i + 9;
	while (i < 29)
	{
		correctValues[i++] = j;
		j +=10;
	}
	correctValues[29] = 100;
	correctValues[30] = 1000;
	correctValues[31] = 1000000;
	correctValues[32] = 1000000000;
	i = 0;
	while (i < 33)
	{
		if (correctValues[i] == number)
			return (1);
		i++;
	}
	return(0);
}

int fill_struct(char *line, t_number_dict *res)
{
	char 			*number;
	char			*word;
	int				number_length;
	int				word_length;

	number_length = length_until_char(line, ' ');
	number = malloc((number_length + 1) * sizeof(char));	
	word_length = length_until_char(line, '\0');
	word = malloc((word_length + 1) * sizeof(char));
	get_line_data(number, word, line, number_length);
	res->number = atoi(number);
	res->word_en = word;
	if (verify_number(res->number) && verify_word(res->word_en))
		return (1);
	return(0);
}

int get_numbers_dict(char **lines, t_number_dict *numbers_dict)
{
	int				i;
	t_number_dict	filled_struct;

	i = 0;
	
	while(lines[i])
	{
		if (!fill_struct(lines[i], &filled_struct))
			return(0);
		numbers_dict[i] = filled_struct;
		i++;
	}
	return (1);
}

int main()
{
	char		*file_content;
	int		line_length;
	int		line_number;
	int		j;
	char		**lines;
	t_number_dict	*numbers_dict;

	line_number = 0;
	j = 0;
	file_content = malloc(4096 * sizeof(char));
	lines = malloc(10000 * sizeof(char*));
	if(read_file("numbers.dict",file_content))
	{
		while(*file_content)
		{
			line_length = length_until_char(file_content, '\n');
			if(line_length > 0)
			{
				lines[line_number] = get_next_line(file_content, line_length);
				line_number++;
			}
			
			file_content += line_length + 1;
		}
		numbers_dict = malloc(line_number * sizeof(t_number_dict));
		if(!get_numbers_dict(lines, numbers_dict))
			printf("Error\n");
		while (j < line_number)
		{
			printf("number : %d word : %s\n", numbers_dict[j].number, numbers_dict[j].word_en);
			j++;
		}
	}
	else
	{
		//"Dict Error\n" //Error while opening the file
	}
	return (0);
}
