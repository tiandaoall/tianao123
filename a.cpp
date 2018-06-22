#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>
using namespace std;
//int read();
struct person
{                   /*定义结构*/
	char num[20];
	char name[20];
	float gwgz;
	float zwjt;
	float jtgz;
	float jxgz;
	float yfgz;
	float sfgz;
};
int read(struct person *p)
{
	int people=0;
	FILE *fp;
	if((fp=fopen("gx.dat","r"))==NULL)//当前目录下是否存在gx.dat文件
	{
	printf("没有文件");
	getch();
	exit(-1);
	}
	struct person s;
	while(!feof(fp))
	{
		fscanf(fp,"%s\t",&s.num);
		fscanf(fp,"%s\t",&s.name);
		fscanf(fp,"%f\t",&s.gwgz);
		fscanf(fp,"%f\t",&s.zwjt);
		fscanf(fp,"%f\t",&s.jtgz);
		fscanf(fp,"%f\t",&s.jxgz);
		fscanf(fp,"%f\t",&s.yfgz);
		fscanf(fp,"%f\t",&s.sfgz);
		p[people]=s;
		people++;
	}
	fclose(fp);
	printf("\nfile endl\n");
	return(0);


}
int main()
{   
	struct person s[50];
	read(s);
	return 0;
}
/*void mian()
{      
struct person per[50]; 最大职工人数
struct person *p;      声明一个结构指针
p=per; 
int i,in;
char ch;
do
{
	printf("\t\t 1.查询职工工资数据 \n");
	printf("\t\t 2.浏览职工工资数据 \n");
	printf("\t\t 3.修改职工工资数据 \n");
	printf("\t\t 4.删除职工工资数据 \n");
	printf("\t\t 5.添加职工工资数据 \n");
    printf("\t\t 6.计算个人所得税 \n");
	if(!scanf("%d,&in)==1)
	{
		while((ch=getchar())!='\n')
			putchar(ch);
		printf("没有此选项，请正确选择");
			getch();
		continue;
	}
	switch(in)
	{
	case 1:
		read(per);
		break;
	case 2:
		list(per);
		break;
	case 3:
		modify(per);
		break;
	case 4:
		del(per);
		break;
	case 5:
		add(per);
		break;
    case 6:
		grsds(per);
		break;
	default:
		printf("没有此选项，请正确选择!");
		getch();
		break;
	}
}while(in!=9);
}*/
