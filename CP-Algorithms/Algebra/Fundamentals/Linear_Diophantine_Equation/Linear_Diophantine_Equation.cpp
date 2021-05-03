#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if(c % g) {
		return false;
	}

	x0 *= c / g;
	y0 *= c / g;

	if(a < 0) x0 *= -1;
	if(b < 0) y0 *= -1;

	return true;
}

int main() {
	// First example 
    int a = 3, b = 6, c = 9, x, y, g;
   	cout << "a : " << a << " b : " << b << " c : " << c << endl;	
    find_any_solution(a, b, c, x, y, g)? cout << "Possible\n" : 
                        cout << "Not Possible\n"; 
  
    // Second example 
    a = 3, b = 6, c = 8; 
	cout << "a : " << a << " b : " << b << " c : " << c << endl;
    find_any_solution(a, b, c, x, y, g)? cout << "Possible\n" : 
                       cout << "Not Possible\n"; 
  
    // Third example 
    a = 2, b = 5, c = 1; 
	cout << "a : " << a << " b : " << b << " c : " << c << endl;
    find_any_solution(a, b, c, x, y, g)? cout << "Possible\n" : 
                       cout << "Not Possible\n"; 
	return 0;
}
