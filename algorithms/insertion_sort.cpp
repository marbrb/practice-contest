#include <bits/stdc++.h>
using namespace std;

#define LENGTH 6


void insertion_sort (int A[]) {
  for (int element=1; element < LENGTH; element++) {
    int index = element;
    int key = A[index];

    // Insert A[index] in the ordered array A[0 .. index - 1]
    while (index > 0 && key < A[index - 1]) {
      A[index] = A[index - 1];
      index--;
    }
    A[index] = key;
  }
}

void print_array(int array[]) {
  for (int i = 0; i < LENGTH; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;

}

int main() {
  int nums[LENGTH] = {5, 2, 4, 6, 1, 3};

  cout << "Initial array:" << endl;
  print_array(nums);

  insertion_sort(nums);

  cout << "Ordered array:" << endl;
  print_array(nums);

  return 0;
}
