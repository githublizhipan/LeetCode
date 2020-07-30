/*************************************************************************
	> File Name: 43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 18时05分10秒
 ************************************************************************/

#include<iostream>

using namespace std;

#define MAX 1000
int val[MAX + 5][MAX +5] = {0};
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){ 
        for(int j = 0; j <= i; ++j) 
        cin >> val[i][j];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; ++j) {
            val[i][j] += (val[i + 1][j] > val[i + 1][j + 1] ? val[i + 1][j] : val[i + 1][j + 1]);
        }
    }
    cout << val[0][0] << endl;
    return 0;
}
