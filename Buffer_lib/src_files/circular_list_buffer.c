#include "../buffer_lib.h"

// creates a circular list buffer of given size,
// returns head on success and NULL on failure
t_list	**buf_circular_list_create(size_t size)
{
	t_list	*node;
	t_list	**head;

	head = NULL;
	while (size--)
	{
		node = new_node(NULL);
		if (node == NULL)
			return (list_clear(head, NULL), NULL);
		list_add_back(&head, node);
	}
	node->next = *head;
	(*head)->state = BUF_OVERLAP;
	return (head);
}

// destroys given circular list buffer,
// given function: void (*del)(void *) is used to clear the content
void	buf_circular_list_destroy(t_list ***head, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (head == NULL || *head == NULL)
		return ;
	tmp = **head;
	tmp_next = tmp->next;
	tmp->next = NULL;
	tmp = tmp_next;
	while (tmp != NULL)
	{
		tmp_next = tmp->next;
		list_delone(tmp, del);
		tmp = tmp_next;
	}
	*head = NULL;
}

// reads from the given circular list buffer,
// returns content and shifts head to new read index
void	*buf_circular_list_read(t_list ***head)
{
	t_list	*tmp;
	
	tmp = **head;
	while (tmp->state == BUF_NULL || tmp->state == BUF_WRITE)
		tmp = tmp->next;
	if (tmp->state != BUF_OVERLAP)
	{
		if (tmp->next->state == BUF_WRITE)
			tmp->next->state = BUF_OVERLAP;
		else
			tmp->next->state = BUF_READ;
		tmp->state = BUF_NULL;
		*head = &tmp->next;
	}
	return (tmp->content);
}

// writes to the given circular list buffer, 
// returns overwritten content pointer
void	*buf_circular_list_write(t_list ***head, void *content)
{
	t_list	*tmp;
	void	*tmp_content;
	
	tmp = **head;
	while (tmp->state == BUF_NULL || tmp->state == BUF_READ)
		tmp = tmp->next;
	tmp_content = tmp->content;
	tmp->content = content;
	if ((tmp->state == BUF_OVERLAP && tmp->content != NULL)
		|| tmp->next->state == BUF_READ)
	{
		tmp->next->state = BUF_OVERLAP;
		*head = &tmp->next;
	}
	else
		tmp->next->state = BUF_WRITE;
	tmp->state = BUF_NULL;
	return (tmp_content);
}