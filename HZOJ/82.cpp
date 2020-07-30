/*************************************************************************
	> File Name: 82.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月02日 星期日 12时59分39秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define MAX 1000005
ll N, M, height[MAX], MAXh = 0, ans;

ll get_len(int mid) {
    ll sum = 0;
    for(int i = 1; i <= N; ++i) {
        if(height[i] <= mid) continue;

        sum += (height[i] - mid);
    }
    return sum;
}

ll binarysearch() {
    int left = 0, right = MAXh, mid;
    while(left <= right) {
        mid = (left + right) >> 1;

/*cout << "left:" << left << " " << "right:" << right << " " << "mid:" << mid << " " << "get_len:" << get_len(mid);
        cout << " " << "ans:" << ans << endl;
*/

        ll temp = get_len(mid);
        //if(temp >= M) ans = mid;
        if(temp >= M){
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    scanf("%lld%lld", &N, &M); 
    for(int i = 1; i <= N; ++i) {
        scanf("%lld", height + i);
        if(height[i] > MAXh) MAXh = height[i]; 
    }
    printf("%lld\n", binarysearch());
    return 0;
}
