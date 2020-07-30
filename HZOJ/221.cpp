/*************************************************************************
	> File Name: 221.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月02日 星期日 16时42分33秒
 ************************************************************************/
#include <cstdio>
#include <algorithm>
#include<iostream>
using namespace std;
#define MAX 1000000005
int n, m;

struct student{
   int h, num, sum; 
};

bool cmp1(struct student a, struct student b) {
    return a.h < b.h;
}

bool cmp2(struct student a, struct student b) {
    return a.num < b.num;
}
int main() {
    scanf("%d%d", &n, &m);
    int height[100005];
    //cin >> n >> m;
    struct student a[100005];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i].h);
        a[i].num = i;
        a[i].sum = 0;
    }
    for(int i = 0; i < m; ++i) {
        //cin >> height[i];
        scanf("%d", &height[i]);
    }
    sort(a, a + n, cmp1);
    sort(height, height + m);
    int index = 0;
    for(int i = 0; i < n; ++i) {
        while(index < m && height[index] <= a[i].h) {
            a[i].sum++;
            index++;
        }
    }
    sort(a, a + n, cmp2);
    for(int i = 0; i < n; ++i) {
        printf("%d\n", a[i].sum);
    }
    return 0;
}
