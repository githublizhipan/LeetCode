/*************************************************************************
	> File Name: 15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 18时49分04秒
 ************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    char *data;
    int top_ind, size;
} Stack;


void init(Stack *s, int n) {
    s->data = (char *)malloc(sizeof(char) * n);
    s->top_ind = -1;
    s->size = n;
    return ;
}

void push(Stack *s, char c) {
    s->top_ind++;
    s->data[s->top_ind] = c;
    return ;
}

char top(Stack *s) {
    return s->data[s->top_ind];
}

void pop(Stack *s) {
    s->top_ind--;
    return ;
}

int empty(Stack *s) {
    return s->top_ind == -1;
}


void output(Stack *s) {
    int t = 0;
    while(t <= s->top_ind) {
        printf("%c ", s->data[t]);
        t++;
    }
    printf("\n\n");
    return ;
}


void clear(Stack *s) {
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char s[10005];
    scanf("%s", s);
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    init(stack, 10005);
    
    for(int i = 0; s[i]; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(stack, s[i]);
            //output(stack);

        } else {
            if(empty(stack)) {
                printf("false\n");
                break;
            }
            switch (s[i]) {
                case ')': {
                    if(top(stack) == '(') pop(stack);
                    //output(stack);
                } break;
                case '}': {
                    if(top(stack) == '{') pop(stack);
                    //output(stack);
                } break;
                case ']': {
                    if(top(stack) == '[') pop(stack);
                    //output(stack);
                } break;
            }
        }
    }
    if(empty(stack)) {
       printf("true\n");    
    } else printf("false\n");
    clear(stack);
    return 0;
}
