/*************************************************************************
	> File Name: 248.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 22时13分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 500005
int main() {
    int x;
    while(cin >> x, x != 0) {
        int arr[MAX];
        for(int i = 0; i < x; ++i) {
            cin >> arr[i];
        }
        int cnt = 0;
        for(int i = 0; i < x - 1; i++) {
            for(int j = i + 1; j < x; j++) {
                if(arr[j] > arr[i]) continue;
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
