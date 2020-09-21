#include<iostream>
#include<vector>

using namespace std;

int main() {
	unsigned long long int m, n;
	int f = 0, i = 0;
	vector<unsigned long long int> A1, A2, A3, Q, B1, B2, B3;
	unsigned long long int mulInverse, addInvere;

	Q.push_back(-1);
	A1.push_back(1);
	A2.push_back(0);
	B1.push_back(0);
	B2.push_back(1);

	cin >> m >> n;

	A3.push_back(m);
	B3.push_back(n);

	while(B3[i] != 1){
	
		if (B3[i] == 0) {
			f = 1;
			break;
		}
		else {
			A1.push_back(B1[i]);
			A2.push_back(B2[i]);
			A3.push_back(B3[i]);
			Q.push_back(m / n);
			i++;
			B1.push_back(A1[i - 1] - Q[i] * A1[i]);
			B2.push_back(A2[i - 1] - Q[i] * A2[i]);
			B3.push_back(A3[i - 1] - Q[i] * A3[i]);
		}
	
	}

	addInvere = m - n;
	mulInverse = B3.front();

	if (f == 1)
		cout << "IMPOSSIBLE";
	else
		cout << addInvere << mulInverse;


	system("Pause");
}