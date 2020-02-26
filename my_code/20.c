/*************************************************************************
	> File Name: 20.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时37分48秒
 ************************************************************************/
typedef struct Stack {
    char *data;
    int top_ind, size;
} Stack;

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

bool isValid(char * s){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (char *)malloc(sizeof(char) * 10000);
    stack->top_ind = -1;
    stack->size = 10000;
    for(int i = 0; s[i]; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(stack, s[i]);
            //output(stack);
        } else {
            if(empty(stack)) {
                return 0;
            }
            switch (s[i]) {
                case ')': {
                    if(top(stack) == '(') pop(stack);
                    else return 0;
                    //output(stack);
                } break;
                case '}': {
                    if(top(stack) == '{') pop(stack);
                    else return 0;
                    //output(stack);
                } break;
                case ']': {
                    if(top(stack) == '[') pop(stack);
                    else return 0;
                    //output(stack);
                } break;
            }
        }
    }
    if(empty(stack)) {
       return 1;    
    } else return 0;
}
