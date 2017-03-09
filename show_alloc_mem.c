/*
** show_alloc_mem.c for malloc in /home/docqui_a/work/PSU_2015_malloc/v2/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Tue Feb  9 22:00:27 2016 Avel Docquin
** Last update Sun Feb 14 22:49:17 2016 Avel Docquin
*/

#include "show_alloc_mem.h"

extern t_block *block;

void	show_alloc_mem() {
  t_block	*tmpBlock;

  tmpBlock = block;
  printf("break : %p\n", sbrk(0));
  tmpBlock = block;
  while (tmpBlock) {
      if (tmpBlock->used == 1)
	printf("%p - %p : %zu bytes\n", tmpBlock + 1, tmpBlock->end, tmpBlock->size);
      tmpBlock = tmpBlock->next;
    }
}
