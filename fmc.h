#ifndef FMC_H
#define FMC_H

#include <string>
#include <vector>
#include <bit>
#include <unordered_map>

#include "key.h"

class fmc{
public:

// returns amount of bits needed to represent number in base 2 (needed for power modulo calculation)
static int bit_width(int n);

// returns mod of b power n mod m
static int pow_mod(int b, int n, int m);

// main encryption function that turns string into RSA encrypted vector
static void turn_into_numerals(std::string raw, std::vector<int>& blocks, int key_size);

// OBSOLETE!! update to professor's own alphabet and use int!!
// helper function to turn our base 26 digits into RSA encrypted blocks
static void encrypt_block(Key key, std::string& block);

// helper functions to exchange values from our own alphabet lookup tables
static int get_equivalent_from_map(char c);
static char get_equivalent_from_map(int n);

// god i wish there was an easier way of doing this. . .
inline static const std::unordered_map<int, char> alphabet_int{
	{11, 'A'}, {12, 'B'}, {13, 'C'}, {14, 'D'}, {15, 'E'}, {16, 'F'}, {17, 'G'}, {18, 'H'}, {19, 'I'},
	{21, 'J'}, {22, 'K'}, {23, 'L'}, {24, 'M'}, {25, 'N'}, {26, 'O'}, {27, 'P'}, {28, 'Q'}, {29, 'R'},
	{31, 'S'}, {32, 'T'}, {33, 'U'}, {34, 'V'}, {35, 'W'}, {36, 'X'}, {37, 'Y'}, {38, 'Z'}, {39, ' '}
};

inline static const std::unordered_map<char, int> alphabet_char{
	{'A', 11}, {'B', 12}, {'C', 13}, {'D', 14}, {'E', 15}, {'F', 16}, {'G', 17}, {'H', 18}, {'I', 19},
	{'J', 21}, {'K', 22}, {'L', 23}, {'M', 24}, {'N', 25}, {'O', 26}, {'P', 27}, {'Q', 28}, {'R', 29},
	{'S', 31}, {'T', 32}, {'U', 33}, {'V', 34}, {'W', 35}, {'X', 36}, {'Y', 37}, {'Z', 38}, {' ', 39}
};

};
#endif
