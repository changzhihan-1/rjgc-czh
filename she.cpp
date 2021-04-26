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
	printf("\n\t\t |-----------  欢迎您使用通讯录管理系统1.0beat版 ----------|");
	printf(" \n\t\t|    [1]添加联系人;[2]删除联系人 ;[3]查找联系人           |   ");
	printf(" \n\t\t|    [4]显示联系人;[5]修改联系人 ;[6]排序联系人 [7]退出   |   ");
	printf("\n\t\t |---------------------------------------------------------|");
	printf("\n\t\t请选择您所所要的服务：");
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
		printf("\n\n\n\n\t      电话簿文件不存在");
		exit(0);
	}
	printf("\n\n********************************欢迎使用通讯录*******************************************");
	printf("\n       姓名     地址       邮编      e_mail          QQ       手机号");
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
int daoruwenji()    //判断通讯录是否为空和如果为空就新建一个txt文本
{
	if ((fp = fopen("jk0119.txt", "rb")) == 0)  //打开jk0119.txt文件
	{
		printf("\n\n\n\n\t      电话簿文件不存在");
		if ((fp = fopen("contact.txt", "wb")) == 0)//判断文件是否为空
		{
			printf("\n\t\t\t\t建立失败");
			exit(0);
		}
		else
		{
			printf("\n\t    电话簿已建立");
			printf("\n\t   按任意键进入主菜单");
			getch();
			return(0);
		}
		exit(0);
	}

	fseek(fp, 0L, 2);//将读取文件的指针移至文件末端

	if (ftell(fp) > 0)//统计文件的字节是否为0
	{
		rewind(fp);
		printf("\n\n\n\n\t \t\t\t\t      文件导入成功");
		printf("\n\t\t\t\t \t    按任意键返回主菜单");
		fclose(fp);
		getch();
		return(0);
	}
	printf("\n\n\n\n\t\t\t文件导入成功");
	printf("\n\t\t\t电话簿文件中无任何纪录");
	printf("\n\t\t\t按任意键返回主菜单");
	fclose(fp);
	getch();
	return(0);

}
void save()   //对修改的函数进行保存到txt文本中
{
	int i;
	if ((fp = fopen("jk0119.txt", "w")) == 0)
	{
		printf("\n\t\t\t\t打开失败");
	}
	for (i = 0; i < NO - k + m; i++)
	{
		fprintf(fp, "%s\t%14s%7s%14s%10s%12s\n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);  //打印出文件的信息
	}
	printf("\n\t   保存文件成功   ");
	fclose(fp);
}
void newrecord()     //新建一个新的联系人
{

	printf("\n\t\t******************请输入联系人信息************************");
	printf("\n\t\t     输入联系人的姓名         ");

	scanf("%s", &frd[NO - k + m].name);
	for (int i = 0; i < NO - k + m; i++)
	{
		if (strcmp(frd[NO].name, frd[i].name) == 0)
		{
			printf("\n\n\t姓名重复请重新新建联系人");
			newrecord();
		}
	}
	printf("\n\t\t     输入联系人的地址         ");
	scanf("%s", &frd[NO - k + m].addr);
	printf("\n\t\t     输入联系人的邮编         ");
	scanf("%s", &frd[NO - k + m].pc);
	printf("\n\t\t     输入联系人的e_mail       ");
	scanf("%s", &frd[NO - k + m].e_mail);
	printf("\n\t\t     输入联系人的QQ           ");
	scanf("%s", &frd[NO - k + m].QQ);
	printf("\n\t\t     输入联系人的手机号码     ");
	scanf("%s", &frd[NO - k + m].tel);
	if (strlen(frd[NO - k + m].tel) == 11)
	{
		printf("输入的电话号码合法");
	}
	else
	{
		printf("请重新输入11位合法的数字");
		scanf("%s", &frd[NO - k + m].tel);
	}
	m++;
	save();
	printf("    是否继续添加新联系人(y/n):      ");

	if (getch() == 'y')
	{
		newrecord();
	}

}
void shanchuname()    //对联系人信息进行全部的删除
{
	int i, j;
	char name[14];
	printf("\n\t\t     输入联系人的姓名         ");
	fflush(stdin);
	scanf("%s", name);
	for (i = 0; i < NO - k + m; i++)
	{
		if (strcmp(name, frd[i].name) == 0)
		{

			printf("%8s%14s%7s%14s%10s%12s\n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);
			printf("\n\n\t    是否删除该联系人的所有信息(y/n):");
			if (getch() == 'y')
			{
				for (j = i; j < NO - k + m - 1; j++)
				{
					frd[j] = frd[j + 1];
				}

				k++;
				printf("\n\t已经删除了该联系人");
				save();
				printf("\n\t是否继续删除联系人(y/n):");
				if (getch() == 'y')
				{
					shanchuname();
				}

			}
			menu();
		}

	}

	printf("\n\n\t通讯录中不存在该联系人");

}
void chazhaoname()     //查找通讯录里的联系人
{
	int i;
	char name[14];
	printf("\n\t     输入联系人的姓名         ");
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
void xiugai()       //对联系人的部分信息进行修改
{
	int i, a; char name[14];
	printf("\n\n\t      输入联系人的姓名 ");
	fflush(stdin);
	scanf("%s", name);
	for (i = 0; i < NO - k + m; i++)
	{
		if (strcmp(name, frd[i].name) == 0)
		{

			printf("%8s%14s%7s%14s%10s%13s\n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);
			printf("\n\n\t  是否确定修改该联系人(y/n):");
			if (getch() == 'y')
			{
				printf("\n\n\t************************************************");
				printf("\n \t      [1]姓名     [2]地址       [3]邮编    ");
				printf("\n \t      [4]邮箱     [5]QQ         [6]手机号码   [7]返回 ");
				printf("\n\n\t************************************************\n");
				printf("\n\t请输入序号");
				scanf("%d", &a);
				switch (a)
				{
				case 1: printf("姓    名:"); scanf("%s", frd[i].name); break;
				case 2: printf("地    址:"); scanf("%s", frd[i].addr); break;
				case 3: printf("邮    编:"); scanf("%s", frd[i].pc); break;
				case 4: printf("邮    箱:"); scanf("%s", frd[i].e_mail); break;
				case 5: printf("Q      Q:"); scanf("%s", frd[i].QQ); break;
				case 6: printf("11位手机号码:"); scanf("%s", frd[i].tel); break;
				case 7:menu();
				default:
					xiugai();
				}
				printf("\n\t\t您的修改结果为:");
				printf("\n\t姓    名:%s", frd[i].name);
				printf("\n\t地    址:%s", frd[i].addr);
				printf("\n\t邮    编:%s", frd[i].pc);
				printf("\n\t邮    箱:%s", frd[i].e_mail);
				printf("\n\tQ      Q:%s", frd[i].QQ);
				printf("\n\t手机号码:%12s", frd[i].tel);
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
void paixu()     //对联系人进行按字母进行排序
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
	printf("\n\n     姓名           地址       邮编      e_mail          QQ       手机号\n");
	for (i = 0; i < NO - k + m; i++)
	{
		printf("%8s%20s%7s%14s%10s%12s\n", frd[i].name, frd[i].addr, frd[i].pc, frd[i].e_mail, frd[i].QQ, frd[i].tel);
	}
	save();


}