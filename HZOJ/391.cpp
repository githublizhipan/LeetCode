/*************************************************************************
	> File Name: 391.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 18时24分41秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
using namespace std;
unsigned long long n, m, book[100005], sum = 0;


bool valued(unsigned long long size) {
   /* 
    unsigned int group = 1, rest = size;
    for(int i = 1; i <= n; ++i) {
        if(rest >= book[i]) {
            rest -= book[i];
        } else {
            group++;
            rest = size - book[i];
        }
    }
    //cout << "mid:" << size << " group:" << group << endl; 
    */
    
    unsigned long long rest = 0, group = 1;
    for(unsigned long long i = 1; i <= n; ++i) {
        if(rest + book[i] <= size) {
            rest += book[i];
        } else {
            group++;
            rest = book[i];
        }
    }
    //cout << "mid:" << size << " group:" << group << endl; 
    
    return group <= m;
}


int main () {
    unsigned long long l = 0, r = 0, mid;
    cin >> n >> m;
    for(unsigned long long i = 1; i <= n; ++i) {
        cin >> book[i];
        r += book[i];
        l = max(l, book[i]);
    }
    while(l < r) {
        mid = (l + r) >> 1;
        if(valued(mid)) {
            r = mid;
        } else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
