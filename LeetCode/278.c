/*************************************************************************
	> File Name: 278.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 22时30分17秒
 ************************************************************************/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long l = 1, r = n, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(isBadVersion(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
