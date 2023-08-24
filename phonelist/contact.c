//
// Created by 38016 on 2023/8/19.
//
//����ʵ��
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
        scanf("%s",pc -> date[pc -> count].name);  //nameΪ������������ȡ��ַ
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
void ShowContact(const Contact* pc)  //��ֹ��Ϣ�����ģ�����const
{
    assert(pc);
    int i = 0;
    printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n","name","age","sex","tele","addr");  //�������ÿ�
    for (i = 0;i < pc -> count;i++)
    {
        printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",  pc -> date[i].name,
                                                       pc -> date[i].age,
                                                       pc -> date[i].sex,
                                                       pc -> date[i].tele,
                                                       pc -> date[i].addr) ; //��ӡ20λ�������ÿո���䣬\tΪˮƽ�Ʊ�����տ�����,������ע�⻻�У���ֱ��
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
    //1.����
    int pos = FindByname(pc,name);
    if(pos == -1)
    {
        printf("the people who you want to delete don't exist\n");
        return;
    }
    //2.ɾ��
    //������Ԫ����ǰ����
    for(i = pos;i < pc->count-1;i++)  //��һ��ֹԽ��(����100����Ϣʱ)
    {
        pc->date[i] = pc->date[i + 1];
    }
    pc->count--;  //���һ���޷����ǣ�������Ϊcount-1��Ҳ�޷����ʣ��൱��ɾ����
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
    //����
    int pos = FindByname(pc,name);
    if(pos == -1)
    {
        printf("the people who you want to search don't exist\n");
        return;
    }
    //�ҵ��ˣ���ӡ����
    printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n","name","age","sex","tele","addr");  //�������ÿ�
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
    //����
    if(pos == -1)
    {
        printf("the people who you want to modify don't exist\n");
        return;
    }
    //�޸�(����¼��һ��)
    printf("please scan name:>");
    scanf("%s",pc -> date[pos].name);  //nameΪ������������ȡ��ַ
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

//������������
void SortContact(Contact* pc)
{
    assert(pc);
    qsort(pc->date,pc->count,sizeof(Peo), cmp_peo_by_name);
    printf("sort success\n");
}

//�ȽϺ���
int cmp_peo_by_name(const void* e1,const void* e2)
{
    return strcmp(((Peo*)e1)->name,((Peo*)e2)->name);
}

