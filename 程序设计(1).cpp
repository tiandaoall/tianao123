#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>
void write();
void grsds();
using namespace std;
FILE *fp;
int n=0;
struct person
{                   //定义结构
	char num[100];
	char name[100];
	float gwgz;
	float xjgz;
    float zwjt;
	float jxgz;
	float yfgz;
	float grsds;
	float sfgz;
}zggz[100];
int read()
{
    grsds();
	int i=0;
	if((fp=fopen("gx.dat","rb"))==NULL)//当前目录下是否存在gx.dat文件
	{
	printf("没有文件");
	exit(1);
	}

while(!feof(fp))
{

	fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",&(zggz[i].num),&(zggz[i].name),&(zggz[i].gwgz),&(zggz[i].xjgz),
    &(zggz[i].zwjt),&(zggz[i].jxgz),&(zggz[i].yfgz),&(zggz[i].grsds),&(zggz[i].sfgz));
	n++;                                //记录员工人数
	i++;
}

	fclose(fp);//关闭文件
    return 0;
}
void write()
{
	grsds();
	if((fp=fopen("gx.dat","wb+"))==NULL) 
	{
	 printf("不能打开 \n"); 
	 getch();
	 exit(1); 
	} 
	rewind(fp);
	for(int i=0;i<n+1;i++)
	{
		fprintf(fp,"%s %s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjgz,
        zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].sfgz);
		//fwrite(&zgs[i],sizeof(struct zggz),1,fp);
	}
	printf("成功保存\n");//关闭文件
	fclose(fp); 

}


void add()
{
	if((fp=fopen("gx.dat","ab+"))==NULL)
			{
	          printf("没有文件");
	          getch();
	          exit(1);
			}
	printf("现在增加第%d个员工\n",n+1);
	printf("请输入员工编号:");
    scanf("%s",&zggz[n].num);//获取员工新编号
	printf("请输入员工名字:");
    scanf("%s",&zggz[n].name);//获取员工新名字
	printf("请输入岗位工资:");
    scanf("%f",&zggz[n].gwgz);//获取员工新岗位工资
	printf("请输入薪级工资:");
    scanf("%f",&zggz[n].xjgz);//获取员工新薪级工资
	printf("请输入职务津贴:");
    scanf("%f",&zggz[n].zwjt);//获取员工新职务工资
	printf("请输入绩效工资:");
    scanf("%f",&zggz[n].jxgz);//获取员工新绩效工资
	grsds();
	printf("请注意保存");
	fclose(fp);//关闭文件
}

int del()
{
	char delnum[100];
    int i;
	char y;
	grsds();
	printf("\n\n\t请输入你要删除的职工的职工编号:");
	scanf("%s",delnum);//获取要删除的职工编号
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].num,delnum)==0)
		{
			printf("\n\t是否确认删除职工 %s 的信息,是的话请输入:1\n",delnum);

			getchar();
			y=getchar();
			if(y=='1')
			{
				zggz[i]=zggz[i+1];
				n--;//减少一位员工人数
			}
			else
			{
				printf("取消删除");
			}
		}
	}

