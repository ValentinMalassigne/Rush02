/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:32:28 by liguyon           #+#    #+#             */
/*   Updated: 2023/03/19 17:06:22 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <fcntl.h>

char	*read_file(int fd)
{
	int		rd;
	char	*content;
	char	*buf;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	content = NULL;
	while (rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			free(content);
			return (NULL);
		}
		buf[rd] = '\0';
		tmp = ft_strjoin(content, buf);
		free(content);
		content = tmp;
	}
	free(buf);
	return (content);
}

int	parse(t_number_dict *dict, int ac, char **av)
{
	int	fd;
	char	*file_content;

	fd = -1;
	if (ac == 3)
	{
		if (!ft_strcmp(av[2], "stdin"))
			fd = 0;
		else
			fd = open(av[2], O_RDONLY);
	}
	if (fd == -1)
		return (ERROR_DICT);
	file_content = read_file(fd);
	if (file_content == NULL)
		return (ERROR_DICT);
	(void)dict;
//	add file_content parsing here
//
//	if (parse_file(dict, file_content) == 1)
//		return (ERROR_DICT);
	free(file_content);
	return (0);
}
