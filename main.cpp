#include <iostream>
#include <string>

#include "key.h"
#include "fmc.h"

int main(){


	Key key(14279, 5347);
	std::string message_encrypted = "4961-3072-9263-324-11807-4221-551-13714-1351-7742-13335-1748-5453-1183-4591-6815-1748-4221-1501-131-263-3435-3382-13501-7616-6966-393-13055-6309-1183-916-6904-11807-3371-3749";

	std::vector<int> message_blocks;

	fmc::turn_into_array(message_encrypted, message_blocks);

	fmc::find_decryption_keys(key, message_blocks);


/*

	Key decryption(1901);
	decryption.modulo = 3071;

	std::string encrypted = "2187-2825-1116-1969-2640-946-1193-895-693-1224-1547-2189-2921-544-2951-2779-1904-3042-827-1721-1148-487";
	std::vector<int> vetor;

	fmc::turn_into_array(encrypted, vetor);
	
	for(int i = 0; i < vetor.size(); i++){
		std::cout << vetor[i] << " ";
	}
	std::cout << std::endl;
	
	fmc::decrypt_vector(decryption, vetor);
	
	for(int i = 0; i < vetor.size(); i++){
		std::cout << vetor[i] << " ";
	}
	std::cout << std::endl;


	std::cout << fmc::turn_into_string(vetor) << std::endl;

*/


/*

	Key key(2537, 13, 937);
	std::cout << "Number of digits possible: " << key.get_max_digits() << std::endl;

	std::vector<int> vetor_teste;

	fmc::turn_into_numerals("ABCDEFGHIJKLMNOPQRSTUVWXYZ ", vetor_teste, key.get_max_digits());

	std::cout << "644's bit width: " << fmc::bit_width(644) << std::endl;


	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;

	// encrypt
	fmc::encrypt_vector(key, vetor_teste);

	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;


	// decrypt
	fmc::decrypt_vector(key, vetor_teste);	
	for(int i = 0; i < vetor_teste.size();i++){
		std::cout << vetor_teste[i] << " ";
	}
	std::cout << std::endl;


	std::cout << fmc::turn_into_string(vetor_teste) << std::endl;
*/
	return 0;
}
