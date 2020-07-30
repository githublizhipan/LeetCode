/*************************************************************************
	> File Name: 584.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月02日 星期日 21时26分56秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
using namespace std;
int main() {
    int n, a[100005], b[100005] = {0};
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    b[0] = 1, b[1] = a[1];
    for(int i = 2; i <= n; ++i) {
        if(a[i] >= b[b[0]]) {
            b[++b[0]] = a[i];
        } else {
            int t = upper_bound(b + 1, b + b[0] + 1, a[i]) - b; //找序列b中第一个大于等于a[i]的数在b中的下标
            //cout << t << endl;
            b[t] = a[i];
        }
    }
    //for(int i = 1; i <= b[0]; ++i) cout << b[i] << " " ;
    cout << b[0] << endl;
    return 0;
}
