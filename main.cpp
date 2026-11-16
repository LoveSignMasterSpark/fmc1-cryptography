#include <iostream>
#include <string>

#include "key.h"
#include "fmc.h"

int main(){
	Key key(2537, 13);
	std::cout << "Number of digits possible: " << key.get_max_digits() << std::endl;

	std::cout << "Converting O: " << fmc::get_equivalent_from_map('O') << std::endl;
	std::cout << "Converting A: " << fmc::get_equivalent_from_map('A') << std::endl;
	std::cout << "Converting B: " << fmc::get_equivalent_from_map('B') << std::endl;

	// . . .
	std::vector<int> vetor_teste;

	fmc::turn_into_numerals("ABCDEFGHIJKLMNOPQRSTUVWXYZ", vetor_teste, key.get_max_digits());

	std::cout << "644's bit width: " << fmc::bit_width(644) << std::endl;


	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;
	
//	std::cout << "getting rest of 3^644 mod 645: " << fmc::pow_mod(3, 644, 645) << std::endl;

	// encrypt
	for(int i = 0; i < vetor_teste.size(); i++){
		fmc::encrypt_block(key, vetor_teste[i]);
	}

	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;


	// decrypt
	for(int i = 0; i < vetor_teste.size(); i++){
		vetor_teste[i] = fmc::pow_mod(vetor_teste[i], 937, key.modulo);
	}

	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}
