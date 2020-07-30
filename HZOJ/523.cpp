/*************************************************************************
	> File Name: 523.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 08时16分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 1, j = 1; i <= n;) {
        if(sum + i < n) {
            sum += i;
            i++;
        } else if(sum + i > n) {
            sum -= j;
            j++;
        } else if(sum + i == n) {
            for(int k = j; k <= i; k++) {
                if(k == j) cout << k;
                else cout << " " << k;
            }
            cout << endl;
            break;
        }
    }

    return 0;
}
