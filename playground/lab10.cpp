#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

int hemmingDistance(char firstString[MAX], char secondString[MAX], int n)
{
	int distance = 0;
	for (int i = 0; firstString[i] != '\0'; i++)
	{
		distance += firstString[i] != secondString[i];
	}
	return distance;
}

void encodeCaesar(char plainText[MAX], int shift, char cipherText[MAX])
{
	int len = strlen(plainText);

	for (int i = 0; i < len; i++)
	{
		if (plainText[i] >= 'a' && plainText[i] <= 'z')
		{
			cipherText[i] = ((plainText[i] + shift) % 'a') % ('z' - 'a') + 'a';
		}
		else
		{
			cipherText[i] = plainText[i];
		}
	}

	cipherText[len] = '\0';
}

void decodeCaesar(char cipherText[MAX], int shift, char plainText[MAX])
{
	int len = strlen(cipherText);

	for (int i = 0; i < len; i++)
	{
		if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
		{
			plainText[i] = ((cipherText[i] - shift) % 'a') % ('z' - 'a' - 1) + 'a';
		}
		else
		{
			plainText[i] = cipherText[i];
		}
	}

	plainText[len] = '\0';
}

bool isValidSentence(char plainText[MAX], char knownWords[MAX * 10][10], int knownWordsLength)
{
	for (int i = 0; i < knownWordsLength; i++)
	{
		if (strstr(plainText, knownWords[i]) == 0)
		{
			return false;
		}
	}
	return true;
}

int crackCaesarCipher(char ciphertext[MAX], char knownWords[MAX * 10][10], int knownWordsLength)
{
	for (int i = 1; i <= 26; i++)
	{
		char plainText[MAX] = "";
		decodeCaesar(ciphertext, i, plainText);
		if (isValidSentence(plainText, knownWords, knownWordsLength))
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	char firstString[MAX] = "pesho e gei";
	char secondString[MAX] = "pesco e gai";

	cout << "Distance: " << hemmingDistance(firstString, secondString, 3) << '\n';

	char cipherPesho[MAX] = "";
	int shift = 1;
	encodeCaesar(firstString, shift, cipherPesho);
	cout << cipherPesho << '\n';
	char decodedPesho[MAX] = "";
	decodeCaesar(cipherPesho, shift, decodedPesho);
	cout << decodedPesho << '\n';

	char gosho[MAX] = "this is gosho";
	char encodedGosho[MAX] = "";

	for (int i = 1; i < 26; i++)
	{
		encodeCaesar(gosho, i, encodedGosho);
		cout << encodedGosho << '\n';
		char plainText[MAX] = "";
		decodeCaesar(encodedGosho, i, plainText);
		cout << plainText << '\n';
		char knownWords[MAX * 10][10] = {"gosho"};
		int usedK = crackCaesarCipher(encodedGosho, knownWords, 1);

		cout << "Guessed K: " << usedK << " Real K: " << i << endl;
	}

	return 0;
}