#include <bits/stdc++.h>

using namespace std;

int count_primes(int n) {
	const int S = 1e4;

	vector<int> primes;
	int nsqrt = sqrt(n);

	vector<char> is_prime(nsqrt + 1, true);
	for(int i = 2;i <= nsqrt;i++) {
		if(is_prime[i]) {
			primes.push_back(i);
			for(int j = i * i;j <= nsqrt;j += i) is_prime[j] = false;
		}
	}

	int result = 0;
	vector<char> block(S);

	for(int k = 0;k * S <= n;k++) {
		fill(block.begin(), block.end(), true);

		int start = k * S;
		for(int p : primes) {
			int start_idx = (start + p - 1) / p;
			int j = max(start_idx, p) * p - start;
			for(;j < S;j += p) block[j] = false;
		}

		if(k == 0) {
			block[0] = block[1] = false;
		}

		for(int i = 0;i < S && start + i <= n;i++) {
			if(block[i]) {
				result++;
			}
		}
	}

	return result;
}



int main() {
	int n = 20;
	cout << "n : " << n << endl;
	cout << "No of prime numbers less than or equal to n : " << count_primes(n) << endl;
	return 0;
}
