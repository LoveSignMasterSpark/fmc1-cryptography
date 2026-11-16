#ifndef KEY_H
#define KEY_H

class Key{
public:
int modulo, exponential, decryption;

Key(int n, int e);
Key(int d);
Key(int n, int e, int d);
int get_max_digits();
int digits = 39;
};

#endif
