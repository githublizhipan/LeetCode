/*************************************************************************
	> File Name: 506.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 18时08分14秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int ind, time;
};

int n;
struct Node node[35]; 

int cmp(struct Node a, struct Node b) {
    return a.time < b.time;
}

int main() {
    double ans = 0, tmp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &node[i].time);
        node[i].ind = i + 1;
    }
    sort(node, node + n, cmp);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", node[i].ind);
        ans += tmp;
        tmp += node[i].time;
    }
    printf("\n");
    ans /= n;
    printf("%.2f\n", ans);
    return 0;
}
