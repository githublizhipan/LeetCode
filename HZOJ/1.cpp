/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月19日 星期三 16时20分37秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) {\
    __typeof(a) __temp = (a);\
    (a) = (b); (b) = __temp;\
}


typedef struct JS{
    int f, s, ind;
} JS;

typedef struct Heap {
    JS *data;
    int cnt;
} Heap;

void init(Heap *h, int n) {
    h->data = (JS *)malloc(sizeof(JS) * n);
    h->cnt = 0;
}

int cmp(JS a, JS b) {
    if(a.f > b.f) return 1;
    if(a.f == b.f && a.ind < b.ind) return 1;
    return 0;
}

void push(Heap *h, JS a) {


    h->data[h->cnt] = a;
    int current = h->cnt, father = (current - 1) / 2;
    while(cmp(h->data[current], h->data[father])) {
        swap(h->data[father], h->data[current]);
        current = father;
        father = (current - 1) / 2;
    }
    h->cnt++;
    return ;
}

int top(Heap *h) {
    return h->data[0].ind;
}

void update(Heap *h, int ind, int n) {
    while(ind * 2 + 1 <= n) {
        int temp = ind, l = temp * 2 + 1, r = temp * 2 + 2;
        if(cmp(h->data[l], h->data[temp])) {
            temp = l;
        }
        if(r <= n && cmp(h->data[r], h->data[temp])) {
            temp = r;
        }
        if(temp == ind) break;
        swap(h->data[temp], h->data[ind]);
        ind = temp;
    }
    return ;
}

void pop(Heap *h) {
    swap(h->data[0], h->data[h->cnt - 1]);
    h->cnt--;
    update(h, 0, h->cnt - 1); //cnt-1xxxxxxxxxxxxxxxxxxxxxxxxxxxx
}

void output(Heap *h) {
    for(int i = 0; i < h->cnt; i++) {
        printf("%d ", h->data[i].f);
    }
    printf("\n");
}

void clear(Heap *h) {
    free(h->data);
    free(h);
    return ;
}

int main() {
    int T, n;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d", &n);
        Heap *h = (Heap *)malloc(sizeof(Heap));
        init(h, n);
        for(int j = 1; j <= n; j++) {
            JS a;
            int f, s;
            scanf("%d%d", &f, &s);
            a.f = f;
            a.s = s;
            a.ind = j;
            push(h, a);
        }
        //output(h);
    
        printf("Case #%d:\n", i);
        printf("%d", top(h));
        pop(h);
    
        //output(h);

        while(h->cnt > 0) {
            for(int i = 0; i < h->cnt; i++) {
                h->data[i].f += h->data[i].s;
            }

            //output(h);

            for(int i = (h->cnt - 1) / 2; i >= 1; i--) {
                update(h, i, h->cnt - 1);
            }
            //output(h);

            int indx = top(h);
            printf(" %d", indx);
            pop(h);
        }
        printf("\n");
        clear(h);
    }
    return 0;
}
