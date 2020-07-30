/*************************************************************************
	> File Name: 390.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月30日 星期四 22时03分16秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
using namespace std;
#define MAX 100005
int arr[MAX];
int n, m, sum = 0, ans = 0;
bool check(int mid) {
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cnt += arr[i] / mid;
    } 
    return cnt >= m ? true : false;
}

int main() {
    cin >> n >> m;
    int maxlen = 0;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
        maxlen = max(maxlen, arr[i]);
    }
    int l = 1, r = arr[n - 1], mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            ans = (ans, mid);
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << ans << endl;
    return 0;
}
