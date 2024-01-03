/*
 * Converts decimal to octal.
 *
 * Project: Homework 2
 * Author:  Sai Valluru
 * Email:   s.valluru001@umb.edu
 * Date:    03/07/2021
 * Notes:   Lectures 9, 10, 11
 */

#include <stdio.h>

void reverse(char *s, int begin, int end);

int main(void) {

    // Declare the necessary int variable here
    // Create unsigned int quotient and int remainder
    unsigned int c, num = 0, ct = 0, quotient, remainder;
    // Declare a char array to record the octal digits on the corresponding index
    // Char oct is char array for octal digits
    char oct[8];

    printf("Please input a positive decimal integer and end with pressing Enter:\n");

    // Read the decimal string, at most 9 characters, since 1 << 32 = 4,294,967,296.
    while ((c = getchar()) != '\n' && ct <= 9) {
        // Use variable num to receive the value
	// Increment ct at the end of while loop
        num = num * 10 + c - '0';
	ct++;
    }

    // If the input is not valid, output the error message.
    if (c != '\n') {
        printf("ERROR: the input should be an integer and less than 1,000,000,000!\n");
    } else if (num == 0) {  // Output 0 directly since it doesn't need the conversion table.
        printf("Octal value: 0\n");
    } else {    // Output the conversion table
        printf("steps decimal quotient remainder oct\n");
        // Convert the decimal to the octal, output the intermediate conversion table
	// Set int step equal to 0
        int step = 0;

	// Using while loop, convert deicmal to octal and increment step by 1 at the end
	while (num != 0) {
	      quotient = num / 8;
	      remainder = num % 8;
	      printf("%d %u %u %u %u\n", step, num, quotient, remainder, remainder);
	      num = quotient;
	      oct[step] = (char)(remainder + '0');
	      step++;
	}

	// use reverse() to reverse characters on the string
	reverse(oct, 0, step);

        // Output the octal value
        printf("Octal value: %s\n", oct + 1);
    }

    return 0;
}

// Reverse the characters on the string s from index begin to index end.
void reverse(char *s, int begin, int end) {
    char c;

    if (begin >= end)
       return;

    c = *(s + begin);
    *(s + begin) = *(s + end);
    *(s + end) = c;

    reverse(s, ++begin, --end);
}

