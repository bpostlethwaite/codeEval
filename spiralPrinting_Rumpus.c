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
//#include <ctype.h>
#include <string.h>

#define BUFFLEN 1024

void getDims(char *line, int * dim) {

  int len;

}


int main(int argc, char *argv[]) {

  FILE * f;
  char line[BUFFLEN];
  int buff[BUFFLEN];
  int dim[2];
  char *sep = " ";
  char *s, *rest, *token;
  int ix, FIRST = 1;
  int pcount, len;
  int j, N, n, M, m, row, col;



  char hello[] = "Hello World, Let me live."; // make this a char array not a pointer to literal.
  char *ptr = hello; // make q point to start of hello.


  if (argc < 2 || !(f = fopen(argv[1], "r"))) {
    fprintf(stderr, "Unable to open file argument\n");
    return 1;
  }

  while (fgets(line, BUFFLEN, f)) {
    FIRST = 1;
    ix = pcount = 0;
    // Skip empty lines
    if (line[0] == '\n') {
      continue;
    }

    /*
     * Get Character array
     */
    // loop till strtok_r returns NULL.
    while(token = strtok_r(ptr, " ,", &rest)) {

      printf("%s\n", token); // print the token returned.
      ptr = rest; // rest contains the left over part..assign it to ptr...and start tokenizing again.
    }
    /* char *ptr = line; */
    /* for (token = strtok_r(ptr, sep, &saveptr); */
    /*      token; */
    /*      token = strtok_r(NULL, sep, &saveptr)) */
    /*   { */
    /*     printf("got token %s\n", token); */
    /*   } */
    break;


    /* for (j = 1; ; j++, line[0] = NULL) { */
    /*   token = strtok_r(line, sep, &saveptr1); */
    /*   if (token == NULL) */
    /*     break; */
    /*   printf("%d: %s\n", j, token); */
    /* } */


    n = N = dim[0];
    m = M = dim[1];


    while (pcount < ix - 1 ) {
      // Along top row
      for (row = N - n, col = M - m; col < m; col++) {
        if (FIRST) {
          printf("%c", buff[ row * M + col ]);
          FIRST = 0;
        }
        else
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

  fclose(f);
  return 0;
}


