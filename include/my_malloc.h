#ifndef _MY_MALLOC_H_
# define _MY_MALLOC_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_global.h"

#if __GNUC__
#if __x86_64__ || __ppc64__
# define ENVIRONMENT64
#else
# define ENVIRONMENT32
#endif
#endif

#ifdef ENVIRONMENT64
# define BLOCK_SIZE	32
#else
# define BLOCK_SIZE	20
#endif

#define ALIGN(x)	(x % 4)

typedef struct		s_block
{
  size_t		size;
  int			free;
  struct s_block	*next;
  struct s_block	*prev;
  char			allocated[1];
}			t_block;

/*		MY_MALLOC.C			*/
void		*malloc(size_t size);
int		add_mem_space(size_t size);
void		show_alloc_mem();

/*		MY_FREE.C			*/
void		free(void *ptr);
t_block		*get_node(void *ptr);
t_block		*fusion(t_block *this);

/*		MY_CALLOC.C			*/
void		*calloc(size_t nmemb, size_t size);

/*		MY_REALLOC.C			*/
void		*realloc(void *ptr, size_t size);

#endif /* _MY_MALLOC_H_ */
