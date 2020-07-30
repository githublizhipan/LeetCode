/*************************************************************************
	> File Name: 195.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月21日 星期二 18时14分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX 100010
int main() {
    long long n, m, a[MAX], q;
    scanf("%lld%lld", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    int flag = 1;
    while(m--) {
        scanf("%lld", &q);
        int l = 0, r = n - 1, mid;
        while(l != r) {
            mid = (l + r + 1) >> 1;
            if(a[mid] > q) r = mid - 1;
            else l = mid;
        }
        if(flag) {
            cout << a[l];
            flag = 0;
        } else cout << " " << a[l];
    }
    cout << endl;
    return 0;
}
