//
// Created by 38016 on 2023/8/19.
//
//�������
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#ifndef PHONELIST_CONTACT_H
#define PHONELIST_CONTACT_H
#endif //PHONELIST_CONTACT_H
#define MAX 100
#define MAX_NAME 20  //������Ĵ�С
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
//ͨѶ¼��Ϣ
typedef struct Contact
{
    Peo date[MAX];
    int count;//��¼��ǰͨѶ¼�˵ĸ���
}Contact;
void InitContact(Contact* pc);  //��ʼ��ͨѶ¼

void AddContact(Contact* pc);   //������ϵ����Ϣ
void ShowContact(const Contact* pc);  //��ʾ��ϵ����Ϣ
void DelContact(Contact* pc);   //ɾ����ϵ����Ϣ
int FindByname(Contact* pc,char name[MAX_NAME]); //������ϵ����Ϣ
void SearchContact(const Contact* pc);  //������ϵ����Ϣ
void ModifyContact(Contact* pc);  //�޸���ϵ����Ϣ
void SortContact(Contact* pc);  //������ϵ����Ϣ
int cmp_peo_by_name(const void* e1,const void* e2); //�ȽϺ���








