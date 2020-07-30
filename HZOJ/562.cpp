/*************************************************************************
	> File Name: 562.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月19日 星期日 11时45分17秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;
int main() {
    int n, ans = 0, t;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        ans ^= t;
    }
    printf("%d\n", ans);
    return 0;
}
