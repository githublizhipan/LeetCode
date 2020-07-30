/*************************************************************************
	> File Name: 372.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月30日 星期四 17时18分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 500005
int n, a[MAX_N], b[MAX_N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    int p = 1, top1 = 1, top2 = 1;
    while (p <= n) {
        while (top1 > 0 && a[p] <= a[top1 - 1]) top1--;
        while (top2 > 0 && b[p] <= b[top2 - 1]) top2--;
        if (top2 - top1) break;
        a[top1++] = a[p];
        b[top2++] = b[p];
        p++;
    }
    cout << p - 1 << endl;
    return 0;
}
