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
{                   //����ṹ
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
	if((fp=fopen("gx.dat","rb"))==NULL)//��ǰĿ¼���Ƿ����gx.dat�ļ�
	{
	printf("û���ļ�");
	exit(1);
	}

while(!feof(fp))
{

	fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",&(zggz[i].num),&(zggz[i].name),&(zggz[i].gwgz),&(zggz[i].xjgz),
    &(zggz[i].zwjt),&(zggz[i].jxgz),&(zggz[i].yfgz),&(zggz[i].grsds),&(zggz[i].sfgz));
	n++;                                //��¼Ա������
	i++;
}

	fclose(fp);//�ر��ļ�
    return 0;
}
void write()
{
	grsds();
	if((fp=fopen("gx.dat","wb+"))==NULL) 
	{
	 printf("���ܴ� \n"); 
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
	printf("�ɹ�����\n");//�ر��ļ�
	fclose(fp); 

}


void add()
{
	if((fp=fopen("gx.dat","ab+"))==NULL)
			{
	          printf("û���ļ�");
	          getch();
	          exit(1);
			}
	printf("�������ӵ�%d��Ա��\n",n+1);
	printf("������Ա�����:");
    scanf("%s",&zggz[n].num);//��ȡԱ���±��
	printf("������Ա������:");
    scanf("%s",&zggz[n].name);//��ȡԱ��������
	printf("�������λ����:");
    scanf("%f",&zggz[n].gwgz);//��ȡԱ���¸�λ����
	printf("������н������:");
    scanf("%f",&zggz[n].xjgz);//��ȡԱ����н������
	printf("������ְ�����:");
    scanf("%f",&zggz[n].zwjt);//��ȡԱ����ְ����
	printf("�����뼨Ч����:");
    scanf("%f",&zggz[n].jxgz);//��ȡԱ���¼�Ч����
	grsds();
	printf("��ע�Ᵽ��");
	fclose(fp);//�ر��ļ�
}

int del()
{
	char delnum[100];
    int i;
	char y;
	grsds();
	printf("\n\n\t��������Ҫɾ����ְ����ְ�����:");
	scanf("%s",delnum);//��ȡҪɾ����ְ�����
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].num,delnum)==0)
		{
			printf("\n\t�Ƿ�ȷ��ɾ��ְ�� %s ����Ϣ,�ǵĻ�������:1\n",delnum);

			getchar();
			y=getchar();
			if(y=='1')
			{
				zggz[i]=zggz[i+1];
				n--;//����һλԱ������
			}
			else
			{
				printf("ȡ��ɾ��");
			}
		}
	}

return 0;
}
int find()
{
    int i=0,j=0;
	char gonghao[100];
    printf("��������Ҫ��ѯ��ְ�����:");
	scanf("%s",gonghao);//��ȡҪ��ѯ��ְ�����
	for(i=0;i<=n;i++)
	{	
		if(strcmp(zggz[i].num,gonghao)==0)           //�����������Ƿ��в�ѯ�ı��
		{
	        printf("���\t\t����\t\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\t\n"); 
            printf(" %-10s\t%-10s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f  \n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjgz,
            zggz[i].zwjt,zggz[i].jxgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].sfgz); 
		    break;	
		}
	}
		if(strcmp(zggz[i].num,gonghao)!=0)
			{
				printf("û��������");
			}
	return 0;

}
int list()
{   
	char zf[10];//�����ַ�����
	zf[0]=0;//��ֵΪ��
	 printf("���\t\t����\t\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\t\n"); 
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
			zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;//����Ӧ������
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
		zggz[i].sfgz=zggz[i].yfgz-zggz[i].grsds;//�����������˰
	}

}
int modify()
{

	grsds();
	char gonghao[100];
    printf("��������Ҫ�޸ĵ�ְ�����:");
    scanf("%s",gonghao);//��ȡҪ�޸ĵ�ְ�����
	for(int i=0;i<=n;i++)
	{   
		if(strcmp(zggz[i].num,gonghao)==0)//�����Ƿ�������
		{ 

			printf("��������Ϣ");
			            printf("\n������ְ������:");
		    scanf("%s",zggz[i].name);//��ȡԱ������
						printf("\n����ְ���µĸ�λ����:");
		    scanf("%f",&zggz[i].gwgz);//��ȡԱ����λ����
						printf("\n����ְ���µ�н������:");
		    scanf("%f",&zggz[i].xjgz);//��ȡԱ��н������
						printf("\n����ְ���µ�ְλ����:");
		    scanf("%f",&zggz[i].zwjt);//��ȡԱ��ְλ����
						printf("\n����ְ���µļ�Ч����:");
		    scanf("%f",&zggz[i].jxgz);//��ȡԱ����Ч����
			break;
		}
  

	}
		if(strcmp(zggz[i].num,gonghao)!=0)
			{
				printf("û��������");//��ʾû������ı��
			}
return 0;
}
int main()
{

	int in; //�����û���ѡ��
	read();
    while(1)
	{
		printf("\n\n");
		printf("\t\t��### ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ ###\n");
		printf("\t\t��                  ��ѡ��1-7��                               \n");
		printf("\t\t��*=============================================*\n");
		printf("\t\t��* ������      1.  ��ѯְ�����ʼ�¼��������    *\n");
		printf("\t\t��*����������������������������������������     *\n");
		printf("\t\t��*������    �� 2.���޸�ְ�����ʼ�¼��������    *\n");
		printf("\t\t��*����������������������������������������     *\n");
		printf("\t\t��*������    �� 3.������ְ�����ʼ�¼��������    *\n");
		printf("\t\t��*����������������������������������������     *\n");
		printf("\t\t��*��������     4.��ɾ��ְ�����ʼ�¼��������    *\n");
		printf("\t\t��*����������������������������������������     *\n");
		printf("\t\t��*������    �� 5.���������ݵ��ļ�����          *\n");
		printf("\t\t��*����������������������������������������     *\n");
		printf("\t\t��*������    �� 6.�����ְ����¼ ������         *\n");
		printf("\t\t��*����������������������������������������     *\n");
		printf("\t\t��*��������     7.  �˳�ϵͳ�� ��������         *\n");
		printf("\t\t  *=============================================*\n");
		printf("\t\t��                 ����ѡ����: ");
		scanf("%d",&in);
		switch(in)
		{
		case 1:	
			find();           //���ò�ѯְ�����ʺ���
			break;
		case 2:
			modify();         //�����޸�ְ�����ʺ�����
			break;
		case 3:
			add();            //��������ְ����¼����
			break;
		case 4:
			del();            //����ɾ��ְ�����ʺ���
			break;
		case 5:
			write();          //���ñ���ְ�����ʼ�¼����
			break;
		case 6:
			list();           //���ְ��������Ϣ
			break;
		case 7: 
			printf("\n\n\n\n\n\n\t\t\t");
            printf("\tл\tл\tʹ\t��\t��\tϵ\tͳ\t!\n\n");
			printf("\n\n\t\t\t\t\tEnding");
			printf("\n");
			return 0;
			break;            //�˳�ϵͳ
		default:
			printf("û�д�ѡ�����ȷѡ��!");
			break;
		}
	}
}
