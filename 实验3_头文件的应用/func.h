#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct STinfo // 学生数据
{
    int _id;           // 学号
    char *_name;       // 姓名
    float _phy_score;  // 物理分数
    float _fl_score;   // 外语分数
    float _math_score; // 数学分数
} STinfo;

// 应实验要求，录入与显示函数只针对单条数据
void STinput(STinfo **arr, STinfo *x, size_t *n) // 每次录入一个学生记录
{
    int id;
    char *name = (char *)malloc(15);
    float phy_score;
    float fl_score;
    float math_score;
    printf("请输入学号: ");
    scanf("%d", &id);
    printf("请输入姓名: ");
    scanf("%s", name);
    printf("请输入物理分数: ");
    scanf("%f", &phy_score);
    printf("请输入外语分数: ");
    scanf("%f", &fl_score);
    printf("请输入数学分数: ");
    scanf("%f", &math_score);
    x->_id = id;
    x->_name = name;
    x->_phy_score = phy_score;
    x->_fl_score = fl_score;
    x->_math_score = math_score;
    arr[(*n)++] = x;
}

void STprint(STinfo **arr, size_t pos, size_t n) // 每次打印下标为pos的学生数据
{
    assert(pos >= 0 && pos < n);

    printf("%d %s %.2f %.2f %.2f\n", arr[pos]->_id, arr[pos]->_name,
           arr[pos]->_phy_score, arr[pos]->_fl_score, arr[pos]->_math_score);
}

void STstatistics(STinfo **arr, size_t n)
{
    int phy_fail = 0;   // 物理不及格人数
    int fl_fail = 0;    // 外语不及格人数
    int math_fail = 0;  // 数学不及格人数
    float phy_max = 0;  // 物理最高分
    float fl_max = 0;   // 外语最高分
    float math_max = 0; // 数学最高分
    int *tmp = (int *)malloc(sizeof(int) * n); //存放不及格学生下标
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0; //没有不及格科目
        if(arr[i]->_phy_score > phy_max) //更新物理最高分
            phy_max = arr[i]->_phy_score;
        if(arr[i]->_fl_score > fl_max) //更新外语最高分
            fl_max = arr[i]->_fl_score;
        if(arr[i]->_math_score > math_max) //更新数学最高分
            math_max = arr[i]->_math_score;
        if(arr[i]->_phy_score < 60)
        {
            phy_fail++;
            flag = 1;
        }
        if(arr[i]->_fl_score < 60)
        {
            fl_fail++;
            flag = 1;
        }
        if(arr[i]->_math_score < 60)
        {
            math_fail++;
            flag = 1;
        }
        if(flag)
            tmp[size++] = i;
    }
    printf("物理最高分: %f\n", phy_max);
    printf("外语最高分: %f\n", fl_max);
    printf("数学最高分: %f\n", math_max);
    printf("物理不及格人数: %d\n", phy_fail);
    printf("外语不及格人数: %d\n", fl_fail);
    printf("数学不及格人数: %d\n", math_fail);
    printf("不及格学生：\n");
    printf("学号 姓名 物理分数 外语分数 数学分数\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d %s %f %f %f\n", arr[tmp[i]]->_id, arr[tmp[i]]->_name,
           arr[tmp[i]]->_phy_score, arr[tmp[i]]->_fl_score, arr[tmp[i]]->_math_score);
    }
}
