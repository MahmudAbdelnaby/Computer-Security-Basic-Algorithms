#include<iostream>
#include<algorithm>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (b == 0)
		return a;
	return(gcd(b, a%b));
}


int main() {
	unsigned long long a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;

	//system("Pause");
}