/*
 * Big number addition
 *
 * Project: Homework 3
 * Author:  Sai Valluru
 * Email:   S.Valluru001@umb.edu
 * Date:    03/28/2021
 * Notes:   Lectures 12-17, Debugging PDF
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10000

/* Reverse the integers in the int array num from index begin to index end */
void reverse(int num[], int begin, int end);

/* Calculate the addition result, you need to complete this function */
int add(int a[], int b[], int len_a, int len_b, int r[]);

/* Simple unit test for add function */
void simpleUnitTestForAdd();

int main() {
    int a[MAX_LEN], b[MAX_LEN], result[MAX_LEN];
    int len_a = 0, len_b = 0, len_result = 0;
    char c;

    // Read the first big number
    // Here the program assumes the input are valid and non-negative
    while ((c = getchar()) != '\n')
        a[len_a++] = c - '0';

    // Read the second big number
    while ((c = getchar()) != '\n')
        b[len_b++] = c - '0';

    // Calculate the sum
    len_result = add(a, b, len_a, len_b, result);

    // Print out the result
    for (int i = 0; i < len_result; i++)
        printf("%d", result[i]);

    printf("\n");

    /* Please uncomment the unit test to check your implementation before submission */
    simpleUnitTestForAdd();

    return 0;
}

/*
 * Calculate the addition result
 *
 * Args:
 *  a:  a big number represented by an int array
 *  b:  a big number represented by an int array
 *  len_a:  the number of valid digits in array a
 *  len_b:  the number of valid digits in array b
 *  r:  an int array to store the addition result
 *
 * Return:
 *  An integer standing for the number of valid digits in r
 */
int add(int a[], int b[], int len_a, int len_b, int r[]) {
    /* Declare and initialize the variables you want to use later */
    // Initialized variables ct, carryover, temp, n, t, j
    int ct = 0, carryover = 0, temp = 0;
    int n, t = 0, j = 0;

    // Get the size of int r[]
    if (len_a > len_b || len_a == len_b) {
        n = len_a;
    }
    else {
        n = len_b;
    }
    n++;

    // While-loop until length is not 0
    while (len_a != 0 || len_b != 0) {

        // If there is a carryover, t is the value of carry which is added to other numbers
        if (carryover == 1) {
            temp = a[--len_a] + b[--len_b] + t;
            t = temp / 10;
            if (t > 0) {
                carryover = 1;
            }
            else {
                carryover = 0;
            }
        }
        // Else, if there is no carry
        else {
            temp = a[--len_a] + b[--len_b];
            t = temp / 10;
            if (t > 0) {
                carryover = 1;
            }
            else {
                carryover = 0;
            }
        }

        if (j < n) {
            r[j] = (temp % 10);
            j++;
        }
    }

    // If there is no carry after all the addition
    // Use reverse() to reverse array in correct order
    if (carryover == 0) {
        reverse(r, 0, n - 2);
        ct = n - 1;
    }
    // If there is still a carry
    // Use reverse() to reverse array in correct order
    else {
        if (j < n) {
            r[j] = t;
            j++;
        }
        reverse(r, 0, n - 1);
        ct = n;
    // Return value of ct
    }
    return ct;
}

// Reverse the integers in the int array num from index begin to index end.
void reverse(int num[], int begin, int end) {
    int i;

    while (begin < end) {
        i = num[begin];
        num[begin++] = num[end];
        num[end--] = i;
    }
}

int equal(int a[], int b[], int len) {
    for (int i = 0; i < len; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

/* Simple unit test for add function */
void simpleUnitTestForAdd() {
    int r[MAX_LEN];

    // Test 1
    int a1[] = {1, 2};
    int b1[] = {2};
    int r1[] = {1, 4};
    add(a1, b1, 2, 1, r);
    if (!equal(r, r1, 2)) {
        printf("ERROR: test 1 failed!!!\n");
        return;
    }

    // Test 2
    int a2[] = {};
    int b2[] = {2};
    int r2[] = {2};
    add(a2, b2, 0, 1, r);
    if (!equal(r, r2, 1)) {
        printf("ERROR: test 2 failed!!!\n");
        return;
    }

    // Test 3
    int a3[] = {0};
    int b3[] = {2};
    int r3[] = {2};
    add(a3, b3, 1, 1, r);
    if (!equal(r, r3, 1)) {
        printf("ERROR: test 3 failed!!!\n");
        return;
    }

    // Test 4
    int a4[] = {1, 3, 0};
    int b4[] = {2, 2};
    int r4[] = {1, 5, 2};
    add(a4, b4, 3, 2, r);
    if (!equal(r, r4, 3)) {
        printf("ERROR: test 4 failed!!!\n");
        return;
    }

    // Test 5
    int a5[] = {8, 6, 8, 3, 7, 8, 4, 3, 2, 4, 2, 3, 6, 4, 2, 3, 8, 4, 6, 2, 3, 9, 1, 2, 9, 3, 7, 8, 2, 7, 3, 8, 3, 2, 4, 5, 2, 3, 8, 6, 8, 2, 1, 2, 1};
    int b5[] = {2, 4, 8, 6, 3, 8, 3, 6, 2, 7, 6, 8, 8, 9, 9, 9, 0, 0, 1, 0, 2, 1, 7, 2, 4, 6, 2, 3, 6, 5, 8, 2, 1, 3, 2, 1, 2};
    int r5[] = {8, 6, 8, 3, 7, 8, 4, 3, 4, 9, 1, 0, 0, 2, 6, 0, 1, 2, 3, 1, 2, 9, 1, 1, 9, 3, 8, 8, 4, 9, 1, 0, 7, 8, 6, 8, 8, 9, 6, 8, 9, 5, 3, 3, 3};
    add(a5, b5, 45, 37, r);
    if (!equal(r, r5, 45)) {
        printf("ERROR: test 5 failed!!!\n");
        return;
    }

    // Test 6
    int a6[] = {7, 2, 3};
    int b6[] = {4, 5, 6, 7, 8, 7, 6, 5, 4, 6, 7, 8, 7, 6, 5, 6, 7, 6, 5, 6, 7, 6, 5, 6, 7, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6};
    int r6[] = {4, 5, 6, 7, 8, 7, 6, 5, 4, 6, 7, 8, 7, 6, 5, 6, 7, 6, 5, 6, 7, 6, 5, 6, 7, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 3, 9};
    add(a6, b6, 3, 58, r);
    if (!equal(r, r6, 58)) {
        printf("ERROR: test 6 failed!!!\n");
        return;
    }

    printf("Congratulations! All tests passed!\n");

}
