#define MaxSize 50 
/*   ˳��ջ�ṹ   */ 
typedef struct
{
	int i;
	int j;
	int di;
} ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;
/*    ��ʼ��˳��ջ  */ 
void InitStack(SqStack *&s)
{
	s=(SqStack*)malloc(sizeof(SqStack));
	s->top=0;
}
/*   ����˳��ջ   */ 
void DestroyStack(SqStack *&s)
{
	free(s);
}
/*    �ж�˳��ջ�Ƿ�Ϊ��    */ 
bool StackEmpty(SqStack *s)
{
	return (s->top==0);
}
/*   ��ջ   */ 
bool Push(SqStack *&s,ElemType e)
{
	if(s->top==MaxSize)	return false;
	s->data[s->top]=e;
	s->top++;
	return true; 
}
/*   ��ջ   */ 
bool Pop(SqStack *&s,ElemType &e)
{
	if(s->top==0) return false;
	s->top--;
	e=s->data[s->top];
	return true;
}
/*   ��ȡջ��Ԫ��   */ 
bool GetTop(SqStack *s,ElemType &e)
{
	if(s->top==0) return false;
	e=s->data[s->top-1];
	return true; 
}
/*   ��ȡջ�ĳ���    */ 
int getLen(SqStack *s)
{
	return s->top;
}
