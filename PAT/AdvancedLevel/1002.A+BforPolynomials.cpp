/*************************************************************************
	> File Name: 1002.A+BforPolynomials.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sun Oct 18 18:51:05 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int k, cnt, expo;
double arr[1010] = {0}, coe;


int main() {
    for (int j = 1; j <= 2; j++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%lf", &expo, &coe);
            arr[expo] += coe;
        }
    }
    for (int i = 0; i < 1002; i++) {
        if (arr[i]) cnt++;
    }
    printf("%d", cnt);
    for (int i = 1005; i >= 0; i--) {
        if (arr[i] == 0) continue;
        printf(" %d %.1f", i, arr[i]);
    }
    printf("\n");
    return 0;
}
