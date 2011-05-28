#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define KSIZE  8
#define R_SIZE 10

#define RESET		0
#define BRIGHT 		1
#define DIM		2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void print(int *, int, int, int);
void textcolor(int, int, int);
void print2(int *, int, int, int);

void insert_sort(int *a, int size) {
  int i, j;
  int k;                                /* number of position move every time */
  int temp;
  for (i = 1; i < size; i++) {
	for (temp = a[i],j = i-1, k = 0; temp <= a[j] && j >= 0; j--) {
      a[j+1] = a[j];
      k++;
    }
    a[j+1] = temp;
    print(a, i+1, k, size);
  }
}

void insert_sort2(int *a, int size) {
  int i, temp;
  int j;
  int k;                                /* the positions need to move */
  for (i = 1; i < size; i++) {
    k = 0;
	if (a[i] < a[i - 1]) {
      temp = a[i];
      for (j = i; j > 0 && a[j-1] > temp; j--) {
        a[j] = a[j-1];
        k++;
      }
      a[j] = temp;
    }
    print2(a, i+1, k, size);
  }
}

void print(int *a, int j, int k, int size) {
  int i;
  for (i = 0; i < size; i++) {
    if (i == j) {
      printf ("|");
    }
	printf ("%d ", a[i]);   
  }
  printf ("(%d)", k);
  printf ("\n");
}

void print2(int *a, int j, int k, int size) {
  int i;
  
  for (i = 0; i < size; i++) {
	if (i < j) {
      textcolor(BRIGHT, RED, BLACK);
      printf ("%d ", a[i]);
    } else {
      textcolor(RESET, WHITE, BLACK);
      printf ("%d ", a[i]);
    }    
  }
  textcolor(RESET, WHITE, BLACK);
  printf ("(%d)", k);
  printf ("\n");
  
}

void textcolor(int attr, int fg, int bg) {
  char command[13];

  /* Command is the control command to the terminal */
  sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
  printf("%s", command);
}



int main(int argc, char **argv) {
  srand(time(NULL));
  int r_array[100], i;
  for (i = 0; i < R_SIZE; i++) {
	r_array[i] = rand() % 100 + 1;      /* generate random number between 1 and 100 */
  }
  int a[KSIZE] = {5, 7, 0, 3, 4, 2, 6, 1};
  insert_sort2(a, KSIZE);
  printf ("\n");
  insert_sort2(r_array, R_SIZE);
  /* print(a); */
  return 0;
}
