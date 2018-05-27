/*
给定两个数组，写一个方法来计算它们的交集。

例如:
给定 nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2, 2].

注意：

   输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
   我们可以不考虑输出结果的顺序。
跟进:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果nums2的元素存储在磁盘上，内存是有限的，你不能一次加载所有的元素到内存中，你该怎么办？
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
int cmp(const void* a, const void* b){
    //return *(int *)a-*(int *)b;
    if (*(int*)a!=*(int*)b) return *(int*)a>*(int*)b?1:-1; 
    else return *((int*)a+1)>*((int*)b+1)?1:-1; 
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    int idx1=0,idx2=0;
    int* out=NULL;
    out = malloc(nums1Size * sizeof(int));
    *returnSize = 0;
    qsort(nums1,nums1Size,sizeof(int),cmp);
    qsort(nums2,nums2Size,sizeof(int),cmp);

    /*
    for(int i=0;i<nums1Size;i++)
        printf("%d ",nums1[i]);
    printf("\n");
    for(int i=0;i<nums2Size;i++)
        printf("%d ",nums2[i]);
    printf("\n");
    */

    while( (idx1<nums1Size) && (idx2<nums2Size)) {
        if(nums1[idx1] > nums2[idx2]){
            idx2++;
        }
        else if(nums1[idx1] < nums2[idx2]){
            idx1++;
        }
        else{
            out[*returnSize] = nums1[idx1];
            printf("out:%d,%d,%d,%d\n",out[*returnSize],*returnSize,idx1,idx2);
            *returnSize += 1;
            idx1++;
            idx2++;
        }
    }
    return out;
}

int main(){
    int a[5] = {-2147483648,1,2,3};
    int b[5] = {1,2,-2147483648,-2147483648};
    int len = 0;
    intersect(a,4,b,4,&len);
    //printf("len:%d\n",len);
    return 0;
}
