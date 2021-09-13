/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdoun <ahamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:21:04 by ahamdoun          #+#    #+#             */
/*   Updated: 2021/09/13 16:37:25 by ahamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int count = 0;

char 	*read_buffer(int fd, char **buffer)
{
	char	buf[BUFFER_SIZE + 1];
	int		return_val = 0;
	char	*next_line;
	char	*curr_line;
	char	*temp;
	
	next_line = NULL;
	count++;
	printf("\n[%d] TRAITEMENT\n",count);

	while ((return_val = read(fd, buf, BUFFER_SIZE)) > 0)
	{
	//	printf("[1] TRAITEMENT JE SUIS DANS LA BOUCLE");
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
		//printf("|[%d]||%s|||%s\n",count,next_line,*buffer);
		if (next_line && *buffer)
		{
			curr_line = ft_strndup(*buffer, next_line + 1 - *buffer);
			temp = *buffer;
			*buffer = ft_strdup(next_line + 1);
			free(temp);
			return (curr_line);
		}

	}
	if (return_val == 0 && *buffer)
	{
		printf("gg");
		/*next_line = ft_strchr(*buffer, '\n');
		if (!(next_line))
		{
			curr_line = ft_strdup(*buffer);
			*buffer = NULL;
			free(*buffer);
			return (curr_line);
		}*/
	}
//	printf("[%d] TRAITEMENT SORTI DE BOUCLE bUFFER : %s  | NEXT LINE : %s | Return val : %d" ,count,*buffer, next_line, return_val);
	if (*buffer)
		free(*buffer);
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
    int fd = open("./gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
    int count = 1;
    char *line = NULL;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("\n==Ligne numero %d==\n|%s|", count, line);
        count++;
        free(line);
    }
    close(fd);
	return (0);
}
