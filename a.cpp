#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>
using namespace std;
//int read();
struct person
{                   /*����ṹ*/
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
	if((fp=fopen("gx.dat","r"))==NULL)//��ǰĿ¼���Ƿ����gx.dat�ļ�
	{
	printf("û���ļ�");
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
struct person per[50]; ���ְ������
struct person *p;      ����һ���ṹָ��
p=per; 
int i,in;
char ch;
do
{
	printf("\t\t 1.��ѯְ���������� \n");
	printf("\t\t 2.���ְ���������� \n");
	printf("\t\t 3.�޸�ְ���������� \n");
	printf("\t\t 4.ɾ��ְ���������� \n");
	printf("\t\t 5.���ְ���������� \n");
    printf("\t\t 6.�����������˰ \n");
	if(!scanf("%d,&in)==1)
	{
		while((ch=getchar())!='\n')
			putchar(ch);
		printf("û�д�ѡ�����ȷѡ��");
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
		printf("û�д�ѡ�����ȷѡ��!");
		getch();
		break;
	}
}while(in!=9);
}*/
