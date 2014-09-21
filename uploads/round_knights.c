/******************************************************************************
 *                                                                            *
 * File: round_knights.c                                                      *
 *                                                                            *
 * This program solves the knights of the round table math problem with some  *
 * bitwise logic                                                              *
 *                                                                            *
 * For details about the problem                                              *
 *  http://mathforum.org/library/drmath/view/55862.html                       *
 *                                                                            *
 * Copyright (C) 2011-2012        ++++++++++++++++++++++++++++++              *
 *                                + Author:  Foivos S. Zakkak  +              *
 *                                + Website: foivos.zakkak.net +              *
 *                                + Email:   foivos@zakkak.net +              *
 *                                ++++++++++++++++++++++++++++++              *
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

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
  char *res = NULL;

  if (argc != 2) {
    printf("Usage: %s \n", argv[0]);
    return 1;
  }

  unsigned long long int n = strtoull(argv[1], &res, 10);

  int msb = (sizeof(n) * 8) - __builtin_clzll(n);

  if (*res != '\0' || n == 0 || strstr(argv[1], "-")) {
    printf("ERROR: \"%s\" is not a correct input\n", argv[1]);
    return 1;
  } else if (errno) {
    printf("ERROR: %s\n", strerror(errno));
    return 1;
  } else {
    printf("%llu is the survivor\n", ((n ^ (1 << (msb - 1))) << 1) + 1);
    return 0;
  }
}
