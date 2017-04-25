#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, num, res = 0, maxi;
    priority_queue<long long> pq;
    cin >> m >> n;

    while (m--) {
        cin >> num;
        pq.push(num);
    }
    maxi = pq.top();
    pq.pop();

    while (n > 0) {
        if (maxi >= pq.top()){
            res += maxi;
            maxi -= 1;
            n -=1 ;
        } else {
            pq.push(maxi);
            maxi = pq.top();
            pq.pop();
        }
    }

    cout << res << '\n';

    return 0;
}
