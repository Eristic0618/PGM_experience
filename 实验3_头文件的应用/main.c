#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    STinfo **arr = (STinfo **)malloc(sizeof(STinfo*) * 10); 
    size_t size = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("��ʼ¼���%d��ѧ����Ϣ...\n", i + 1);
        STinfo *pst = (STinfo *)malloc(sizeof(STinfo));
        STinput(arr, pst, &size);
    }

    printf("\n��ʼ��ӡѧ����Ϣ...\n");
    printf("ѧ�� ���� ������� ������� ��ѧ����\n");
    for (int i = 0; i < size; i++)
    {
        STprint(arr, i, size);
    }

    printf("\n��ʼͳ��ѧ����Ϣ...\n");
    STstatistics(arr, size);
    return 0;
}