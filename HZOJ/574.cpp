/*************************************************************************
	> File Name: 574.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月18日 星期六 09时06分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 100000
long long a[MAX + 5];
int main() {
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) cnt++;
    }
    if(cnt & 1) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
