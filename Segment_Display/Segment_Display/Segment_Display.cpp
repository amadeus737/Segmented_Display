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
	//     (f)
	// (g) is the diving center line
	
	switch (c)
	{
		case '0': case 'D': case 'O': return (A | B | C | D | E | F);
		case '1': return (D | E);
		case '2': case 'Z': case 'z': return (C | D | G | A | F);
		case '3': return (C | D | G | E | F);
		case '4': case 'Y': case 'y': return (B | G | D | E);
		case '5': case 'S': case 's': return (C | B | G | E | F);
		case '6': return (C | B | G | A | F | E);
		case '7': return (C | D | E);
		case '8': case 'B': return (A | B | C | D | E | F | G);
		case '9': case 'Q': case 'q': return (B | C | G | D | E| F);
		case 'A': case 'R': return (A | B | C | D | E | G);
		case 'a': return (A | C | D | E | F | G);
		case 'b': return (A | B | E | F | G);
		case 'C': return (A | B | C | F);
		case 'c': return (A | F | G);
		case 'd': return (A | F | G | E | D);
		case 'E': case 'e': return (C | B | A | F | G);
		case 'F': case 'f': return (C | B | A | G);
		case 'G': return (C | B | A | F | E);
		case 'g': return (C | B | G | D | E | F);
		case 'H': case 'K': case 'k': case 'M': case 'm': case 'W': case 'w': case 'X': case 'x': return (A | B | D | E | G);
		case 'h': return (A | B | G | E);
		case 'I': return (D | E);
		case 'i': return (E);
		case 'J': case 'j': return (D | E | F);
		case 'L': return (B | A | F);
		case 'l': return (B | A);
		case 'N': case 'n': return (A | G | E);
		case 'o': return (A | G | E | F);
		case 'P': case 'p': return (A | B | C | D | G);
		case 'r': return (A | G);
		case 'T': case 't': return (A | B | F | G);
		case 'U': case 'V': return (A | B | D | E | F);
		case 'u': case 'v': return (A | F | E);
		case '-': return (G);
		case '=': return (C | F);
		case '<': return (A | F | E | D);
		default: case ' ' : return NULL;
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

void PrintAllCharacters()
{
	PrintSegmentedCharacter(ConvertCharToSegDisplay('0'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('1'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('2'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('3'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('4'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('5'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('6'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('7'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('8'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('9'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('a'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('A'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('b'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('B'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('c'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('C'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('d'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('D'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('e'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('E'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('f'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('F'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('g'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('G'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('h'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('H'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('i'));	
	PrintSegmentedCharacter(ConvertCharToSegDisplay('I'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('j'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('J'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('k'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('K'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('l'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('L'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('m'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('M'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('n'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('N'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('o'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('O'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('p'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('P'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('q'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('Q'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('r'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('R'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('s'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('S'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('t'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('T'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('u'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('U'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('v'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('V'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('w'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('W'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('x'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('X'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('y'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('Y'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('z'));
	PrintSegmentedCharacter(ConvertCharToSegDisplay('Z'));
}


int main()
{
//    unsigned char zero = BuildCharacter(A | B | C | D | E | F);

//	std::cout << "Binary: 0b" << std::bitset<8>{zero};
//	std::cout << "\n";
//	std::cout << "Hex: 0x" << std::hex << (int)zero;
//	std::cout << "\n";
  
//	PrintAllCharacters();	

// Prepare ROM data
	unsigned char romData[32768];  // 32768 = 32 KBytes = 256 KBits
	memset(romData, 0x00, 32768);  // Set 32768 bytes to 0x00
	int index = 0;

	// Create the binary file
	FILE *file = fopen("..\\SegDisplayROM.bin", "wb");
		
	// Define data - 1024 frames worth
	unsigned char frame0000[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0001[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0002[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0003[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0004[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0005[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0006[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0007[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0008[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0009[] = { ' ', ' ', '0', '0', '0', '0', ' ', ' ' };
	unsigned char frame0010[] = { ' ', ' ', '0', '0', '0', '0', ' ', ' ' };
	unsigned char frame0011[] = { ' ', ' ', '0', '0', '0', '0', ' ', ' ' };
	unsigned char frame0012[] = { ' ', ' ', '0', '0', '0', '0', ' ', ' ' };
	unsigned char frame0013[] = { ' ', ' ', '0', '0', '0', '0', ' ', ' ' };
	unsigned char frame0014[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0015[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0016[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0017[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0018[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0019[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0020[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0021[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0022[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0023[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0024[] = { ' ', ' ', '0', '0', '0', '1', ' ', ' ' };
	unsigned char frame0025[] = { ' ', ' ', '0', '0', '0', '1', ' ', ' ' };
	unsigned char frame0026[] = { ' ', ' ', '0', '0', '0', '1', ' ', ' ' };
	unsigned char frame0027[] = { ' ', ' ', '0', '0', '0', '1', ' ', ' ' };
	unsigned char frame0028[] = { ' ', ' ', '0', '0', '0', '1', ' ', ' ' };
	unsigned char frame0029[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0030[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0031[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0032[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0033[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0034[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0035[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0036[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0037[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0038[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0039[] = { ' ', ' ', '0', '0', '1', '0', ' ', ' ' };
	unsigned char frame0040[] = { ' ', ' ', '0', '0', '1', '0', ' ', ' ' };
	unsigned char frame0041[] = { ' ', ' ', '0', '0', '1', '0', ' ', ' ' };
	unsigned char frame0042[] = { ' ', ' ', '0', '0', '1', '0', ' ', ' ' };
	unsigned char frame0043[] = { ' ', ' ', '0', '0', '1', '0', ' ', ' ' };
	unsigned char frame0044[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0045[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0046[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0047[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0048[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0049[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0050[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0051[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0052[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0053[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0054[] = { ' ', ' ', '0', '0', '1', '1', ' ', ' ' };
	unsigned char frame0055[] = { ' ', ' ', '0', '0', '1', '1', ' ', ' ' };
	unsigned char frame0056[] = { ' ', ' ', '0', '0', '1', '1', ' ', ' ' };
	unsigned char frame0057[] = { ' ', ' ', '0', '0', '1', '1', ' ', ' ' };
	unsigned char frame0058[] = { ' ', ' ', '0', '0', '1', '1', ' ', ' ' };
	unsigned char frame0059[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0060[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0061[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0062[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0063[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0064[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0065[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0066[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0067[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0068[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0069[] = { ' ', ' ', '0', '1', '0', '0', ' ', ' ' };
	unsigned char frame0070[] = { ' ', ' ', '0', '1', '0', '0', ' ', ' ' };
	unsigned char frame0071[] = { ' ', ' ', '0', '1', '0', '0', ' ', ' ' };
	unsigned char frame0072[] = { ' ', ' ', '0', '1', '0', '0', ' ', ' ' };
	unsigned char frame0073[] = { ' ', ' ', '0', '1', '0', '0', ' ', ' ' };
	unsigned char frame0074[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0075[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0076[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0077[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0078[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0079[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0080[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0081[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0082[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0083[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0084[] = { ' ', ' ', '0', '1', '0', '1', ' ', ' ' };
	unsigned char frame0085[] = { ' ', ' ', '0', '1', '0', '1', ' ', ' ' };
	unsigned char frame0086[] = { ' ', ' ', '0', '1', '0', '1', ' ', ' ' };
	unsigned char frame0087[] = { ' ', ' ', '0', '1', '0', '1', ' ', ' ' };
	unsigned char frame0088[] = { ' ', ' ', '0', '1', '0', '1', ' ', ' ' };
	unsigned char frame0089[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0090[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0091[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0092[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0093[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0094[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0095[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0096[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0097[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0098[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0099[] = { ' ', ' ', '0', '1', '1', '0', ' ', ' ' };
	unsigned char frame0100[] = { ' ', ' ', '0', '1', '1', '0', ' ', ' ' };
	unsigned char frame0101[] = { ' ', ' ', '0', '1', '1', '0', ' ', ' ' };
	unsigned char frame0102[] = { ' ', ' ', '0', '1', '1', '0', ' ', ' ' };
	unsigned char frame0103[] = { ' ', ' ', '0', '1', '1', '0', ' ', ' ' };
	unsigned char frame0104[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0105[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0106[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0107[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0108[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0109[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0110[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0111[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0112[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0113[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0114[] = { ' ', ' ', '0', '1', '1', '1', ' ', ' ' };
	unsigned char frame0115[] = { ' ', ' ', '0', '1', '1', '1', ' ', ' ' };
	unsigned char frame0116[] = { ' ', ' ', '0', '1', '1', '1', ' ', ' ' };
	unsigned char frame0117[] = { ' ', ' ', '0', '1', '1', '1', ' ', ' ' };
	unsigned char frame0118[] = { ' ', ' ', '0', '1', '1', '1', ' ', ' ' };
	unsigned char frame0119[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0120[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0121[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0122[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0123[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0124[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0125[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0126[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0127[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0128[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0129[] = { ' ', ' ', '1', '0', '0', '0', ' ', ' ' };
	unsigned char frame0130[] = { ' ', ' ', '1', '0', '0', '0', ' ', ' ' };
	unsigned char frame0131[] = { ' ', ' ', '1', '0', '0', '0', ' ', ' ' };
	unsigned char frame0132[] = { ' ', ' ', '1', '0', '0', '0', ' ', ' ' };
	unsigned char frame0133[] = { ' ', ' ', '1', '0', '0', '0', ' ', ' ' };
	unsigned char frame0134[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0135[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0136[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0137[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0138[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0139[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0140[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0141[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0142[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0143[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0144[] = { ' ', ' ', '1', '0', '0', '1', ' ', ' ' };
	unsigned char frame0145[] = { ' ', ' ', '1', '0', '0', '1', ' ', ' ' };
	unsigned char frame0146[] = { ' ', ' ', '1', '0', '0', '1', ' ', ' ' };
	unsigned char frame0147[] = { ' ', ' ', '1', '0', '0', '1', ' ', ' ' };
	unsigned char frame0148[] = { ' ', ' ', '1', '0', '0', '1', ' ', ' ' };
	unsigned char frame0149[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0150[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0151[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0152[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0153[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0154[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0155[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0156[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0157[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0158[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0159[] = { ' ', ' ', '1', '0', '1', '0', ' ', ' ' };
	unsigned char frame0160[] = { ' ', ' ', '1', '0', '1', '0', ' ', ' ' };
	unsigned char frame0161[] = { ' ', ' ', '1', '0', '1', '0', ' ', ' ' };
	unsigned char frame0162[] = { ' ', ' ', '1', '0', '1', '0', ' ', ' ' };
	unsigned char frame0163[] = { ' ', ' ', '1', '0', '1', '0', ' ', ' ' };
	unsigned char frame0164[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0165[] = { '-', ' ', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0166[] = { '-', '-', ' ', ' ', ' ', ' ', '-', '-' };
	unsigned char frame0167[] = { ' ', ' ', '-', '-', ' ', '-', '-', ' ' };
	unsigned char frame0168[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0169[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0170[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0171[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0172[] = { ' ', ' ', '=', '=', '=', '=', ' ', ' ' };
	unsigned char frame0173[] = { ' ', ' ', '-', '-', '-', '-', ' ', ' ' };
	unsigned char frame0174[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0175[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0176[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0177[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0178[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0179[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0180[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0181[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0182[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0183[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0184[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0185[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0186[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0187[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0188[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0189[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0190[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0191[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0192[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0193[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0194[] = { ' ', ' ', '1', '0', '1', '1', ' ', ' ' };
	unsigned char frame0195[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0196[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0197[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0198[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'H' };
	unsigned char frame0199[] = { ' ', ' ', ' ', ' ', ' ', ' ', 'H', 'A' };
	unsigned char frame0200[] = { ' ', ' ', ' ', ' ', ' ', 'H', 'A', 'P' };
	unsigned char frame0201[] = { ' ', ' ', ' ', ' ', 'H', 'A', 'P', 'P' };
	unsigned char frame0202[] = { ' ', ' ', ' ', 'H', 'A', 'P', 'P', 'Y' };
	unsigned char frame0203[] = { ' ', ' ', 'H', 'A', 'P', 'P', 'Y', ' ' };
	unsigned char frame0204[] = { ' ', 'H', 'A', 'P', 'P', 'Y', ' ', '1' };
	unsigned char frame0205[] = { 'H', 'A', 'P', 'P', 'Y', ' ', '1', '1' };
	unsigned char frame0206[] = { 'A', 'P', 'P', 'Y', ' ', '1', '1', 't' };
	unsigned char frame0207[] = { 'P', 'P', 'Y', ' ', '1', '1', 't', 'h' };
	unsigned char frame0208[] = { 'P', 'Y', ' ', '1', '1', 't', 'h', ' ' };
	unsigned char frame0209[] = { 'Y', ' ', '1', '1', 't', 'h', ' ', 'A' };
	unsigned char frame0210[] = { ' ', '1', '1', 't', 'h', ' ', 'A', 'n' };
	unsigned char frame0211[] = { '1', '1', 't', 'h', ' ', 'A', 'n', 'n' };
	unsigned char frame0212[] = { '1', 't', 'h', ' ', 'A', 'n', 'n', 'I' };
	unsigned char frame0213[] = { 't', 'h', ' ', 'A', 'n', 'n', 'I', 'V' };
	unsigned char frame0214[] = { 'h', ' ', 'A', 'n', 'n', 'I', 'V', 'E' };
	unsigned char frame0215[] = { ' ', 'A', 'n', 'n', 'I', 'V', 'E', 'r' };
	unsigned char frame0216[] = { 'A', 'n', 'n', 'I', 'V', 'E', 'r', 'S' };
	unsigned char frame0217[] = { 'n', 'n', 'I', 'V', 'E', 'r', 'S', 'A' };
	unsigned char frame0218[] = { 'n', 'I', 'V', 'E', 'r', 'S', 'A', 'r' };
	unsigned char frame0219[] = { 'I', 'V', 'E', 'r', 'S', 'A', 'r', 'Y' };
	unsigned char frame0220[] = { 'V', 'E', 'r', 'S', 'A', 'r', 'Y', ' ' };
	unsigned char frame0221[] = { 'E', 'r', 'S', 'A', 'r', 'Y', ' ', 'R' };
	unsigned char frame0222[] = { 'r', 'S', 'A', 'r', 'Y', ' ', 'R', 'E' };
	unsigned char frame0223[] = { 'S', 'A', 'r', 'Y', ' ', 'R', 'E', 'B' };
	unsigned char frame0224[] = { 'A', 'r', 'Y', ' ', 'R', 'E', 'B', 'E' };
	unsigned char frame0225[] = { 'r', 'Y', ' ', 'R', 'E', 'B', 'E', 'C' };
	unsigned char frame0226[] = { 'Y', ' ', 'R', 'E', 'B', 'E', 'C', 'C' };
	unsigned char frame0227[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0228[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0229[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0230[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0231[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0232[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0233[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0234[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0235[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0236[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0237[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0238[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0239[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0240[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0241[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0242[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0243[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0244[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0245[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0246[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0247[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0248[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0249[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0250[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0251[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0252[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0253[] = { ' ', 'R', 'E', 'B', 'E', 'C', 'C', 'A' };
	unsigned char frame0254[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0255[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0256[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0257[] = { ' ', ' ', ' ', 'L', 'U', ' ', ' ', ' ' };
	unsigned char frame0258[] = { ' ', ' ', 'L', 'O', 'O', 'U', ' ', ' ' };
	unsigned char frame0259[] = { ' ', 'L', 'O', 'V', 'Y', 'O', 'U', ' ' };
	unsigned char frame0260[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0261[] = { 'O', 'V', 'E', ' ', ' ', ' ', 'Y', 'O' };
	unsigned char frame0262[] = { 'V', 'E', ' ', ' ', ' ', ' ', ' ', 'Y' };
	unsigned char frame0263[] = { 'E', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0264[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0265[] = { 'E', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0266[] = { 'V', 'E', ' ', ' ', ' ', ' ', ' ', 'Y' };
	unsigned char frame0267[] = { 'O', 'V', 'E', ' ', ' ', ' ', 'Y', 'O' };
	unsigned char frame0268[] =	{ 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0269[] = { ' ', 'L', 'O', 'V', 'Y', 'O', 'U', ' ' };
	unsigned char frame0270[] = { ' ', ' ', 'L', 'O', 'O', 'U', ' ', ' ' };
	unsigned char frame0271[] = { ' ', ' ', ' ', 'L', 'U', ' ', ' ', ' ' };
	unsigned char frame0272[] = { ' ', ' ', 'L', 'O', 'O', 'U', ' ', ' ' };
	unsigned char frame0273[] = { ' ', 'L', 'O', 'V', 'Y', 'O', 'U', ' ' };
	unsigned char frame0274[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0275[] = { 'O', 'V', 'E', ' ', ' ', ' ', 'Y', 'O' };
	unsigned char frame0276[] = { 'V', 'E', ' ', ' ', ' ', ' ', ' ', 'Y' };
	unsigned char frame0277[] = { 'E', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0278[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0279[] = { 'E', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0280[] = { 'V', 'E', ' ', ' ', ' ', ' ', ' ', 'Y' };
	unsigned char frame0281[] = { 'O', 'V', 'E', ' ', ' ', ' ', 'Y', 'O' };
	unsigned char frame0282[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0283[] = { ' ', 'L', 'O', 'V', 'Y', 'O', 'U', ' ' };
	unsigned char frame0284[] = { ' ', ' ', 'L', 'O', 'O', 'U', ' ', ' ' }; 
	unsigned char frame0285[] = { ' ', 'L', 'O', 'V', 'Y', 'O', 'U', ' ' };
	unsigned char frame0286[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0287[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0288[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0289[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0290[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0291[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0292[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0293[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0294[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0295[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0296[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0297[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0298[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0299[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0300[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0301[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0302[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0303[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0304[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0305[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0306[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0307[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0308[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0309[] = { 'L', 'O', 'V', 'E', ' ', 'Y', 'O', 'U' };
	unsigned char frame0310[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0311[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0312[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0313[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0314[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0315[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0316[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0317[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0318[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0319[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0320[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0321[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0322[] = { '1', '1', ' ', 'Y', 'E', 'A', 'R', 'S' };
	unsigned char frame0323[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0324[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0325[] =	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0326[] = { ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ' };
	unsigned char frame0327[] = { ' ', ' ', ' ', 'G', 'L', 'A', ' ', ' ' };
	unsigned char frame0328[] = { ' ', ' ', 'G', 'L', 'A', 'D', ' ', ' ' };
	unsigned char frame0329[] = { ' ', ' ', 'G', 'L', 'A', 'D', ' ', ' ' };
	unsigned char frame0330[] = { ' ', ' ', 'G', 'L', 'A', 'D', ' ', ' ' };
	unsigned char frame0331[] = { ' ', ' ', 'G', 'L', 'A', 'D', ' ', ' ' };
	unsigned char frame0332[] = { ' ', ' ', 'G', 'L', 'A', 'D', ' ', ' ' };
	unsigned char frame0333[] = { ' ', ' ', 'G', 'L', 'A', 'D', ' ', ' ' };
	unsigned char frame0334[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0335[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0336[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0337[] = { ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ' };
	unsigned char frame0338[] = { ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ' };
	unsigned char frame0339[] = { ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ' };	
	unsigned char frame0340[] = { ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ' };
	unsigned char frame0341[] = { ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ' };
	unsigned char frame0342[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0343[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0344[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0345[] = { ' ', ' ', ' ', ' ', 'P', ' ', ' ', ' ' };
	unsigned char frame0346[] = { ' ', ' ', ' ', 'P', 'I', 'C', ' ', ' ' };
	unsigned char frame0347[] = { ' ', ' ', 'P', 'I', 'C', 'K', 'E', ' ' };
	unsigned char frame0348[] = { ' ', 'P', 'I', 'C', 'K', 'E', 'D', ' ' };
	unsigned char frame0349[] = { ' ', 'P', 'I', 'C', 'K', 'E', 'D', ' ' };
	unsigned char frame0350[] = { ' ', 'P', 'I', 'C', 'K', 'E', 'D', ' ' };
	unsigned char frame0351[] = { ' ', 'P', 'I', 'C', 'K', 'E', 'D', ' ' };
	unsigned char frame0352[] = { ' ', 'P', 'I', 'C', 'K', 'E', 'D', ' ' };
	unsigned char frame0353[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0354[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0355[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0356[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0357[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0358[] = { ' ', ' ', ' ', ' ', 'Y', ' ', ' ', ' ' };
	unsigned char frame0359[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0360[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0361[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0362[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0363[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0364[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0365[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0366[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0367[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0368[] = { ' ', ' ', ' ', 'Y', 'O', 'U', ' ', ' ' };
	unsigned char frame0369[] = { ' ', ' ', 'Y', ' ', 'O', ' ', 'U', ' ' };
	unsigned char frame0370[] = { ' ', 'Y', ' ', ' ', 'O', ' ', ' ', 'U' };
	unsigned char frame0371[] = { 'Y', ' ', ' ', ' ', 'O', ' ', ' ', ' ' };
	unsigned char frame0372[] = { ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ' };
	unsigned char frame0373[] = { ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ' };
	unsigned char frame0374[] = { ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ' };
	unsigned char frame0375[] = { ' ', ' ', ' ', ' ', 'U', ' ', ' ', ' ' };
	unsigned char frame0376[] = { ' ', ' ', ' ', ' ', '<', ' ', ' ', ' ' };
	unsigned char frame0377[] = { ' ', ' ', ' ', ' ', 'J', ' ', ' ', ' ' };
	unsigned char frame0378[] = { ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ' };
	unsigned char frame0379[] = { ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ' };
	unsigned char frame0380[] = { ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ' };
	unsigned char frame0381[] = { ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ' };
	unsigned char frame0382[] = { ' ', ' ', ' ', '-', ' ', '-', ' ', ' ' };
	unsigned char frame0383[] = { ' ', ' ', '-', ' ', ' ', ' ', '-', ' ' };
	unsigned char frame0384[] = { ' ', '-', ' ', ' ', ' ', ' ', ' ', '-' };
	unsigned char frame0385[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0386[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0387[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0388[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned char frame0389[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

	unsigned char* frames[] = { frame0000, frame0001, frame0002, frame0003, frame0004, frame0005, frame0006, frame0007, frame0008, frame0009, 
								frame0010, frame0011, frame0012, frame0013, frame0014, frame0015, frame0016, frame0017, frame0018, frame0019,
								frame0020, frame0021, frame0022, frame0023, frame0024, frame0025, frame0026, frame0027, frame0028, frame0029,
								frame0030, frame0031, frame0032, frame0033, frame0034, frame0035, frame0036, frame0037, frame0038, frame0039,
								frame0040, frame0041, frame0042, frame0043, frame0044, frame0045, frame0046, frame0047, frame0048, frame0049,
								frame0050, frame0051, frame0052, frame0053, frame0054, frame0055, frame0056, frame0057, frame0058, frame0059,
								frame0060, frame0061, frame0062, frame0063, frame0064, frame0065, frame0066, frame0067, frame0068, frame0069,
								frame0070, frame0071, frame0072, frame0073, frame0074, frame0075, frame0076, frame0077, frame0078, frame0079,
								frame0080, frame0081, frame0082, frame0083, frame0084, frame0085, frame0086, frame0087, frame0088, frame0089,
								frame0090, frame0091, frame0092, frame0093, frame0094, frame0095, frame0096, frame0097, frame0098, frame0099,
								frame0100, frame0101, frame0102, frame0103, frame0104, frame0105, frame0106, frame0107, frame0108, frame0109,
								frame0110, frame0111, frame0112, frame0113, frame0114, frame0115, frame0116, frame0117, frame0118, frame0119,
								frame0120, frame0121, frame0122, frame0123, frame0124, frame0125, frame0126, frame0127, frame0128, frame0129,
								frame0130, frame0131, frame0132, frame0133, frame0134, frame0135, frame0136, frame0137, frame0138, frame0139,
								frame0140, frame0141, frame0142, frame0143, frame0144, frame0145, frame0146, frame0147, frame0148, frame0149,
								frame0150, frame0151, frame0152, frame0153, frame0154, frame0155, frame0156, frame0157, frame0158, frame0159,
								frame0160, frame0161, frame0162, frame0163, frame0164, frame0165, frame0166, frame0167, frame0168, frame0169,
								frame0170, frame0171, frame0172, frame0173, frame0174, frame0175, frame0176, frame0177, frame0178, frame0179,
								frame0180, frame0181, frame0182, frame0183, frame0184, frame0185, frame0186, frame0187, frame0188, frame0189,
								frame0190, frame0191, frame0192, frame0193, frame0194, frame0195, frame0196, frame0197, frame0198, frame0199,
								frame0200, frame0201, frame0202, frame0203, frame0204, frame0205, frame0206, frame0207, frame0208, frame0209,
								frame0210, frame0211, frame0212, frame0213, frame0214, frame0215, frame0216, frame0217, frame0218, frame0219,
								frame0220, frame0221, frame0222, frame0223, frame0224, frame0225, frame0226, frame0227, frame0228, frame0229,
								frame0230, frame0231, frame0232, frame0233, frame0234, frame0235, frame0236, frame0237, frame0238, frame0239,
								frame0240, frame0241, frame0242, frame0243, frame0244, frame0245, frame0246, frame0247, frame0248, frame0249,
								frame0250, frame0251, frame0252, frame0253, frame0254, frame0255, frame0256, frame0257, frame0258, frame0259,
								frame0260, frame0261, frame0262, frame0263, frame0264, frame0265, frame0266, frame0267, frame0268, frame0269,
								frame0270, frame0271, frame0272, frame0273, frame0274, frame0275, frame0276, frame0277, frame0278, frame0279,
								frame0280, frame0281, frame0282, frame0283, frame0284, frame0285, frame0286, frame0287, frame0288, frame0289,
								frame0290, frame0291, frame0292, frame0293, frame0294, frame0295, frame0296, frame0297, frame0298, frame0299,
								frame0300, frame0301, frame0302, frame0303, frame0304, frame0305, frame0306, frame0307, frame0308, frame0309,
								frame0310, frame0311, frame0312, frame0313, frame0314, frame0315, frame0316, frame0317, frame0318, frame0319,
								frame0320, frame0321, frame0322, frame0323, frame0324, frame0325, frame0326, frame0327, frame0328, frame0329,
								frame0330, frame0331, frame0332, frame0333, frame0334, frame0335, frame0336, frame0337, frame0338, frame0339,
								frame0340, frame0341, frame0342, frame0343, frame0344, frame0345, frame0346, frame0347, frame0348, frame0349,
								frame0350, frame0351, frame0352, frame0353, frame0354, frame0355, frame0356, frame0357, frame0358, frame0359,
								frame0360, frame0361, frame0362, frame0363, frame0364, frame0365, frame0366, frame0367, frame0368, frame0369,
								frame0370, frame0371, frame0372, frame0373, frame0374, frame0375, frame0376, frame0377, frame0378, frame0379,
								frame0380, frame0381, frame0382, frame0383, frame0384, frame0385, frame0386, frame0387, frame0388, frame0389,
							  };

	// Now actually add the frames to the ROM data array	
	int numFrames = 390;
	int numElemsInFrame = 7;
	for (int f = 0; f < numFrames; f++)
	{
		for (int i = numElemsInFrame; i >= 0; i--)
		{
			unsigned char* currFrame = frames[f];
			unsigned char  currElement = ConvertCharToSegDisplay(currFrame[i]);
			
			romData[index] = currElement;

			//std::cout << std::hex << (int)currElement;
			//std::cout << "\n";
			//PrintSegmentedCharacter(currElement);
			
			index++;
		}
	}
	
	// Write data to binary file (will be written to ROM via TL86II Plus Programmer)
	fwrite(romData, 1, 32768, file);
	fclose(file);

	return 0;
}
