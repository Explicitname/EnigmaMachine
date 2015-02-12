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

std::vector<int> reverseConstruct_shifts(const std::string &wiring, const std::string &alpha)//Please suggest improvements here. Not sure if correct.
{
	std::vector<int> reversePopulatedVector(26);
	for (int i = 0; i < 26; i++)
	{
		reversePopulatedVector[charToNum(wiring[i])] = (charToNum(alpha[i]) - charToNum(wiring[i]));
		//std::cout <<(charToNum(alpha[i]) - charToNum(wiring[i])) << std::endl;
	}

	return(reversePopulatedVector);
}


char shift_char(char c, int offset)//Encrypts the input char, A-Z, and returns the encrypted char, A-Z
{

	int EncryptedNum;
	char EncryptedChar;
	std::cout << "charToNum is: " << charToNum(c) << " offset is: " << offset << std::endl;
	EncryptedNum = charToNum(c) + offset;
	EncryptedChar = numToChar(EncryptedNum);
	return(EncryptedChar);
}

void test_suite()//Tests conditions.
{
	//try
	ASSERT_TRUE('B', shift_char('A', 1));
	ASSERT_TRUE('A', shift_char('B', -1));
	ASSERT_TRUE('Z', shift_char('A', -1));
	ASSERT_TRUE('A', shift_char('Z', 1));
	ASSERT_TRUE('B', shift_char('A', 27));
	ASSERT_TRUE('A', shift_char('A', 26));
	ASSERT_TRUE('A', shift_char('A', -26));

}

int getOffset(char f, char x)

{
	int offset = 0;
	std::string wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";
	std::vector<int> populatedVector;
	std::vector<int> reversePopulatedVector;

	if (f == 'F' || f == 'f')
	{
		populatedVector = construct_shifts(wiring, alpha);
		for (int i = 0; i < 26; i++)
		{
			if (x == alpha[i])
			{
				offset = populatedVector[i];
			}
		}
	}
	else
	{
		reversePopulatedVector = reverseConstruct_shifts(wiring, alpha);
		for (int j = 0; j < 26; j++)
		{
			if (x == alpha[j])
			{
				offset = reversePopulatedVector[j];
			}
		}
	}


	return(offset);
}

int main()
{
char x;
char direction;

int offset = 0;


//dump_vec(reversePopulatedVector);
std::cout << "Would you like to go forward or reverse? " << std::endl;
std::cin >> direction;




std::cout << shift_char(x, offset) ;

return(0);
}
