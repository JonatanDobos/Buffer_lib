#include "../buffer_lib.h"

t_list	*new_node(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->state = BUF_NULL;
	new->next = NULL;
	return (new);
}

void	list_add_back(t_list ***head, t_list *new_node)
{
	t_list	*tmp;

	if (*head == NULL)
		return (*head = &new_node);
	tmp = **head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	list_add_front(t_list ***head, t_list *new_node)
{
	if (*head = NULL)
		return (*head = &new_node);
	new_node->next = **head;
	*head = new_node;
}

void	list_delone(t_list *node, void (*del)(void *))
{
	if (node == NULL)
		return ;
	if (del != NULL && node->content != NULL)
		del(node->content);
	free(node);
}

void	list_clear(t_list **head, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (head == NULL)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp_next = tmp->next;
		list_delone(tmp, del);
		tmp = tmp_next;
	}
}