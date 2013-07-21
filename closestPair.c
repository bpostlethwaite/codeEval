/*
 * CodeEval Challenge
 * CLOSEST PAIR
 * Ben Postlethwaite
 * post.ben.here@gmail.com
 * 2013
 */

/*


ou will be given the x/y co-ordinates of several locations.
You will be laying out 1 cable between two of these locations.
In order to minimise the cost, your task is to find the shortest
distance between a pair of locations, so that pair can be chosen
for the cable installation.

Input sample:

Your program should accept as its first argument a path to a filename.
The input file contains several sets of input.
Each set of input starts with an integer N (0<=N<=10000), which denotes
the number of points in this set. The next N line contains the coordinates
of N two-dimensional points. The first of the two numbers denotes the
X-coordinate and the latter denotes the Y-coordinate.
The input is terminated by a set whose N=0.
This set should not be processed.
The value of the coordinates will be less than 40000 and non-negative. eg.

5
0 2
6 67
43 71
39 107
189 140
0
Output sample:

For each set of input produce a single line of output containing
a floating point number (with four digits after the decimal point)
which denotes the distance between the closest two points.
If there is no such two points in the input whose distance is less than 10000,
print the line INFINITY. eg.

36.2215


*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define BUFFLEN 1024
#define MINRADIUS 10000.0


/*
 * Convenience function to get radius
 */
double getRadius(int *p1, int *p2) {

  int xd2 = (p1[0] - p2[0]) * (p1[0] - p2[0]);
  int yd2 = (p1[1] - p2[1]) * (p1[1] - p2[1]);

  return sqrt((double) (xd2 + yd2));
}


/*
 * Main Algorithm function
 *
 * Trick is to not compute same pairs twice
 * so set a limiter which decrements each main loop
 */
double findClosestPair(int(*set)[2], int N) {

  int p1[2] = {0,0};
  int p2[2] = {0,0};

  int limiter = 0;
  double r;
  double minr = MINRADIUS + 1;

  for (int i = 0; i < N-1; i++) {

    p1[0] = set[i][0];
    p1[1] = set[i][1];

    limiter++;

    for (int j = limiter; j < N; j++) {

      p2[0] = set[j][0];
      p2[1] = set[j][1];

      r = getRadius(p1, p2);

      if (r < minr)
        minr = r;
    }
  }

  return minr;
}


int main(int argc, char *argv[]) {

  FILE * f;
  char line[BUFFLEN];
  int N, l, r;
  double radius = MINRADIUS;


  /*
   * Open file for reading
   */
  if (argc < 2 || !(f = fopen(argv[1], "r"))) {
    fprintf(stderr, "Unable to open file argument\n");
    return 1;
  }

  /* get header N */
  /*   read N lines */
  /*   get next line, if 0 stop */
  /*   eles repeate */

  while (fgets(line, BUFFLEN, f)) {

    /*
     * Get Header
     */
    fgets(line, BUFFLEN, f);
    sscanf(line, "%i", &N, &l);

    /*
     * Allocate 2D array of size (N, 2)
     */
    int(*set)[2] = malloc((sizeof *set) * N);

    /*
     * Loop over remaining N lines
     */

    for (int i = 0; i < N; i++) {


      /*
       * Get new line
       */
      fgets(line, BUFFLEN, f);


      /*
       * Assign ints to array
       */
      sscanf(line, "%i %i", &set[i][0], &set[i][1]);
    }

    /*
     * Run main algorithm
     */
    radius = findClosestPair(set, N);


    /*
     * Specified output
     */
    if (radius > MINRADIUS)
      printf("INFINITY\n");
    else
      printf("%.4f\n", radius);

    /*
     * Check if end of input
     */
    fgets(line, BUFFLEN, f);
    sscanf(line, "%i", &N);
    if ((N == 0) && (line[1] == '\n'))
      break;


    free(set);
  }




  fclose(f);

  return 0;
}
