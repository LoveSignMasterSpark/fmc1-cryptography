#include "fmc.h"

#include <string>
#include <cmath>
#include <iostream>

int fmc::bit_width(int n){
	if(n <= 0) return -1;
	int bits = 0;
	while(n > 0){
		bits++;
		n >>= 1;
	}
	return bits;
}

int fmc::pow_mod(int b, int n, int m){
	int remainder = 1;
	int power = b % m;

	// gets base 2 representation of number, inline with fast modular exponentiation from Discrete Mathematics
	for(int i = 0; i < fmc::bit_width(n);i++){
		if(n >> i & 1){
			remainder = (remainder*power) % m;
		}
		power = (power*power) % m;
	}
	return remainder;
}

void fmc::turn_into_numerals(std::string raw, std::vector<int>& blocks, int block_size){
	// cleans up string, leaves only characters handled by our system
	// ugly, needs to be its own function eventually
	for(int i = 0;i < raw.size();i++){
		if(raw[i] < 'A' || raw[i] > 'Z'){
			if(raw[i] > 'a' && raw[i] < 'z'){
				raw[i] -= ('a' - 'A');
			} else if(raw[i] == 32){
				raw[i] = ' ';
			} else {
				raw.erase(i);
				i--;
			}
		}
	}
	
	int digit_size = block_size/2;

	int block_quantity = raw.size()/digit_size;

	// pads end of string so our blocks are equivalent in size
	if((raw.size() % digit_size) != 0){
		int rest = raw.size() % digit_size;
		block_quantity++;
		for(int i = 0;i<rest;i++) { raw.push_back('X'); }
	}

	// runs through our string, separates it into blocks, then turns them into our own base XX alphabet
	for(int i = 0;i<block_quantity;i++){
		int new_block = 0;
		for(int x = 0; x < digit_size;x++){
			// scales well with different block sizes i think
			new_block += fmc::get_int_from_map(raw[x+i*digit_size]) * std::pow(10, (digit_size-x-1)*2);
		}
		blocks.push_back(new_block);
	}
	return;
}

void fmc::turn_into_array(std::string numbers, std::vector<int>& blocks){
	while(1){
		int position = numbers.find('-');
		std::cout << "Found - at position " << position << std::endl;

		blocks.push_back(std::stoi(numbers.substr(0, position)));
	
		if(position == numbers.npos){ return; }
		else{ numbers.erase(0, position+1); }
	}
}

std::string fmc::turn_into_string(std::vector<int>& blocks, int key_quantity){
	// yeah this is gonna be ugly as fuck
	// yeah fuck ittt 
	std::string message = "";
	for(int i = 0; i < blocks.size(); i++){
		std::string code = std::to_string(blocks[i]);
		for(int x = 0; x < key_quantity; x++){
			message += get_char_from_map(std::stoi(code.substr(x*2, (x*2)+2))); // lol
			// dont ask me why +2 here. everything tells me this should be +1.
		}
	}

	return message;

}


// this wouldve been prettier if i did this in java
// but hindsight is 20 20 etc etc
int fmc::get_int_from_map(char c){
	if(auto search = alphabet_char.find(c); search != alphabet_char.end()){ return search->second; }
	else { return 11; }
}

char fmc::get_char_from_map(int n){
	if(auto search = alphabet_int.find(n); search != alphabet_int.end()){ return search->second; }
	else {	return 'A'; }
}

void fmc::encrypt_vector(Key key, std::vector<int>& blocks){
	for(int i = 0; i < blocks.size(); i++){ encrypt_block(key, blocks[i]); }
}

void fmc::decrypt_vector(Key key, std::vector<int>& blocks){
	for(int i = 0; i < blocks.size(); i++){ decrypt_block(key, blocks[i]); }
}

void fmc::encrypt_block(Key key, int& block){
	block = pow_mod(block, key.exponential, key.modulo);
}

void fmc::decrypt_block(Key key, int& block){
	block = pow_mod(block, key.decryption, key.modulo);
}
