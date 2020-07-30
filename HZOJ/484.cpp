/*************************************************************************
	> File Name: 484.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 13时43分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[30] = {0}, maxnum = 0;

int main() {
    char s[1005];
    while(scanf("%s", s) != EOF) {
        for(int i = 0; s[i]; ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                arr[s[i] - 'A']++;
                maxnum = max(maxnum, arr[s[i] - 'A']);
            }
        }
    }
    
    for(int i = 0; i < maxnum; i++) {
        int t = maxnum - i, j;
        for(j = 25; j >= 0; j--) {
            if(arr[j] < t) continue;
            break;
        }
        for(int k = 0; k <= j; k++) {
            if(!k) {
                if(arr[k] < t) cout << " ";
                else cout << "*";
            } else {
                if(arr[k] < t) cout << "  ";
                else cout << " *";
            }
        }
        cout << endl;
    }
    cout << 'A';
    for(int i = 1; i <= 25; i++) {
        cout << " " << char('A' + i);
    }
    cout << endl;

    return 0;
}
