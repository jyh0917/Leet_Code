double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum = nums1Size + nums2Size;
    int array[sum];
    //循环存储数组
    int *p = nums1;
    int *q = nums2;
    int len1 = 0;
    int len2 = 0;
    int size = 0;
    //p,q都存在
    while(len1!=nums1Size&&len2!=nums2Size){
        if(*p>=*q){
            array[size] = *q;
            q++;
            len2++;
        }else{
            array[size] = *p;
            p++;
            len1++;
        }
        size++;
    }
    if(len1!=nums1Size){
        while(len1!=nums1Size){
            array[size] = *p;
            size++;
            p++;
            len1++;
        }
    }
    else if(len2!=nums2Size){
        while(len2!=nums2Size){
            array[size] = *q;
            size++;
            q++;
            len2++;
        }
    }
    //返回结果
    double result = 0;
    if(size%2){
        //奇数个
        result = array[size/2];
    }else{
        //偶数个
        result = (array[size/2 - 1] + array[size/2])/2.0;
    }
    return result;
}