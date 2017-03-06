#include "stdafx.h"
#include <string>
#include <bitset>
#include <iostream>
using namespace std;
string b64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string prepareString(string str)
{
	//  Convert to binary
	string outstr;
	for (size_t i = 0; i < str.size(); ++i)
	{
		outstr += bitset<8>(str[i]).to_string();
	}
	//  Split to 6-bit and convert to decimal - then b64
	string decstr, b64string;
	for (unsigned i = 0; i < outstr.length(); i += 6)
	{
		string decstr = outstr.substr(i, 6);
		while (decstr.length() % 6 != 0)
			decstr += "0";
		int decnum = stoi(decstr, nullptr, 2);
		b64string += b64chars[decnum];
	}
	while (b64string.length() % 4 != 0)
		b64string += "=";
	return b64string;
}

int main()
{
	string instr;
	while (true)
	{
		cout << "Enter text: ";
		cin >> instr;
		cout << prepareString(instr) << endl;
	}
    return 0;
}
