/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:16:01 by eperperi          #+#    #+#             */
/*   Updated: 2024/04/04 13:31:51 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_nexti_line_test(int fd)
{
	int			read_chars;
	char		*buffer;
	static char	*temp_buffer;
	int			i;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while ((read_chars = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		if (read_chars == 0)
			return (free(buffer), NULL);
		i = 0;
		while (buffer[i] != '\n' || buffer[i] || '\0' || i < read_chars)
		{
			temp_buffer[i] = buffer[i];
		}
	}
	return (buffer);
}
int	main(void)
{
	int		fd;
	char	*new_line;
	int		counter;
	int		i;

	counter = 0;
	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		new_line = get_next_line_test(fd);
		counter++;
		printf("%d : %s\n", counter, new_line);
		if (new_line == NULL)
			break ;
		new_line = NULL;
	}
	close(fd);
	return (0);
}