#include <iostream>
#include <string>
#include <vector>

#define ASSERT_TRUE(EXPECTED, ACTUAL) \
std::cout << "Asserting that " << #EXPECTED << " is " << #ACTUAL <<": "; \
if (EXPECTED == ACTUAL) \
{\
	std::cout << "SUCCESS!\n"; \
} \
else \
{ \
	std::cout << "FAIL\n"; \
}


int charToNum(char x)//Converts a capital A-Z into a number from 0-25 and implements wrap around

{
	int y = (int) x;
	y = y - (int)'A';
	if (y > 25)
		{
			y = y - 26;
		}
	else if ( y < 0)
		{
			y = y + 26;
		}
	//std::cout << y << std::endl;
	return(y);
}

char numToChar(int n)//Converts a number, from 0-25, to a capital letter A-Z

{
	if (n > 25)
		{
			n = n - 26;
		}
	else if ( n < 0)
		{
			n = n + 26;
		}
	n = (int)'A' + n;
	//std::cout << n << std::endl;
	char c = (char) n;
	return(c);

}

/*int populateArray(std::string rotor1, std::string alpha, int populatedArray[25])
	//This needs to be a function
	for (int i = 0; i < 26; i++)
	{
		populatedArray[i] = charToNum(rotor1[i]) - charToNum(alpha[i]);
	}

	return(populatedArray[25]);
}*/
std::vector<int> construct_shifts(const std::string &wiring, const std::string &alpha)//Please suggest improvements here. Not sure if correct.
{
	std::vector<int> populatedVector;
	for (int i = 0; i < 26; i++)
	{

		populatedVector.push_back(charToNum(wiring[i]) - charToNum(alpha[i]));
	}

	return(populatedVector);
}

char shift_char(char c, int offset)//Encrypts the input char, A-Z, and returns the encrypted char, A-Z
{
	int EncryptedNum;
	char EncryptedChar;
	EncryptedNum = charToNum(c) + offset;
	EncryptedChar = numToChar(EncryptedNum);
	return(EncryptedChar);
}

void test_suite()//Tests conditions.
{
	//try
	ASSERT_TRUE('B', shift_char('A', 1))
	if (shift_char('A', 1) == 'B')
	{
		std::cout << "Success!" << std::endl;
	}
	else
	{
		std::cout << "Failure!" << std::endl;
	}
	if (shift_char('B', -1) == 'A')
	{
		std::cout << "Success!" << std::endl;
	}
	else
	{
		std::cout << "Failure!" << std::endl;
	}
	if (shift_char('A', -1) == 'Z')
	{
		std::cout << "Success!" << std::endl;
	}
	else
	{
		std::cout << "Failure!" << std::endl;
	}
	if (shift_char('Z', 1) == 'A')
	{
		std::cout << "Success!" << std::endl;
	}
	else
	{
		std::cout << "Failure!" << std::endl;
	}
	if (shift_char('A', 27) == 'B')
	{
		std::cout << "Success!" << std::endl;
	}
	else
	{
		std::cout << "Failure!" << std::endl;
	}
	if (shift_char('A', 26) == 'A')
	{
		std::cout << "Success!" << std::endl;
	}
	else
	{
		std::cout << "Failure!" << std::endl;
	}
	if (shift_char('A', -26) == 'A')
	{
		std::cout << "Success!" << std::endl;
	}
	else
	{
		std::cout << "Failure!" << std::endl;
	}

}


int main()
{
//char x;
std::string wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";
std::vector<int> populatedVector;
//int offset = 0;


populatedVector = construct_shifts(wiring, alpha);//Seems like this should go somewhere else

/*std::cout << "Enter a letter to Encrypt: " << std::endl;
std::cin >> x;


for (int j = 0; j < 26; j++)
{
	if (x == alpha[j])
	{
		offset = populatedVector[j];
	}
}
std::cout << shift_char(x, offset);*/
/*ASSERT_TRUE("A + 1", 'B')
ASSERT_TRUE("B - 1", 'A')
ASSERT_TRUE("A - 1", 'Z')
ASSERT_TRUE("Z + 1", 'A')
ASSERT_TRUE("A + 27", 'B')
ASSERT_TRUE("A + 26", 'A')
ASSERT_TRUE("A - 26", 'A')*/
test_suite();
return(0);
}
