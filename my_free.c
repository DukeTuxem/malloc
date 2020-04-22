#include "my_malloc.h"

void		free(void *ptr)
{
  t_block	*tmp;

  tmp = get_node(ptr);
  if (tmp)
    {
      tmp->free = 1;
      if (tmp->next == NULL)
	{
          if (tmp->prev)
            {
              tmp->prev->next = NULL;
              end = tmp->prev;
              brk(tmp->prev + tmp->prev->size + BLOCK_SIZE);
            }
          else
            {
              brk(start);
              start = NULL;
              end = start;
            }
	}
      else
        fusion(tmp);
    }
}

t_block		*get_node(void *ptr)
{
  if (ptr > start && ptr <= end + BLOCK_SIZE)
    return ((t_block*)((char *)(ptr) - BLOCK_SIZE));
  return (NULL);
}

t_block		*fusion(t_block *this)
{
  if (this->prev && this->prev->free == 1)
    this = this->prev;
  if (this->next && this->free == 1)
    {
      this->size += this->next->size + BLOCK_SIZE;
      this->next = this->next->next;
      if (this->next)
        this->next->prev = this;
    }
  return (this);
}
