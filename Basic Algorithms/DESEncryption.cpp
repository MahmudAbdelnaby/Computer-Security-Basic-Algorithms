#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

string hex2bin(string input_hex) {
	string input_binary = "";

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
	return input_binary;
}

string hex2binPermutation(string input_hex) {
	string input_binary = "0";

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
	return input_binary;
}

string bin2hex(string input_binary) {
	vector<string> temp;
	string out_hex = "";
	for (int i = 0; i < input_binary.size(); i += 4) {
		temp.push_back(input_binary.substr(i, 4));
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
	return out_hex;
}

string expansionPermutation(int table[], string input_hex) {
	string input_binary = hex2binPermutation(input_hex);
	string out_binary = "";
	for (int i = 1; i <= 48; i++) {
		out_binary += input_binary[table[i]];
	}
	return out_binary;
}

string straightPermutation(int table[], string input_hex) {
	string input_binary = hex2binPermutation(input_hex);
	string out_binary = "";
	for (int i = 1; i <= 32; i++) {
		out_binary += input_binary[table[i]];
	}
	return out_binary;
}

string dec2bin(int n) {
	string out = "";
	int binaryNum[32];

	int i = 0;
	if (n == 0) {
		out += '0';
		return out;
	}
	while (n > 0) {

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	for (int j = i - 1; j >= 0; j--) {
		if (binaryNum[j] == 0)
			out += '0';
		else
			out += '1';
	}
	return out;
}

string _4digit(string s) {
	int x = stoi(s);
	ostringstream out;
	out << std::internal << std::setfill('0') << std::setw(4) << x;
	return out.str();
}

string sBox(string inputHex) {

	string inputBin, output = "", temp;
	vector<string> inputSubstrings; //input to the s-boxes (each one is 6 bits)

	int box1[4][16] = { {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
						{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
						{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
						{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13} };

	int box2[4][16] = { {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
						{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
						{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
						{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9} };

	int box3[4][16] = { {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
						{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
						{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
						{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12} };

	int box4[4][16] = { {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
						{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
						{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
						{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14} };

	int box5[4][16] = { {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
						{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
						{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
						{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3} };

	int box6[4][16] = { {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
						{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
						{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
						{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13} };

	int box7[4][16] = { {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
						{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
						{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
						{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12} };

	int box8[4][16] = { {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
						{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
						{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
						{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11} };

	inputBin = hex2bin(inputHex); //devide it to 8 groups of 6 bits

	for (int i = 0; i < 48; i += 6) {
		temp = inputBin.substr(i, 6);
		inputSubstrings.push_back(temp);
	}

	int row[8], col[8]; //row and column for each box
	for (int i = 0; i < 8; i++) {
		temp = inputSubstrings[i];
		//row calculation
		char t0 = temp[0];
		char t5 = temp[5];
		//column calculation
		char t1 = temp[1];
		char t2 = temp[2];
		char t3 = temp[3];
		char t4 = temp[4];
		row[i] = atoi(&t0) * 2 + atoi(&t5);
		col[i] = atoi(&t1) * 8 + atoi(&t2) * 4 + atoi(&t3) * 2 + atoi(&t4);
	}

	int decimal[8];
	decimal[0] = box1[row[0]][col[0]];
	decimal[1] = box2[row[1]][col[1]];
	decimal[2] = box3[row[2]][col[2]];
	decimal[3] = box4[row[3]][col[3]];
	decimal[4] = box5[row[4]][col[4]];
	decimal[5] = box6[row[5]][col[5]];
	decimal[6] = box7[row[6]][col[6]];
	decimal[7] = box8[row[7]][col[7]];
	//get the correspoding binary from the obained decimals
	string semiOutput = "";
	for (int i = 0; i < 8; i++) {
		string t = "";
		t = dec2bin(decimal[i]);
		semiOutput += (_4digit(t));
	}
	output = bin2hex(semiOutput);
	return output;
}

string DESFunction(string _32bitBlockHex, string keyHex) {
	int expansionTable[] = { 0,32,1,2,3,4,5,
							4,5,6,7,8,9,
							8,9,10,11,12,13,
							12,13,14,15,16,17,
							16,17,18,19,20,21,
							20,21,22,23,24,25,
							24,25,26,27,28,29,
							28,29,30,31,32,1 };

	int straightTable[] = { 0,16,7,20,21,29,12,28,17,
						1,15,23,26,5,18,31,10,
						2,8,24,14,32,27,3,9,
						19,13,30,6,22,11,4,25 };

	string  _32bitBlockBin, keyBin, _48xored;
	string outFromExpansionPermutation;

	keyBin = hex2bin(keyHex);

	outFromExpansionPermutation = expansionPermutation(expansionTable, _32bitBlockHex);

	string inputSBoxBin = "";
	for (int i = 0; i < 48; i++) {
		inputSBoxBin += ((outFromExpansionPermutation[i] - '0') ^ (keyBin[i] - '0')) + '0';
	}

	string inputSBoxHex = bin2hex(inputSBoxBin);
	string outputSBoxHex = sBox(inputSBoxHex);
	//string outputSBoxBin = hex2bin(outputSBoxHex);

	string outputStriaghtPermutation = straightPermutation(straightTable, outputSBoxHex);

	string finalOutput = bin2hex(outputStriaghtPermutation);

	return finalOutput;
}

string _56straightPermutation(int table[], string input_hex) {
	string input_binary = hex2binPermutation(input_hex);
	string out_binary = "";
	for (int i = 1; i <= 56; i++) {
		out_binary += input_binary[table[i]];
	}
	return out_binary;
}

string initialPermutation(int table[], string input_hex) {
	string input_binary = hex2binPermutation(input_hex);
	string out_binary = "";
	for (int i = 1; i <= 64; i++) {
		out_binary += input_binary[table[i]];
	}
	return out_binary;
}

string _48straightPermutation(int table[], string input_hex) {
	string input_binary = hex2binPermutation(input_hex);
	string out_binary = "";
	for (int i = 1; i <= 48; i++) {
		out_binary += input_binary[table[i]];
	}
	return out_binary;
}

string leftShiftCircular(string in, int shifts) {
	string out = in.substr(shifts, in.size() - shifts);
	for (int i = 0; i < shifts; i++) {
		out += in[i];
	}
	return out;
}

void keyGeneration(string keyHex, vector<string> &output) {
	int PC1[] = { 0, 57, 49, 41, 33, 25, 17, 9, 1,
				58, 50, 42, 34, 26, 18, 10, 2,
				59, 51, 43, 35, 27, 19, 11, 3,
				60, 52, 44, 36, 63, 55, 47, 39,
				31, 23, 15, 7, 62, 54, 46, 38,
				30, 22, 14, 6, 61, 53, 45, 37,
				29, 21, 13, 5, 28, 20, 12, 4 };

	int PC2[] = { 0, 14, 17, 11, 24, 1, 5, 3, 28,
				  15, 6, 21, 10, 23, 19, 12, 4,
				  26, 8, 16, 7, 27, 20, 13, 2,
				  41, 52, 31, 37, 47, 55, 30, 40,
				  51, 45, 33, 48, 44, 49, 39, 56,
				  34, 53, 46, 42, 50, 36, 29, 32 };

	int shifts[] = { 1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28 };

	string keyBin = hex2bin(keyHex);
	string _56key = _56straightPermutation(PC1, keyHex);
	string leftKey, rightKey;
	leftKey = _56key.substr(0, _56key.size() / 2);
	rightKey = _56key.substr(_56key.size() / 2, _56key.size() / 2);

	for (int i = 0; i < 16; i++) {
		string temp1, temp2, temp3, temp4, temp5, temp6;
		temp1 = leftShiftCircular(leftKey, shifts[i]);
		temp2 = leftShiftCircular(rightKey, shifts[i]);
		temp3 = temp1 + temp2;
		temp4 = bin2hex(temp3);
		temp5 = _48straightPermutation(PC2, temp4);
		temp6 = bin2hex(temp5);
		output.push_back(temp6);
	}
	return;
}




int main() {

	int IPTable[] = { 0,58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17,9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7 };

	int inverseIPTable[] = { 0,40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33,1,41,9,49,17,57,25};

	string originalKey, plainText;
	string ciphertext;
	vector<string> generatedKeys;
	string ciphers[20];
	int n;
	cin >> originalKey >> plainText >> n;

	keyGeneration(originalKey, generatedKeys);

	for (int i = 0; i < n; i++) {
		string permutationPlainText = initialPermutation(IPTable, plainText);
		string temp ="";

		string plaintextLeft = permutationPlainText.substr(0, permutationPlainText.size() / 2);
		string plaintextRight = permutationPlainText.substr(permutationPlainText.size() / 2, permutationPlainText.size() / 2);

		string outDESFunction = DESFunction(plaintextRight, generatedKeys[0]);
		string outDESFunctionBin = hex2bin(outDESFunction);

		for (int k = 0; k < 32; k++) { 
			temp += ((outDESFunctionBin[k] - '0') ^ (plaintextLeft[k] - '0')) + '0';
		}
		ciphers[0] = plaintextRight + temp;
		for (int j = 1; j < 16; j++) {
			string previousLeft, previousRight, currentLeft, currentRight = "";
			previousLeft = ciphers[j - 1].substr(0, ciphers[j - 1].size() / 2);
			previousRight = ciphers[j - 1].substr(ciphers[j - 1].size() / 2, ciphers[j - 1].size() / 2);
			currentLeft = previousRight;
			string inXor = DESFunction(previousRight, generatedKeys[j]);
			string inXorBin = hex2bin(inXor);
			
			for (int k = 0; k < 32; k++) {
				currentRight += ((inXorBin[k] - '0') ^ (previousLeft[k] - '0')) + '0';
			}
			ciphers[j] = currentLeft + currentRight;
		}
		
		string lastLeft, lastRight, lastHex;
		lastLeft = ciphers[15].substr(ciphers[15].size() / 2, ciphers[15].size() / 2);
		lastRight = ciphers[15].substr(0, ciphers[15].size() / 2);
		string d = lastLeft + lastRight;
		lastHex = bin2hex(d);
		string binCipher = initialPermutation(inverseIPTable, lastHex);
		ciphertext = bin2hex(binCipher);
		plainText = ciphertext; //in case of more than one encryption
	}

	cout << ciphertext << endl;
		
	system("Pause");
}