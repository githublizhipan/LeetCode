/*************************************************************************
	> File Name: 476.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 22时00分49秒
 ************************************************************************/
#include <string>
#include <cstring>
#include<iostream>
using namespace std;
#define MAX 100000

int main() {
    int m[MAX] = {0}, n[MAX] = {0}, ans[MAX] = {0}, cnt = 0;
    string N, M;
    cin >> N >> M;
    for(int i = 0; i < N.size(); i++) {
        n[i] = N[N.size() - i - 1] - '0';
    }
    
    /*
    for(int i = 0; i < N.size(); i++) {
        cout << n[i];
    }
    cout << "\n";
    cout << "N.size: " << N.size() << ";     M.size:" << M.size() << endl;
    */

    while(M.size() > N.size() || M > N) {
        
        for(int i = 0; i < M.size(); i++) {
            m[i] = M[M.size() - i - 1] - '0';
        }
        for(int i = 0; i < M.size(); i++) {
            ans[i] = m[i] - n[i];
        }
        for(int i = 0; i < M.size(); i++) {
            if(ans[i] >= 0) continue;
            ans[i] += 10;
            ans[i + 1] -= 1;
        }
        int l = M.size() - 1;
        M.clear();
        while(!ans[l]) l--; 
        for(int i = l; i >= 0; i--) {
            M.push_back(ans[i] + '0');
        }
        memset(m, 0, sizeof(m));
        cnt++;
    }
    cout << cnt << endl;
    //cout << M << endl;
    return 0;
}
