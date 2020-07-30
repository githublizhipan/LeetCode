/*************************************************************************
	> File Name: 503.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 21时47分26秒
 ************************************************************************/
#include <algorithm>
#include <iostream>
using namespace std;


int w, n, a[30005], ans = 0;

int main() {
    cin >> w >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    
    for(int i = 1, j = n; i <= j;) {
        if(i == j) {
            ans++;
            break;
        }

        if(a[i] + a[j] <= w) {
            //cout << a[i] << " " << a[j] << endl;
            i++;
            j--;
        } else {
            //cout << a[j] << endl;
            j--;
        }
        ans++;
    }
    //if(n % 2 == 1) ans++;
    cout << ans << endl;
    return 0;
}
