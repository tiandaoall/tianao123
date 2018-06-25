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
}per[20];
int read()
{
	int people=0;
	int i=0;
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
		//从文件中读取数据到结构体
    fscanf(fp,"%s%s%f%f%f%f%f%f",&(per[i].num),&(per[i].name),&(per[i].gwgz),&(per[i].zwjt),
    &(per[i].jtgz),&(per[i].jxgz),&(per[i].yfgz),&(per[i].sfgz));
    i++;
}
	for(int j=0;j<20;j++)
	{
	printf("%s\n%s\n%f\n%f\n%f\n%f\n%f\n%f\n",per[j].num,per[j].name,per[j].gwgz,per[j].zwjt,
    per[j].jtgz,per[j].jxgz,per[j].yfgz,per[j].sfgz); 
	}
	fclose(fp);
    return 0;
}
int main()
{

	read();
	return 0;
}