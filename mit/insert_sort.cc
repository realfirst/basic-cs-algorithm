// this is c++ code which implement
// the insert sort algorithm in the
// introduction to algorithm third edition

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int iArray[6] = {5, 2, 4, 6, 1, 3};
  int key;
  for (int j = 1; j < 6; j++) {
    key = iArray[j];
    // Insert A[j] into the sorted sequence iArray[1..j-1].
    int i = j - 1;
    while (i >= 0 && iArray[i] > key) {
      iArray[i+1] = iArray[i];
      i--;
    }
    iArray[i+1] = key;
  }
  
  for (int i = 0; i < 6; i++) {
    std::cout << iArray[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
