#include <iostream>
#include <cstring>

using namespace std;

bool isReverseDNAPalindrome(char dna[1000])
{
	int dnaLength = strlen(dna);
	for (int i = 0; i < dnaLength / 2; i++)
	{
		switch (dna[i])
		{
		case 'A':
			if (dna[dnaLength - 1 - i] != 'T')
			{
				return false;
			}
			break;
		case 'T':
			if (dna[dnaLength - 1 - i] != 'A')
			{
				return false;
			}
			break;
		case 'G':
			if (dna[dnaLength - 1 - i] != 'C')
			{
				return false;
			}
			break;
		case 'C':
			if (dna[dnaLength - 1 - i] != 'G')
			{
				return false;
			}
			break;
		}
	}
	return true;
}

int main()
{
	char dna1[1000] = "GCATGC";
	char dna2[1000] = "GATCGAATGACATGCATGTCATTCGATC";
	char dna3[1000] = "GATCGAATGACATGATGTCATTCGAAC";
	char dna4[1000] = "AT";
	char dna5[1000] = "AA";
	char dna6[1000] = "ATCCATGCGCATGGAT";
	char dna7[1000] = "ACGTACGTACGTACGT";


	std::cout << isReverseDNAPalindrome(dna1);
	std::cout << isReverseDNAPalindrome(dna2);
	std::cout << isReverseDNAPalindrome(dna3);
	std::cout << '\n';

	std::cout << isReverseDNAPalindrome(dna4);
	std::cout << '\n';

	std::cout << isReverseDNAPalindrome(dna5);
	std::cout << '\n';

	std::cout << isReverseDNAPalindrome(dna6);
	std::cout << '\n';

	std::cout << isReverseDNAPalindrome(dna7);
	std::cout << '\n';

	return 0;
}