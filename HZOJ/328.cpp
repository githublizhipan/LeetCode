/*************************************************************************
	> File Name: 328.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月24日 星期日 16时29分43秒
 ************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 200000
#define lowbit(x) ((x) & (-x))
long long c[MAX_N + 5] = {0};
long long y[MAX_N + 5];
void add(long long i, long long val, long long n) { //修改一个数，要改变c[i]
    while (i <= n) c[i] += val, i += lowbit(i);
    return ;
}

long long S(long long i) { //求前缀和
    long long sum = 0;
    while (i) sum += c[i], i -= lowbit(i);
    return sum;
}

int main() {
    long long n;
    long long ans1 = 0, ans2 = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> y[i];
    for (long long i = 1; i <= n; i++) {
        /*
        long long l_small_num = S(y[i]);
        long long l_big_num = i - 1 - l_small_num;
        long long r_small_num = y[i] - l_small_num - 1;
        long long r_big_num = n - y[i] - l_big_num;
        ans1 += l_small_num * r_small_num;
        ans2 += l_big_num * r_big_num;
        add(arr[i], 1, n);
        */
        long long lnum = S(y[i]);
        ans1 += (y[i] - lnum - 1) * lnum;
        ans2 += (i - 1 - lnum) * (n - y[i] - i + 1 + lnum);
        add(y[i], 1, n);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}

