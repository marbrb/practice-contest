
#include <bits/stdc++.h>
#define left(x) x << 1
#define right(x) x << 1 | 1
#define ROOT 1
using namespace std;

void build(int *T, int *A, int node, int start, int end) {
    if(start == end) {
        T[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        build(T, A, left(node), start, mid);
        build(T, A, right(node), mid + 1, end);
        // Merging the children
        T[node] = T[left(node)] + T[right(node)];

    }
}


int query(int *T, int node, int start, int end, int a, int b) {
    if(b < start || end < a)  // out of he boundaries
        return 0;
    if(a <= start && end <= b)
        return T[node];

    int mid = (start + end) / 2;
    int p1 = query(T, left(node), start, mid, a, b);
    int p2 = query(T, right(node), mid + 1, end, a, b);

    return p1 + p2;
}

int main() {
    int n, k,c;
    cin >> n >> k >> c;


    int *a = new int[n];
    int aux;
    for (int i=0; i<n; i++){
        cin >> aux;
        if (aux <= k){
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }


    int *stree = new int[4 * n];


    build(stree, a, ROOT, 0, n - 1);

    int cont = 0;

    for (int i=0; i<= n-c; i++){

        int to= i+c-1;
        if (query(stree, ROOT, 0, n-1, i, to) == c) {
            cont++;
        }
    }

    cout << cont << '\n';

    return 0;
}
