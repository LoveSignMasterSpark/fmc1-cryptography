#ifndef FMC_H
#define FMC_H

#include <string>
#include <vector>
#include <bit>

#include "key.h"

class fmc{
public:

// returns amount of bits needed to represent number in base 2 (needed for power modulo calculation)
static int bit_width(int n);

// returns mod of b power n mod m
static int pow_mod(int b, int n, int m);

// main encryption function that turns string into RSA encrypted vector
static void turn_into_numerals(std::string raw, std::vector<std::string>& blocks, int key_size);

// OBSOLETE!! update to professor's own alphabet and use int!!
// helper function to turn our base 26 digits into RSA encrypted blocks
static void encrypt_block(Key key, std::string& block);

//OBSOLETE!! update to use int
// helper function that turns our string elements into our base 26 alphabet of choice
static std::string get_integer_representation(char c);
};

#endif
