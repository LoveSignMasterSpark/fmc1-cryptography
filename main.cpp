#include <iostream>
#include <string>

#include "key.h"
#include "fmc.h"

int main(){
	Key key(2537, 13, 937);
	std::cout << "Number of digits possible: " << key.get_max_digits() << std::endl;

	std::cout << "Converting O: " << fmc::get_equivalent_from_map('O') << std::endl;
	std::cout << "Converting A: " << fmc::get_equivalent_from_map('A') << std::endl;
	std::cout << "Converting B: " << fmc::get_equivalent_from_map('B') << std::endl;

	// . . .
	std::vector<int> vetor_teste;

	fmc::turn_into_numerals("ABCDEFGHIJKLMNOPQRSTUVWXYZ ", vetor_teste, key.get_max_digits());

	std::cout << "644's bit width: " << fmc::bit_width(644) << std::endl;


	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;

	// encrypt
	fmc::encrypt_vector(key, vetor_teste);
/*
	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;
*/

	// decrypt
	fmc::decrypt_vector(key, vetor_teste);	
	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}
