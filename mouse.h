#include <windows.h> //ͷ�ļ�
void gotoxy(int x,int y)
{
	COORD coord;//�������λ��
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
