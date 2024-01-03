/*
* Print the size of C types
*/

#include <stdio.h>

int main(void) {
	char c;
	int i;
	short s;
	long l;
	long long ll;
	float f;
	double d;
	signed int si;
	unsigned int usi;

	printf("char\t%lubyte\n", sizeof(c));
	printf("int\t%lubyte\n", sizeof(i));
	printf("short\t%lubyte\n", sizeof(s));
	printf("long\t%lubyte\n", sizeof(l));
	printf("long long\t%lubyte\n", sizeof(ll));
	printf("float\t%lubyte\n", sizeof(f));
	printf("double\t%lubyte\n", sizeof(d));
	printf("signed int\t%lubyte\n", sizeof(si));
	printf("unsigned int\t%lubyte\n", sizeof(usi));

	return 0;
}
