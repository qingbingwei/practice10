#include "contact.h"
//ͨѶ¼
//����
//��̬�汾
int main()
{
    //�˵���Ϣ
    //����
    //����
    //�Ա�
    //�绰
    //��ַ
    //����
    //1.���100����
    //2.������ϵ��
    //3.ɾ��ָ����ϵ��
    //4.������ϵ��
    //5.�޸���ϵ��
    //6.����
    //7.��ʾ��ϵ��

    Contact con;//ͨѶ¼
    //��ʼ��ͨѶ¼
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
