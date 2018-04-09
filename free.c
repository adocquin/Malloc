/*
** free.c for malloc in /home/docqui_a/work/PSU_2015_malloc/v2/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Tue Feb  9 23:11:12 2016 Avel Docquin
** Last update Sun Feb 14 23:37:13 2016 Avel Docquin
*/

#include "headers/free.h"

extern t_block	*block;

void	free(void *ptr)
{
  t_block	*tmpBlock;

  if (ptr && block)
    {
      tmpBlock = block;
      while (tmpBlock && tmpBlock + 1 != ptr)
	tmpBlock = tmpBlock->next;
      if (tmpBlock + 1 == ptr)
	{
	  tmpBlock->used = 0;
	  if (!tmpBlock->prev && !tmpBlock->next)
	    {
	      brk(block);
	      block = NULL;
	      }
	}
    }
}
