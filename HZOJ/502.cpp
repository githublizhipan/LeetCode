/*************************************************************************
	> File Name: 502.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 21时02分04秒
 ************************************************************************/
#include <algorithm>

#include <cmath>
#include<iostream>
using namespace std;

#define MAX 1000005

int main() {
    int n, a[MAX];
    cin >> n;
    int minnum = MAX + 1, maxnum = -MAX - 1;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] > 0) {
            minnum = min(a[i], minnum);
        } else {
            maxnum = max(a[i], maxnum);
        }
    }


    cout << maxnum << " " << minnum << endl;
    cout << abs(maxnum + minnum) << endl;

    return 0;
}
