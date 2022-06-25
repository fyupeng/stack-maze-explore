#define MaxSize 50 
/*   顺序栈结构   */ 
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
/*    初始化顺序栈  */ 
void InitStack(SqStack *&s)
{
	s=(SqStack*)malloc(sizeof(SqStack));
	s->top=0;
}
/*   销毁顺序栈   */ 
void DestroyStack(SqStack *&s)
{
	free(s);
}
/*    判断顺序栈是否为空    */ 
bool StackEmpty(SqStack *s)
{
	return (s->top==0);
}
/*   入栈   */ 
bool Push(SqStack *&s,ElemType e)
{
	if(s->top==MaxSize)	return false;
	s->data[s->top]=e;
	s->top++;
	return true; 
}
/*   出栈   */ 
bool Pop(SqStack *&s,ElemType &e)
{
	if(s->top==0) return false;
	s->top--;
	e=s->data[s->top];
	return true;
}
/*   获取栈顶元素   */ 
bool GetTop(SqStack *s,ElemType &e)
{
	if(s->top==0) return false;
	e=s->data[s->top-1];
	return true; 
}
/*   获取栈的长度    */ 
int getLen(SqStack *s)
{
	return s->top;
}
