#ifndef BUFFER_LIB_H
# define BUFFER_LIB_H
# include "buffer_lib_dtypes.h"

// utils_list.c
t_list	*new_node(void *content);
void	list_add_back(t_list ***head, t_list *new_node);
void	list_add_front(t_list ***head, t_list *new_node);
void	list_delone(t_list *node, void (*del)(void *));
void	list_clear(t_list **head, void (*del)(void *));

#endif