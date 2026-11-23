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

		blocks.push_back(std::stoi(numbers.substr(0, position)));
	
		if(position == numbers.npos){ return; }
		else{ numbers.erase(0, position+1); }
	}
}

std::string fmc::turn_into_string(std::vector<int>& blocks){
	// yeah this is gonna be ugly as fuck
	// yeah fuck ittt 
	std::string message = "";
	for(int i = 0; i < blocks.size(); i++){
		std::string code = std::to_string(blocks[i]);
		message += code;
	}

	std::cout << message << std::endl;

	std::string message_decoded = "";
	for(int i = 0; i < message.size()/2;i++){
		message_decoded += get_char_from_map(std::stoi(message.substr(i*2, 2)));
	}

	return message_decoded;

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


std::vector<int> fmc::sieve_all_primes(int n){
	std::vector<int> primes;
	std::vector<bool> is_prime(n + 1, true);
	for(int i = 2; i*i <= n;i++){
		if(is_prime[i]){
			for(int x = i * i; x <= n; x += i){
				is_prime[x] = false;
			}
		}
	}

	for(int i = 2; i <= n;i++){
		if(is_prime[i]){
			if( !(n % i) ){ // filter primes that do not divide n
				primes.push_back(i);
//				std::cout << "Prime that divides " << n << ": " << i << std::endl;
			}
		}
	}
//	std::cout << std::endl;
	return primes;
}

// what we prolly need
// is something like 
// run through prime vector
// run through prime vector starting with i
// multiply them, check if equals our public key
// if it does, find the inverse of (p-1)(q-1) with exponential mod modulo
// then use that inverse as the decryption 
// repeat till all options exhausted
// check all outputs to see which one was right

void fmc::find_decryption_keys(Key key, std::vector<int> message_blocks){

	
	std::vector<int> primes = sieve_all_primes(key.modulo);

	for(int i = 0; i < primes.size();i++){
		for(int o = i+1; o < primes.size();o++){
			if(primes[i] * primes[o] == key.modulo){
				int p = primes[i] - 1;
				int q = primes[o] - 1;
				int pq = p * q;
				// find inverse of encryption modulo (i-1)(o-1)

				key.decryption = get_inverse(key.exponential, pq);

				decrypt_and_print(key, p, q, message_blocks);
				return;
			}

		}
	}

	std::cout << "Something went wrong? No prime factorization found" << std::endl;

}


int fmc::get_inverse(int value, int modulo){
	int original_modulo = modulo;

	std::cout << "Trying to find inverse of " << value << " mod " << modulo << std::endl;

	int last_inverse = 0;
	int inverse = 1;
	while(value!=0){
		int mult = modulo/value;
		int x = modulo - value*mult;
		modulo = value;
		value = x;
		x = inverse;
		inverse = last_inverse - inverse*mult;
		last_inverse = x;
		std::cout << value << " | " << inverse << std::endl;
	}

	std::cout << std::endl;

	if(last_inverse < 0){
		while(last_inverse<0){
			last_inverse += original_modulo;
		}
	}

	// brother. you should put me in front of the firing squad for this one.
	std::cout << "Found as inverse: " << last_inverse << std::endl;
	return last_inverse;

}

void fmc::decrypt_and_print(Key key, std::vector<int>& message_blocks){
	decrypt_vector(key, message_blocks);
	std::string message = turn_into_string(message_blocks);
	std::cout << "D = " << key.decryption << " => " << message << std::endl;
}

void fmc::decrypt_and_print(Key key, int p, int q, std::vector<int>& message_blocks){
	decrypt_vector(key, message_blocks);
	std::string message = turn_into_string(message_blocks);
	std::cout << "D = " << key.decryption << " = " << p << " * " << q << " => " << message << std::endl;

}
