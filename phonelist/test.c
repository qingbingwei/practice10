#include "contact.h"
//通讯录
//测试
//静态版本
int main()
{
    //人的信息
    //姓名
    //年龄
    //性别
    //电话
    //地址
    //功能
    //1.存放100个人
    //2.增加联系人
    //3.删除指定联系人
    //4.查找联系人
    //5.修改联系人
    //6.排序
    //7.显示联系人

    Contact con;//通讯录
    //初始化通讯录
    InitContact(&con);

    int input = 0;
    do
    {
        menu();
        printf("please choose:>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                AddContact(&con);
                break;
            case 2:
                DelContact(&con);
                break;
            case 3:
                SearchContact(&con);
                break;
            case 4:
                ModifyContact(&con);
                break;
            case 5:
                ShowContact(&con);
                break;
            case 6:
                SortContact(&con);
                break;
            case 0:
                break;
            default:
                printf("wrong\n");
                break;
        }

    } while (input);

    return 0;
}
