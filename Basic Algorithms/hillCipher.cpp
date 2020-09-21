#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<math.h>
using namespace std;

char getChar(int x, map<char, int>_map) {

	for (auto itr = _map.begin(); itr != _map.end(); itr++) {
		if (itr->second == x)
			return itr->first;
	}

}

int main() {
	map<char, int> m;
	int n, temp, toBeAdded, x, index = 0;
	string text, cipher = "";
	
	for (int i = 0; i < 26; i++) {
		m['A' + i] = i;
	}

	cin >> n;
	x = sqrt(n);
	vector<vector<unsigned long long int>> matrix(x, vector<unsigned long long int>());

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			cin >> temp;
			matrix[i].push_back(temp);
		}
	}

	cin >> text; 

	if (text.size() % x != 0) {
		toBeAdded = x - (text.size() % x);
	}
	else
		toBeAdded = 0;
		
	for (int i = 0; i < toBeAdded; i++) {
		text += 'X';
	}

	for (int i = 0; i < text.size(); i+= x) {
		vector<int> vec(x);
		vector<unsigned long long int> res(x, 0);

		for (int j = 0; j < x; j++) {
			vec[j] = m[text[index]];
			index++;
		}

		for (int j = 0; j < x; j++) {
			for (int k = 0; k < x; k++) {
				res[j] += (matrix[j][k] * vec[k])%26;
			}
			char c = getChar(res[j]%26, m);
			cipher += c;
		}
		
	}

	cout << cipher << endl;
	//system("Pause");
}
