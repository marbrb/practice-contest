#include <bits/stdc++.h>
using namespace std;

int main() {
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int> > min_heap;
  int q, a,b;
  cin >> q;
  int nums[100001];
  for (int i=1; i< 100002; i++){
    nums[i] = 0;
  }

  for (int i=0; i<q; i++) {
    cin >> a;

    if (a == 1) {
      cin >> b;
      max_heap.push(b); min_heap.push(b);
      nums[b] += 1;

    } else if (a == 2) {
      cin >> b;
      if (nums[b] == 0) {
         cout << "-1\n";
      } else {
        nums[b]--;
      }

    } else if (a == 3) {
      while (true) {
        if (max_heap.empty()){
          cout << "-1\n";
          break;
        }
        b = max_heap.top();

        if (nums[b]) {
          cout << b << '\n';
          break;
        } else {
          max_heap.pop();
        }
      }

    } else {
      while (true) {
        if (min_heap.empty()){
          cout << "-1\n";
          break;
        }
        b = min_heap.top();

        if (nums[b]) {
          cout << b << '\n';
          break;
        } else {
            min_heap.pop();
        }
      }
    }
  }

  return 0;
}
