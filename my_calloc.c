#include "my_malloc.h"

void		*calloc(size_t nmemb, size_t size)
{
  void		*ptr;
  int		*tab;
  unsigned int	i;

  i = 0;
  ptr = malloc(nmemb * size);
  if (ptr == NULL)
    return (NULL);
  tab = ptr;
  while (i * 4 < size)
    tab[i++] = 0;
  return (ptr);
}
