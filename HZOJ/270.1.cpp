/*************************************************************************
	> File Name: 270.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月30日 星期四 14时55分08秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 3000000
int n, m, s[MAX_N + 5], q[MAX_N + 5], head, tail;

//单调队列维护区间最小前缀和，因为当前点对应前缀和减去前面最小前缀和才能得到区间最大值，前提那个最小位置与当前位置差不能超过m
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0;
    int ans = s[1]; 
    for (int i = 1; i <= n; i++) {
        if (i - q[head] > m) head++;
        ans = max(ans, s[i] - s[q[head]]);
        while (tail - head && s[i] < s[q[tail - 1]]) tail--;
        q[tail++] = i;
    }
    cout << ans << endl;
    return 0;
}
