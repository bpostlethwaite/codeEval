/*
 * CodeEval Challenge
 * TrialPay
 * ROBOTMOVEMENTS
 * Ben Postlethwaite
 * post.ben.here@gmail.com
 * 2013
 */

/*
Description:

A robot is located at the top-left corner of a 4x4 grid. The robot can move either up, down, left, or right, but can not visit the same spot twice. The robot is trying to reach the bottom-right corner of the grid.

Input sample:

There is no input for this program.

Output sample:

Print out the unique number of ways the robot can reach its destination. (The number should be printed as an integer whole number eg. if the answer is 10 (its not !!), print out 10, not 10.0 or 10.00 etc)
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SEEN 1
#define BOARDSIZE 4
#define ROW 0
#define COL 1

void roboMove(int, int, int, int step[4][2], int *, int *);

int main() {

  int i, win = 0;
  int n = BOARDSIZE * BOARDSIZE;
  int path[n];

  for (i = 0; i < n; i++) {
    path[i] = 0;
  }

  int step[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

  roboMove(0, 0, BOARDSIZE, step, path, &win);

  printf("%.0d\n", win);

  return 0;
}

void roboMove(int row, int col, int bsize, int step[4][2], int *oldpath, int * win) {

  int i, r ,c;

  if (row == bsize - 1 && col == bsize - 1) {
    (*win)++;
    return;
  }

  int *newpath = malloc(sizeof(int) * bsize * bsize);
  memcpy(newpath, oldpath, sizeof(int) * bsize * bsize);

  newpath[row * bsize + col] = SEEN;

  for (i = 0; i < 4; i++) {
    r = row + step[i][ROW];
    c = col + step[i][COL];
    if (r < bsize && r >= 0 &&
        c < bsize && c >= 0 &&
        newpath[r * bsize + c] != SEEN) {

      roboMove(r, c, bsize, step, newpath, win);

    }
  }
  free(newpath);

  return;
}



