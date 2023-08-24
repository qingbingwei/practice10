//
// Created by 38016 on 2023/8/19.
//
//功能实现
#include "contact.h"

void menu()
{
    printf("******************************************\n");
    printf("******** 1.add        2.del       ********\n");
    printf("******** 3.search     4.modify    ********\n");
    printf("******** 5.show       6.sort      ********\n");
    printf("******** 0.exit                   ********\n");
    printf("******************************************\n");
}
void InitContact(Contact* pc)
{
    assert(pc);
    pc -> count = 0;
    memset(pc -> date,0,sizeof(pc -> date));
}
void AddContact(Contact* pc)
{
    assert(pc);
    if(pc -> count == MAX)
        printf("full\n");
    else
    {
        printf("please scan name:>");
        scanf("%s",pc -> date[pc -> count].name);  //name为数组名，不用取地址
        printf("please scan age:>");
        scanf("%d",&(pc -> date[pc -> count].age));
        printf("please scan sex:>");
        scanf("%s",pc -> date[pc -> count].sex);
        printf("please scan tele:>");
        scanf("%s",pc -> date[pc -> count].tele);
        printf("please scan addr:>");
        scanf("%s",pc -> date[pc -> count].addr);

        pc -> count++;
        printf("success\n");
    }
}
void ShowContact(const Contact* pc)  //防止信息被更改，加上const
{
    assert(pc);
    int i = 0;
    printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n","name","age","sex","tele","addr");  //左对齐更好看
    for (i = 0;i < pc -> count;i++)
    {
        printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",  pc -> date[i].name,
                                                       pc -> date[i].age,
                                                       pc -> date[i].sex,
                                                       pc -> date[i].tele,
                                                       pc -> date[i].addr) ; //打印20位，不足用空格填充，\t为水平制表符，空开距离,长代码注意换行，更直观
    }
}

void DelContact(Contact* pc)
{
    int i = 0;
    char name[MAX_NAME];
    assert(pc);
    printf("please scan name:>");
    if(pc -> count == 0)
    {
        printf("empty,nothing to delete");
        return;
    }

    scanf("%s",name);
    //1.查找
    int pos = FindByname(pc,name);
    if(pos == -1)
    {
        printf("the people who you want to delete don't exist\n");
        return;
    }
    //2.删除
    //将后面元素向前覆盖
    for(i = pos;i < pc->count-1;i++)  //减一防止越界(放入100条信息时)
    {
        pc->date[i] = pc->date[i + 1];
    }
    pc->count--;  //最后一个无法覆盖，但是因为count-1，也无法访问，相当于删除了
    printf("success\n");
}

int FindByname(Contact* pc,char name[MAX_NAME])
{
    assert(pc);
    int i = 0;
    for(i = 0;i < pc -> count;i++)
    {
        if(0 == strcmp(pc->date[i].name,name))
        {
            return i;
        }

    }
    return -1;
}
void SearchContact(const Contact* pc)
{
    assert(pc);
    char name[MAX_NAME];
    printf("please scan name:>");
    scanf("%s",name);
    //查找
    int pos = FindByname(pc,name);
    if(pos == -1)
    {
        printf("the people who you want to search don't exist\n");
        return;
    }
    //找到了，打印数据
    printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n","name","age","sex","tele","addr");  //左对齐更好看
    printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",  pc -> date[pos].name,
               pc -> date[pos].age,
               pc -> date[pos].sex,
               pc -> date[pos].tele,
               pc -> date[pos].addr) ;
}
void ModifyContact(Contact* pc)
{
    assert(pc);
    char name[MAX_NAME];
    printf("please scan name you want to modify:>");
    scanf("%s",name);
    int pos = FindByname(pc,name);
    //查找
    if(pos == -1)
    {
        printf("the people who you want to modify don't exist\n");
        return;
    }
    //修改(重新录入一遍)
    printf("please scan name:>");
    scanf("%s",pc -> date[pos].name);  //name为数组名，不用取地址
    printf("please scan age:>");
    scanf("%d",&(pc -> date[pos].age));
    printf("please scan sex:>");
    scanf("%s",pc -> date[pos].sex);
    printf("please scan tele:>");
    scanf("%s",pc -> date[pos].tele);
    printf("please scan addr:>");
    scanf("%s",pc -> date[pos].addr);
    printf("success\n");
}

//按照名字排序
void SortContact(Contact* pc)
{
    assert(pc);
    qsort(pc->date,pc->count,sizeof(Peo), cmp_peo_by_name);
    printf("sort success\n");
}

//比较函数
int cmp_peo_by_name(const void* e1,const void* e2)
{
    return strcmp(((Peo*)e1)->name,((Peo*)e2)->name);
}

