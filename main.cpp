#include <iostream>
#include "csl.h"
#include<Windows.h>
#include<stdlib.h>
using namespace std;
#define X 30
#define Y 30
char A[6];
char SP[6];
enum TrangThai{UP, DOWN, LEFT, RIGH,STAND, UL, UR, DL,DR};

struct Go
{
    int x;
    int y;
    int live=1;
    TrangThai tt;
};Go Go;
struct Ball
{
    int x;
    int y;
    int live=1;
    TrangThai tt;
}; Ball Ball[5];

int spd=100;
void xuat();
void khoitao();
void diChuyen();
void xuLyPhim();
void xuLyBall();
void xoa();
void doiTro();
void xuatKhung();
void tocDo();
int main()
{
   // for(int i=0;i<=255;i++)
   // {
   //     cout<<i<<(char)i<<endl;
   // }
   khoitao();
   xuatKhung();
   while(1){
        //clrscr();
        xuLyPhim();
        xuLyBall();
        diChuyen();
        xuat();
        Sleep(spd);
        xoa();
        if(Ball[0].live);
        else break;
   }
    return 0;
}
void doiTro()
{
    gotoxy(140,0);
}
void xoa()
{
    gotoxy(Go.x,Go.y);
        puts(SP);
        doiTro();
    gotoxy(Ball[0].x,Ball[0].y);
        printf(" ");
        doiTro();
}
void chamBien()
{
    if(Ball[0].x==X+5&&Ball[0].y==Y)
    {
        if(Ball[0].x<Go.x-1||Ball[0].x>=Go.x+7)// xu ly Ball cham mep' tam van
            Ball[0].live=0;
        else{
        Ball[0].tt=UL;}
    }
    if(Ball[0].x==0&&Ball[0].y==0)
    {
        Ball[0].tt=DR;
    }
    if(Ball[0].x==X+5&&Ball[0].y==0)
    {
        Ball[0].tt=DL;
    }
    if(Ball[0].x==0&&Ball[0].y==Y)
    {
        if(Ball[0].x<Go.x-1||Ball[0].x>=Go.x+7)// xu ly Ball cham mep' tam van
            Ball[0].live=0;
        else{
        Ball[0].tt=UR;
        spd-=5;
        }
    }
    if(Ball[0].x==X+5&&Ball[0].y>0&&Ball[0].y<Y)//bien phai
    {
        if(Ball[0].tt==UR)
            Ball[0].tt=UL;
        else
            Ball[0].tt=DL;
    }
    if(Ball[0].x==0&&Ball[0].y>0&&Ball[0].y<Y)//bien trai
    {
        if(Ball[0].tt==UL)
            Ball[0].tt=UR;
        else
            Ball[0].tt=DR;
    }
    if(Ball[0].y==0&&Ball[0].x>0&&Ball[0].x<X+6)//bien tren
    {
        if(Ball[0].tt==UL)
            Ball[0].tt=DL;
        else
            Ball[0].tt=DR;
    }
    if(Ball[0].y==Y-1&&Ball[0].x>0&&Ball[0].x<X)//bien duoi
    {
        if(Ball[0].x<Go.x-1||Ball[0].x>=Go.x+6)// xu ly Ball cham mep' tam van
            Ball[0].live=0;
        else{
            if(Ball[0].tt==DL){
                Ball[0].tt=UL;
                spd-=10;
                }
            else{
                Ball[0].tt=UR;
                spd-=10;
            }
        }
    }

}
void xuLyBall()
{
    chamBien();
    if(Ball[0].tt==UR&&(Ball[0].x<X+6&&Ball[0].y>0))
    {
        Ball[0].x++;
        Ball[0].y--;
    }
    if(Ball[0].tt==UL&&(Ball[0].x>0&&Ball[0].y>0))
    {
        Ball[0].x--;
        Ball[0].y--;
    }
    if(Ball[0].tt==DR&&(Ball[0].x<X+6&&Ball[0].y<Y))
    {
        Ball[0].x++;
        Ball[0].y++;
    }
    if(Ball[0].tt==DL&&(Ball[0].x>0&&Ball[0].y<Y))
    {
        Ball[0].x--;
        Ball[0].y++;
    }
}
void diChuyen()
{

    if(Go.tt==LEFT&&Go.x>=2){
        Go.x-=2;
        Go.tt=STAND;
    }
    if(Go.tt==RIGH&&Go.x<=X-2){
        Go.x+=2;
        Go.tt=STAND;
    }
}
void xuLyPhim()
{
    if(_kbhit())
    {
        char k;
        k=_getch();
       if(k=='d'||k=='D')
           Go.tt=RIGH;
        if(k=='a'||k=='A')
            Go.tt=LEFT;
    }
}
void khoitao()
{
    for(int i=0;i<6;i++)
        SP[i]=' ';
    for(int i=0;i<6;i++)
        A[i]=254;
    Go.x=0;
    Go.y=Y;
    Go.tt=STAND;
    Ball[0].x=Go.x+2;
    Ball[0].y=Go.y-1;
    Ball[0].tt=UR;
    Ball[0].live=1;
}
void xuatKhung()
{
    for(int i=0;i<=Y+1;i++)
    {
        gotoxy(X+6,i);
        printf("|");
    }
}
void xuat()
{

    //xuatKhung();
    gotoxy(Go.x,Go.y);
    puts(A);
    doiTro();
    if(Ball[0].live){
    gotoxy(Ball[0].x,Ball[0].y);
    puts("o");
    doiTro();
    }
    else {printf("GAME OVER");}
}
