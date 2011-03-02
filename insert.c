#include <stdio.h>

int main(int argc, char **argv) {
  int array[20], N, temp,i,j;
  printf ("Enter the length of the array...\n");
  scanf("%d", &N);
  printf("Please a array for sort(array.length <  20)...\n");
  for (i = 0; i < N; i++) {
    scanf("%d", array+i);
  }
  printf ("before the sort \n");
  for (i = 0; i < N; i++) {
    printf("%d ", *(array+i));
  }
  printf ("\n");

  for (i = 1; i < N; i++) {
    temp = array[i];
    j = i -1;
    while (temp < array[j] && j >=0) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = temp;
  }

  printf ("After  the sort \n");
  for (i = 0; i < N; i++) {
    printf("%d ", *(array+i));
  }
  printf ("\n");

  return 0;
}

