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

int n, arr[MAXN], ans;
int dp[MAXN]; // dp[i] 表示：当以第 i 个元素作为结尾时的最长上升子序列的长度

int len[MAXN]; 
/*
 * len[j] 表示：所有长度为 j 的子序列中的最后一个数最小的数
 * 如假设长度为 4 的上升子序列有：
 *      。。。6
 *      。。。8
 *      。。。10
 *      。。。12
 * 那么 len[4] = 6
 * 接下来的一个数arr[i]如果大于 6 的话就接在 6 后面，组成长度为 5 的序列，否则会通过二分找 len[3],len[2]....
 *
 */  


//这是找第一个大于等于 x 的数，这是二分答案000001111(找第一个1)情况的递归写法，返回的第一个 1 的下标(也就是 x 接在后面组成上升子序列的长度)
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
        dp[i] = 1; // 当以第 i 个数结尾时，我们把最长上升子序列的长度初始化为 1
        len[i] = 0x3f3f3f3f;  // 最长上升子序列长度为 i 时的最后一个数最小的值初始化为一个比较大的值
    }
    len[++ans] = arr[1]; // 最长上升子序列长度为 1 的最后一个数最小值初始化数组第一个数
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1 , arr[i]); //在len[]中找第一个大于等于arr[i]的数的下标(也就是 arr[i] 接在后面组成的子序列的长度)赋给 dp[i]
        len[dp[i]] = arr[i]; // 然后把长度为 dp[i] 的子序列的最后一个值最小值更新为 arr[i]
        ans = max(dp[i], ans); // 更新ans
    }
    cout << ans << endl;
    return 0;
}

