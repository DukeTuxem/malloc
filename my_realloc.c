#include "my_malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_block	*tmp;
  void		*ret;
  int		*cpy_ptr;
  int		*cpy_ret;
  unsigned int	i;

  i = 0;
  if ((tmp = get_node(ptr)) == NULL)
    return (malloc(size));
  if ((ret = malloc(size)) == NULL)
    return (NULL);
  cpy_ptr = (int *)ptr;
  cpy_ret = (int *)ret;
  while (i * 4 < size)
    {
      cpy_ret[i] = cpy_ptr[i];
      ++i;
    }
  if (tmp)
    free(ptr);
  return (ret);
}
