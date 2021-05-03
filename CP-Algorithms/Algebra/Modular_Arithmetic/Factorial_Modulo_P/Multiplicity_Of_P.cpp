#include <bits/stdc++.h>

using namespace std;

int multiplicity_factorial(int n, int p) {
	int count = 0;
	do {
		n /= p;
		count += n;
	} while(n);

	return count;
}	

int main() {
	int n = 7, p = 3;
	cout << "n : " << n << " p : " << p << endl;
	cout << "Multiplicity Factorial is : " << multiplicity_factorial(n, p) << endl;
	return 0;
}
