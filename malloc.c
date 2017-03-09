/*
** malloc.c for malloc in /home/docqui_a/work/PSU_2015_malloc/v2/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Tue Feb  9 17:50:49 2016 Avel Docquin
** Last update Sun Feb 14 23:37:21 2016 Avel Docquin
*/

#include "malloc.h"

extern t_block	*block;

void	*malloc(size_t size)
{
  size_t	mem;
  t_block	*cBlock;
  t_block	*tmpBlock;

  if (size <= 0)
    return (NULL);
  mem = (size - 1) / 4 * 4 + 4;
  if (!block)
    {
      if (!init_block(mem))
	return (NULL);
      return (block + 1);
    }
  if ((tmpBlock = find_free_block(size)) != NULL)
    {
      tmpBlock->used = 1;
      return (tmpBlock + 1);
    }
  cBlock = add_block(mem);
  return (cBlock + 1);
}
