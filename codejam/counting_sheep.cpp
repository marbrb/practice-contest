#include <bits/stdc++.h>

using namespace std;

set<int> digits (long long n){
	set<int> digi;
	while (n) {
		digi.insert(n%10);
		n = n/10;
	}
	return digi;
}

int main() {
	int cases;
	long long n, auxi;
	set<int> natu;
	cin >> cases;

	for (int i=1; i<=cases; i++){
		cin >> n;
		if (n == 0){
			cout << "Case #"<< i <<": INSOMNIA\n";
		}else{
			int op = 2;
			auxi = n;
			natu.clear();
			while(true){

				set<int> aux = digits(auxi);
				natu.insert(aux.begin(), aux.end());

				if (natu.size() < 10){
					auxi = n*op;
					op += 1;

				}else{
					cout << "Case #" << i << ": " << auxi << '\n';
					break;
				}
			}
		}
	}
}
