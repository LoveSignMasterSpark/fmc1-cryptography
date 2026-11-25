#include <iostream>
#include <string>

#include "key.h"
#include "fmc.h"

int main(){

//	decryption of message given only its encryption key and modulo
	Key key(14279, 5347);
	std::string message_encrypted = "4961-3072-9263-324-11807-4221-551-13714-1351-7742-13335-1748-5453-1183-4591-6815-1748-4221-1501-131-263-3435-3382-13501-7616-6966-393-13055-6309-1183-916-6904-11807-3371-3749";
	std::vector<int> message_blocks;

	fmc::turn_into_array(message_encrypted, message_blocks);
	fmc::find_decryption_keys(key, message_blocks);
	std::cout << std::endl << std::endl;

//	start of decryption of our given message by its decryption key
	Key decryption(1901);
	decryption.modulo = 3071;

	std::string encrypted = "2187-2825-1116-1969-2640-946-1193-895-693-1224-1547-2189-2921-544-2951-2779-1904-3042-827-1721-1148-487";
	std::vector<int> vetor;

	fmc::turn_into_array(encrypted, vetor);
	fmc::decrypt_and_print(decryption, vetor);
	
	return 0;
}

//	algorithm made to better intuit byte range of numbers ; UNUSED
/*
	int number = 152;
	int number_2 = number;
	std::vector<int> number_list;
	std::vector<bool> byte_list;
	bool found_match = false;
	while(!found_match){

		number_list.push_back(number_2);
		number_2 *= 2;
		if(number_2 >= 1000){
			byte_list.push_back(true);
			number_2 -= 1000;
		}
		else{
			byte_list.push_back(false);
		}


		for(int i = 0; i < number_list.size(); i++){
			if(number_2 == number_list[i]){
				found_match = true;
				break;
			}
		}
		if(number_list.size() > 10000){ break; } // yeah just a catch all

	}

	if(found_match){
		std::cout << std::endl << number << " => " << byte_list.size() << " bytes => ";
		for(int i = 0;i < byte_list.size();i++){
			std::cout << byte_list[i];	
		}
		std::cout << std::endl;
	} else {
		std::cout << std::endl << "1000 entries reached but no match" << std::endl;
	}
*/
