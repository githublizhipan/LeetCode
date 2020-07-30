/*************************************************************************
	> File Name: 43.1记忆化.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 18时12分42秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 1000
int val[MAX + 5][MAX + 5];
int keep[MAX + 5][MAX + 5] = {0};

int dfs(int i, int j, int n){
    if(i + 1 == n) return val[i][j];
    if(keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = (val1 > val2 ? val1 : val2) + val[i][j];
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, n) << endl;
    return 0;
}
