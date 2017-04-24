#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,temp, a,b;
    priority_queue<long long> pq;
    cin >> n;
    for (int i; i<n; i++) {
        cin >> temp;
        pq.push(temp);

        if (pq.size() < 3) {
            cout << "-1\n";
            continue;
        }else{
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            cout << a*b*pq.top() << '\n';
            pq.push(a);
            pq.push(b);
        }
    }
    return 0;
}
