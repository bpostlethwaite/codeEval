/*
 * CodeEval Challenge
 * BitTorrent
 * SPIRALPRINTING
 * Ben Postlethwaite
 * post.ben.here@gmail.com
 * 2013
 */

/*
Description:

Write a program to print a 2D array (n x m) in spiral order (clockwise)

Input sample:

Your program should accept as its first argument a path to a filename.The input file contains several lines. Each line is one test case. Each line contains three items (semicolon delimited). The first is 'n'(rows), the second is 'm'(columns) and the third is a single space separated list of characters/numbers in row major order. eg.

3;3;1 2 3 4 5 6 7 8 9
Output sample:

Print out the matrix in clockwise fashion, one per line, space delimited. eg.

1 2 3 6 9 8 7 4 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFLEN 1024
#define NUMDIMS 2

char * getDims(char *, int *, int);

int main(int argc, char *argv[]) {

  FILE * f;
  char line[BUFFLEN];
  char buff[BUFFLEN];
  int dim[NUMDIMS];
  char *s;
  int ix;
  int pcount;
  int N, n, M, m, row, col;

  if (argc < 2 || !(f = fopen(argv[1], "r"))) {
    fprintf(stderr, "Unable to open file argument\n");
    return 1;
  }

  while (fgets(line, BUFFLEN, f)) {

    ix = pcount = 0;
    // Skip empty lines
    if (line[0] == '\n') {
      continue;
    }

    s = getDims(line, dim, NUMDIMS);

    // For this 2D problem
    N = dim[0];
    M = dim[1];

    //remove spaces and count length.
    for(; *s != '\0'; s++) {
      if (*s == ' ' || *s == ';')
        continue;
      buff[ix++] = *s;

    }
    buff[ix] = '\0';

    n = N;
    m = M;
    while (pcount < ix - 1 ) {
      // Along top row
      for (row = N - n, col = M - m; col < m; col++) {
        printf(" %c", buff[ row * M + col ]);
        pcount++;
      }
      // Down back side
      if (2 * n - N > 2) {
        for (col = m - 1, row = N - n + 1; row < n - 1; row++) {
          printf(" %c", buff[ row * M + col ]);
          pcount++;
        }
      }
      if (pcount == ix - 1)
        break;
      // reverse along bottom row
      for (row = n - 1, col = m - 1; col >= M - m; col--) {
        printf(" %c", buff[ row * M + col ]);
        pcount++;
      }
      // Up along front side (reverse)
      if (2 * n - N > 2) {
        for (col = M - m, row = n - 2; row >= N - n + 1 ; row--) {
          printf(" %c", buff[ row * M + col ]);
          pcount++;
        }
      }
      n--;
      m--;
    }
    printf("\n");
  }

  return 0;
}


char * getDims(char *s, int * dim, int n) {
  int dx = 0;
  for(; *s != '\0'; s++) {
    if ( (*s != ' ' || *s != ';') && isdigit(*s)) {
      dim[dx] = *s - '0';
      dx++;
    }
    if (dx == n)
      return (s+2); //To move past the last dx and the ;
  }
}
