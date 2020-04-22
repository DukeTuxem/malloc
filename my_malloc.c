#include "my_malloc.h"

void		*start = NULL;
void		*end = NULL;

void		*malloc(size_t size)
{
  t_block	*last;

  size += ALIGN(size);
  if (size < 4)
    size = 4;
  if (add_mem_space(size) == EXIT_FAILURE)
    return (NULL);
  last = end;
  return (last->allocated);
}

int		add_mem_space(size_t size)
{
  t_block	*tmp;

  if (start)
    {
      if ((tmp = sbrk(BLOCK_SIZE + size)) == (void *)-1)
	return (EXIT_FAILURE);
      tmp->prev = end;
      tmp->prev->next = tmp;
    }
  else
    {
      start = sbrk(0);
      tmp = start;
      if ((tmp = sbrk(BLOCK_SIZE + size)) == (void *)-1)
        return (EXIT_FAILURE);
      tmp->prev = NULL;
    }
  tmp->size = size;
  tmp->free = 0;
  tmp->next = NULL;
  end = tmp;
  return (EXIT_SUCCESS);
}

void		show_alloc_mem()
{
  t_block	*tmp;

  tmp = start;
  printf("break : %p\n", sbrk(0));
  while (tmp != NULL)
    {
      printf("%p - %p : %ld bytes\n",
	     tmp, tmp->allocated + tmp->size, tmp->size);
      tmp = tmp->next;
    }
}
