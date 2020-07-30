/*************************************************************************
	> File Name: 471.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月08日 星期三 21时25分56秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#define MAX 100000

char a1[MAX] = {0}, b1[MAX] = {0};
int a2[MAX] = {0}, b2[MAX] = {0}, c[MAX + 5] = {0};


int main() {
    scanf("%s%s", a1, b1);
    int len1 = strlen(a1), len2 = strlen(b1);
    int len3 = len1 + len2;
    for(int i = 0; i < len1; i++) {
        a2[i] = a1[len1 - 1 - i] - '0';
    }
    for(int i = 0; i < len2; i++) {
        b2[i] = b1[len2 - 1 - i] - '0';
    }

    //for(int i = 0; i < len2; ++i) printf("%d", b2[i]);
    //printf("\n");

    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            c[i + j] += a2[i] * b2[j];
            
            if(c[i + j] < 10) continue;
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }
    while(!c[len3]) len3--;
    for(int i = len3; i >= 0; i--) {
        printf("%d", c[i]);
    }
    printf("\n");
    return 0;
}
