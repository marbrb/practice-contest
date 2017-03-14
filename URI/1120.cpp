#include <bits/stdc++.h>

using namespace std;

int main() {

  string number, solution;
  char dig;

  while (true) {
    cin >> dig >> number;
    solution = "";
    if (dig == '0') {
      if (number == "0"){
        break; //0 0 Base case
      }
    }

    for (int i=0; i<number.length(); i++) {
      if (number[i] != dig) {
        if (number[i] == '0') {
          if (solution.length() != 0) {
            solution.push_back(number[i]);
          }
        } else {
          solution.push_back(number[i]);
        }
      }
    }

    if (solution.length() == 0) {
      cout << "0\n";
    } else {
      cout << solution << '\n';
    }

  }

  return 0;
}
