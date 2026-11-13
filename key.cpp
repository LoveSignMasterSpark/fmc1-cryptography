#include <cmath>
#include "key.h"


Key::Key(int n, int e) : modulo(n), exponential(e) {}

// this is something like
// 2626 < n < 262626
// so only edge case here is like, n being lower than 2626, but still 4 digit wide
// this would make the max length 2
int Key::get_max_digits(){
	int digits = 26; // alphabet + space
	int max = 0;
	if(modulo <= 0) return -1;
	while(1){
		if(digits > modulo) return max;
		digits += 26 * std::pow(10, max+2);
		max += 2;
	}
}
