/*************************************************************************
	> File Name: 599.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月21日 星期四 17时49分51秒
 ************************************************************************/

#include<iostream>
using namespace std;
int n, t, num[10000005];
int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int i = 0, j = n - 1;
    while (i < j) {
        int temp = num[i] + num[j];
        if (temp == t) {
            printf("%d %d\n", i, j);
            return 0;
        }
        if (temp < t) i++;
        else j--;
    }
    return 0;
}
