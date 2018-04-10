#include <bits/stdc++.h>
using namespace std;

int a, b, rows[8], solNum;

bool place(int r, int c){
  for (int ant=0; ant<c; ant++){
    if (rows[ant] == r || (abs(rows[ant] - r) == abs(ant - c)))
      return false;
  }
  return true;
}

void backtracking(int col){
  if (col == 8 && rows[b] == a){ // this is a valid solution
    printf("%2d     ", solNum++);
    for(int i=0;i<col;i++){
      cout << ' ' << rows[i]+1;
    }cout << endl;
  }
  for(int row=0; row<=7; row++){
    if(place(row, col)){
      rows[col] = row;
      backtracking(col+1);
    }
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> a >> b;
    a--; b--;
    solNum=1;
    cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n\n";
    backtracking(0);
    if(t) cout << '\n';
  }
  
  return 0;
}
