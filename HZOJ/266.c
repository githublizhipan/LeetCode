/*************************************************************************
	> File Name: 266.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月19日 星期三 09时42分13秒
 ************************************************************************/
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include <inttypes.h>
#include <math.h>
#define MAX 100000
int calc(char *s, int l, int r) {
    int pos = -1, temp = 0, prior = MAX;
    for(int i = l; i <= r; i++) {
        int current = MAX;
        switch(s[i]) {
            case '(':
                temp += 100;
                break;
            case ')':
                temp -= 100;
                break;
            case '-':
                
                //current = temp + 3;
                //break;
            case '+':
                current = temp + 1;
                break;
            case '*':
            case '/':
                current = temp + 2;
                break;
            case '^':
                current = temp + 4;
                break;
        }
        if(current < prior) {
            prior = current;
            pos = i;
        }
    }

    //printf("pos : %d\n", pos);

    if(pos == -1) {
        int t = 0;
        for(int i = l; i <= r; i++) {
            if(s[i] < '0' || s[i] > '9') continue;
            t = t * 10 + s[i] - '0';
        }
        return t;
    }
    int a = calc(s, l, pos - 1);
    int b = calc(s, pos + 1, r);
    
    //printf("%d %d\n", a, b);
    
    switch (s[pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
    }
    return 0;
}


int main() {
    char s[1005];
    scanf("%s", s);
    int ans = calc(s, 0, strlen(s) - 1);
    printf("%d\n", ans);
    return 0;
}
