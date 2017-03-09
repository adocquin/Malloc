/*
** block.h for malloc in /home/docqui_a/work/PSU_2015_malloc/v2/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Tue Feb  9 17:51:02 2016 Avel Docquin
** Last update Sun Feb 14 22:22:50 2016 Avel Docquin
*/

#ifndef BLOCK_H_
# define BLOCK_H_

#include	<string.h>
#include	<unistd.h>

#define BLOCK_SIZE sizeof(t_block)

typedef struct	s_block {
  size_t		size;
  int			used;
  void			*end;
  struct s_block	*next;
  struct s_block	*prev;
}		t_block;

t_block		*init_block(size_t mem);
t_block		*add_block(size_t mem);
t_block		*copy_block(t_block *tmpBlock, size_t mem);
t_block		*find_free_block(size_t mem);

#endif /* BLOCK_H_ */
