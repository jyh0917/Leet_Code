//
// Created by 32585 on 2024/1/22.
//
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //遍历每两组数
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i] + nums[j] == target){
                //创建空间
                int*result = (int*)malloc(sizeof(int)*2);
                //返回下标
                result[0] = i;
                result[1] = j;
                //返回returnSize
                *returnSize = 2;
                //结束程序
                return result;
            }
        }
    }
    *returnSize = 0;
    return 0;
}