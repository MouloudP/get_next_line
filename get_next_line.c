/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdoun <ahamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:21:04 by ahamdoun          #+#    #+#             */
/*   Updated: 2021/09/13 11:52:12 by ahamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*read_buffer(int fd, char **buffer)
{
	char	buf[BUFFER_SIZE + 1];
	int		return_val = 1;
	char	*next_line;
	char	*curr_line;
	char	*temp;
	
	curr_line = NULL;	
	next_line = NULL;
	temp = NULL;
	while (return_val > 0)
	{
		return_val = read(fd, buf, BUFFER_SIZE);
		buf[return_val] = '\0';
		if (!*buffer)
			*buffer = ft_strdup(buf);
		else
		{
			temp = *buffer;
			*buffer = ft_strjoin(*buffer, buf);
			free(temp);
		}
		next_line = ft_strchr(*buffer, '\n');
		if (next_line)
		{
			curr_line = ft_strndup(*buffer, next_line + 1 - *buffer);
			printf("size -> [%zu]\n\n%s\n", next_line + 1 - *buffer,curr_line);
			//curr_line = "ss";
			temp = *buffer;
			*buffer = ft_strdup(next_line + 1);
			free(temp);
			return (curr_line);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*content = NULL;
	char		*line;
	char		buf;
	
	if (BUFFER_SIZE <= 0 || read(fd, &buf, 0) < 0)
		return (NULL);
	line = read_buffer(fd, &content);
	if (line && line[0])
		return (line);
	return (NULL);
}

int main()
{
    int fd = open("/Users/ahamdoun/Desktop/gnls/get_next_line.h", O_RDONLY);
    int count = 1;
    char *line = NULL;

    while ((line = get_next_line(fd)) != NULL)
    {
        //iprintf("\n==Ligne numero %d==\n|%s|", count, line);
        count++;
        free(line);
    }
    close(fd);
    return (0);
}
