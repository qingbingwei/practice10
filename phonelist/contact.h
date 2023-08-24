//
// Created by 38016 on 2023/8/19.
//
//相关声明
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#ifndef PHONELIST_CONTACT_H
#define PHONELIST_CONTACT_H
#endif //PHONELIST_CONTACT_H
#define MAX 100
#define MAX_NAME 20  //方便更改大小
#define MAX_SEX 100
#define MAX_TELE 100
#define MAX_ADDR 100


void menu();
typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}Peo;
//通讯录信息
typedef struct Contact
{
    Peo date[MAX];
    int count;//记录当前通讯录人的个数
}Contact;
void InitContact(Contact* pc);  //初始化通讯录

void AddContact(Contact* pc);   //增加联系人信息
void ShowContact(const Contact* pc);  //显示联系人信息
void DelContact(Contact* pc);   //删除联系人信息
int FindByname(Contact* pc,char name[MAX_NAME]); //查找联系人信息
void SearchContact(const Contact* pc);  //查找联系人信息
void ModifyContact(Contact* pc);  //修改联系人信息
void SortContact(Contact* pc);  //排序联系人信息
int cmp_peo_by_name(const void* e1,const void* e2); //比较函数








