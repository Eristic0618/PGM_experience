#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

void InputStr()
{
    const char *filename = "file1.txt";
    char *str = (char *)malloc(128);
    memset(str, 0, sizeof(str));
    FILE *wfp = fopen("file1.txt", "w"); //只写方式打开文件
    if (wfp != NULL)
    {
        for (int i = 0; i < 5; i++) //读入五个字符串
        {
            gets(str);
            str = strcat(str, "\n"); //字符串结尾加上\n
            fputs(str, wfp); //写入文件
        }
        fclose(wfp); //关闭文件
    }
    char buf[128];
    FILE *rfp = fopen("file1.txt", "r"); //只读方式打开文件
    if (rfp != NULL)
    {
        while (fgets(buf, sizeof(buf) - 1, rfp) != NULL) //读取文件
            printf("%s", buf);
        fclose(rfp); //关闭文件
    }
}

typedef struct StuInfo
{
    long long id_;  // 学号
    char name_[15]; // 姓名
    float score_;   // 成绩
} StuInfo;

void save(StuInfo arr[], int n)
{
    FILE *fp = fopen("file2.dat", "wb+"); //读写二进制
    if (fp != NULL)
    {
        for (int i = 0; i < n; i++) //遍历数组
        {
            fwrite(&(arr[i]), sizeof(StuInfo), 1, fp); //写入
        }
        fclose(fp);
    }
}

void print(const char* path)
{
    FILE *fp = fopen(path, "rb+"); //读写二进制
    if(fp != NULL)
    {
        StuInfo s;
        memset(&s, 0, sizeof(s));
        while(1) //若fread返回0说明读取完毕
        {
            fread(&s, sizeof(StuInfo), 1, fp);
            if(feof(fp))
                break;
            printf("%lld %s %f\n", s.id_, s.name_, s.score_); //打印
        }
        fclose(fp);
    }
}



int main()
{
    InputStr();

    StuInfo arr[SIZE] = {{1, "张三", 90}, {2, "李四", 80}, {3, "王五", 95}, {4, "小刘", 85.5}, {5, "小何", 76.5}, {6, "小周", 56}, {7, "小林", 100}};
    save(arr, SIZE);
    print("file2.dat");

    FILE *rfp = fopen("file2.dat", "rb");
    if(rfp == NULL)
    {
        perror("fopen failed");
        exit(1);
    }
    FILE *wfp = fopen("file3.dat", "wb");
    if(wfp == NULL)
    {
        perror("fopen failed");
        exit(1);
    }
    int idx = 1;
    while(1)
    {
        if(idx % 2 == 1) //奇数编号
        {
            StuInfo s;
            memset(&s, 0, sizeof(s));
            fread(&s, sizeof(StuInfo), 1, rfp);
            if(feof(rfp))
                break;
            fwrite(&s, sizeof(StuInfo), 1, wfp);
        }
        else
        {
            fseek(rfp, sizeof(StuInfo), SEEK_CUR);
        }
        idx++;
    }
    fclose(rfp);    
    fclose(wfp);
    print("file3.dat");

    return 0;
}