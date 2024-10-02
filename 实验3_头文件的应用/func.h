#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct STinfo // ѧ������
{
    int _id;           // ѧ��
    char *_name;       // ����
    float _phy_score;  // �������
    float _fl_score;   // �������
    float _math_score; // ��ѧ����
} STinfo;

// Ӧʵ��Ҫ��¼������ʾ����ֻ��Ե�������
void STinput(STinfo **arr, STinfo *x, size_t *n) // ÿ��¼��һ��ѧ����¼
{
    int id;
    char *name = (char *)malloc(15);
    float phy_score;
    float fl_score;
    float math_score;
    printf("������ѧ��: ");
    scanf("%d", &id);
    printf("����������: ");
    scanf("%s", name);
    printf("�������������: ");
    scanf("%f", &phy_score);
    printf("�������������: ");
    scanf("%f", &fl_score);
    printf("��������ѧ����: ");
    scanf("%f", &math_score);
    x->_id = id;
    x->_name = name;
    x->_phy_score = phy_score;
    x->_fl_score = fl_score;
    x->_math_score = math_score;
    arr[(*n)++] = x;
}

void STprint(STinfo **arr, size_t pos, size_t n) // ÿ�δ�ӡ�±�Ϊpos��ѧ������
{
    assert(pos >= 0 && pos < n);

    printf("%d %s %.2f %.2f %.2f\n", arr[pos]->_id, arr[pos]->_name,
           arr[pos]->_phy_score, arr[pos]->_fl_score, arr[pos]->_math_score);
}

void STstatistics(STinfo **arr, size_t n)
{
    int phy_fail = 0;   // ������������
    int fl_fail = 0;    // ���ﲻ��������
    int math_fail = 0;  // ��ѧ����������
    float phy_max = 0;  // ������߷�
    float fl_max = 0;   // ������߷�
    float math_max = 0; // ��ѧ��߷�
    int *tmp = (int *)malloc(sizeof(int) * n); //��Ų�����ѧ���±�
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0; //û�в������Ŀ
        if(arr[i]->_phy_score > phy_max) //����������߷�
            phy_max = arr[i]->_phy_score;
        if(arr[i]->_fl_score > fl_max) //����������߷�
            fl_max = arr[i]->_fl_score;
        if(arr[i]->_math_score > math_max) //������ѧ��߷�
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
    printf("������߷�: %f\n", phy_max);
    printf("������߷�: %f\n", fl_max);
    printf("��ѧ��߷�: %f\n", math_max);
    printf("������������: %d\n", phy_fail);
    printf("���ﲻ��������: %d\n", fl_fail);
    printf("��ѧ����������: %d\n", math_fail);
    printf("������ѧ����\n");
    printf("ѧ�� ���� ������� ������� ��ѧ����\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d %s %f %f %f\n", arr[tmp[i]]->_id, arr[tmp[i]]->_name,
           arr[tmp[i]]->_phy_score, arr[tmp[i]]->_fl_score, arr[tmp[i]]->_math_score);
    }
}
