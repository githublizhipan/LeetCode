/*************************************************************************
	> File Name: 511.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 22时36分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
long long a, b, k;

int main() {
    scanf("%lld%lld%lld", &a, &b, &k);
    if (k <= 1) {
        printf("%lld\n", b - a);
        return 0;
    }
    long long cnt = 0;
    while (b != a) {
        if (b % k == 0) {
            long long t = b / k;
            if (t < a) {
                cnt += b - a;
                break;
            } else {
                b = t;
            }
        }
        else b--;
        cnt++;
    }
    printf("%lld\n", cnt);
    return 0;
}
