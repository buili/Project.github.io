#include <Windows.h>
#include <conio.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
#define MAX 100
using namespace std;

void menu();
void vechu();
void ve_khung();
void dieukhien();
void ve_chu_thoat();
void ve_thoat_1();
void ve_thoat_2();
int diem = 0;
int sl = 5;
void khoi_tao_ran(int toadox[], int toadoy[]);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua);
void them(int a[], int x);
void xoa(int a[], int vt);
bool kt_ran_cham_tuong(int x0, int y0);
bool kt_ran_cham_duoi(int toadox[], int toadoy[]);
bool kt_ran(int toadox[], int toadoy[]);
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);
char map[100][100];
void ran();
void choi();

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}


void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}


void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}


void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void VeHinh(int x, int y, string str, int color)
{
	gotoxy(x, y); 
	textcolor(color); 
	cout << str;
	textcolor(7); 
}
void xoacontro()
{
 CONSOLE_CURSOR_INFO Info;
 Info.bVisible = FALSE;
 Info.dwSize = 20;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void DOC_FILE_1(string a, ifstream &filein1){
	while(!filein1.eof()){
		getline(filein1, a, '|');
	    filein1 >> a;
		cout << a;
	}
}

void DOC_FILE_2(string b, ifstream &filein){
	while(!filein.eof()){
		getline(filein, b, '|');
	    filein >> b;
		cout << b;
	}
}

void menu(){
    VeHinh(30, 9, "-----------------------------------------------------------", 68);
    VeHinh(30, 10, "\t\t\t\t\t\t\t\t", 176);
	VeHinh(30, 11, "\t\t\t\t\t\t\t\t", 176);
	VeHinh(30, 12, "\t\t\t\t\t\t\t\t", 176);
	VeHinh(30, 13, "\t\t\t\t\t\t\t\t", 176);
	VeHinh(30, 14, "\t\t\t\t\t\t\t\t", 176);
	VeHinh(30, 15, "-----------------------------------------------------------", 136);
	VeHinh(30, 16, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 17, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 18, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 19, "-----------------------------------------------------------", 136);
	VeHinh(30, 20, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 21, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 22, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 23, "-----------------------------------------------------------", 136);
	VeHinh(30, 24, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 25, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 26, "\t\t\t\t\t\t\t\t", 170);
	VeHinh(30, 27, "-----------------------------------------------------------", 68);
}

void vechu(){
	VeHinh(58, 12,"MENU", 190);
	VeHinh(57, 17,"1.BAT DAU", 174);
	VeHinh(56, 21,"2.HUONG DAN", 174);
	VeHinh(57, 25,"3.THOAT", 174);

}
void ve_khung(){
	for(int i = 9; i <= 27; i++){
		VeHinh(29, i, "||", 68);
		VeHinh(89, i, "||", 68);
	}
}
void ve_chu_thoat(){
	VeHinh(48, 16, "BAN CO MUON THOAT KHONG", 190);
	VeHinh(54, 19, "KHONG", 78);
	VeHinh(62, 19, "CO", 190);
}
void ve_thoat_1(){
	VeHinh(30, 9, "-----------------------------------------------------------", 187);
	 VeHinh(30, 10, "-----------------------------------------------------------", 187);
    VeHinh(30, 11, "-----------------------------------------------------------", 187);
    VeHinh(30, 12, "-----------------------------------------------------------", 187);
    VeHinh(30, 13, "-----------------------------------------------------------", 187);
    VeHinh(30, 14, "-----------------------------------------------------------", 187);
	 VeHinh(30, 15, "-----------------------------------------------------------", 187);
    VeHinh(30, 16, "-----------------------------------------------------------", 187);
    VeHinh(30, 17, "-----------------------------------------------------------", 187);
    VeHinh(30, 18, "-----------------------------------------------------------", 187);
    VeHinh(30, 19, "-----------------------------------------------------------", 187);
	 VeHinh(30, 20, "-----------------------------------------------------------", 187);
    VeHinh(30, 21, "-----------------------------------------------------------", 187);
    VeHinh(30, 22, "-----------------------------------------------------------", 187);
    VeHinh(30, 23, "-----------------------------------------------------------", 187);
    VeHinh(30, 24, "-----------------------------------------------------------", 187);
	VeHinh(30, 25, "-----------------------------------------------------------", 187);
    VeHinh(30, 26, "-----------------------------------------------------------", 187);
    VeHinh(30, 27, "-----------------------------------------------------------", 187);
	for(int i = 9; i <= 27; i++){
		VeHinh(29, i, "||", 187);
		VeHinh(89, i, "||", 187);
	}
	ve_chu_thoat();

	while(true){
		if(kbhit())
	{ 
	char d = getch();
				if(d == 13){
					system("cls");
				resizeConsole(940, 800);
	xoacontro();
	VeHinh(30, 9, "-----------------------------------------------------------", 68);
    VeHinh(30, 10, "-----------------------------------------------------------", 187);
    VeHinh(30, 11, "-----------------------------------------------------------", 187);
    VeHinh(30, 12, "-----------------------------------------------------------", 187);
    VeHinh(30, 13, "-----------------------------------------------------------", 187);
    VeHinh(30, 14, "-----------------------------------------------------------", 187);
	VeHinh(30, 15, "-----------------------------------------------------------", 136);
    VeHinh(30, 16, "-----------------------------------------------------------", 170);
	VeHinh(30, 17, "-----------------------------------------------------------", 170);
    VeHinh(30, 18, "-----------------------------------------------------------", 170);
	VeHinh(30, 19, "-----------------------------------------------------------", 136);
	VeHinh(30, 20, "-----------------------------------------------------------", 170);
    VeHinh(30, 21, "-----------------------------------------------------------", 170);
    VeHinh(30, 22, "-----------------------------------------------------------", 170);
	VeHinh(30, 23, "-----------------------------------------------------------", 136);
	VeHinh(30, 24, "-----------------------------------------------------------", 170);
    VeHinh(30, 25, "-----------------------------------------------------------", 170);
    VeHinh(30, 26, "-----------------------------------------------------------", 170);
	VeHinh(30, 27, "-----------------------------------------------------------", 68);
	vechu();
	ve_khung();
	dieukhien();
				}
	else if(GetAsyncKeyState(VK_LEFT))
		{
			
			VeHinh(54, 19, "KHONG", 78);
	        VeHinh(62, 19, "CO", 190);
	        while(true){
	        		if(kbhit())
	{ 
	        	char d = getch();
				if(d == 13){
					system("cls");
				resizeConsole(940, 800);
	xoacontro();
	VeHinh(30, 9, "-----------------------------------------------------------", 68);
    VeHinh(30, 10, "-----------------------------------------------------------", 187);
    VeHinh(30, 11, "-----------------------------------------------------------", 187);
    VeHinh(30, 12, "-----------------------------------------------------------", 187);
    VeHinh(30, 13, "-----------------------------------------------------------", 187);
    VeHinh(30, 14, "-----------------------------------------------------------", 187);
	VeHinh(30, 15, "-----------------------------------------------------------", 136);
    VeHinh(30, 16, "-----------------------------------------------------------", 170);
	VeHinh(30, 17, "-----------------------------------------------------------", 170);
    VeHinh(30, 18, "-----------------------------------------------------------", 170);
	VeHinh(30, 19, "-----------------------------------------------------------", 136);
	VeHinh(30, 20, "-----------------------------------------------------------", 170);
    VeHinh(30, 21, "-----------------------------------------------------------", 170);
    VeHinh(30, 22, "-----------------------------------------------------------", 170);
	VeHinh(30, 23, "-----------------------------------------------------------", 136);
	VeHinh(30, 24, "-----------------------------------------------------------", 170);
    VeHinh(30, 25, "-----------------------------------------------------------", 170);
    VeHinh(30, 26, "-----------------------------------------------------------", 170);
	VeHinh(30, 27, "-----------------------------------------------------------", 68);
	vechu();
	ve_khung();
	dieukhien();
				}
				else if(GetAsyncKeyState(VK_RIGHT)){
					break;
				}
			}
		}
	}

	 else if(GetAsyncKeyState(VK_RIGHT))
		{
		
			VeHinh(54, 19, "KHONG", 190);
	        VeHinh(62, 19, "CO", 78);
	        while(true){
	        		if(kbhit())
	{ 
	        	char d = getch();
				if(d == 13){
					exit(0);
			
				}
				else if(GetAsyncKeyState(VK_LEFT)){
				 break;
				}
			}
		}
	}
	}
}  
}
void ve_thoat_2(){
		VeHinh(48, 16, "THOAT", 78);
		while(true){
		
				if(kbhit() != 13)
	{ 
	char d = getch();
				if(d == 13){
				system("cls");
				resizeConsole(940, 800);
	xoacontro();
	VeHinh(30, 9, "-----------------------------------------------------------", 68);
    VeHinh(30, 10, "-----------------------------------------------------------", 187);
    VeHinh(30, 11, "-----------------------------------------------------------", 187);
    VeHinh(30, 12, "-----------------------------------------------------------", 187);
    VeHinh(30, 13, "-----------------------------------------------------------", 187);
    VeHinh(30, 14, "-----------------------------------------------------------", 187);
	VeHinh(30, 15, "-----------------------------------------------------------", 136);
    VeHinh(30, 16, "-----------------------------------------------------------", 170);
	VeHinh(30, 17, "-----------------------------------------------------------", 170);
    VeHinh(30, 18, "-----------------------------------------------------------", 170);
	VeHinh(30, 19, "-----------------------------------------------------------", 136);
	VeHinh(30, 20, "-----------------------------------------------------------", 170);
    VeHinh(30, 21, "-----------------------------------------------------------", 170);
    VeHinh(30, 22, "-----------------------------------------------------------", 170);
	VeHinh(30, 23, "-----------------------------------------------------------", 136);
	VeHinh(30, 24, "-----------------------------------------------------------", 170);
    VeHinh(30, 25, "-----------------------------------------------------------", 170);
    VeHinh(30, 26, "-----------------------------------------------------------", 170);
	VeHinh(30, 27, "-----------------------------------------------------------", 68);
	vechu();
	ve_khung();
	dieukhien();
}
}
}
}


void ve_tuong_ngang(){
	VeHinh(10, 6, "-------------------------------------------------------------------------------------------------------", 68);
	VeHinh(10, 40, "-------------------------------------------------------------------------------------------------------", 68);
}
void ve_tuong_phai()
{
	int x = 113, y = 6;
	while (y <= 40)
	{
		gotoxy(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong_trai()
{
	int x = 10, y = 6;
	while (y <= 40)
	{
		gotoxy(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong(){
	ve_tuong_ngang();
	textcolor(68);
	ve_tuong_phai();
	ve_tuong_trai();
	textcolor(7);
}
void khoi_tao_ran(int toadox[], int toadoy[])
{
	int x = 50, y = 13;
	for (int i = 0;i < sl;i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[])
{
	for (int i = 0;i < sl;i++)
	{
		gotoxy(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << "@";
		}
		else
		{
			cout << "o";
		}
	}
}
void xoa_du_lieu_cu(int toadox[], int toadoy[])
{
	for (int i = 0;i < sl;i++)
	{
		gotoxy(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void xu_ly_ran(int toadox[], int toadoy[], int x, int y,int &xqua,int &yqua)
{

	them(toadox, x); 
	them(toadoy, y);
     
	if (kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false)
	{
		
		xoa(toadox, sl - 1); 
		xoa(toadoy, sl - 1); 

	}
	else
	{ 
               
                sl--;
		tao_qua(xqua, yqua, toadox, toadoy);
	}
	
	ve_ran(toadox, toadoy);
}
void them(int a[], int x)
{
	for (int i = sl;i > 0;i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt)
{
	for (int i = vt;i < sl;i++)
	{
		a[i] = a[i + 1];
	}
	sl--;
}
bool kt_ran_cham_tuong(int x0,int y0)
{

	if (y0 == 6 && (x0 >= 10 && x0 <= 113))
	{
		return true;
	}
	
	else if (y0 == 40 && (x0 >= 10 && x0 <= 113))
	{
		return true;
	}
	
	else if (x0 == 113 && (y0 >= 6 && y0 <= 40))
	{
		return true;
	}

	else if (x0 == 10 && (y0 >= 6 && y0 <= 40))
	{
		return true;
	}
	return false;
}
bool kt_ran_cham_duoi(int toadox[],int toadoy[])
{
	for (int i = 1;i < sl;i++)
	{
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		{
			return true;
		}
	}
	return false;
}
bool kt_ran(int toadox[],int toadoy[])
{
	bool kt1 = kt_ran_cham_duoi(toadox, toadoy);
	bool kt2 = kt_ran_cham_tuong(toadox[0], toadoy[0]);
	if (kt1 == true || kt2 == true)
	{
		return true;
	}
	return false;
}
void tao_qua(int &xqua,int &yqua,int toadox[],int toadoy[])
{
	do
	{
	
		xqua = rand() % (112 - 11 + 1) + 11;
		
		yqua = rand() % (39 - 7 + 1) + 7;
	} while (kt_ran_de_qua(xqua,yqua,toadox,toadoy)==true);
	int i = rand() % (15 - 1 + 1) + 1;
	textcolor(i);
	gotoxy(xqua, yqua);
	cout << "$";
	textcolor(7);
}
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[])
{
	for (int i = 0;i < sl;i++)
	{
		if ((xqua == toadox[i]) && (yqua == toadoy[i]))
		{
			return true;
		}
	}
	return false;
}
bool kt_ran_an_qua(int xqua, int yqua, int x0,int y0)
{
	if ((x0 == xqua) && (y0 == yqua))
	{  
	    diem++;
		return true;
	}
	return false;
}

void ran(){
	system("cls");
	resizeConsole(940, 800);
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	xoacontro();
	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	
	srand(time(NULL));
	int xqua = 0, yqua = 0;

	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;
	int check = 2;
	while (gameover == false)
	{   gotoxy(50, 4);
		cout <<"Score: "<<diem;
		
		xoa_du_lieu_cu(toadox, toadoy);
		
		if (_kbhit())
		{
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && check != 0)
				{
					check = 1;
	
				}
				else if (kitu == 80 && check != 1)
				{
					check = 0;
				
				}
				else if (kitu == 77 && check != 3)
				{
					check = 2;
				}
				else if (kitu == 75 && check != 2)
				{
					check = 3;
				}
			}
		}
	
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		
		gameover = kt_ran(toadox, toadoy);
		Sleep(150);
	}
	cout << "\a";
	Sleep(200);
	choi();
}

void choi(){
	VeHinh(30, 9, "-----------------------------------------------------------", 187);
	 VeHinh(30, 10, "-----------------------------------------------------------", 187);
    VeHinh(30, 11, "-----------------------------------------------------------", 187);
    VeHinh(30, 12, "-----------------------------------------------------------", 187);
    VeHinh(30, 13, "-----------------------------------------------------------", 187);
    VeHinh(30, 14, "-----------------------------------------------------------", 187);
	 VeHinh(30, 15, "-----------------------------------------------------------", 187);
    VeHinh(30, 16, "-----------------------------------------------------------", 187);
    VeHinh(30, 17, "-----------------------------------------------------------", 187);
    VeHinh(30, 18, "-----------------------------------------------------------", 187);
    VeHinh(30, 19, "-----------------------------------------------------------", 187);
	 VeHinh(30, 20, "-----------------------------------------------------------", 187);
    VeHinh(30, 21, "-----------------------------------------------------------", 187);
    VeHinh(30, 22, "-----------------------------------------------------------", 187);
    VeHinh(30, 23, "-----------------------------------------------------------", 187);
    VeHinh(30, 24, "-----------------------------------------------------------", 187);
	VeHinh(30, 25, "-----------------------------------------------------------", 187);
    VeHinh(30, 26, "-----------------------------------------------------------", 187);
    VeHinh(30, 27, "-----------------------------------------------------------", 187);
	for(int i = 9; i <= 27; i++){
		VeHinh(29, i, "||", 187);
		VeHinh(89, i, "||", 187);
	}
	VeHinh(50, 14, "DIEM CUA BAN LA:", 190);
	gotoxy(66, 14); textcolor(190); cout << diem; textcolor(7);
	VeHinh(48, 16, "BAN CO MUON CHOI LAI KHONG", 190);
	VeHinh(54, 19, "KHONG", 78);
	VeHinh(62, 19, "CO", 190);
		while(true){
		if(kbhit())
	{ 
	char d = getch();
				if(d == 13){
					system("cls");
				resizeConsole(940, 800);
	xoacontro();
	VeHinh(30, 9, "-----------------------------------------------------------", 68);
    VeHinh(30, 10, "-----------------------------------------------------------", 187);
    VeHinh(30, 11, "-----------------------------------------------------------", 187);
    VeHinh(30, 12, "-----------------------------------------------------------", 187);
    VeHinh(30, 13, "-----------------------------------------------------------", 187);
    VeHinh(30, 14, "-----------------------------------------------------------", 187);
	VeHinh(30, 15, "-----------------------------------------------------------", 136);
    VeHinh(30, 16, "-----------------------------------------------------------", 170);
	VeHinh(30, 17, "-----------------------------------------------------------", 170);
    VeHinh(30, 18, "-----------------------------------------------------------", 170);
	VeHinh(30, 19, "-----------------------------------------------------------", 136);
	VeHinh(30, 20, "-----------------------------------------------------------", 170);
    VeHinh(30, 21, "-----------------------------------------------------------", 170);
    VeHinh(30, 22, "-----------------------------------------------------------", 170);
	VeHinh(30, 23, "-----------------------------------------------------------", 136);
	VeHinh(30, 24, "-----------------------------------------------------------", 170);
    VeHinh(30, 25, "-----------------------------------------------------------", 170);
    VeHinh(30, 26, "-----------------------------------------------------------", 170);
	VeHinh(30, 27, "-----------------------------------------------------------", 68);
	vechu();
	ve_khung();
	dieukhien();
				}
	else if(GetAsyncKeyState(VK_LEFT))
		{
			//cout << "\nBan chon NO";
			VeHinh(54, 19, "KHONG", 78);
	        VeHinh(62, 19, "CO", 190);
	        while(true){
	        		if(kbhit())
	{ 
	        	char d = getch();
				if(d == 13){
					system("cls");
				resizeConsole(940, 800);
	xoacontro();
	VeHinh(30, 9, "-----------------------------------------------------------", 68);
    VeHinh(30, 10, "-----------------------------------------------------------", 187);
    VeHinh(30, 11, "-----------------------------------------------------------", 187);
    VeHinh(30, 12, "-----------------------------------------------------------", 187);
    VeHinh(30, 13, "-----------------------------------------------------------", 187);
    VeHinh(30, 14, "-----------------------------------------------------------", 187);
	VeHinh(30, 15, "-----------------------------------------------------------", 136);
    VeHinh(30, 16, "-----------------------------------------------------------", 170);
	VeHinh(30, 17, "-----------------------------------------------------------", 170);
    VeHinh(30, 18, "-----------------------------------------------------------", 170);
	VeHinh(30, 19, "-----------------------------------------------------------", 136);
	VeHinh(30, 20, "-----------------------------------------------------------", 170);
    VeHinh(30, 21, "-----------------------------------------------------------", 170);
    VeHinh(30, 22, "-----------------------------------------------------------", 170);
	VeHinh(30, 23, "-----------------------------------------------------------", 136);
	VeHinh(30, 24, "-----------------------------------------------------------", 170);
    VeHinh(30, 25, "-----------------------------------------------------------", 170);
    VeHinh(30, 26, "-----------------------------------------------------------", 170);
	VeHinh(30, 27, "-----------------------------------------------------------", 68);
	vechu();
	ve_khung();
	dieukhien();
				}
				else if(GetAsyncKeyState(VK_RIGHT)){
					break;
				}
			}
		}
	}

	 else if(GetAsyncKeyState(VK_RIGHT))
		{
			
			VeHinh(54, 19, "KHONG", 190);
	        VeHinh(62, 19, "CO", 78);
	        while(true){
	        		if(kbhit())
	{ 
	        	char d = getch();
				if(d == 13){
					 diem = 0;
					ran();
				
				}
				else if(GetAsyncKeyState(VK_LEFT)){
				 break;
				}
			}
		}
	}
	}
}  

}

void dieukhien(){
	while(true)
	{
		if(kbhit())
		{
		 	char c = getch();
		 	if(c == '1')
		 	{
		 	VeHinh(58, 12,"MENU", 190);
	        VeHinh(57, 17,"1.BAT DAU", 198);
	        VeHinh(56, 21,"2.HUONG DAN", 174);
	        VeHinh(57, 25,"3.THOAT", 174);
	        while(true){
	        	if(kbhit())
		{
	        	char d = getch();
				if(d == 13){
					ran();
					
				}
				else if(d == '2'){
					break;
				}
				else if(d == '3'){
					break;
				}
			}
		}
		 	}

		else if(c == '2')
		 	{
		 	VeHinh(58, 12,"MENU", 190);
	        VeHinh(57, 17,"1.BAT DAU", 174);
	        VeHinh(56, 21,"2.HUONG DAN", 198);
	        VeHinh(57, 25,"3.THOAT", 174);
	        while(true){
	        		if(kbhit())
		{
	        	char d = getch();
				if(d == 13){
				system("cls");
	ifstream FileIn;
	FileIn.open("ran2.txt", ios::in);
    while(!FileIn.eof())
	{
		char d;
		FileIn.get(d);
		Sleep(100);
		textcolor(14);
		cout << d;
		textcolor(7);
	if(kbhit())
	{   
	    XoaManHinh();
		ifstream filein1;
	    filein1.open("ran2.txt", ios::in);
		string y;
		textcolor(14);
	    DOC_FILE_1(y, filein1);
	    textcolor(7);
	    filein1.close();
	    break;
}
}
FileIn.close();

ve_thoat_2();
}
else if(d == '1'){
					break;
				}
else if(d == '3'){
					break;
				}
		}
	}
}
		else if(c == '3')
		 	{
		 	VeHinh(58, 12,"MENU", 190);
	        VeHinh(57, 17,"1.BAT DAU", 174);
	        VeHinh(56, 21,"2.HUONG DAN", 174);
	        VeHinh(57, 25,"3.THOAT", 198);
	        while(true){
	        	if(kbhit())
		{
	        	char d = getch();
				if(d == 13){
					ve_thoat_1();
				}
				else if(d == '1'){
					break;
				}
				else if(d == '2'){
					break;
				}
			}
		}
		  	}
		}
	}
}
int main(){
	resizeConsole(940, 800);
	xoacontro();
	menu();
	vechu();
	ve_khung();
	dieukhien();
    return 0;
}
