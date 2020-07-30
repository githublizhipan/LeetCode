/*************************************************************************
	> File Name: 88.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时42分19秒
 ************************************************************************/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0, j = 0, k = 0;
    while(i < m || j < n) {
        if(i < m && (j >= n || nums1[i] <= nums2[j])) {
            nums1[k] = nums1[i];
            i++;
        } else {
            nums1[k] = nums2[j];
            j++;
        }
        k++;
    }
    return ;
}
