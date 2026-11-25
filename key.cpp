#include <cmath>
#include "key.h"

Key::Key(int n, int e) : modulo(n), exponential(e) {}
Key::Key(int d) : decryption(d) {}
Key::Key(int n, int e, int d) : modulo(n), exponential(e), decryption(d) {}


// this is supposed to return our max length for encrypted blocks based on our given modulo
// calculated by:
// 4444 < n < 444444
//
// so only edge case here is like, n being lower than 4444, but still 4 digit wide
// this would make the max length 2

int Key::get_max_digits(){
	int count = digits; // alphabet + space
	int max = 0;
	if(modulo <= 0) return -1;
	while(1){
		if(count > modulo) return max;
		count += digits * std::pow(10, max+2);
		max += 2;
	}
}
