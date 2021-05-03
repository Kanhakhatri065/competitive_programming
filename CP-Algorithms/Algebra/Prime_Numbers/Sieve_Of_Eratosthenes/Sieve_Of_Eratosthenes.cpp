#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
bool sieve[MAX];
void sieve_of_eratosthenes() {
	memset(sieve, true, sizeof(sieve));
	sieve[0] = sieve[1] = false;

	for(int i = 2;i < MAX;i++) {
		if(sieve[i]) {
			for(int j = 2 * i;j < MAX;j += i) {
				sieve[j] = false;
			}
		}
	}
}

int main() {
	sieve_of_eratosthenes();
	
	cout << "Prime numbers between 1 and 16 : " << endl;
	for(int i = 1;i <= 16;i++) {
		if(sieve[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
