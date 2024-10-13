#include "SList.h"
#include <unistd.h>

void AddInfo(SList *sl) // 增加职工信息
{
    Info info;

    printf("请输入职工编号 姓名 部门号 工资数:");
    scanf("%lld %s %d %d", &info.no_, info.name_, &info.depno_, &info.salary_); // 输入信息

    SListInsert(sl, sl->size + 1, info);  // 尾插
}

void PrintInfo(SList *sl) // 显示所有职工信息
{
    if (SListIsEmpty(sl))
    {
        printf("信息系统为空！\n\n");
        return;
    }

    Info **arr;
    SListOutput(sl, &arr); // 获取链表元素

    printf("所有职工信息如下:\n");
    printf("职工编号 职工姓名 部门号 工资\n");
    for (int i = 0; i < sl->size; i++) // 遍历并打印
    {
        printf("%lld %s %d %d\n", arr[i]->no_, arr[i]->name_, arr[i]->depno_, arr[i]->salary_);
    }
    printf("\n");
}

void PrintDepInfo(SList *sl) // 显示指定部门的职工信息
{
    if (SListIsEmpty(sl))
    {
        printf("信息系统为空！\n\n");
        return;
    }

    int dep;
    printf("请输入要显示的部门:");
    scanf("%d", &dep);

    Info **arr;
    SListOutput(sl, &arr); // 获取链表元素

    int flag = 0;          // 标志位
    for (int i = 0; i < sl->size; i++)
    {
        if (arr[i]->depno_ == dep) // 查找对应部门并输出信息
        {
            if (flag == 0) // 第一次查找成功才打印，后续不需要打印
            {
                printf("%d号部门职工信息如下:\n", dep);
                printf("职工编号 职工姓名 部门号 工资\n");
            }
            printf("%lld %s %d %d\n", arr[i]->no_, arr[i]->name_, arr[i]->depno_, arr[i]->salary_);
            flag = 1; // 修改标志位
        }
    }

    if (flag == 0)
        printf("该部门不存在！\n");
    printf("\n");
}

void DeleteInfo(SList *sl) // 删除指定职工号的职工信息
{
    if (SListIsEmpty(sl))
    {
        printf("信息系统为空！\n\n");
        return;
    }

    long long no;
    printf("请输入要删除的职工号:");
    scanf("%lld", &no);

    Info **arr;
    SListOutput(sl, &arr); // 获取链表元素
    int pos = 0;
    int flag = 0;

    for (int i = 0; i < sl->size; i++)
    {
        if (arr[i]->no_ == no) // 查找指定职工号
        {
            pos = i + 1; // 保存位置
            flag = 1;
        }
    }

    if (flag)
    {
        SListErase(sl, pos); // 删除对应位置的节点
        printf("删除成功！\n\n");
    }
    else
        printf("未查找到对应职工信息\n\n");
}

void DeleteAllInfo(SList *sl) // 删除所有职工信息
{
    if (SListIsEmpty(sl))
    {
        printf("信息系统为空！\n\n");
        return;
    }

    int n = sl->size;
    for (int i = 1; i <= n; i++) // 遍历
    {
        SListErase(sl, 1); // 头删n次即可
    }
    printf("删除成功！\n\n");
}

void FindByName(SList *sl) // 按照姓名查找职工信息
{
    if (SListIsEmpty(sl))
    {
        printf("信息系统为空！\n\n");
        return;
    }

    char name[15];
    printf("请输入需要查找的姓名:");
    scanf("%s", name);

    Info **arr;
    SListOutput(sl, &arr); // 获取链表元素

    int flag = 0;
    for (int i = 0; i < sl->size; i++)
    {
        if (strcmp(arr[i]->name_, name) == 0) // 查找成功
        {
            if(flag == 0)
            {
                printf("查找结果如下:\n");
                printf("职工编号 职工姓名 部门号 工资\n");
            }
            printf("%lld %s %d %d\n", arr[i]->no_, arr[i]->name_, arr[i]->depno_, arr[i]->salary_);
            flag = 1;
        }
    }

    if(flag == 0)
        printf("职工不存在！\n");
    printf("\n");
}

void FuzzyFindByName(SList* sl) //按照姓名模糊查找职工信息（关键字查找）
{
    if (SListIsEmpty(sl))
    {
        printf("信息系统为空！\n\n");
        return;
    }

    char name[15];
    printf("请输入需要查找的姓名关键字:");
    scanf("%s", name);

    Info **arr;
    SListOutput(sl, &arr); // 获取链表元素

    int flag = 0;
    for (int i = 0; i < sl->size; i++)
    {
        if (strstr(arr[i]->name_, name) != NULL) // 查找成功
        {
            if(flag == 0)
            {
                printf("模糊查找结果如下:\n");
                printf("职工编号 职工姓名 部门号 工资\n");
            }
            printf("%lld %s %d %d\n", arr[i]->no_, arr[i]->name_, arr[i]->depno_, arr[i]->salary_);
            flag = 1;
        }
    }

    if(flag == 0)
        printf("模糊查找结果为空！\n");
    printf("\n");
}

