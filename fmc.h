#ifndef FMC_H
#define FMC_H

#include <string>
#include <vector>
#include <bit>

#include "key.h"

class fmc{
public:

static int bit_width(int n);
static int pow_mod(int b, int n, int m);
static void turn_into_numerals(std::string raw, std::vector<std::string>& blocks, int key_size);
static void encrypt_block(Key key, std::string& block);
static std::string get_integer_representation(char c);
};

#endif
