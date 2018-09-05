/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <mbellaic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:36:40 by mbellaic          #+#    #+#             */
/*   Updated: 2018/09/03 21:35:09 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2 || !(ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	free((void*)s1);
	return (ptr);
}
