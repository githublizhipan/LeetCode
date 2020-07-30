/*************************************************************************
	> File Name: 376.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 14时57分03秒
 ************************************************************************/
#include <queue>
#include<iostream>
using namespace std;

int arr[1005] = {0};

int main() {
    int M, N, t, ans = 0;

    queue<int> q;

    cin >> M >> N;

    while(N--) {
        cin >> t;
        if(arr[t]) continue;
        if(q.size() < M) {
            q.push(t);
            arr[t] = 1;
            ans++;
        } else {
            arr[q.front()] = 0;
            q.pop();
            q.push(t);
            arr[t] = 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
