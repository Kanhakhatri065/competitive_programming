#include <bits/stdc++.h>

using namespace std;

int phi(int n) {
	int result = n;
	for(int i = 2;i * i <= n;i++) {
		if(n % i == 0) {
			while(n % i == 0) {
				n /= i;
			}

			result -= result / i;
		}
	}

	if(n > 1) {
		result -= result / n;
	}

	return result;
}

int main() {
	int n = 25;
	cout << "n : " << n << endl;
	cout << "total number which are coprime to " << n <<  " between 1 and " << n << " are : " << phi(n) << endl;
	return 0;
}
