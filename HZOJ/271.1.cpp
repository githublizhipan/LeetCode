/*************************************************************************
	> File Name: 271.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 23时07分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
int n, k;
int arr[300005], q[300005], head, tail;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        while (tail - head && arr[i] < arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i < k) continue;
        i == k || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    tail = head = 0;
    for (int i = 1; i <= n; i++) {
        while (tail - head && arr[i] > arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++; 
        if (i < k) continue;
        i == k || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    return 0;
}
