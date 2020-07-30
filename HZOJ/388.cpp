/*************************************************************************
	> File Name: 388.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 20时48分02秒
 ************************************************************************/
#include<set>
#include<iostream>
using namespace std;

#define MAX 100050
int main() {
    int m, n, x[MAX];
    set<int> y;
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        cin >> x[i];
    }


    int t;
    for(int i = 0; i < n; i++) {
        cin >> t;
        y.insert(t);
    }


    long long sum = 0;
    int flag = 1;
    for(int i = 0; i < m; i++) {
        if(y.find(x[i]) == y.end()) continue;
        if(flag) {
            cout << x[i];
            flag = 0;
        } else cout << " " << x[i];
        sum += x[i];
    }
    cout << endl << sum << endl;
    return 0;
}
