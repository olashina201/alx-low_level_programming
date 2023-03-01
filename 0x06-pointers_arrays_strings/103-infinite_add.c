#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* infinite_add(char* n1, char* n2, char* r, int size_r) {
    int len1 = strlen(n1);
    int len2 = strlen(n2);

    if (len1 > size_r || len2 > size_r)
    {
        return NULL; // result can't fit in r
    }

    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = size_r - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;
        if (i >= 0) {
            sum += n1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += n2[j] - '0';
            j--;
        }
        carry = sum / 10;
        int digit = sum % 10;
        r[k] = digit + '0';
        k--;
    }

    return &r[k + 1];
}
