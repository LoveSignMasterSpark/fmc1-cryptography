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

// main decryption function that will parse our input number string and output it as our vector of choice
static void turn_into_array(std::string numbers, std::vector<int>& blocks);

// please disregard this.
static std::string turn_into_string(std::vector<int>& blocks);
	

static void encrypt_vector(Key key, std::vector<int>& blocks);
static void decrypt_vector(Key key, std::vector<int>& blocks);

static void encrypt_block(Key key, int& block);
static void decrypt_block(Key key, int& block);

// helper functions to exchange values from our own alphabet lookup tables
static int get_int_from_map(char c);
static char get_char_from_map(int n);

static void find_decryption_keys(Key key, std::vector<int> message_blocks);

static std::vector<int> sieve_all_primes(int n);

static void decrypt_and_print(Key key, int p, int q, std::vector<int>& message_blocks);
static int get_inverse(int exponential, int modulo);	

// god i wish there was an easier way of doing this. . .
inline static const std::unordered_map<int, char> alphabet_int{
	{11, 'A'}, {12, 'B'}, {13, 'C'}, {14, 'D'}, {15, 'E'}, {16, 'F'}, {17, 'G'}, {18, 'H'}, {19, 'I'},
	{21, 'J'}, {22, 'K'}, {23, 'L'}, {24, 'M'}, {25, 'N'}, {26, 'O'}, {27, 'P'}, {28, 'Q'}, {29, 'R'},
	{31, 'S'}, {32, 'T'}, {33, 'U'}, {34, 'V'}, {35, 'W'}, {36, 'X'}, {37, 'Y'}, {38, 'Z'}, {39, ' '},
	{41, '.'}, {42, ','}, {43, '!'}, {44, '?'}
};

inline static const std::unordered_map<char, int> alphabet_char{
	{'A', 11}, {'B', 12}, {'C', 13}, {'D', 14}, {'E', 15}, {'F', 16}, {'G', 17}, {'H', 18}, {'I', 19},
	{'J', 21}, {'K', 22}, {'L', 23}, {'M', 24}, {'N', 25}, {'O', 26}, {'P', 27}, {'Q', 28}, {'R', 29},
	{'S', 31}, {'T', 32}, {'U', 33}, {'V', 34}, {'W', 35}, {'X', 36}, {'Y', 37}, {'Z', 38}, {' ', 39},
	{'.', 41}, {',', 42}, {'!', 43}, {'?', 44}
};

};
#endif
