#include "pch.h"
#include <iostream>
#include <bitset>

enum Segments
{
	A = 1 << 7,  // Binary: 10000000
	B = 1 << 6,  // Binary: 01000000
	C = 1 << 5,  // Binary: 00100000
	D = 1 << 4,  // Binary: 00010000
	E = 1 << 3,  // Binary: 00001000
	F = 1 << 2,  // Binary: 00000100
	G = 1 << 1,  // Binary: 00000010
	H = 1 << 0   // Binary: 00000001
};

unsigned char BuildCharacter(unsigned char c)
{
	unsigned char newChar = 0;

	newChar |= c & A;
	newChar |= c & B;
	newChar |= c & C;
	newChar |= c & D;
	newChar |= c & E;
	newChar |= c & F;
	newChar |= c & G;
	newChar |= c & H;

	return newChar;
}

unsigned char ConvertCharToSegDisplay(unsigned char c)
{
	unsigned char newChar = 0;

	switch (c)
	{
		case '0': return (newChar | (A | B | C | D | E | F));
		case '1': return (newChar | (D | E));
		case '2': return (newChar | (C | D | G | A | F));
		case '3': return (newChar | (C | D | G | E | F));
	}
}

void PrintSegmentedCharacter(unsigned char c)
{
	bool segA = c & A;
	bool segB = c & B;
	bool segC = c & C;
	bool segD = c & D;
	bool segE = c & E;
	bool segF = c & F;
	bool segG = c & G;
	bool segH = c & H;
	
	segC ? std::cout << " _" : std::cout << " ";
	std::cout << "\n";
	segB ? std::cout << "|" : std::cout << " ";
	segG ? std::cout << "_" : std::cout << " ";
	segD ? std::cout << "|" : std::cout << " ";
	std::cout << "\n";
	segA ? std::cout << "|" : std::cout << " ";	
	segF ? std::cout << "_" : std::cout << " ";
	segE ? std::cout << "|" : std::cout << " ";	
	segH ? std::cout << "." : std::cout << " ";
	std::cout << "\n";
}

int main()
{
    unsigned char zero = BuildCharacter(A | B | C | D | E | F);

	std::cout << "Binary: 0b" << std::bitset<8>{zero};
	std::cout << "\n";
	std::cout << "Hex: 0x" << std::hex << (int)zero;
	std::cout << "\n";

	PrintSegmentedCharacter(ConvertCharToSegDisplay('0'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('1'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('2'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('3'));

	return 0;
}