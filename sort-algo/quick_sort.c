#include <stdio.h>

#define SIZE 9

void quick_sort(int a[], int lo, int hi) {
  int i = lo;                           /* lower index */
  int j = hi;                           /* upper index */
  int h;

  int x = a[(lo + hi)/2];

  do {
	while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      h = a[i];
      a[i] = a[j];
      a[j] = h;
      i++;
      j--;
    }
  } while (i <= j);

  /* recursion */
  if (lo < j) quick_sort(a, lo, j);
  if (i < hi) quick_sort(a, i, hi);
}

void print(int a[], int size) {
  int i;
  for (i = 0; i < size; i++) {
	printf ("%d ",a[i]);
  }
  printf ("\n");
}

int main(int argc, char **argv) {
  int a[SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  print(a, SIZE);
  quick_sort(a, 0, SIZE-1);
  print(a, SIZE);
  return 0;
}
