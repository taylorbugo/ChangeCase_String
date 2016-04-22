// ChangeCase_String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

string ChangeCase(string input)
{
	int vowels = 0;
	int index = 0;
	string output = input;

	//handles case conversion for standard cases, ignores the sometimes y rule
	//could simplify this function using using methods like isupper and islower
	while (output[index] != NULL)
	{
		if ((output[index] >= 'a') && (output[index] <= 'z'))
		{
			if ((output[index] != 'a') || (output[index] != 'e') || (output[index] != 'i') || (output[index] != 'o') || (output[index] != 'u'))
			{
				//32 ascii conversion value from lowercase to uppercase
				output[index] = output[index] - 32;
			}
		}
		if ((output[index] == 'A') || (output[index] == 'E') || (output[index] == 'I') || (output[index] == 'O') || (output[index] == 'U'))
		{
			//32 ascii conversion value from uppercase to lowercase
			output[index] = output[index] + 32;
			vowels++;
		}
		index++;
	}
	output[index] = NULL;

	//handles special case where no vowels present besides y
	if (vowels == 0)
	{
		index = 0;
		while (output[index] != NULL)
		{
			if (output[index] == 'Y')
			{
				output[index] = 'y';
			}
			index++;
		}
	}

	return output;
}


int main()
{
	//some sample test cases
	cout << ChangeCase("alphabet") << endl;
	cout << ChangeCase("yesterday") << endl;
	cout << ChangeCase("synth") << endl;
	cout << ChangeCase("WHY") << endl;
	cout << ChangeCase("CAndYLaNd") << endl;
	cout << ChangeCase("!@#!@#@!#") << endl;
	cout << ChangeCase("") << endl;
	cout << ChangeCase("67365534097") << endl;
	return 0;
}