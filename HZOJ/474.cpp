/*************************************************************************
	> File Name: 474.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 10时06分03秒
 ************************************************************************/
#include <cstdio>
#include<iostream>
using namespace std;
int main() {
    int n;
    char key[110], c1, c2, c3, c4;
    int choose[5], ans[2000] = {0};
    ans[0] = ans[1] = 1;
    
    cin >> n >> key; 
    for(int i = 0; i < n; ++i) {
        scanf("%d%c %d%c %d%c %d%c", &choose[0], &c1, &choose[1], &c2, &choose[2], &c3, &choose[3], &c4);
        int t = choose[key[i] - 'A'];
       
        //cout << t << endl;

        for(int j = 1; j <= ans[0]; j++) {
            ans[j] *= t;
            //cout << ans[j] << " ";
        }
        for(int k = 1; k <= ans[0]; k++) {
            if(ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] = ans[k] % 10;
            ans[0] += (k == ans[0]);
        }
        
        //cout << ans[0] << endl;
        //for(int i = ans[0]; i >= 1; i--) cout << ans[i];
        //cout << endl;
    }
    int i = 1;
    while(ans[i] == 0) {
        i++;
        if(i > ans[0]) break;
    }
    //cout << ans[0] << " " << i << endl;
    if(ans[0] == i - 1) cout << 0 << endl;
    else if(ans[0] == 2 * n + 1) cout << 1 << endl;
    else { 
        ans[0] = 2 * n;
        cout << "0.";
        int j = 1;
        while(ans[j++] == 0);
        for(int i = ans[0]; i >= j - 1; i--) cout << ans[i];
        cout << endl;
    }
    return 0;
}
