#include <cmath>
#include "key.h"

Key::Key(int n, int e) : modulo(n), exponential(e) {}
Key::Key(int d) : decryption(d) {}
Key::Key(int n, int e, int d) : modulo(n), exponential(e), decryption(d) {}




// this is something like
// 2626 < n < 262626
// so only edge case here is like, n being lower than 2626, but still 4 digit wide
// this would make the max length 2
//
// due to new int alphabet limits, i have done the unthinkable
// see if this breaks anything
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
