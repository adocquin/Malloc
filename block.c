/*
** block.c for malloc in /home/docqui_a/work/PSU_2015_malloc/v2/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Tue Feb  9 18:35:15 2016 Avel Docquin
** Last update Sun Feb 14 23:36:50 2016 Avel Docquin
*/

#include "headers/block.h"

t_block *block = NULL;

t_block	*init_block(size_t mem)
{
  block = sbrk(0);
  if ((sbrk(BLOCK_SIZE + mem)) == (void *) - 1)
    return (NULL);
  block->size = mem;
  block->used = 1;
  block->end = sbrk(0);
  block->next = NULL;
  block->prev = NULL;
  return (block);
}

t_block	*add_block(size_t mem)
{
  t_block	*newBlock;
  t_block	*tmpBlock;

  newBlock = sbrk(0);
  if ((sbrk(BLOCK_SIZE + mem)) == (void *) - 1)
    return (NULL);
  newBlock->size = mem;
  newBlock->used = 1;
  newBlock->end = sbrk(0);
  if (block->next == NULL)
    {
      block->next = newBlock;
      newBlock->prev = block;
    }
  else
    {
      tmpBlock = block;
      while (tmpBlock->next)
	tmpBlock = tmpBlock->next;
      tmpBlock->next = newBlock;
      newBlock->prev = tmpBlock;
    }
  newBlock->next = NULL;
  return (newBlock);
}

t_block	*copy_block(t_block *tmpBlock, size_t mem)
{
  t_block	*newBlock;

  newBlock = sbrk(0);
  if ((sbrk(BLOCK_SIZE + mem)) == (void *) - 1)
    return (NULL);
  if (tmpBlock->size <= mem)
    memcpy(newBlock + 1, tmpBlock + 1, tmpBlock->size);
  else
    memcpy(newBlock + 1, tmpBlock + 1, mem);
  tmpBlock = block;
  while(tmpBlock->next)
    tmpBlock = tmpBlock->next;
  newBlock->size = mem;
  newBlock->used = 1;
  newBlock->prev = tmpBlock->prev;
  newBlock->end = sbrk(0);
  tmpBlock->next = newBlock;
  newBlock->next = NULL;
  return (newBlock);
}

t_block	*find_free_block(size_t mem)
{
  t_block	*tmpBlock;

  tmpBlock = block;
  while (tmpBlock != NULL)
    {
      if (tmpBlock->size >= mem && tmpBlock->used == 0)
	return (tmpBlock);
      tmpBlock = tmpBlock->next;
    }
  return (NULL);
}
