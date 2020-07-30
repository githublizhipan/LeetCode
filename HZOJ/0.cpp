/*************************************************************************
	> File Name: 0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 10时41分29秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define swap(a, b) {\
	__typeof(a) __temp = (a);\
	(a) = (b); (b) = __temp;\
}


typedef struct priorty_queue{
	double *data;
    int cnt;
} priority_queue;

void init(priority_queue *q, int n) {
    q->data = (double *)malloc(sizeof(double) * (n + 3));
 	q->cnt = 0;
    return ;
}

double top(priority_queue *q) {
    return q->data[1];
}

void push(priority_queue *h, double value) {
   /* 
    q->data[q->cnt] = val;
    int current = q->cnt;
    int f = (current - 1) / 2;
    while(q->data[f] < q->data[current]) {
        swap(q->data[f], q->data[current]);
        current = f;
        f = (current - 1) / 2;
    }
    q->cnt++;
    return ;
    */
    h->data[h->cnt] = value;
    int current = h->cnt;
    int father = (current - 1) / 2;
    while (h->data[current] > h->data[father]) {
        swap(h->data[current], h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->cnt++;
}

/*
void update(priority_queue *q, int ind, int n) {
    while(ind << 1 <= n) {
        int temp = ind, l = temp << 1, r = temp << 1 | 1;
        if(q->data[l] < q->data[temp]) temp = l;
        if(r <= n && q->data[r] < q->data[temp]) temp = r;
        if(temp == ind) break;
        swap(q->data[temp], q->data[ind]);
        ind = temp;
    }
    return ;
}
*/

void pop(priority_queue *q) {
    q->data[1] = q->data[q->cnt];
    q->cnt--;
    int ind = 1, temp, l, r;
    while(ind * 2 <= q->cnt) {
        temp = ind, l = temp * 2, r = temp * 2 + 1;
        if(q->data[l] > q->data[temp]) temp = l;
        if(r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if(temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return ;
}

double calc(priority_queue *q, int n){
    double ans = 0;
    while(q->cnt > 1) {
        double a = top(q);
        pop(q);
        double b = top(q);
        pop(q);

//printf("%lf %lf\n", a, b);
        double c = pow(b, 1.0 / 3.0) * pow(a, 2.0 / 3.0);
//printf("c: %lf\n\n", c);       
        push(q, c);
    }
    return top(q);
}


void output(priority_queue *q) {
    for(int i = 1; i <= q->cnt; i++) {
        printf("%lf ", q->data[i]);
    }
    printf("\n");
    return ;
}

void clear(priority_queue *q) {
    free(q->data);
    free(q);
    return ;
}
int main() {
	int n;
    double m;
    double ans;
    scanf("%d", &n);
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    init(q, n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &m);
        push(q, m);
    }
    output(q);
    
    
    
    //ans = calc(q, q->cnt);
    //printf("%lf\n", ans);
    clear(q);
    return 0;
}
