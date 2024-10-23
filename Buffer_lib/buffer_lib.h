#ifndef BUFFER_LIB_H
# define BUFFER_LIB_H
# include "buffer_lib_dtypes.h"

// circular_list_buffer.c
t_list	**buf_circular_list_create(size_t size);
void	*buf_circular_list_read(t_list ***head);
void	*buf_circular_list_write(t_list ***head, void *content);
void	buf_circular_list_destroy(t_list ***head, void (*del)(void *));

// utils_list.c
t_list	*new_node(void *content);
void	list_add_back(t_list ***head, t_list *new_node);
void	list_add_front(t_list ***head, t_list *new_node);
void	list_delone(t_list *node, void (*del)(void *));
void	list_clear(t_list **head, void (*del)(void *));

#endif