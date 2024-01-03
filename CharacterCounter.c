/*
 * Counts the number of the input characters.
 *
 * Project : hw1
 * Author  : Sai Valluru
 * Email   : s.valluru001@umb.edu
 * Date    : 02/15/2021
 * Notes   : count_words.c, lecture 5 & 6 notes
 */

#include <stdio.h>

int main(void) {

    int c;
    // Define an int variable with initial value as 0 to count the characters.
    // Int count is initialized at 0.
    int count = 0;

    // The while loop exits when Enter is pressed,
    // or the first line of the input finished,
    // or it gets EOF.
    // Int count will increment +1 when there is a character.
    while ((c = getchar()) != EOF && c != '\n') {
        // Increment the counter
        count = count + 1;
    }

    // Print the number of the input characters.
    // Print final value of int count.
    printf("%d\n", count);

    return 0;
}
