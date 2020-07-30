/*************************************************************************
	> File Name: 54.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 18时05分09秒
 ************************************************************************/
/*
#include <stdio.h>
#define max 1500
char str[10000];

void f(int x) {
    int ans[max + 5] = {0};
    ans[0] = 1, ans[1] = 1;
    for(int i = x; i >= 1; i--) {
        for(int j = 1; j <= ans[0]; j++) {
            ans[j] *= i;
        }
        for(int k = 1; k <= ans[0]; ++k) {
            if(ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10; 
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }
    }
    for(int i = ans[0]; i > 0; i--) {
        str[i] = ans[i] + '0';
        //printf("%d", ans[i]);
    }
    //printf("\n");
}


int main() {
    int x;
    while(scanf("%d", &x) != EOF) {
        f(x);
        printf("\n");
    }
    
    return 0;
}

*/

#include <stdio.h>
#include <string.h>
#define max 1500

int ans[max + 5];
int res[max + 5];
void solve(int x) {
    memset(ans, 0, sizeof(ans));
    ans[0] = 1; ans[1] = 1;
    for(int i = 1; i <= x; ++i) {
        for(int j = 1; j <= ans[0]; ++j) {
            ans[j] *= i;
        }
        for(int k = 1; k <= ans[0]; k++) {
            if(ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (ans[0] == k);
        }
        
    }
    memset(res, 0, sizeof(res));
    res[0] = 1, res[1] = 1;
    for(int i = 1; i <= ans[0]; ++i) {
        if(!ans[i]) continue;
        for(int j = 1; j <= res[0]; ++j) {
            res[j] *= ans[i];
        }
        for(int k = 1; k <= res[0]; ++k) {
            if(res[k] < 10) continue;
            res[k + 1] += res[k] / 10;
            res[k] %= 10；
            res[0] += (res[0] == k);
        }

    }
    for(int i = res[0]; i >= 1; i--) {
        printf("%d", res[i]);
    }
    printf("\n");

}

int main(){
    int x;
    while(scanf("%d", &x) != EOF) {
        solve(x);
    }
    return 0;
}
