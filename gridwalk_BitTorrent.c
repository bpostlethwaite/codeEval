/*
 * CodeEval Challenge
 * BitTorrent
 * GRIDWALK
 * Ben Postlethwaite
 * post.ben.here@gmail.com
 * 2013
 */

/*
Description:

There is a monkey which can walk around on a planar grid. The monkey can move one space at a time left, right, up or down. That is, from (x, y) the monkey can go to (x+1, y), (x-1, y), (x, y+1), and (x, y-1). Points where the sum of the digits of the absolute value of the x coordinate plus the sum of the digits of the absolute value of the y coordinate are lesser than or equal to 19 are accessible to the monkey. For example, the point (59, 79) is inaccessible because 5 + 9 + 7 + 9 = 30, which is greater than 19. Another example: the point (-5, -7) is accessible because abs(-5) + abs(-7) = 5 + 7 = 12, which is less than 19. How many points can the monkey access if it starts at (0, 0), including (0, 0) itself?

Input sample:

There is no input for this program.

Output sample:

Print the number of points the monkey can access. It should be printed as an integer — for example, if the number of points is 10, print "10", not "10.0" or "10.00", etc.
*/

#include <stdio.h>
#include <stdlib.h>

#define TARG 19
#define SEEN 1

struct node {
  int x;
  int y;
  struct node *next;
};

struct queue {
  struct node *first;
  struct node *last;
};

void enqueue(struct queue *, int, int);
struct node * dequeue(struct queue *);


int main() {

  int i, j, sum, lim, num, found;
  int ix, iy;
  /*
   * Find maximum bounding box:
   * The gridpoint on zero axis that
   * digit sums > TARG
   */
  lim = sum = 0;
  while (sum <= TARG) {
    num = lim;
    sum = 0;
    while(num != 0) {
      sum += num % 10;
      num /= 10;
   }
   lim++;
  }

  struct queue q = {NULL, NULL};
  struct queue *qp = &q;
  struct node *np;

  int marks[lim+1][lim+1];
  for(i = 0; i < lim + 1; i++) {
    for(j = 0; j < lim + 1; j++) {
      marks[i][j] = 0;
    }
  }

 int ind[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
 int ixy[2];

 /*
  * Breadth first search.
  * Loop through possible movements
  * add to queue if meets criteria and
  * has not been previously searched.
  * Only search 1/4 of domain since the problem
  * is symmetric about x and y.
  * Then multiply by 4 (with a little thought).
  */
 enqueue(qp, 0, 0);
 marks[0][0] = SEEN;
 found = 1;

 while ( np = dequeue(qp) ) {
   // Loop through a step in each direction
   for(i = 0; i < 4; i++) {
     ixy[0] = np->x + ind[i][0];
     ixy[1] = np->y + ind[i][1];
     if (ixy[0] >= 0 && ixy[1] >= 0 && marks[ixy[0]][ixy[1]] != SEEN) {
      // digit sum alg
       sum = 0;
       for(j = 0; j < 2; j++) {
         num = ixy[j];
         while(num != 0) {
           sum += num % 10;
           num /= 10;
         }
       }
       // end digit sum alg
       if (sum <= TARG) {
         enqueue(qp, ixy[0], ixy[1]);
         ++found;
       }
       marks[ixy[0]][ixy[1]] = SEEN;
     }
   }
 }

 found--; // account for [0, 0] before multiplying for other quadrants;
 /*
  * Subtract one zero axis leg before multiplying by 4 (to avoid double counting)
  * Note that it's lim - 2, since we did a lim++ AFTER <TARG was satisfied and
  * again, we remove the origin so it is not multiplied.
  */
 found -= lim - 2;
 printf("%.0d\n", found * 4 + 1); // Add back origin count after multiplying.

 return 0;
}


/*
 * Add node to end of queue
 */
void enqueue(struct queue *q, int x, int y) {
  struct node *newnode = malloc(sizeof(struct node));
  newnode->x = x;
  newnode->y = y;
  newnode-> next = NULL;

  if(q->first == NULL) {
    q->first = q->last = newnode; //if list is empty, first and last = newnode
  }
  else {
    q->last->next = newnode; //append newnode after last element
    q->last = q->last->next; // point "last" pointer to the new node
  }
  return;
}
/*
 * remove and return first node from queue
 */
struct node * dequeue(struct queue *q) {
  if (q->first == NULL) {
    return NULL;
  }
  else {
    struct node *temp = q->first;
    q->first = q->first->next;
    return temp;
  }
}
