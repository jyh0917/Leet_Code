//
// Created by 32585 on 2024/1/25.
//
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;
    int choose = n%2;   //偶数choose = 0,奇数choose = 1;
    int *p = nums1;
    int *q = nums2;
    int count = 0;

    // n/2 偶数是两个的平均数
    //  n/2 奇数是中间的数
    int flag = 0;       //0选,1选p;选大的
    //奇数
    if(choose){

        //循环知道count = n/2;
        while(count!=n/2){
            if(*p<=*q){
                p++;
                count++;
                flag = 1;
            }else{
                q++;
                count++;
                flag = 0;
            }
        }
        //选择
        if(flag){
            return *q;
        }else
            return *p;
    }
        //偶数
    else{
        while(count!=(n/2)-1){
            if(*p<=*q){
                p++;
                count++;
            }else{
                q++;
                count++;
            }
        }
        double result = 0;
        result = (*p+*q)/2.0;
        return  result;
    }
}