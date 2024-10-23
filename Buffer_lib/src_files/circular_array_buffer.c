#include "../buffer_lib.h"

// LEFTOFF WRITE!

void	*buf_circular_ptrarray_read(t_circ_ptr *buf)
{
	if (buf->index[0] == buf->index[1])
		return (buf->array[buf->index[0]]);
	if (buf->index[0] == buf->size - 1)
		return (buf->index[0] = 0, buf->array[buf->size - 1]);
	return (buf->index[0]++, buf->array[buf->index[0]]);
}

char	buf_circular_chararray_read(t_circ_char *buf)
{
	if (buf->index[0] == buf->index[1])
		return (buf->array[buf->index[0]]);
	if (buf->index[0] == buf->size - 1)
		return (buf->index[0] = 0, buf->array[buf->size - 1]);
	return (buf->index[0]++, buf->array[buf->index[0]]);
}

int	buf_circular_intarray_read(t_circ_int *buf)
{
	if (buf->index[0] == buf->index[1])
		return (buf->array[buf->index[0]]);
	if (buf->index[0] == buf->size - 1)
		return (buf->index[0] = 0, buf->array[buf->size - 1]);
	return (buf->index[0]++, buf->array[buf->index[0]]);
}

t_circ_ptr	buf_circular_ptrarray_create(size_t size)
{
	t_circ_ptr	new;
	void		**array;

	array = (void **)malloc(sizeof(void *) * size);
	if (array == NULL)
		return (new.array = NULL, new.size = 0, new);
	new.size = size;
	while (size--)
		array[size] = NULL;
	new.array = array;
	new.index[0] = 0;
	new.index[1] = 0;
	return (new);
}

t_circ_char	buf_circular_chararray_create(size_t size)
{
	t_circ_char	new;
	char		*array;

	array = (char *)malloc(sizeof(char) * (size + 1));
	if (array == NULL)
		return (new.array = NULL, new.size = 0, new);
	array[size] = '\0';
	new.size = size;
	while (size--)
		array[size] = '\0';
	new.array = array;
	new.index[0] = 0;
	new.index[1] = 0;
	return (new);
}

t_circ_int	buf_circular_intarray_create(size_t size)
{
	t_circ_int	new;
	int			*array;

	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		return (new.array = NULL, new.size = 0, new);
	new.size = size;
	while (size--)
		array[size] = 0;
	new.array = array;
	new.index[0] = 0;
	new.index[1] = 0;
	return (new);
}