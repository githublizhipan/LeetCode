/*************************************************************************
	> File Name: 559.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 20时51分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int M, N;
double ans; 
double arr[1005];

struct Node {
    int s, f;
    double a;
} node[1005];

int cmp(struct Node x, struct Node y) {
    return x.a > y.a;
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> node[i].s >> node[i].f;
        node[i].a = 1.0 * node[i].s / node[i].f;
    }
    sort(node, node + N, cmp);
    for (int i = 0; i < N; i++) {
        if (M * node[i].a >= node[i].s) {
            ans += node[i].s;
            M -= node[i].f;
        } else {
            ans += M * node[i].a;
            break;
        }
    }
    printf("%.3lf\n", ans);
    return 0;
}
