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
				printf("█"); 	
			}
			else
				printf("");
		}
	}
	MazePath(1,1,6,0);
} 
/*如果该迷宫为可走迷宫，函数执行结束后须撤销顺序栈*/
bool MazePath(int xi,int yi,int xe,int ye)
{/*MazePath是迷宫探索函数，入口点是（xi,yi),出口点是（xe,ye)*/
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
	SqStack *st;   /*定义一个顺序栈st*/
	InitStack(st);   /*初始化栈*/
	e.i=xi;e.j=yi;e.di=-1;   /*e压栈*/ 
	Push(st,e);
	maze[xi][yi]=-1;  /*防止重复寻找*/
	while(!StackEmpty(st))  /*栈不为空则循环*/ 
	{
		GetTop(st,etop);   /*获取栈顶元素*/
		if(etop.i==xe&&etop.j==ye)  /*找到出口了，输出路径*/
		{
		/*	printf("The maze path:\n");
			/*五个点一行输出点集*/
		/*	for(k=0;k<st->top;k++)
			{
				printf("\t(%d,%d)",st->data[k].i,st->data[k].j);
				if((k+1)%5==0)
					printf("\n");
		    }
		    printf("\n");*/
		    DestroyStack(st);  /*顺序栈使用完毕，撤销栈*/
		    printf("成功走出迷宫！"); 
			return true;
		}	
		find=0;	
		di=etop.di;/*找下一个可走方块*/ 
		while(di<4&&find==0)
		{
			di++;/*按照0、1、2、3地顺序去寻找*/
			switch(di)
			{
				case 0: i=etop.i-1;j=etop.j;break;
				case 1: i=etop.i;j=etop.j+1;break;
				case 2: i=etop.i+1;j=etop.j;break;
				case 3: i=etop.i;j=etop.j-1;break;
			}
			if(maze[i][j]==0)/*找到了下一个相邻可走方块*/
		 		find=1; 
		 }
		 if(find==1)
		 {
		 	Pop(st,e);
		 	e.di=di;/*修改栈顶元素的 di值，需要弹出再压入*/
		 	Push(st,e);
			e.i=i;e.j=j;e.di=-1;   /*用找到的下一个相邻可走方块地信息初始化 e */
			Push(st,e);      /*把新的点压入栈*/
			gotoxy(e.j*2,e.i);printf("☆");Sleep(500);
			maze[i][j]=-1;  /*新压入地点地maze设为-1；避免重复走到该方块*/
		 }
		 else   /*没有找到下一个相邻可走方块*/
		 {
		 	Pop(st,e);   /*弹出栈元素，当前位置已经没有路可以探索了*/
			maze[e.i][e.j]=0;   /*恢复当前地maze点为可走，方便其他路径使用*/
			gotoxy(e.j*2,e.i);printf("  ");Sleep(500);		  
		 }
    }
    DestroyStack(st);  /*顺序栈使用完毕，撤销栈*/
    printf("无出口");
	return false;
}
