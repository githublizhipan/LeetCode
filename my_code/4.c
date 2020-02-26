/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时23分00秒
 ************************************************************************/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *num = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    int i = 0, j = 0, k = 0;
    while(i < nums1Size || j < nums2Size) {
        if(i < nums1Size && (j >= nums2Size || nums1[i] < nums2[j])) {
            num[k++] = nums1[i++];
        } else num[k++] = nums2[j++];
    }
    int l = nums1Size + nums2Size;
    if(l & 1) {
        return num[l >> 1] * 1.0;
    } else {
        return (num[l >> 1] + num[(l >> 1) - 1]) / 2.0;
    }
}
