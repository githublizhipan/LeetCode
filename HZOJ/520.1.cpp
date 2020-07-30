/*************************************************************************
	> File Name: 520.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月28日 星期四 12时08分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
long long n, k, a;

int main() {
    scanf("%d", &a);
    long long lsum = (1 + (a - 2)) * (a - 2) / 2, l, r = 20000000;
    for (int i = a; ; i++) {
        lsum += (i - 1);
        l = i + 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid == lsum) {
                printf("%d %d\n", i, r);
                return 0;
            }
            if (mid > lsum) r = mid - 1;
            else l = mid + 1;
        }
    }
    return 0;
}
