#include <iostream>
#include <string>
#include <vector>

std::vector construct_shifts(const std::string &wiring)
{
	//Write this function
	#error Unimplemented
}

char shift_char(char c, int offset)
{
	//Write this function
	#error Unimplemented

}

int charToNum(char x)

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
	std::cout << y << std::endl;
	return(y);
}

char numToChar(int n)

{
	n = (int)'A' + n;
	std::cout << n << std::endl;
	char c = (char) n;
	return(c);

}

/*int offset1(std::string alpha)
{
	for (int i = 0; i < 26; i++)
	{
		int x = charToNum(rotor1[i]) - charToNum(alpha[i]);
		std::cout << array1[i] << std::endl;
	}

	return(x);
}*/


int main()
{
char x;
//int n;
std::string rotor1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";
int array1[25];
int off = 0;
int encrypted = 0;

//This needs to be a function
for (int i = 0; i < 26; i++)
{
	array1[i] = charToNum(rotor1[i]) - charToNum(alpha[i]);
	//std::cout << array1[i] << std::endl;
}

std::cout << "Enter a letter to Encrypt: " << std::endl;
std::cin >> x;

for (int j = 0; j < 26; j++)
{
	if (x == alpha[j])
	{
		off = array1[j];
		std::cout << off << std::endl;
	}
}

encrypted = charToNum(x) + off;
std::cout << encrypted << std::endl;

std::cout << numToChar(encrypted);







/*std::cout << "Enter a letter to convert to a number: ";
std::cin >> x;
charToNum(x);
std::cout << (int)x << std::endl;

std::cout << "Enter a Num to convert to a char: ";
std::cin >> n;
numToChar(n);
std::cout << (char)n << std::endl;*/













	return(0);
}



