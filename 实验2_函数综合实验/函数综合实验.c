#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

float area(float r)
{
    float pi = 3.14;
    float s = pi * r * r;
    return s;
}

int isprime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int* primeNum(int l, int r) 
{
    assert(l >= 0 && l < r);
    int maxSize = r - l + 1;
    int* aNum = (int*)malloc(sizeof(int) * maxSize);
    aNum[0] = 0;
    for (int i = l; i <= r; i++)
    {
        if (isprime(i))
        {
            aNum[aNum[0] + 1] = i;
            aNum[0]++;
        }
    }
    return aNum;
}

char* inverseStr(char* str)
{
    int len = strlen(str);
    int n = 0;
    char *tmp = (char *)malloc(len + 1);
    for (int i = len - 1; i >= 0; i--)
    {
        tmp[n] = str[i];
        n++;
    }
    tmp[n] = '\0';
    return tmp;
}

int main()
{
    printf("#��Բ�����#\n");
    float r1, r2;
    printf("�������⻷�뾶: ");
    scanf("%f", &r1);
    printf("�������ڻ��뾶: ");
    scanf("%f", &r2);
    if(r1 <= r2)
    {
        printf("���ݷǷ�\n");
        return 0;
    }
    float fs = area(r1) - area(r2);
    printf("Բ�����Ϊ: %f\n\n", fs);

    printf("#������#\n");
    int* prime = primeNum(1, 100);
    int sum = 0;
    for (int i = 1; i <= prime[0]; i++)
    {
        sum += prime[i];
    }
    printf("���������ĺ�Ϊ: %d\n\n", sum);

    printf("#�������#\n");
    char *aStr = "abcde";
    int len = strlen(aStr);
    char *aMS = (char*)malloc(len * 2 + 1);
    strcpy(aMS, aStr);
    aStr = inverseStr(aStr);
    aMS = strcat(aMS, aStr);
    printf("���Ĵ�: %s\n", aMS);

    return 0;
}