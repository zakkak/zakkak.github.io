/******************************************************************************
 *                                                                            *
 * File: hanoi_towers.c                                                       *
 *                                                                            *
 * This program solves the Towers of Hanoi puzzle recursively                 *
 *                                                                            *
 * For details about that weird \033 staff visit                              *
 *  www.linuxdoc.org/HOWTO/Bash-Prompt-HOWTO/c327.html                        *
 *                                                                            *
 * Compile:                                                                   *
 *  gcc -lm hanoi.c -o hanoi                                                  *
 *                                                                            *
 * Copyright (C) 2011-2012  Foivos S. Zakkak                                  *
 *                                                                            *
 * This program is free software: you can redistribute it and/or modify       *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.      *
 *                                                                            *
 ******************************************************************************/

/* needed for usleep (see man usleep) */
#define _BSD_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>

/* Unomment to disable effects */
/* #define CS100 */
#ifndef CS100
#if defined(WIN32) || defined(WIN64)
#undef COLORED
#undef KEEPLOG
#else
#define COLORED
#define KEEPLOG
#endif
#define ANIMATED
#endif                          /*CS100 */

/* N will hold the number of disks */
int N, delay;

/* declare a structure for each column */
/* each column is actually a LIFO stack */
typedef struct column {
  int top;                      /* top holds the stack's top index */
  int *stack;                   /* stack is a dynamically allocated array which
                                   is used as the stack */
} column_t;

/* This function prints the board
 * won't work well for N>9 */
void printBoard(column_t board[3])
{

  int i, j, k, n, num_of_digits, width, disk, mod, div;

  /* calculate the width of the largest disk and add some extra space */
  int maxwidth = (2 * (N - 1)) + 4;

  /* print the letters of the columns */
  for (i = 0; i < 3; ++i) {
    for (k = 0; k < (maxwidth / 2); ++k)
      printf(" ");

    printf("%c", 'A' + i);

    for (k = 0; k < (maxwidth / 2); ++k)
      printf(" ");
  }
  printf("\n");
#ifdef KEEPLOG
  printf("\033[2K");
#endif                          /* KEEPLOG */
  printf("\n");


  /* print the first empty line for all three columns */
  for (i = 0; i < 3; ++i) {
    for (k = 0; k < (maxwidth / 2); ++k)
      printf(" ");

    printf("|");

    for (k = 0; k < (maxwidth / 2); ++k)
      printf(" ");
  }
  printf("\n");

  /* now print the actual columns */
  for (i = N - 1; i >= 0; --i) {        /* for each stack level */
    for (j = 0; j < 3; ++j) {   /* for each column/stack */
      disk = board[j].stack[i];
      /* calculate the disk's width */
      width = (2 * (disk - 1)) + 1;

      if (disk) {            /* if there is a disk at this level of the stack */
        for (k = 0; k < (((maxwidth - width) + 1) / 2); ++k)
          printf(" ");

        /* calculate the numbers width */
        n = disk;
        num_of_digits = 0;
        while (n > 0) {
          n /= 10;
          ++num_of_digits;
        }

#ifdef COLORED
        /* change color */
        printf("\033[1;%dm", 31 + disk % 6);
#endif                          /* COLORED */
        div = width / num_of_digits;
        for (k = 0; k < div; ++k)
          printf("%d", disk);

        mod = width % num_of_digits;
        /* if there are more digits to print */
        if (mod)
          printf("%d", disk / (int) pow(10, num_of_digits - mod));

#ifdef COLORED
        /* reset color */
        printf("\033[0m");
#endif                          /* COLORED */

        for (k = 0; k < (((maxwidth - width) + 1) / 2); ++k)
          printf(" ");
      } else {              /* if there is no disk at this level of the stack */
        for (k = 0; k < (maxwidth / 2); ++k)
          printf(" ");

        printf("|");

        for (k = 0; k < (maxwidth / 2); ++k)
          printf(" ");

      }

    }
    printf("\n");
  }

  /* print the bottom line */
  for (i = 0; i < (maxwidth + 1) * 3; ++i)
    printf("-");

  printf("\n");

#ifdef ANIMATED
  /* set the delay between the printings */
  usleep(delay);
#endif                          /* ANIMATED */
}

