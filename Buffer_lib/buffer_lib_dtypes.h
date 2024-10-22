#ifndef BUFFER_LIB_DTYPES_H
# define BUFFER_LIB_DTYPES_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

enum	e_states
{
	BUF_NULL,
	BUF_READ,
	BUF_WRITE,
	BUF_OVERLAP
};

typedef struct s_list
{
	void			*content;
	short			state;
	struct s_list	*next;
}	t_list;

typedef struct s_list_twoway
{
	struct s_list_twoway	*prev;
	void					*content;
	struct s_list_twoway	*next;
}	t_list_twoway;

#endif