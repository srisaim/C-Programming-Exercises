/*
 * Converts octal to decimal.
 *
 * Project: Homework 2
 * Author:  Sai Valluru
 * Email:   s.valluru001@umb.edu
 * Date:    03/07/2021
 * Notes:   Lectures 9, 10, 11
 */

#include <stdio.h>

int main(void) {
    unsigned int c, num = 0, ct = 0;

    printf("Please input a positive octal integer and end with pressing Enter:\n");

    // Read the octal string, at most 10 characters.
    while ((c = getchar()) != '\n' && ((c >= '0' && c <= '9') && ct++ < 11)) {
        // Convert the input string to an value storing in int
        num = num << 3 | (c - '0');
    }
    // If the input is not valid, output the error message.
    if (c != '\n') {
        printf("ERROR: the input should be an octal string containing 0-7, with length less than 11!\n");
    } else {    // Output the conversion table.
        printf("i 8^i digit product\n");
	// Using for-loop print output
        for (int i = 0; i < ct; i++) {
	    printf("%u %u %u %u\n",i,1 << (3 * i),num >> (3 * i) & 7,
		  (1 << (3 * i)) * (num >> (3 * i) & 7));
	}

        // Output the decimal value
        printf("Decimal value: %d\n", num);
    }

    return 0;
}

