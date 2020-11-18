/*************************************************************************
	> File Name: 2533.最长上升子序列.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Nov 18 08:43:59 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAXN 1000010

int n, arr[MAXN], dp[MAXN], ans;
int len[MAXN]; //存 i 长度的子序列的最小值

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l; 
    int mid = (l + r) >> 1;
    if (arr[mid] < x) return bs(arr, mid + 1, r, x);
    return bs(arr, l, mid, x);
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        len[i] = 0x3f3f3f3f;
    }
    len[++ans] = arr[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1 , arr[i]); //在len[]中找第一个大于等于arr[i]的数 
        len[dp[i]] = arr[i];
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}

