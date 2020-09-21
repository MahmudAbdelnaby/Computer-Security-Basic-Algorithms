#include<iostream>
#include<string>
#include<queue>
using namespace std;


int main() {

	unsigned long long n;
	int shift, ti;
	char toBe;
	string s;
	string out ="";
	cin >> n;
	cin >> s;
	shift = n % 26;
	for (int i = 0; i < s.size(); i++) {
		ti = shift + s[i];
		if (ti > 90) {
			toBe = ti - 26; 
			out += toBe;
		}
		else {
			toBe = s[i] + shift;
			out += toBe;
		}
	}

	cout << out << endl;
	
	//system("Pause");
}