void FindBySalary(SList *sl) //按照工资范围查找职工信息
{
    if (SListIsEmpty(sl))
    {
        printf("信息系统为空！\n\n");
        return;
    }

    int upper, lower;
    printf("请输入要查找的工资上下限:");
    scanf("%d %d", &upper, &lower);

    Info **arr;
    SListOutput(sl, &arr); // 获取链表元素

    int flag = 0;
    for (int i = 0; i < sl->size; i++)
    {
        if(arr[i]->salary_ >= upper && arr[i]->salary_ <= lower)
        {
            if(flag == 0)
            {
                printf("查找结果如下:\n");
                printf("职工编号 职工姓名 部门号 工资\n");
            }
            printf("%lld %s %d %d\n", arr[i]->no_, arr[i]->name_, arr[i]->depno_, arr[i]->salary_);
            flag = 1;
        }
    }

    if(flag == 0)
        printf("没有符合要求的职工\n");
    printf("\n");
}

int PartSort(DataType** a, int left, int right) //hoare版本单趟排序
{
    //left从待排序序列头部向后走，right从待排序序列尾部向前走
	int key = left; //将待排序序列的第一个元素作为key值
	while (left < right) //left小于right说明单趟排序没结束
	{
		while (left < right && a[right]->salary_ >= a[key]->salary_) //right位置的值不比key小时向前走
		{
			right--;
		}
		while (left < right && a[left]->salary_ <= a[key]->salary_) //left位置的值不比key大时向后走
		{
			left++;
		}
		DataType* tmp = a[left]; //此时right位置的值比key小，left位置的值比key大
		a[left] = a[right]; //二者交换
		a[right] = tmp;
	}
	DataType* tmp = a[key]; //把序列头部作为key值的元素交换到left位置，完成单趟排序
	a[key] = a[left];
	a[left] = tmp;
	return left; //返回left位置存放的key值
}

void QuickSort(DataType** a, int left, int right) //快排
{
	if (left >= right)
		return;
	int key = PartSort(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}

SList* SortBySalary(SList* sl) //按照工资进行递增排序并新建有序列表
{
    if (SListIsEmpty(sl))
    {
        printf("信息系统为空！\n\n");
        return NULL;
    }

    Info **arr;
    SListOutput(sl, &arr); // 获取链表元素

    SList *psl = (SList *)malloc(sizeof(SList)); //创建新链表
    if(psl == NULL)
    {
        perror("malloc failed");
        return NULL;
    }
    SListInit(psl); //初始化链表

    QuickSort(arr, 0, sl->size - 1); //从小到大快排

    for (int i = sl->size - 1; i >= 0; i--) //从后向前遍历
    {
        SListInsert(psl, 1, *(arr[i])); //头插
    }
    printf("排序成功！\n");

    return psl;
}

void Menu()
{
    printf("---------------职工信息管理系统---------------\n");
    printf("----1.增加信息 2.显示所有信息 3.显示指定部门----\n");
    printf("----4.删除信息 5.删除所有信息 6.按姓名查找------\n");
    printf("----7.模糊查找 8.按工资查找   9.按工资排序------\n");
    printf("----0.退出     ------------------------------\n");
}

void InfoSystem()
{
    SList sl;
    SListInit(&sl);
    int op = -1;
    do
    {    
        Menu();
        printf("请选择：");
        scanf("%d", &op);
        system("cls"); // 清屏
        switch (op)
        {
        case 1:
            AddInfo(&sl);
            break;
        case 2:
            PrintInfo(&sl);
            break;
        case 3:
            PrintDepInfo(&sl);
            break;
        case 4:
            DeleteInfo(&sl);
            break;
        case 5:
            DeleteAllInfo(&sl);
            break;
        case 6:
            FindByName(&sl);
            break;
        case 7:
            FuzzyFindByName(&sl);
            break;
        case 8:
            FindBySalary(&sl);
            break;
        case 9:
        {
            SList* tmp = SortBySalary(&sl);
            memcpy(&sl, tmp, sizeof(SList));
            break;
        }
        case 0:
            printf("正在退出...\n");
            break;
        default:
            printf("非法操作，请重新输入\n");
            break;
        }
    } while (op);
}

int main()
{
    // SList sl;
    // SListInit(&sl);
    // for (int i = 0; i < 4; i++)
    // {
    //     AddInfo(&sl); // 增加职工信息
    // }
    // PrintInfo(&sl); // 显示所有职工信息
    // PrintDepInfo(&sl); // 显示指定部门的职工信息
    // DeleteInfo(&sl); // 删除指定职工号的职工信息
    // PrintInfo(&sl);

    // FindByName(&sl); // 按照姓名查找职工信息

    // FuzzyFindByName(&sl); //按照姓名模糊查找职工信息（关键字查找）

    // FindBySalary(&sl); //按照工资范围查找职工信息

    // SList* psl = SortBySalary(&sl); //按照工资进行递增排序并新建有序列表
    // PrintInfo(psl);

    // DeleteAllInfo(&sl); // 删除所有职工信息
    // PrintInfo(&sl);

    InfoSystem();

    return 0;
}
