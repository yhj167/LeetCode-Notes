/*数组：只出现一次的数字
* 思路3：数学算法：全部异或一遍
* 因为自己与自己 异或 =0
* 0和任意数 异或 还是任意数 
*/
int singleNumber(int* nums, int numsSize) {
    int i,result=0;
    for(i=0; i<numsSize; i++){
        result ^= nums[i];
    }
    return result;
}

/*数组：只出现一次的数字
* 思路2：先排序，然后2位间隔比较前后值是否相等
*/
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;//升序
}
int singleNumber(int* nums, int numsSize) {
    int i = 0;
     
	if(numsSize%2==0)
		return -1;

    qsort(nums,numsSize,sizeof(int),cmp);
	for(i = 0 ; i<numsSize; i=i+2)
        if(i==numsSize-1 || nums[i]!=nums[i+1] )
            break;
    return nums[i];
}

/*数组：只出现一次的数字
* 思路1：直接比较
*/
int singleNumber(int* nums, int numsSize) {
    int i,j;
    for(i=0; i<numsSize; i++){
        for(j=0; j<numsSize; j++){
            if(j!=i){
                if(nums[i] == nums[j])
                    break;
            }
        }
        if(j==numsSize)
            return nums[i];
    }
    return -1;
}
