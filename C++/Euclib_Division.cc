#include <bits/stdc++.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void);
void exchangvalue_2(long long int *,long long int *);
int greatest_common_divisor(long long int,long long int);
void SetColor(unsigned short, unsigned short);
int main()
{

	HWND hWnd = GetConsoleWindow();						//禁用最大化
	HMENU hMenu = GetSystemMenu(hWnd, false);
	RemoveMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	DestroyMenu(hMenu);
	ReleaseDC(hWnd, NULL);

	SetWindowPos(GetForegroundWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);//窗口置顶

	//居中窗口
   int scrWidth, scrHeight;
   RECT rect;
   scrWidth = GetSystemMetrics(SM_CXSCREEN);
   scrHeight = GetSystemMetrics(SM_CYSCREEN);
   GetWindowRect(hWnd, &rect);
   SetWindowPos(hWnd, HWND_TOPMOST, (scrWidth - rect.right) / 2, (scrHeight - rect.bottom) / 2, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);




	long long int m, n, divisor;

	system("cls");
	system("mode con cols=40 lines=6");
	system("title Euclid Division");

	SetColor(7, 0);
	cout << "Please Input ";
	SetColor(6,0);
	cout<<"Two ";
	SetColor(7,0);
	cout<<"Integers:" << endl;

	Sleep(800);
	cout<<"The ";
	SetColor(9,0);
	cout<<"1st ";
	SetColor(7,0);
	cout<<"One: ";
	SetColor(9, 0);
	cin >> m;

	Sleep(200);
	SetColor(7, 0);
	cout<<"The ";
	SetColor(2,0);
	cout<<"2nd ";
	SetColor(7, 0);
	cout<<"One: ";
	SetColor(2, 0);
	cin >> n;
	SetColor(7, 0);

	if (m < n)
		exchangvalue_2(&m, &n);
	divisor = greatest_common_divisor(m, n);

	cout << "The Greatest Common Divisor Is : ";
	SetColor(4, 0);
	cout << divisor << endl
		 << endl;
	SetColor(8, 0);
	system("pause");
	SetColor(7,0);
	cout<<endl;
	return 0;
}
void exchangvalue_2(long long int *a,long long int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
	return;
}
int greatest_common_divisor(long long int x,long long int y)
{
	int start, finish; 
	long long int remainder;
	start = clock();
	do
	{
		remainder = x % y;
		x = y;
		y = remainder;
		finish = clock();
		if ((finish - start) >= 1000)
		{
			//cout << "Time Out!" << endl;
			//system("pause");
			return -1;
		}
	} while (remainder != 0);
	return x;
}
void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
	return;
	//1 Deep Blue
	//2 Green
	//3 Small Blue
	//4 Red
	//5 Purple
	//6 Yellow
	//7 White
	//8 Little White
	//9 Normal Bule
}
