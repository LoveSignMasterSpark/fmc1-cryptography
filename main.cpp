#include <iostream>
#include <string>

#include "key.h"
#include "fmc.h"

int main(){
	Key key(2637, 13);
	std::cout << "Number of digits possible: " << key.get_max_digits() << std::endl;

	std::cout << "Converting O to string: " << fmc::get_integer_representation('O') << std::endl;
	std::cout << "Converting A to string: " << fmc::get_integer_representation('A') << std::endl;
	std::cout << "Converting B to string: " << fmc::get_integer_representation('B') << std::endl;

	// . . .
	std::vector<std::string> vetor_teste;

	fmc::turn_into_numerals("ABCDEFGHIJLMNOPQRSTUVXYZ", vetor_teste, key.get_max_digits());

	std::cout << fmc::bit_width(644) << std::endl;


	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << fmc::pow_mod(3, 644, 645) << std::endl;

	return 0;
}
