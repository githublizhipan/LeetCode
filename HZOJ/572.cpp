/*************************************************************************
	> File Name: 572.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 19时54分01秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;

#define MAX 400005
int n;
long long a[MAX], b[MAX], ans[MAX];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int j = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if(j >= n) continue;
        for(int k = 0; a[k] <= b[i]; k++) {
            ans[j++] = a[k] + b[i];
        }
    }
    //cout << j << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
