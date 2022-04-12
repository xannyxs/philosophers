/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 21:00:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/12 21:06:16 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>

/* frees a null-terminated array of c strings. */
void	ft_free_str_arr(char **arr)
{
	char	**og_str;

	og_str = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(og_str);
}

void	ft_free_mutex_arr(pthread_mutex_t **arr)
{
	pthread_mutex_t	**og_str;

	og_str = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(og_str);
}
