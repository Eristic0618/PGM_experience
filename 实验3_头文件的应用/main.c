#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    STinfo **arr = (STinfo **)malloc(sizeof(STinfo*) * 10); 
    size_t size = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("开始录入第%d个学生信息...\n", i + 1);
        STinfo *pst = (STinfo *)malloc(sizeof(STinfo));
        STinput(arr, pst, &size);
    }

    printf("\n开始打印学生信息...\n");
    printf("学号 姓名 物理分数 外语分数 数学分数\n");
    for (int i = 0; i < size; i++)
    {
        STprint(arr, i, size);
    }

    printf("\n开始统计学生信息...\n");
    STstatistics(arr, size);
    return 0;
}