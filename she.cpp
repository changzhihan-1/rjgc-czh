#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"conio.h"
void menus();
void newrecord();
void xiugai();
void shanchuname();
void chazhaoname();
void xianshi();
int daoruwenji();
void save();
void paixu();
struct friends
{
	char   name[8];
	char   addr[14];
	char   pc[7];
	char   e_mail[14];
	char   QQ[10];
	char   tel[12];
}frd[500];

int NO = 10;
int k, m;
FILE *fp;
void menu()  
{
	int a;
	printf("\n\t\t |-----------  ��ӭ��ʹ��ͨѶ¼����ϵͳ1.0beat�� ----------|");
	printf(" \n\t\t|    [1]�����ϵ��;[2]ɾ����ϵ�� ;[3]������ϵ��           |   ");
	printf(" \n\t\t|    [4]��ʾ��ϵ��;[5]�޸���ϵ�� ;[6]������ϵ�� [7]�˳�   |   ");
	printf("\n\t\t |---------------------------------------------------------|");
	printf("\n\t\t��ѡ��������Ҫ�ķ���");
	scanf("%d", &a);
	switch (a)
	{
	case 1:newrecord(); break;
	case 2:shanchuname(); break;
	case 3:chazhaoname(); break;
	case 4:xianshi(); break;
	case 5:xiugai(); break;
	case 6:paixu(); break;
	case 7:exit(0);
	default:
		exit(0);
	}
}
int main()    
{

	daoruwenji();
	while (1)      
	{
		menu();
	}
	return 0;
}
void xianshi()     
{
	int i;
	fp = fopen("jk0119.txt", "r");
	if (fp == 0)
	{
		printf("\n\n\n\n\t      �绰���ļ�������");
		exit(0);
	}
	printf("\n\n********************************��ӭʹ��ͨѶ¼*******************************************");
	printf("\n       ����     ��ַ       �ʱ�      e_mail          QQ       �ֻ���");
	for (i = 0; i < NO - k + m; i++)
	{

		fscanf(fp, "%s%s%s%s%s%s", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);
	}
	for (i = 0; i < NO - k + m; i++)
	{
		printf("\t\n%3d", i + 1);
		printf("%8s%14s%7s%14s%10s%12s", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);


	}
	printf("\n\n*****************************************************************************************");

}
int daoruwenji()    //�ж�ͨѶ¼�Ƿ�Ϊ�պ����Ϊ�վ��½�һ��txt�ı�
{
	if ((fp = fopen("jk0119.txt", "rb")) == 0)  //��jk0119.txt�ļ�
	{
		printf("\n\n\n\n\t      �绰���ļ�������");
		if ((fp = fopen("contact.txt", "wb")) == 0)//�ж��ļ��Ƿ�Ϊ��
		{
			printf("\n\t\t\t\t����ʧ��");
			exit(0);
		}
		else
		{
			printf("\n\t    �绰���ѽ���");
			printf("\n\t   ��������������˵�");
			getch();
			return(0);
		}
		exit(0);
	}

	fseek(fp, 0L, 2);//����ȡ�ļ���ָ�������ļ�ĩ��

	if (ftell(fp) > 0)//ͳ���ļ����ֽ��Ƿ�Ϊ0
	{
		rewind(fp);
		printf("\n\n\n\n\t \t\t\t\t      �ļ�����ɹ�");
		printf("\n\t\t\t\t \t    ��������������˵�");
		fclose(fp);
		getch();
		return(0);
	}
	printf("\n\n\n\n\t\t\t�ļ�����ɹ�");
	printf("\n\t\t\t�绰���ļ������κμ�¼");
	printf("\n\t\t\t��������������˵�");
	fclose(fp);
	getch();
	return(0);

}
void save()   //���޸ĵĺ������б��浽txt�ı���
{
	int i;
	if ((fp = fopen("jk0119.txt", "w")) == 0)
	{
		printf("\n\t\t\t\t��ʧ��");
	}
	for (i = 0; i < NO - k + m; i++)
	{
		fprintf(fp, "%s\t%14s%7s%14s%10s%12s\n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);  //��ӡ���ļ�����Ϣ
	}
	printf("\n\t   �����ļ��ɹ�   ");
	fclose(fp);
}
void newrecord()     //�½�һ���µ���ϵ��
{

	printf("\n\t\t******************��������ϵ����Ϣ************************");
	printf("\n\t\t     ������ϵ�˵�����         ");

	scanf("%s", &frd[NO - k + m].name);
	for (int i = 0; i < NO - k + m; i++)
	{
		if (strcmp(frd[NO].name, frd[i].name) == 0)
		{
			printf("\n\n\t�����ظ��������½���ϵ��");
			newrecord();
		}
	}
	printf("\n\t\t     ������ϵ�˵ĵ�ַ         ");
	scanf("%s", &frd[NO - k + m].addr);
	printf("\n\t\t     ������ϵ�˵��ʱ�         ");
	scanf("%s", &frd[NO - k + m].pc);
	printf("\n\t\t     ������ϵ�˵�e_mail       ");
	scanf("%s", &frd[NO - k + m].e_mail);
	printf("\n\t\t     ������ϵ�˵�QQ           ");
	scanf("%s", &frd[NO - k + m].QQ);
	printf("\n\t\t     ������ϵ�˵��ֻ�����     ");
	scanf("%s", &frd[NO - k + m].tel);
	if (strlen(frd[NO - k + m].tel) == 11)
	{
		printf("����ĵ绰����Ϸ�");
	}
	else
	{
		printf("����������11λ�Ϸ�������");
		scanf("%s", &frd[NO - k + m].tel);
	}
	m++;
	save();
	printf("    �Ƿ�����������ϵ��(y/n):      ");

	if (getch() == 'y')
	{
		newrecord();
	}

}
void shanchuname()    //����ϵ����Ϣ����ȫ����ɾ��
{
	int i, j;
	char name[14];
	printf("\n\t\t     ������ϵ�˵�����         ");
	fflush(stdin);
	scanf("%s", name);
	for (i = 0; i < NO - k + m; i++)
	{
		if (strcmp(name, frd[i].name) == 0)
		{

			printf("%8s%14s%7s%14s%10s%12s\n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);
			printf("\n\n\t    �Ƿ�ɾ������ϵ�˵�������Ϣ(y/n):");
			if (getch() == 'y')
			{
				for (j = i; j < NO - k + m - 1; j++)
				{
					frd[j] = frd[j + 1];
				}

				k++;
				printf("\n\t�Ѿ�ɾ���˸���ϵ��");
				save();
				printf("\n\t�Ƿ����ɾ����ϵ��(y/n):");
				if (getch() == 'y')
				{
					shanchuname();
				}

			}
			menu();
		}

	}

	printf("\n\n\tͨѶ¼�в����ڸ���ϵ��");

}
void chazhaoname()     //����ͨѶ¼�����ϵ��
{
	int i;
	char name[14];
	printf("\n\t     ������ϵ�˵�����         ");
	fflush(stdin);
	scanf("%s", name);
	for (i = 0; i < NO - k + m; i++)
	{
		if (strcmp(name, frd[i].name) == 0)
		{

			printf("%8s   %14s   %7s  %14s  %10s   %11s \n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);
			menu();
		}

	}

}
void xiugai()       //����ϵ�˵Ĳ�����Ϣ�����޸�
{
	int i, a; char name[14];
	printf("\n\n\t      ������ϵ�˵����� ");
	fflush(stdin);
	scanf("%s", name);
	for (i = 0; i < NO - k + m; i++)
	{
		if (strcmp(name, frd[i].name) == 0)
		{

			printf("%8s%14s%7s%14s%10s%13s\n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);
			printf("\n\n\t  �Ƿ�ȷ���޸ĸ���ϵ��(y/n):");
			if (getch() == 'y')
			{
				printf("\n\n\t************************************************");
				printf("\n \t      [1]����     [2]��ַ       [3]�ʱ�    ");
				printf("\n \t      [4]����     [5]QQ         [6]�ֻ�����   [7]���� ");
				printf("\n\n\t************************************************\n");
				printf("\n\t���������");
				scanf("%d", &a);
				switch (a)
				{
				case 1: printf("��    ��:"); scanf("%s", frd[i].name); break;
				case 2: printf("��    ַ:"); scanf("%s", frd[i].addr); break;
				case 3: printf("��    ��:"); scanf("%s", frd[i].pc); break;
				case 4: printf("��    ��:"); scanf("%s", frd[i].e_mail); break;
				case 5: printf("Q      Q:"); scanf("%s", frd[i].QQ); break;
				case 6: printf("11λ�ֻ�����:"); scanf("%s", frd[i].tel); break;
				case 7:menu();
				default:
					xiugai();
				}
				printf("\n\t\t�����޸Ľ��Ϊ:");
				printf("\n\t��    ��:%s", frd[i].name);
				printf("\n\t��    ַ:%s", frd[i].addr);
				printf("\n\t��    ��:%s", frd[i].pc);
				printf("\n\t��    ��:%s", frd[i].e_mail);
				printf("\n\tQ      Q:%s", frd[i].QQ);
				printf("\n\t�ֻ�����:%12s", frd[i].tel);
				save();
				return;
			}
			else
			{
				menu();
			}
		}
	}
	printf(" \n    \n");
}
void paixu()     //����ϵ�˽��а���ĸ��������
{
	struct friends fr[500];
	struct friends t;
	int i, j;
	for (i = 0; i < NO - k + m; i++)
		fr[i] = frd[i];
	for (i = 0; i < NO - k + m - 1; i++)
	{
		for (j = 1; j < NO - k + m; j++)
		{
			if (strcmp(fr[i].name, fr[j].name) > 0)
			{
				t = fr[i];
				fr[i] = fr[j];
				fr[j] = t;
			}
		}
	}
	printf("\n\n     ����           ��ַ       �ʱ�      e_mail          QQ       �ֻ���\n");
	for (i = 0; i < NO - k + m; i++)
	{
		printf("%8s%20s%7s%14s%10s%12s\n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);
	}
	save();


}