return 0;
}
int find()
{
    int i=0,j=0;
	char gonghao[100];
    printf("请输入你要查询的职工编号:");
	scanf("%s",gonghao);//获取要查询的职工编号
	for(i=0;i<=n;i++)
	{	
		if(strcmp(zggz[i].num,gonghao)==0)           //查找数据里是否有查询的编号
		{
	        printf("编号\t\t姓名\t\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\t\n"); 
            printf(" %-10s\t%-10s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f  \n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjgz,
            zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].sfgz); 
		    break;	
		}
	}
		if(strcmp(zggz[i].num,gonghao)!=0)
			{
				printf("没有这个编号");
			}
	return 0;

}
int list()
{   
	char zf[10];//定义字符数组
	zf[0]=0;//赋值为零
	 printf("编号\t\t姓名\t\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\t\n"); 
    for(int i=0;i<=n;i++)
	{
	    	grsds();			
		    printf(" %-10s\t%-10s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f  \n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjgz,
            zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].sfgz);
	        if(strcmp(zggz[i+1].num,zf)==0)
			{
				break;
			}

	}
  return 0;
}
void grsds()
{
	for(int i=0;i<=n;i++)
	{
			zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;//计算应发工资
	}
	for( i=0;i<=100;i++)
	{
		if(zggz[i].yfgz<=500)
			zggz[i].grsds=zggz[i].yfgz*0.05;
		else if(zggz[i].yfgz>=500&&zggz[i].yfgz<=2000)
			zggz[i].grsds=(zggz[i].yfgz-500)*0.1+25;
		else if(zggz[i].yfgz>=2000&&zggz[i].yfgz<=5000)
			zggz[i].grsds=(zggz[i].yfgz-2000)*0.15+150+25;
		else if(zggz[i].yfgz>=5000&&zggz[i].yfgz<=20000)
			zggz[i].grsds=(zggz[i].yfgz-5000)*0.20+450+150+25;
		else if(zggz[i].yfgz>=20000&&zggz[i].yfgz<=40000)
			zggz[i].grsds=(zggz[i].yfgz-20000)*0.25+3000+450+150+25;
		else if(zggz[i].yfgz>=40000&&zggz[i].yfgz<=60000)
			zggz[i].grsds=(zggz[i].yfgz-40000)*0.3+5000+3000+450+150+25;
		else if(zggz[i].yfgz>=60000&&zggz[i].yfgz<=80000)
			zggz[i].grsds=(zggz[i].yfgz-60000)*0.35+6000+5000+3000+450+150+25;
		else if(zggz[i].yfgz>=80000&&zggz[i].yfgz<=100000)
			zggz[i].grsds=(zggz[i].yfgz-80000)*0.4+7000+6000+5000+3000+450+150+25;
		else if(zggz[i].yfgz>=100000)
			zggz[i].grsds=(zggz[i].yfgz-100000)*0.45+8000+7000+6000+5000+3000+450+150+25;
	}

	for( i=0;i<=100;i++)
	{	
		zggz[i].sfgz=zggz[i].yfgz-zggz[i].grsds;//计算个人所得税
	}

}
int modify()
{

	grsds();
	char gonghao[100];
    printf("请输入你要修改的职工编号:");
    scanf("%s",gonghao);//获取要修改的职工编号
	for(int i=0;i<=n;i++)
	{   
		if(strcmp(zggz[i].num,gonghao)==0)//查找是否有这编号
		{ 

			printf("请输入信息");
			            printf("\n输入新职工姓名:");
		    scanf("%s",zggz[i].name);//获取员工名字
						printf("\n输入职工新的岗位工资:");
		    scanf("%f",&zggz[i].gwgz);//获取员工岗位工资
						printf("\n输入职工新的薪级工资:");
		    scanf("%f",&zggz[i].xjgz);//获取员工薪级工资
						printf("\n输入职工新的职位工资:");
		    scanf("%f",&zggz[i].zwjt);//获取员工职位工资
						printf("\n输入职工新的绩效工资:");
		    scanf("%f",&zggz[i].jxgz);//获取员工绩效工资
			break;
		}
  

	}
		if(strcmp(zggz[i].num,gonghao)!=0)
			{
				printf("没有这个编号");//提示没有输入的编号
			}
return 0;
}
int main()
{

	int in; //接收用户的选择
	read();
    while(1)
	{
		printf("\n\n");
		printf("\t\t　### 欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###\n");
		printf("\t\t　                  请选择《1-7》                               \n");
		printf("\t\t　*=============================================*\n");
		printf("\t\t　* 　　　      1.  查询职工工资记录　　　　    *\n");
		printf("\t\t　*　　　　　　　　　　　　　　　　　　　　     *\n");
		printf("\t\t　*　　　    　 2.　修改职工工资记录　　　　    *\n");
		printf("\t\t　*　　　　　　　　　　　　　　　　　　　　     *\n");
		printf("\t\t　*　　　    　 3.　增加职工工资记录　　　　    *\n");
		printf("\t\t　*　　　　　　　　　　　　　　　　　　　　     *\n");
		printf("\t\t　*　　　　     4.　删除职工工资记录　　　　    *\n");
		printf("\t\t　*　　　　　　　　　　　　　　　　　　　　     *\n");
		printf("\t\t　*　　　    　 5.　保存数据到文件　　          *\n");
		printf("\t\t　*　　　　　　　　　　　　　　　　　　　　     *\n");
		printf("\t\t　*　　　    　 6.　浏览职工记录 　　　         *\n");
		printf("\t\t　*　　　　　　　　　　　　　　　　　　　　     *\n");
		printf("\t\t　*　　　　     7.  退出系统　 　　　　         *\n");
		printf("\t\t  *=============================================*\n");
		printf("\t\t　                 您的选择是: ");
		scanf("%d",&in);
		switch(in)
		{
		case 1:	
			find();           //调用查询职工工资函数
			break;
		case 2:
			modify();         //调用修改职工工资函函数
			break;
		case 3:
			add();            //调用增加职工记录函数
			break;
		case 4:
			del();            //调用删除职工工资函数
			break;
		case 5:
			write();          //调用保存职工工资记录函数
			break;
		case 6:
			list();           //浏览职工工资信息
			break;
		case 7: 
			printf("\n\n\n\n\n\n\t\t\t");
            printf("\t谢\t谢\t使\t用\t本\t系\t统\t!\n\n");
			printf("\n\n\t\t\t\t\tEnding");
			printf("\n");
			return 0;
			break;            //退出系统
		default:
			printf("没有此选项，请正确选择!");
			break;
		}
	}
}
