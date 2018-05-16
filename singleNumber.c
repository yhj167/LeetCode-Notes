int singleNumber(int* nums, int numsSize) {
    int i,result=0;
    for(i=0; i<numsSize; i++){
        result ^= nums[i];
    }
    return result;
}


/*
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
*/
