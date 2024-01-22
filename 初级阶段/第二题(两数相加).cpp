//
// Created by 32585 on 2024/1/22.
//
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


//声明
void init_Link(struct ListNode*&L);
void init_Link_with_input(struct ListNode*&L,int *input,int len);
void print_Link(struct ListNode*L);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
int main(){
    int array[] = {9,9,9,9,9,9,9};
    int arr[] = {9,9,9,9};
    struct ListNode*l1;
    struct ListNode*l2;
    struct ListNode*l3;
    //初始化
    init_Link(l1);
    init_Link(l2);
    init_Link(l3);
    //初始化数据
    init_Link_with_input(l1,array,sizeof(array)/sizeof(int));
    init_Link_with_input(l2,arr,sizeof(arr)/sizeof(int));
    //打印
    print_Link(l1);
    print_Link(l2);
    //相加
    l3 = addTwoNumbers(l1,l2);
    //打印
    print_Link(l3);
}

//初始化
void init_Link(struct ListNode*&L){
    L = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(L == NULL){
        printf("mallo error\n");
        exit(1);
    }
    L->val = 0;
    L->next = NULL;
    return ;
}

//用输入值初始化链表
void init_Link_with_input(struct ListNode*&L,int *input,int len){
    struct ListNode*p = L;
    /*
    int len = sizeof(input)/sizeof(input[0]);
    printf("input = %d\n",sizeof(input)/sizeof(int));
    */

    //头节点
    p->val = input[0];
    p->next = NULL;
    for(int i = 1;i < len;i++){
        struct ListNode*temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = input[i];
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
    return ;
}

//打印链表
void print_Link(struct ListNode*L){
    struct ListNode*p = L;
    while(p){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
    return ;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //结果链表
    struct ListNode*l3 =(struct ListNode*)malloc(sizeof(struct ListNode)) ;
    //处理异常
    if(!l3)return NULL;
    //l3初始化
    l3->val = 0;
    l3->next = NULL;

    //求和
    struct ListNode*p = l1;
    struct ListNode*q = l2;
    struct ListNode*r = l3;
    int flag = 0;
    //当两个链表都有值时
    while(q&&p){
        //赋值
        r->val = (p->val + q->val + flag)%10;
        if((p->val + q->val + flag)>=10){
            flag = 1;
        }else{
            flag = 0;
        }

        if(p->next&&q->next){
            //创建  下一位的空间   接到  新链表的末尾
            struct ListNode*Node =(struct ListNode*)malloc(sizeof(struct ListNode)) ;
            if(!Node)return NULL;
            r->next = Node;
            Node->next = NULL;
            Node->val = 0;
            //r指针后移
            r = Node;
        }else break;
        //有进位

        // l1 和 l2往下移动
        p = p->next,q = q->next;
    }


    //结束后p,q都在最短的最后一位


    //其他
    if((!p->next)&&(!q->next)){
        return l3;
    }
    else if(q->next){
        //后移r指针
        struct ListNode*Node =(struct ListNode*)malloc(sizeof(struct ListNode)) ;
        if(!Node)return NULL;
        r->next = Node;
        Node->next = NULL;
        Node->val = 0;
        //r指针后移
        r = Node;

        q = q->next;
        //把q接上
        while(q){
            r->val = (q->val + flag)%10;
            //有进位
            if((q->val + flag)>=10){
                flag = 1;
            }else{
                flag = 0;
            }
            if(q->next){
                //创建下一位的空间接到末尾
                struct ListNode*Node =(struct ListNode*)malloc(sizeof(struct ListNode)) ;
                r->next = Node;
                Node->next = NULL;
                r = Node;
                Node->val = 0;
            }else break;
            //移动指针
            q = q->next;
        }
        //最后还有一个flag
        if(flag == 1){
            struct ListNode*Node = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
            r->next = Node;
            Node->next = NULL;
            r = Node;
            Node->val = 1;
        }
    }
    else if(p->next){

        //后移r指针
        struct ListNode*Node =(struct ListNode*)malloc(sizeof(struct ListNode)) ;
        if(!Node)return NULL;
        r->next = Node;
        Node->next = NULL;
        Node->val = 0;
        //r指针后移
        r = Node;

        p = p->next;
        //把p接上
        while(p){
            r->val = (p->val + flag)%10;
            //有进位
            if((p->val + flag)>=10){
                flag = 1;
            }else{
                flag = 0;
            }
            //创建下一位的空间接到末尾
            if(p->next){
                struct ListNode*Node = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
                r->next = Node;
                Node->next = NULL;
                r = Node;
                Node->val = 0;
            }else break;
            //移动指针
            p = p->next;
        }
        //最后还有一个flag
        if(flag == 1){
            struct ListNode*Node = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
            r->next = Node;
            Node->next = NULL;
            r = Node;
            Node->val = 1;
        }
    }
    return l3;
}