/*
** realloc.c for malloc in /home/docqui_a/work/PSU_2015_malloc/v2/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Wed Feb 10 17:38:38 2016 Avel Docquin
** Last update Sun Feb 14 23:36:44 2016 Avel Docquin
*/

#include "realloc.h"

extern t_block	*block;

void	*realloc(void *ptr, size_t size)
{
  t_block	*newBlock;
  t_block	*tmpBlock;

  if (size != 0)
    {
      if (!block)
	{
	  init_block(size);
	  return (block + 1);
	}
      if (!ptr)
	return (malloc(size));
      tmpBlock = block;
      while (tmpBlock + 1 != ptr)
	tmpBlock = tmpBlock->next;
      if ((newBlock = find_free_block(size)) != NULL)
	{
	  free(tmpBlock);
	  memcpy(newBlock + 1, ptr, tmpBlock->size);
	  return (newBlock + 1);
	}
      if ((newBlock = copy_block(tmpBlock, size)) != NULL)
	{
	  free(ptr);
	  return (newBlock + 1);
	}
    }
  if (size == 0)
    free(ptr);
  return (NULL);
}
