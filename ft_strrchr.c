/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:22:15 by eperperi          #+#    #+#             */
/*   Updated: 2024/03/10 14:31:06 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (c == '\0')
		return ((char *)&s[len]);
	while (len >= 0)
	{
		if (s[len] == (char)c)
		{
			return ((char *)&s[len]);
		}
		len--;
	}
	return (NULL);
}
// int main() {
//     const char *str = "Hello, world!";
//     char search_char = 'o';

//     printf("String: \"%s\"\n", str);
//     printf("Search character: '%c'\n", search_char);

//     char *result = ft_strrchr(str, search_char);

//     if (result != NULL) {
//         printf("Last occurrence found at position: %ld\n", result - str);
//     } else {
//         printf("Character not found.\n");
//     }

//     return 0;
// }