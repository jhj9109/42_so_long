/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:46:28 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/06 19:46:30 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstnew(char	*line)
{
	t_list	*ret;

	ret = ft_calloc(1, sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->line = line;
	return (ret);
}

t_list	*ft_lstlast(t_list *head)
{
	t_list	*cur;

	if (head == NULL)
		return (NULL);
	cur = head; 
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void	ft_lstiter(t_list *head, void (*f)(char *))
{
	t_list	*cur;

	cur = head;
	while (cur)
	{
		(f)(cur->line);
		cur = cur->next;
	}
}

void	ft_lstclear(t_list **head)
{
	t_list	*cur;
	t_list	*temp;

	cur = *head;
	while (cur)
	{
		temp = cur->next;
		if (cur->line)
			free(cur->line);
		free(cur);
		cur = temp;
	}
	*head = NULL;
}

void	ft_lst_delone(t_list **head, t_list *deleted)
{
	t_list	*cur;

	if (*head == deleted)
	{
		free(deleted);
		*head = NULL;
		return ;
	}
	cur = *head;
	while (cur->next)
	{
		if (cur->next == deleted)
		{
			cur->next = deleted->next;
			free(deleted);
			return ;
		}
		cur = cur->next;
	}
}
