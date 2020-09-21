#include<iostream>
#include<vector>
#include<string>
#include <stdlib.h>
using namespace std;

int main() {

	//int x = 0b1111;
	//printf("%x", x);
	int s, n;
	
	string input_hex, input_binary = "0", out_binary = "", out_hex="";
	char final_out[256];
	string bla;
	cin >> s; 
	vector <int> table(s+10);
	vector <string> final_output;
	table[0] = 555;
	for (int i = 1; i <= s; i++) {
		cin >> table[i];
		
	}
	cin >> n;
	cin >> input_hex;

	for (int i = 0; i < input_hex.size(); i++) {
		switch (input_hex[i])
		{
		case'0':
			input_binary += "0000";
			break;

		case'1':
			input_binary += "0001";
			break;

		case'2':
			input_binary += "0010";
			break;

		case'3':
			input_binary += "0011";
			break;

		case'4':
			input_binary += "0100";
			break;

		case'5':
			input_binary += "0101";
			break;

		case'6':
			input_binary += "0110";
			break;

		case'7':
			input_binary += "0111";
			break;

		case'8':
			input_binary += "1000";
			break;

		case'9':
			input_binary += "1001";
			break;

		case'A':
			input_binary += "1010";
			break;

		case'B':
			input_binary += "1011";
			break;

		case'C':
			input_binary += "1100";
			break;

		case'D':
			input_binary += "1101";
			break;

		case'E':
			input_binary += "1110";
			break;

		case'F':
			input_binary += "1111";
			break;

		default:
			break;
		}
	}

	for (int i = 1; i <= s; i++) {
		out_binary += input_binary[table[i]];
	}
	
	vector<string>temp;

	for (int i = 0; i < out_binary.size(); i += 4) {
		 temp.push_back(out_binary.substr(i,4));
	}

	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == "0000")
			out_hex += '0';
		else if (temp[i] == "0001")
			out_hex += '1';
		else if (temp[i] == "0010")
			out_hex += '2';
		else if (temp[i] == "0011")
			out_hex += '3';
		else if (temp[i] == "0100")
			out_hex += '4';
		else if (temp[i] == "0101")
			out_hex += '5';
		else if (temp[i] == "0110")
			out_hex += '6';
		else if (temp[i] == "0111")
			out_hex += '7';
		else if (temp[i] == "1000")
			out_hex += '8';
		else if (temp[i] == "1001")
			out_hex += '9';
		else if (temp[i] == "1010")
			out_hex += 'A';
		else if (temp[i] == "1011")
			out_hex += 'B';
		else if (temp[i] == "1100")
			out_hex += 'C';
		else if (temp[i] == "1101")
			out_hex += 'D';
		else if (temp[i] == "1110")
			out_hex += 'E';
		else //(temp[i] == "1111")
			out_hex += 'F';
	}
//	cout << out_binary << endl;
//	cout << out_hex << endl;;
	
	for (int i = 0, j = 0; i < s / 4; i++) {
		cout << out_hex[j++];
	}
	
	//system("Pause");
}
