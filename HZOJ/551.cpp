/*************************************************************************
	> File Name: 551.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 18时03分34秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int n, a[2500], b[2500];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int j = 1;
    b[1] = a[1];
    for(int i = 2; i <= n; i++) {
        if(a[i] <= b[j]) {
            b[++j] = a[i];
        } else {
            for(int k = 1; k <= j; ++k) {
                if(b[k] > a[i]) continue;
                else {
                    b[k] = a[i];
                    break;
                }
            }
        }
    }
    cout << j << endl;

    return 0;
}
