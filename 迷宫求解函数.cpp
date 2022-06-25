#include "stdio.h"
#include "stdlib.h"
#include "SqstackMaze.h"
#include "mouse.h"
#include "time.h"
#define M 10
#define N 10
bool MazePath(int xi,int yi,int xe,int ye);
int main()
{
	int i=0,j=0,k;
	int maze[M][N]={1,1,1,1,1,1,1,1,1,1,
					1,0,0,1,1,0,0,0,0,1,
					1,1,0,0,0,0,1,0,0,1,
					1,0,0,1,1,0,1,1,0,1,
					1,1,1,1,1,0,1,1,1,1,
					1,0,0,1,1,0,1,1,1,1,
					0,0,0,1,1,0,0,0,0,1,
					1,1,0,1,1,0,1,1,0,1,
					1,0,0,0,0,0,1,1,0,1,
					1,1,1,1,1,1,1,1,1,1
					};

	for(i=0;i<M;i++){
	 	for(j=0;j<N;j++){
	 		k=j*2;
			if(maze[i][j]==1){
				gotoxy(k,i);
				printf("��"); 	
			}
			else
				printf("");
		}
	}
	MazePath(1,1,6,0);
} 
/*������Թ�Ϊ�����Թ�������ִ�н������볷��˳��ջ*/
bool MazePath(int xi,int yi,int xe,int ye)
{/*MazePath���Թ�̽����������ڵ��ǣ�xi,yi),���ڵ��ǣ�xe,ye)*/
	int i,j,di,find,k;
	int maze[M][N]={1,1,1,1,1,1,1,1,1,1,
					1,0,0,1,1,0,0,0,0,1,
					1,1,0,0,0,0,1,0,0,1,
					1,0,0,1,1,0,1,1,0,1,
					1,1,1,1,1,0,1,1,1,1,
					1,0,0,1,1,0,1,1,1,1,
					0,0,0,1,1,0,0,0,0,1,
					1,1,0,1,1,0,1,1,0,1,
					1,0,0,0,0,0,1,1,0,1,
					1,1,1,1,1,1,1,1,1,1
					};
	ElemType etop,e;
	SqStack *st;   /*����һ��˳��ջst*/
	InitStack(st);   /*��ʼ��ջ*/
	e.i=xi;e.j=yi;e.di=-1;   /*eѹջ*/ 
	Push(st,e);
	maze[xi][yi]=-1;  /*��ֹ�ظ�Ѱ��*/
	while(!StackEmpty(st))  /*ջ��Ϊ����ѭ��*/ 
	{
		GetTop(st,etop);   /*��ȡջ��Ԫ��*/
		if(etop.i==xe&&etop.j==ye)  /*�ҵ������ˣ����·��*/
		{
		/*	printf("The maze path:\n");
			/*�����һ������㼯*/
		/*	for(k=0;k<st->top;k++)
			{
				printf("\t(%d,%d)",st->data[k].i,st->data[k].j);
				if((k+1)%5==0)
					printf("\n");
		    }
		    printf("\n");*/
		    DestroyStack(st);  /*˳��ջʹ����ϣ�����ջ*/
		    printf("�ɹ��߳��Թ���"); 
			return true;
		}	
		find=0;	
		di=etop.di;/*����һ�����߷���*/ 
		while(di<4&&find==0)
		{
			di++;/*����0��1��2��3��˳��ȥѰ��*/
			switch(di)
			{
				case 0: i=etop.i-1;j=etop.j;break;
				case 1: i=etop.i;j=etop.j+1;break;
				case 2: i=etop.i+1;j=etop.j;break;
				case 3: i=etop.i;j=etop.j-1;break;
			}
			if(maze[i][j]==0)/*�ҵ�����һ�����ڿ��߷���*/
		 		find=1; 
		 }
		 if(find==1)
		 {
		 	Pop(st,e);
		 	e.di=di;/*�޸�ջ��Ԫ�ص� diֵ����Ҫ������ѹ��*/
		 	Push(st,e);
			e.i=i;e.j=j;e.di=-1;   /*���ҵ�����һ�����ڿ��߷������Ϣ��ʼ�� e */
			Push(st,e);      /*���µĵ�ѹ��ջ*/
			gotoxy(e.j*2,e.i);printf("��");Sleep(500);
			maze[i][j]=-1;  /*��ѹ��ص��maze��Ϊ-1�������ظ��ߵ��÷���*/
		 }
		 else   /*û���ҵ���һ�����ڿ��߷���*/
		 {
		 	Pop(st,e);   /*����ջԪ�أ���ǰλ���Ѿ�û��·����̽����*/
			maze[e.i][e.j]=0;   /*�ָ���ǰ��maze��Ϊ���ߣ���������·��ʹ��*/
			gotoxy(e.j*2,e.i);printf("  ");Sleep(500);		  
		 }
    }
    DestroyStack(st);  /*˳��ջʹ����ϣ�����ջ*/
    printf("�޳���");
	return false;
}
