#ifndef KEY_H
#define KEY_H

class Key{
public:
int modulo, exponential, decryption;

Key(int n, int e);
Key(int d);
Key(int n, int e, int d);

// most functions here were to be used in encryption, instead of decryption, so they are mostly legacy
int get_max_digits();
int digits = 44;
};

#endif
