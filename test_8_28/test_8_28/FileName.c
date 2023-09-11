#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include <stdio.h>
#include <string.h>

int main() {

    char c;
    char word[100][22] = { '\0' };
    int num = 0, top = 0;
    while ((c = getchar()) != EOF) {

        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            word[num][top++] = c;
        else {
            num++;
            top = 0;
        }


    }
    for (int i = num - 1; i >= 0; i--) {
        printf("%s ", word[i]);
    }

    return 0;
}