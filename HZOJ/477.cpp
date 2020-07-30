/*************************************************************************
	> File Name: 477.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 22时50分17秒
 ************************************************************************/
#include <cstdio>
#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
int ans = 0, arr[150];
int main() {
    char str[110];
    cin >> str; 
    int j = 0;
    for(int i = 0; str[i]; i++) {
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            arr[j++] = i;
        }
    }
    for(int i = j; i > 0; i--) {
        ans = max(ans,  arr[i] - arr[i - 1]);
    }
    cout << ans << endl;
    return 0;
}
