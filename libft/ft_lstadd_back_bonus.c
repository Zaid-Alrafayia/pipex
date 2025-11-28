/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 03:36:14 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 17:29:17 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*cur;

	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	if (!lst || !new_node)
		return ;
	cur = *lst;
	while (cur && cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
}
