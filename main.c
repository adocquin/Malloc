/*
** main.c for malloc in /home/docqui_a/work/PSU_2015_malloc/v2/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Tue Feb  9 18:43:07 2016 Avel Docquin
** Last update Sun Feb 14 23:03:28 2016 Avel Docquin
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	main() {
  int	i;
  int	random;

  i = 0;
  int *ok;
  int *ptr_one;
  int *ptr_two;
  if ((ptr_one = (int *)realloc(NULL, 100000000)) == NULL) {
    printf("ERROR: Out of memory\n");
    return 1;
  }
  printf("ptr_one = %p\n", ptr_one);
  *ptr_one = 25;
  if ((ptr_one = realloc(ptr_one, 100)) == NULL) {
    printf("ERROR: Out of memory\n");
    return 1;
  }
  printf("realloc\n");
  *ptr_one = 250;
  printf("%d\n", *ptr_one);
  if ((ptr_two = (int *)malloc(sizeof(int))) == 0) {
    printf("ERROR: Out of memory\n");
    return 1;
  }
  *ptr_two = 40;
  printf("%d\n", *ptr_two);
  printf("sbrk: %p\n", sbrk(0));
  free(ptr_one);
  srand(time(NULL));
  while (i < 10) {
      random = rand() % 10000;
      malloc(random);
      random = (random - 1) / 4 * 4 + 4;
      printf("m[%d]: %d\n", i, random);
      ++i;
  }
  /*printf("1st brk = %p\n", sbrk(0));
  realloc(NULL, 0);
  show_alloc_mem();
  char *str = malloc(0);*/
  /*printf("%d\n", BLOCK_SIZE);
  printf("%p\n", block->ptr);
  printf("%p\n", block);*/
  /*char *str1 = malloc(16);
  char *str2 = malloc(32);
  char *str3 = malloc(2047);
  show_alloc_mem();*/
  /*free(str);
  show_alloc_mem();
  malloc(240);
  show_alloc_mem();
  free(str2);
  realloc(str2, 10000);
  show_alloc_mem();
  free(str1);
  char *str4 = malloc(14);
  show_alloc_mem();
  free(str4);
  show_alloc_mem();*/
  return (0);
}
