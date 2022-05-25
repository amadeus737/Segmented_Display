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
	// Seven segment display
	//     (c)
	//      __
	// (b) |__| (d)
	// (a) |__| (e)  .(h)
	//      (f)
	// (g) is the diving center line
	
	unsigned char newChar = 0;

	switch (c)
	{
		case '0' || 'D' || 'O': return (newChar | (A | B | C | D | E | F));
		case '1': return (newChar | (D | E));
		case '2' || 'Z' || 'z': return (newChar | (C | D | G | A | F));
		case '3': return (newChar | (C | D | G | E | F));
		case '4' || 'Y' || 'y': return (newChar | (B | G | D | E));
		case '5' || 'S' || 's': return (newChar | (C | B | G | E | F));
		case '6': return (newChar | (C | B | G | A | F | E));
		case '7': return (newChar | (C | D | E));
		case '8' || 'B': return (newChar | (A | B | C | D | E | F | G));
		case '9' || 'Q' || 'q': return (newChar | (B | C | G | D | E| F));
		case 'A' || 'R': return (newChar | (A | B | C | D | E | G));
		case 'a': return (newChar | (A | C | D | E | F | G));
		case 'b': return (newChar | (A | B | E | F | G));
		case 'C': return (newChar | (A | B | C | F));
		case 'c': return (newChar | (A | F | G));
		case 'd': return (newChar | (A | F | G | E | D));
		case 'E' || 'e': return (newChar | (C | B | A | F | G));
		case 'F' || 'f': return (newChar | (C | B | A | G));
		case 'G': return (newChar | (C | B | A | F | E));
		case 'g': return (newChar | (C | B | G | D | E | F));
		case 'H' || 'K' || 'k' || 'M' || 'm' || 'W' || 'w' || 'X' || 'x': return (newChar | (A | B | D | E | G));
		case 'h': return (newChar | (A | B | G | E));
		case 'I': return (newChar | (D | E));
		case 'i': return (newChar | (E));
		case 'J' || 'j': return (newChar | (D | E | F));
		case 'L': return (newChar | (B | A | F));
		case 'l': return (newChar | (B | A));
		case 'N' || 'n': return (newChar (A | G | E));
		case 'o': return (newChar (A | G | E | F));
		case 'P' || 'p': return (newChar(A | B | C | D | G));
		case 'r': return (newChar | (A | G));
		case 'T' || 't': return (newChar | (A | B | F | G));
		case 'U' || 'V': return (newChar | (A | B | D | E | F));
		case 'u' || 'v': return (newChar | (A | F | E));
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
	PrintSegmentedCharacter(ConvertCharToSegDisplay('4'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('5'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('6'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('7'));
	
	return 0;
}
