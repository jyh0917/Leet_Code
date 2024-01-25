//
// Created by 32585 on 2024/1/23.
//
#include<stdio.h>
int lengthOfLongestSubstring(char* s);
int main(){
    char*ch = "abcabcbb";
    int result = lengthOfLongestSubstring(ch);
    printf("len = %d\n",result);
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int maxLen = 0;

    //p表示字符串头
    char*p = s;
    if(!p){
        return 0;
    }
    //q移动
    char*q = p++;
    if(!q){
        return 1;
    }

    while(q){
        int count = 1;
        //检查这个 q 元素是否和之前的元素有相同的
        char*r1 = p;
        int flag = 0;
        while(r1!=q&&flag!=1){
            if(*r1!=*q){
                r1++;
            }else
                flag = 1;
        }
        if(flag==0){
            count++;
        }else{
            if(count>maxLen)
                maxLen = count;
            //这个元素与之前的 r1 相同
            p = ++r1;
        }
        if(++p){
            q = p;
        }else
            return maxLen;

    }
    return maxLen;
}