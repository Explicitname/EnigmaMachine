#include <iostream>
#include <string>
#include <vector>

std::vector construct_shifts(const std::string &wiring)//Unsure of what to put here.
{
	//Write this function
	#error Unimplemented
}



int charToNum(char x)//Converts a capital A-Z into a number from 0-25 and implements wrap around

{
	int y = (int) x;
	y = y - (int)'A';
	if (y > 25)
		{
			y = y - 25;
		}
	else if ( y < 0)
		{
			y = y + 25;
		}
	//std::cout << y << std::endl;
	return(y);
}

char numToChar(int n)//Converts a number, from 0-25, to a capital letter A-Z

{
	n = (int)'A' + n;
	//std::cout << n << std::endl;
	char c = (char) n;
	return(c);

}

int populateArray(std::string rotor1, std::string alpha, int populatedArray[25])//Populates the array with offset values, based on rotator 1
{
	//This needs to be a function
	for (int i = 0; i < 26; i++)
	{
		populatedArray[i] = charToNum(rotor1[i]) - charToNum(alpha[i]);
		//std::cout << populatedArray[i] << std::endl;
	}

	return(populatedArray[25]);
}

char shift_char(char c, int offset)//Encrypts the input char, A-Z, and returns the encrypted char, A-Z
{
	int EncryptedNum;
	char EncryptedChar;
	EncryptedNum = charToNum(c) + offset;
	EncryptedChar = numToChar(EncryptedNum);
	return(EncryptedChar);
}


int main()
{
char x;
std::string rotor1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";
int populatedArray[25];
int offset = 0;


populatedArray[25] = populateArray(rotor1, alpha, populatedArray);//Seems like this should go somewhere else

std::cout << "Enter a letter to Encrypt: " << std::endl;
std::cin >> x;


for (int j = 0; j < 26; j++)
{
	if (x == alpha[j])
	{
		offset = populatedArray[j];
	}
}
std::cout << shift_char(x, offset);
return(0);
}