/* moves 'disk' from 'from' to 'to' in 'board' */
void move(column_t * board, int disk, int from, int to)
{

  /* remove the disk from the 'from' column */
  board[from].stack[--board[from].top] = 0;
  assert(board[from].top >= 0);

  /* move the disk to the 'to' column */
  board[to].stack[board[to].top++] = disk;

#ifdef ANIMATED
  /* clear the terminal for animated solving */
#if defined(WIN32) || defined(WIN64)
  system("CLS");
#else
  /* there are many ways to do it
   * 1st call system call clear
   */
  /* system("clear");
   */
  /* 2nd do yourself what clear would do \033[H moves the cursor to the top left
   * of the terminal and \033[J clears it
   */
  /*printf("\033[H\033[J");
   */
  /* 3rd move your cursor X lines up and continue your printing from there
   * \033[A moves cursor up N lines
   */
#ifdef KEEPLOG
  printf("\033[%dA", N + 6);
#else
  printf("\033[%dA", N + 7);
#endif                          /* KEEPLOG */
#endif                          /* WIN32 || WIN64 */
#endif                          /* ANIMATED */

  /* print the move and then the board */
  printf("\n%c-->%c\n", 'A' + from, 'A' + to);
#ifdef KEEPLOG
  printf("\033[2K");
#endif                          /* KEEPLOG */
  printf("\n");
  printBoard(board);

  return;
}

/* moves 'disk' number of disks from 'from' to 'to' in 'board' */
void hanoi(column_t * board, int disk, int from, int to)
{
  int tmp;

  /* if there are no disks to move return (end recursion) */
  if (--disk == 0)
    return;

  /* calculate the column to use as temporary */
  tmp = 3 - (to + from);

  /* step 1:
   *   first move all the disks except the bottom one to the tmp column */
  hanoi(board, disk, from, tmp);
  /* step 2:
   *   now we can move the last disk to 'to' */
  move(board, disk, from, to);
  /* step 3:
   *   now move the previously moved (step 1) disks from the tmp column
   *   to 'to' */
  hanoi(board, disk, tmp, to);

  return;
}

int main(int argc, char **argv)
{

  int i;
  column_t board[3];

#ifndef CS100
  if (argc != 3)
#else
  if (argc != 2)
#endif                          /* CS100 */
  {
    printf("
       Copyright (C) 2011-2012 Foivos S. Zakkak \n
       This program comes with ABSOLUTELY NO WARRANTY.\n
       This is free software, and you are welcome to redistribute it\n
       under certain conditions.\n\n");
#ifndef CS100
    printf("
       Usage:%s  \n
       Example:%s 5 100\n", argv[0], argv[0]);
#else
    printf("
       Usage:%s \n
       Example:%s 5\n", argv[0], argv[0]);
#endif                          /* CS100 */
    return 1;
  }

  N = atoi(argv[1]);
#ifndef CS100
  delay = atoi(argv[2]) * 1000;

  if ((N * delay) < 0) {
    printf("Please enter positive numbers!");
    return 1;
  }
#endif                          /* CS100 */

  board[0].top = N;
  board[0].stack = (int *) malloc(N * sizeof(int));

  /* initially place all disks at first column */
  for (i = 0; i < N; ++i)
    board[0].stack[i] = N - i;

  for (i = 1; i < 3; ++i) {
    board[i].top = 0;
    board[i].stack = (int *) malloc(N * sizeof(int));
  }

  printf("\n\n\n");
  printBoard(board);
  hanoi(board, N + 1, 0, 2);

  /* free the allocated memory */
  for (i = 0; i < 3; ++i)
    free(board[i].stack);

  return 0;
}
