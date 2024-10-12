#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inv(int *x, int n) // 逆置数组
{
    int* l = x, *r = x + n - 1; // 双指针
    while (l < r)
    {
        int tmp = *l; // 前后交换
        *l = *r;
        *r = tmp;
        l++;
        r--;
    }
}

char *seaBackStr(char *str, char *s)
{
    int len = strlen(str); // 字符串长度
    char *ans = (char *)malloc(len);
    if (ans == NULL)
    {
        perror("malloc failed");
        exit(1);
    }
    int slen = strlen(s);    // 子串长度
    int l = 0, r = slen - 1; // 滑动窗口
    while (r < len)
    {
        int flag = 1;
        for (int i = l; i <= r; i++) // 对比
        {
            if (str[i] != s[i - l]) // 字符不相同
            {
                flag = 0;
                break;
            }
        }
        if (flag) // 找到相同子串
        {
            ans = str + r + 1; // 子串位置后面的字符串的首地址
            return ans;
        }
        l++, r++; // 窗口向后滑动
    }
    return NULL; // 没找到
}

void OddEvenArrange(int a[], int n) // 奇偶排列
{
    int* l = a, *r = a + n - 1; // 还是双指针
    while (l < r)
    {
        if (*l % 2 == 0 && *r % 2 == 1) // 左边偶数，右边奇数
        {
            // 交换
            int tmp = *l;
            *l = *r;
            *r = tmp;
            l++, r--;
        }
        while (*l % 2 == 1 && l < a + n) // 左边奇数，l向后
            l++;
        while (*r % 2 == 0 && r >= a) // 右边偶数，r向前
            r--;
    }
}

int main()
{
    // 逆置数组
    int a1[6] = {1, 2, 3, 4, 5, 6};
    inv(a1, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");

    // 查找子串
    char *str = "Data Structure";
    char *s = "Stru";
    char *ret = seaBackStr(str, s);
    printf("%s\n", ret);

    int a2[7] = {2, 4, 6, 8, 1, 3, 5};
    OddEvenArrange(a2, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a2[i]);
    }

    return 0;
}