#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct Info
{
    long long no_; //职工编号
    char name_[15]; //职工姓名
    int depno_; //部门号
    int salary_; //工资数
} Info;

typedef Info DataType;

typedef struct ListNode
{
    DataType val;
    struct ListNode *next;
} ListNode;

typedef struct SList
{
    int size;
    ListNode *head;
} SList;

void SListInit(SList* sl) //初始化单链表
{
    assert(sl);
    sl->head = (ListNode *)malloc(sizeof(ListNode));
    sl->size = 0; 
    sl->head->next = NULL;
}

void SListInsert(SList* sl, int pos, DataType x) //pos位置插入新节点(头节点位置为0)
{
    assert(sl);
    assert(pos >= 0 && pos <= sl->size + 1);
    ListNode *cur = sl->head;
    for (int i = 1; i < pos; i++) //遍历到pos位置
    {
        cur = cur->next;
    }

    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode)); //创建新节点
    if(newnode == NULL)
    {
        perror("malloc failed");
        return;
    }
    memcpy(&(newnode->val), &x, sizeof(DataType));
    //插入新节点
    newnode->next = cur->next; 
    cur->next = newnode;
    sl->size++; //更新节点个数
}

void SListErase(SList* sl, int pos) //删除pos位置节点
{
    assert(sl);
    assert(sl->size); //链表非空才能删
    assert(pos > 0 && pos <= sl->size);
    ListNode *prev = sl->head;
    ListNode *cur = prev->next;
    for (int i = 1; i < pos; i++) //遍历到pos位置
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next; //删除节点
    sl->size--; //更新节点个数
    free(cur); //释放节点空间
}

void SListOutput(SList* sl, DataType** arr[]) //输出所有元素
//为了方便后续管理系统的复用，这里采用输出型参数将所有元素输出，但因为要传出一个指针数组所以参数得是一个三级指针
{
    assert(sl);
    if(sl->size == 0)
    {
        printf("链表为空！\n");
        return;
    }
    DataType **a = (DataType **)malloc(sizeof(DataType *) * sl->size); //数组中保存元素的地址，方便在外部进行修改
    ListNode *cur = sl->head->next; //第一个节点
    int idx = 0;
    while(cur) //遍历链表
    {
        a[idx++] = &(cur->val); //存储链表中的元素地址
        cur = cur->next;
    }
    *arr = a;
}

bool SListIsEmpty(SList* sl) //判断链表是否为空
{
    assert(sl);
    return sl->size == 0;
}
