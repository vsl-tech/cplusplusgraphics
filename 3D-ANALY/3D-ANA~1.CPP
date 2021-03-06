#include<dos.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
//#include<t2m.h>
#include<dir.h>
#include<time.h>
REGS regs;
int ON=1,OFF=0,DUAL_CUBE=OFF,cube_x=200,cube_y=250,COLOR=15,LINE_MODE=OFF,SPEED=4,SHADOW=OFF;
double x1,x2,y1,y2,theta=0,LENGTH=1.05,BREATH=1.05,HEIGHT=1.05;

void vp_(int x,int tc,int bk,char *text);
void User();
void rotate(double edge[20][3]);
void draw_cube(double edge[20][3]);
void Help_Page1xxx(int x,int y);
void mini_window(int x,int y,char caption[]);
void ButtonOn(int xaxis,int yaxis,double fclr,double bclr,char caption[]);

void Rotate_x();
void Rotate_y();
void Rotate_z();
void logo(int x,int y);

void clear()
{ if(SHADOW==OFF){clearviewport();}  if(SHADOW==ON){delay(3);}
}
/*int getkey()//--------------------------------------
 {
 union REGS i,o;  while(!kbhit());  i.h.ah=0;  int86(22,&i,&o);
 return(o.h.ah);
 } //------------------------------------------------- */
void load()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   { clrscr();
   printf("GRAPHICS ERROR: %s\n", grapherrormsg(errorcode));
   printf(" PRESS ANY KEY TO EXIT or RESTART THE PROGRAME.");
   getch();
   }
}

void main()
{
load();
//int gd=DETECT,gm; initgraph(&gd,&gm,"..\\bgi");
//if (registerbgidriver(_EGAVGA_driver) < 0) exit(1); line(0,a2,700,a2);delay(3);

FILE *log;
time_t t;time(&t); log=fopen("K3D_CUBE.txt","a+");
	 fputs("\n\nkrishx007@yahoo.com\n3D-cube.",log);
	 fputs("Time Accessed:",log);fputs(ctime(&t),log);

regs.x.ax=1;int86(0x33,&regs,&regs);
User();
}

void draw_cube(double edge[20][3])
{      setcolor(COLOR);
    if(SHADOW==ON){int R=random(16);if(R<10)R=15;setcolor(R);}

       for(int i=0;i<19;i++)
	      {
	       if(LINE_MODE==ON) { setlinestyle(1,0,3);  }

	       x1=edge[i][0]+edge[i][2]*(cos(2.3562));
	       y1=edge[i][1]-edge[i][2]*(sin(2.3562));
	       x2=edge[i+1][0]+edge[i+1][2]*(cos(2.3562));
	       y2=edge[i+1][1]-edge[i+1][2]*(sin(2.3562));

	       line(x1+cube_x, cube_y-y1, x2+cube_x, cube_y-y2);
	       setlinestyle(0,0,1);

	if(DUAL_CUBE==ON)
	{ line(x1+cube_x+130,cube_y-y1+50,x2+cube_x+130,cube_y-y2+50);
	}
settextstyle(2,0,4);
setcolor(12);line(20,240,20,220);outtextxy(22,215,"Z");//z
setcolor(14);line(20,240,40,240);outtextxy(40,240,"X");//x
setcolor(2);line(20,240,10,250);outtextxy(10,250,"Y");//y
setcolor(COLOR);
	     }
}
////////////////////////////////////////////////////

double edge[20][3]=
{100,0,0, 100,100,0, 0,100,0, 0,100,100, 0,0,100, 0,0,0, 100,0,0, 100,0,100,
100,75,100, 75,100,100, 100,100,75, 100,100,0, 100,100,75, 100,75,100,
75,100,100, 0,100,100, 0,100,0, 0,0,0, 0,0,100, 100,0,100};

void  User()
{//------------------------------------------------


   char A;
  int TUNE=OFF;
  setbkcolor(1);
   char msg[80];
  float CUBE_SIZE=1.05;
  for(int X=0,XX=0;;X=X+1,XX++)
  {
 // X=X+1;
  if(X==9){X=5;}
   regs.x.ax=3;int86(0x33,&regs,&regs);

   while(kbhit())  A=getch(); if(A=='x'||A=='X')exit(0);
   if(A=='f'||A=='F')
   {setviewport(0,0,getmaxx(),getmaxy(),3);clear(); draw_cube(edge);
   delay(500);clear();
 //  for(int a2=0;a2<480;a2=a2+2){line(0,a2,700,a2);setcolor(5);}

   setcolor(15);//mouse position bar
   setfillstyle(7,7);
   bar(0,0,getmaxx(),getmaxy());

   logo(585,20); vp_(80,2,12,""); User();
   }


   time_t t; time(&t);
   gotoxy(1,1);  printf("%d|%d|%d\nTME|%d",regs.x.cx,regs.x.dx,X,time(&t),theta);

if(X==2) { // int RR= random(3);
       setcolor(15);
       sprintf(msg," Started- %s",ctime(&t) );
      settextstyle(0,0,1); outtextxy(80,44,msg);
       setcolor(COLOR);}



///////////////////////////////////////////////left mouse botton printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n %s",ctime(&t));
if(X==4){setviewport(8,56,getmaxx()-221,getmaxy()-11,3);clearviewport();draw_cube(edge);}
if(X==1){

 ///  setcolor(7);//mouse position bar
   setfillstyle(6,8);
   bar(0,0,getmaxx(),getmaxy());
for(int a2=0;a2<480;a2=a2+2)
{ line(0,a2,700,a2);setcolor(5);/*5*///line(0,a2+1,700,a2+1);setcolor(1);
  /*1*/}
logo(585,20);vp_(80,2,12,"");}

if(X==1)
{   setcolor(15);
    setfillstyle(1,4);
    fillellipse(520,120,20,60 );// up & down

    fillellipse(520,120,60,20);//left & right

   setcolor(2);
   setfillstyle(9,2);
   circle(520,120,24);
   floodfill(520,120,2);

  setcolor(6);circle(520,120,66);setcolor(2);circle(520,120,67);
  circle(520,120,68);circle(520,120,69);//for green circle suround auto
  setcolor(14);
  settextstyle(0,0,1);outtextxy(457,80,"   UP  ^^    ");
  settextstyle(0,0,1);outtextxy(425,115,"LEFT <<<  AUTO  >>>  RIGHT");
  settextstyle(0,0,1);outtextxy(457,153,"       vv  DOWN    ");
  setcolor(15);
  settextstyle(2,0,5);outtextxy(435,30,"  MOUSE CONTROLES ");
  settextstyle(2,0,4);outtextxy(420,187,"  ROTATION        FORWARD  REVERS");
  outtextxy(180,43,"   ");outtextxy(425,269," EXTRA SETTING       OPTIONS");
}

//center (auto)
if(regs.x.bx==1&&regs.x.cx>=500&&regs.x.dx>=100&&regs.x.cx<=540&&regs.x.dx<=140||A=='c')
  {  setcolor(COLOR);

     {setviewport(8,56,getmaxx()-221,getmaxy()-11,3);
      regs.x.bx=0;sound(1000);delay(200);nosound();  rotate(edge); sound(100);delay(5);nosound();
      draw_cube(edge);
     }
  }

//up
if(regs.x.bx==1&&regs.x.cx>=500&&regs.x.dx>=60&& regs.x.cx<=540&&regs.x.dx<=100)//up
 {
 while(regs.x.bx==1)
  {
   regs.x.ax=3;int86(0x33,&regs,&regs);
   setviewport(8,56,getmaxx()-221,getmaxy()-11,3);  clear();
   cube_y= cube_y-5;  draw_cube(edge); sound(100);delay(5);nosound();
  }
 }

//down
if(regs.x.bx==1&&regs.x.cx>=500&&regs.x.dx>=140&& regs.x.cx<=540&&regs.x.dx<=175)//up
 {
 while(regs.x.bx==1)
  {
 regs.x.ax=3;int86(0x33,&regs,&regs);
 setviewport(8,56,getmaxx()-221,getmaxy()-11,3);  clear();
 cube_y= cube_y+5;  draw_cube(edge); sound(100);delay(5);nosound();
  }
 }
//left
if(regs.x.bx==1&&regs.x.cx>=450&&regs.x.dx>=100&& regs.x.cx<=500&&regs.x.dx<=140)//up
 {
 while(regs.x.bx==1)
  {
  regs.x.ax=3;int86(0x33,&regs,&regs);
  setviewport(8,56,getmaxx()-221,getmaxy()-11,3);  clear();
  cube_x= cube_x-5;  draw_cube(edge); sound(300);delay(5);nosound();
  }
 }
//right
if(regs.x.bx==1&&regs.x.cx>=540&&regs.x.dx>=100&& regs.x.cx<=570&&regs.x.dx<=140)//up
 {
 while(regs.x.bx==1)
  {
  regs.x.ax=3;int86(0x33,&regs,&regs);
  setviewport(8,56,getmaxx()-221,getmaxy()-11,3);  clear();
  cube_x= cube_x+5;  draw_cube(edge); sound(300);delay(5);nosound();
  }
 }
//------------------
if(X==1){
	ButtonOn(430,200,14,8,"                     >>");
	ButtonOn(430,200,14,8,"             <<  ");
	ButtonOn(430,200,15,7,"X axis -   ");
	}
// X axsis <<<
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=200&& regs.x.cx<=570&&regs.x.dx<=220||A=='a')
{
 // while(regs.x.bx==1)
  {
  Rotate_x();  theta=theta+SPEED;sound(300); delay(5);nosound();
  }
}
// X axsis >>>
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=200&& regs.x.cx<=620&&regs.x.dx<=220)
{
  while(regs.x.bx==1)
   {
     Rotate_x(); theta=theta-SPEED;sound(300); delay(5);nosound();
   }
}
//------------------
if(X==1){
	ButtonOn(430,225,14,8,"                     >>");
	ButtonOn(430,225,14,8,"             <<  ");
	ButtonOn(430,225,15,7,"Y axis -   ");
	}
// Y axsis <<<
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=225&& regs.x.cx<=570&&regs.x.dx<=242)
{
  while(regs.x.bx==1)
   {
   Rotate_y();   theta=theta+SPEED; sound(300); delay(5); nosound();
   }
}
// Y axsis >>>
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=225&& regs.x.cx<=620&&regs.x.dx<=242)
 {
  while(regs.x.bx==1)
   {
    Rotate_y(); theta=theta-SPEED; sound(300);delay(5);nosound();
   }
 }
//------------------
if(X==1){
	ButtonOn(430,250,14,8,"                     >>");
	ButtonOn(430,250,14,8,"             <<  ");
	ButtonOn(430,250,15,7,"Z axis -   ");
	}
// Z axsis <<<
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=250&& regs.x.cx<=570&&regs.x.dx<=270)
{
 while(regs.x.bx==1)
  {
   Rotate_z(); theta=theta+SPEED;sound(300); delay(5); nosound();
  }
}

// Z axsis >>>
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=250&& regs.x.cx<=620&&regs.x.dx<=270)
{
 while(regs.x.bx==1)
 {
   Rotate_z();  theta=theta-SPEED; sound(300); delay(5); nosound();
 }
}
//---------------------------


if(X==1){
	ButtonOn(430,280,14,4,"                    OFF");
	ButtonOn(430,280,14,4,"             ON  ");
	ButtonOn(430,280,5,2,"DUAL CUBE  ");
	}
// DUAL CUBE ON
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=280&& regs.x.cx<=570&&regs.x.dx<=300)
{
   regs.x.ax=3;int86(0x33,&regs,&regs);
  setviewport(8,56,getmaxx()-221,getmaxy()-11,3);  clear();
  DUAL_CUBE=ON; draw_cube(edge);sound(300); delay(50); nosound();// draw_cube(edge[20][3]);
}
// DUAL CUBE OFF
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=280&& regs.x.cx<=620&&regs.x.dx<=300)
{
 DUAL_CUBE=OFF;clear(); draw_cube(edge); sound(300); delay(5); nosound();//draw_cube(edge[20][3]);
}
//----------------------
if(X==1){
	ButtonOn(430,300,14,4,"                    OFF");
	ButtonOn(430,300,14,4,"             ON  ");
	ButtonOn(430,300,5,2,"SHADOW     ");
	}
// SHADOW ON
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=300&& regs.x.cx<=570&&regs.x.dx<=320)
{
   regs.x.ax=3;int86(0x33,&regs,&regs);
  setviewport(8,56,getmaxx()-221,getmaxy()-11,3);  clear();
  SHADOW=ON; draw_cube(edge);sound(300); delay(50); nosound();// draw_cube(edge[20][3]);
}
// SHADOW OFF
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=300&& regs.x.cx<=620&&regs.x.dx<=320)
{
 SHADOW=OFF;clear(); draw_cube(edge); sound(300); delay(5); nosound();//draw_cube(edge[20][3]);
}
//-------------------------
if(X==1){
	ButtonOn(430,320,14,12,"                     --");
	ButtonOn(430,320,14,12,"             ++  ");
	ButtonOn(430,320,15,12,"SIZE       ");
	}

//CUBE SIZE ++
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=320&& regs.x.cx<=570&&regs.x.dx<=340)
{  for(int i=0;i<20;i++)
		{ edge[i][0]=edge[i][0]*CUBE_SIZE;
		  edge[i][1]=edge[i][1]*CUBE_SIZE;
		  edge[i][2]=edge[i][2]*CUBE_SIZE;
		 }
   clear();draw_cube(edge);sound(300);delay(50);nosound();
}
//CUBE SIZE --
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=320&& regs.x.cx<=620&&regs.x.dx<=340)
{   for(int i=0;i<20;i++)
		{ edge[i][0]=edge[i][0]/CUBE_SIZE;
		  edge[i][1]=edge[i][1]/CUBE_SIZE;
		  edge[i][2]=edge[i][2]/CUBE_SIZE;
		}
    clear(); draw_cube(edge);sound(300);delay(50);nosound();
}
//----------------------
if(X==1){
	ButtonOn(430,340,14,4,"                     --");
	ButtonOn(430,340,14,4,"             ++  ");
	ButtonOn(430,340,15,2,"LENGTH     ");
	}
//CUBE LENGTH ++
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=340&& regs.x.cx<=570&&regs.x.dx<=360)
{  for(int i=0;i<20;i++)
		{ edge[i][0]=edge[i][0]*LENGTH;
		  edge[i][1]=edge[i][1];
		  edge[i][2]=edge[i][2];
		 }
   clear();draw_cube(edge);sound(300);delay(50);nosound();
}
//CUBE LENGTH --
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=340&& regs.x.cx<=620&&regs.x.dx<=360)
{   for(int i=0;i<20;i++)
		{ edge[i][0]=edge[i][0]/LENGTH;
		  edge[i][1]=edge[i][1];
		  edge[i][2]=edge[i][2];
		}
    clear(); draw_cube(edge);sound(300);delay(50);nosound();
}
//--------------------------------
if(X==1){
	ButtonOn(430,360,14,4,"                     --");
	ButtonOn(430,360,14,4,"             ++  ");
	ButtonOn(430,360,15,2,"BREADTH    ");
	}
//CUBE BREADTH ++
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=360&& regs.x.cx<=570&&regs.x.dx<=380)
{  for(int i=0;i<20;i++)
		{ edge[i][0]=edge[i][0];
		  edge[i][1]=edge[i][1];
		  edge[i][2]=edge[i][2]*BREATH;
		 }
   clear();draw_cube(edge);sound(300);delay(50);nosound();
}
//CUBE BREADTH --
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=360&& regs.x.cx<=620&&regs.x.dx<=380)
{   for(int i=0;i<20;i++)
		{ edge[i][0]=edge[i][0];
		  edge[i][1]=edge[i][1];
		  edge[i][2]=edge[i][2]/BREATH;
		}
    clear(); draw_cube(edge);sound(300);delay(50);nosound();
}
//-------------------------------
if(X==1){
	ButtonOn(430,380,14,4,"                     --");
	ButtonOn(430,380,14,4,"             ++  ");
	ButtonOn(430,380,15,2,"HEIGHT     ");
	}
//CUBE HEIGHT ++
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=380&& regs.x.cx<=570&&regs.x.dx<=400)
{  for(int i=0;i<20;i++)
		{ edge[i][0]=edge[i][0];
		  edge[i][1]=edge[i][1]*HEIGHT;
		  edge[i][2]=edge[i][2];
		 }
   clear();draw_cube(edge);sound(300);delay(50);nosound();
}
//CUBE HEIGHT --
if(regs.x.bx==1&&regs.x.cx>=570&&regs.x.dx>=380&& regs.x.cx<=620&&regs.x.dx<=400)
{   for(int i=0;i<20;i++)
		{ edge[i][0]=edge[i][0];
		  edge[i][1]=edge[i][1]/HEIGHT;
		  edge[i][2]=edge[i][2];
		}
    clear(); draw_cube(edge);sound(300);delay(50);nosound();
}

//----------------------
if(X==1){
	ButtonOn(430,405,14,4,"                    +3 ");
	ButtonOn(430,405,14,4,"               +2 ");
	ButtonOn(430,405,14,4,"          +1 ");
	ButtonOn(430,405,01,2," <SPEED>");
	}
//SPEED +1
if(regs.x.bx==1&&regs.x.cx>=500&&regs.x.dx>=405&& regs.x.cx<=540&&regs.x.dx<=420)
{    SPEED=2;  draw_cube(edge);sound(300);delay(50);nosound();
}
//SPEED +2
if(regs.x.bx==1&&regs.x.cx>=540&&regs.x.dx>=405&& regs.x.cx<=580&&regs.x.dx<=420)
{    SPEED=6;  draw_cube(edge);sound(600);delay(50);nosound();
}
//SPEED +1
if(regs.x.bx==1&&regs.x.cx>=580&&regs.x.dx>=405&& regs.x.cx<=620&&regs.x.dx<=420)
{   SPEED=10;  draw_cube(edge);sound(900);delay(50);nosound();
}
//-----------------------
//------------------------
if(X==1){
	ButtonOn(430,425,14,12,"              <CREDIT> ");
      //ButtonOn(430,380,14,4,"             ++  ");
	ButtonOn(430,425,14,12," <REFRESH> ");
	}
//CUBE REFRESH
if(regs.x.bx==1&&regs.x.cx>=430&&regs.x.dx>=425&& regs.x.cx<=525&&regs.x.dx<=440)
{
 clearviewport();DUAL_CUBE=OFF,cube_x=200,cube_y=250;
 double edge2[20][3]={100,0,0, 100,100,0, 0,100,0, 0,100,100, 0,0,100, 0,0,0, 100,0,0, 100,0,100,
 100,75,100, 75,100,100, 100,100,75, 100,100,0, 100,100,75, 100,75,100,
 75,100,100, 0,100,100, 0,100,0, 0,0,0, 0,0,100, 100,0,100};
    for(int i=0;i<20;i++)
	       {  edge[i][0]=edge2[i][0];
		  edge[i][1]=edge2[i][1];
		  edge[i][2]=edge2[i][2];
	       }
 clear(); draw_cube(edge);sound(3);delay(50);nosound();
}
//CREDIT
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=425&& regs.x.cx<=620&&regs.x.dx<=440)
{mini_window(100,40,"");
 ButtonOn(260,100,14,6,"   OK   ");logo(300,52);
 setcolor(4); settextstyle(2,0,4); outtextxy(105,60,"Programed by Krishna Kumar");
 setcolor(11); outtextxy(105,70,"                          ");setcolor(4);
 outtextxy(105,80,"Email-krishx007@yahoo.com"); outtextxy(105,90,"Website-www.gfxguru.net,India,2010");
 for(int i=0;i<30;i++){sound(80*i);delay(i);}
 sound(800);delay(200);sound(1500);delay(300);sound(500);delay(200);nosound();
   while(regs.x.bx!=2)
   { if(regs.x.bx==1&&regs.x.cx>=270&&regs.x.dx>=160&& regs.x.cx<=340&&regs.x.dx<=175){break;}//exit
     delay(70);regs.x.ax=3;int86(0x33,&regs,&regs);
   }
  clearviewport();draw_cube(edge);
}
//------------------------
if(X==1){
	ButtonOn(430,445,14,12,"              <POUSE>  ");
      //ButtonOn(430,380,14,4,"             ++  ");
	ButtonOn(430,445,14,12,"<FULL SCRN>");
	}
//CUBE FULL SCREEN
if(regs.x.bx==1&&regs.x.cx>=430&&regs.x.dx>=445&& regs.x.cx<=525&&regs.x.dx<=460)
{ setviewport(0,0,getmaxx(),getmaxy(),3);clear(); draw_cube(edge);
  delay(650);clear(); X=0; clear(); draw_cube(edge);sound(300);delay(50);nosound();
}
//POUSE
if(regs.x.bx==1&&regs.x.cx>=520&&regs.x.dx>=445&& regs.x.cx<=620&&regs.x.dx<=460)
{
sound(3000);delay(50);nosound();
while(1)
  {  setcolor(random(16));int R1=random(600);
      int R4=random(400); int  R=random(15);
     for (int x=0;x<150;x=x+1)
   circle(R4,R1,x );setcolor(R);
  delay(50);regs.x.ax=3;int86(0x33,&regs,&regs); if(regs.x.bx==1){break;}
    }

clear(); draw_cube(edge);sound(300);delay(50);nosound();
}
//-------------------------
if(X==1)ButtonOn(190,2,14,6,"[ 3-D CUBE ANALYSE SYSTEM ]");
//-------------------------
if(X==1)
{
setcolor(15);//mouse position bar
setfillstyle(7,7);
bar(0,0,80,50);
rectangle(0,0,80,50);
}
if(regs.x.bx==1&&regs.x.cx>=1&&regs.x.dx>=1&& regs.x.cx<=80&&regs.x.dx<=50)
 {sound(300);delay(500);nosound();}
//---------------
if(X==1)ButtonOn(570,2,14,8,"<EXIT>");
if(regs.x.bx==1&&regs.x.cx>=572&&regs.x.dx>=1&& regs.x.cx<=623&&regs.x.dx<=20)
{
   mini_window(100,40,"Do you want to exit ?"); sound(3000);delay(50);nosound();
   ButtonOn(120,100,4,2,"   YES  ");
   ButtonOn(260,100,4,2,"   NO   ");
    while(1)
  {
  sound(500);delay(50);nosound();delay(100);regs.x.ax=3;int86(0x33,&regs,&regs);
  if(regs.x.bx==1&&regs.x.cx>=130&&regs.x.dx>=160&& regs.x.cx<=200&&regs.x.dx<=175){exit(1);}
  if(regs.x.bx==1&&regs.x.cx>=270&&regs.x.dx>=160&& regs.x.cx<=340&&regs.x.dx<=175){clearviewport();draw_cube(edge);break;}
  }
}
//--------------
if(X==1)ButtonOn(500,2,4,7,"<CLEAR>");
if(regs.x.bx==1&&regs.x.cx>=500&&regs.x.dx>=1&& regs.x.cx<=560&&regs.x.dx<=17)
{ sound(800);delay(50);nosound();setviewport(8,56,getmaxx()-221,getmaxy()-11,3);clearviewport();draw_cube(edge);
}
//--------------
if(X==1)ButtonOn(424,2,4,7," <HELP> ");
if(regs.x.bx==1&&regs.x.cx>=431&&regs.x.dx>=1&& regs.x.cx<=483&&regs.x.dx<=19)
  {  Help_Page1xxx(-100,-100);
  }
//--------------
if(X==1)ButtonOn(90,2,4,7,"<  LINE  >");
if(regs.x.bx==1&&regs.x.cx>=90&&regs.x.dx>=1&& regs.x.cx<=175&&regs.x.dx<=19)
 {
  clearviewport();
  mini_window(100,40,"Choose the line style _ _"); sound(3000);delay(50);nosound();
   ButtonOn(120,100,14,2,"PlanLine");
   ButtonOn(260,100,14,2,"Dot Line");
  while(1)
  { delay(100);regs.x.ax=3;int86(0x33,&regs,&regs);
   if(regs.x.bx==1&&regs.x.cx>=130&&regs.x.dx>=160&& regs.x.cx<=200&&regs.x.dx<=175){LINE_MODE=OFF;break;}//plan line
   if(regs.x.bx==1&&regs.x.cx>=270&&regs.x.dx>=160&& regs.x.cx<=340&&regs.x.dx<=175){LINE_MODE=ON;break;}//dot line
  }
  clearviewport();draw_cube(edge);
  sound(800);delay(50);nosound();regs.x.ax=3;int86(0x33,&regs,&regs);
 }
//--------------
if(X==1)ButtonOn(90,25,4,7,"< COLOUR >");
if(regs.x.bx==1&&regs.x.cx>=90&&regs.x.dx>=24&& regs.x.cx<=175&&regs.x.dx<=41)
 {
   mini_window(100,40,"");sound(800);delay(50);nosound();
   ButtonOn(130,60,4,2,"Select Color");
   outtextxy(130,190,"Mouse Right click for OK");
   ButtonOn(260,100,14,6,"   OK   ");
   while(regs.x.bx!=2)
   {
    ButtonOn(270,60,4,COLOR,"        ");
    if(regs.x.bx==1){ COLOR=COLOR-1;sound(800);delay(50);nosound(); }
    delay(70);regs.x.ax=3;int86(0x33,&regs,&regs);
   if(regs.x.bx==1&&regs.x.cx>=270&&regs.x.dx>=160&& regs.x.cx<=340&&regs.x.dx<=175){break;}//exit
   }
  clearviewport();draw_cube(edge);
}
//--------------
if(X==1)ButtonOn(190,25,8,7,"<WORKING WITH TUNE");
if(regs.x.bx==1&&regs.x.cx>=190&&regs.x.dx>=24&& regs.x.cx<=348&&regs.x.dx<=41)
 { sound(800);delay(50);nosound();   TUNE =ON;
 }
//--------------
if(X==1)ButtonOn(343,25,8,7,"STOP TUNE>");
if(regs.x.bx==1&&regs.x.cx>=350&&regs.x.dx>=24&& regs.x.cx<=412&&regs.x.dx<=41)
 { TUNE=OFF;
 }
///////////////////////////////////////////////left mouse botton end
if(TUNE==ON){sound(regs.x.cx*10);delay(10);sound(regs.x.dx*10);delay(10);nosound();}


 if(regs.x.bx==1)//if left mouse botton pushed
    {
    setcolor(COLOR);
    circle(regs.x.cx,regs.x.dx,3);
    circle(regs.x.cx,regs.x.dx,2);circle(regs.x.cx,regs.x.dx,1);draw_cube(edge);
    }
//=======================
  if(regs.x.bx==3)//if both mouse botton pushed
  {
   circle(regs.x.cx,regs.x.dx,10);draw_cube(edge);
  }
//====================
  if(regs.x.bx==2)//if right mouse botton pushed
  {  setcolor(COLOR);
     setviewport(8,56,getmaxx()-221,getmaxy()-11,3);
     draw_cube(edge);   rotate(edge);
     clear();
   }
//-------------------

 }//for while
}//------------------------------------------------end user

//////////////////////////////////////////////////////////////////

 void rotate(double edge[20][3])
      {
       double temp,theta=0,temp1;
       while(regs.x.bx!=1)
       {
	 theta=(theta*3.14)/180;regs.x.ax=3;int86(0x33,&regs,&regs);
	 for(int i=0;i<20;i++)
	  {
	   edge[i][0]=edge[i][0];
	   temp=edge[i][1];
	   temp1=edge[i][2];
	   edge[i][1]=temp*cos(theta)-temp1*sin(theta);
	   edge[i][2]=temp*sin(theta)+temp1*cos(theta);
	  }
	 draw_cube(edge);
	 delay(10);theta=theta+SPEED;
	 clear();
      } //for while
  draw_cube(edge);
}

////////////////////////////////////////////////////

//--------------------------------------------
void Rotate_x()
{
      double temp,temp1;
      setviewport(8,56,getmaxx()-221,getmaxy()-11,3);    clear();
      theta=(theta*3.14)/180; regs.x.ax=3;int86(0x33,&regs,&regs);
    for(int i=0;i<20;i++)
      {
      edge[i][0]=edge[i][0];
      temp=edge[i][1];
      temp1=edge[i][2];
      edge[i][1]=temp*cos(theta)-temp1*sin(theta);
      edge[i][2]=temp*sin(theta)+temp1*cos(theta);
       }
   draw_cube(edge);
}
//------------------------------------------
void Rotate_y()
{
      double temp,temp1;
      setviewport(8,56,getmaxx()-221,getmaxy()-11,3);    clear();
      theta=(theta*3.14)/180; regs.x.ax=3;int86(0x33,&regs,&regs);
       for(int i=0;i<20;i++)
       {
       edge[i][2]=edge[i][2];
       temp=edge[i][0];
       temp1=edge[i][1];
       edge[i][0]=temp*cos(theta)-temp1*sin(theta);
       edge[i][1]=temp*sin(theta)+temp1*cos(theta);
       }
       draw_cube(edge);
}//-----------------------------------------
//----------------------------------------------
void Rotate_z()
{
   double temp,temp1;
   setviewport(8,56,getmaxx()-221,getmaxy()-11,3); clear();
   theta=(theta*3.14)/180; regs.x.ax=3;int86(0x33,&regs,&regs);
      for(int i=0;i<20;i++)
	{
	 edge[i][1]=edge[i][1];
	 temp=edge[i][0];
	 temp1=edge[i][2];
	 edge[i][0]=temp*cos(theta)+temp1*sin(theta);
	 edge[i][2]=-temp*sin(theta)+temp1*cos(theta);
	}
   draw_cube(edge);
}
void vp_(int x,int tc,int bk,char *text)
{//-------------------------------
  setcolor(tc);
  settextstyle(2,0,5);
  outtextxy(x,-4,text);
  setcolor(bk);

setcolor(13);
rectangle(1,1,getmaxx()-1,getmaxy()-1);

setcolor(2);//for frame of cube
rectangle(4,52,getmaxx()-217,getmaxy()-7);
rectangle(5,53,getmaxx()-218,getmaxy()-8);
rectangle(6,54,getmaxx()-219,getmaxy()-9);
setcolor(6);
rectangle(7,55,getmaxx()-220,getmaxy()-10);
 }//--------------------------------
void ButtonOn(int xaxis,int yaxis,double fclr,double bclr,char caption[])
	     {
	      int length=strlen(caption);length=(length*8)+6;
	      setfillstyle(1,bclr);bar(xaxis,yaxis,xaxis+length,yaxis+18);
	      settextstyle(0,0,1);
	      setcolor(fclr);outtextxy(xaxis+2,yaxis+5,caption);
	      setcolor(15);
	      line(xaxis,yaxis,xaxis+length,yaxis);
	      line(xaxis,yaxis,xaxis,yaxis+18);
	      setcolor(0);
	      line(xaxis,yaxis+18,xaxis+length,yaxis+18);
	      line(xaxis+length,yaxis,xaxis+length,yaxis+18);
	     }

//--------------------------------
 void Help_Page1xxx(int x,int y)
	   {
	      setviewport(8,56,getmaxx()-221,getmaxy()-11,3);

	     setfillstyle(1,7);bar(120+x,150+y,420+x,450+y);
	     setcolor(15);
	     line(120+x,150+y,120+x,450+y);line(120+x,150+y,420+x,150+y);
	     setcolor(7);
	     line(120+x,450+y,420+x,450+y);line(420+x,150+y,420+x,450+y);
	     line(124+x,176+y,415+x,176+y);
	     setfillstyle(1,7);bar(124+x,154+y,416+x,446+y);
	     setfillstyle(1,1);bar(125+x,155+y,415+x,175+y);
	     setcolor(15);outtextxy(160+x,160+y,"3-D CUBE ANALYSE SYSTEM [HELP] ");
	     ButtonOn(150+x,420+y,11+x,8+y,"  Press Mouse Left Button  ");


	     setfillstyle(1,8);bar(125+x,177+y,415+x,400+y);
	     settextstyle(2,0,4);setcolor(15);
	     outtextxy(380+x,175+y,"Page:1");
	     setcolor(14);
	     outtextxy(130+x,175+y,"PROGRAMED BY");
	     line(130+x,187+y,200+x,187+y);
	     outtextxy(130+x,235+y,"HELP IMFORMATION");
	     line(130+x,247+y,210+x,247+y);

	     settextstyle(2,0,4);setcolor(11);
	     outtextxy(130+x,190+y,"Krishna Kumar,                          ");
	     outtextxy(130+x,205+y,"Branch-CSE BERI BHOPAL(M.P)");
	     outtextxy(130+x,220+y,"       krishx007@yahoo.com                      ");

	     outtextxy(130+x,250+y,"This is a programe for anaylsing  3-DIMENSIONAL ");
	     outtextxy(130+x,265+y,"CUBE or CUBOID. Gernaly student or people face");
	     outtextxy(130+x,280+y,"problem to understand 3-D figure in mathematics ");
	     outtextxy(130+x,295+y,"and physics.And the rotation of 3D cube about  ");
	     outtextxy(130+x,310+y,"X,Y and Z axces.From this software you can under");
	     outtextxy(130+x,325+y,"stand all things easily. You can rotate the cube ");
	     outtextxy(130+x,340+y,"about all three exces both FORWARD and REVERSE. ");
	     outtextxy(130+x,355+y,"Even you can keep the cube in AUTOMATIC ROTASION");
	     outtextxy(130+x,370+y,"from AUTO button in the center. You can change  ");
	     setcolor(15);outtextxy(180+x,385+y,"All rights reserved.(2007 - 2008) ");

	     delay(500);regs.x.bx=0;
	     while(regs.x.bx!=1){int86(0x33,&regs,&regs);}
	     setcolor(11);
	     setfillstyle(1,8);bar(125+x,177+y,415+x,400+y);
	     outtextxy(130+x,175+y,"                                                 ");
	     outtextxy(130+x,190+y,"CUBE INTO CUBOID with your required shape & size ");
	     outtextxy(130+x,205+y,"from EXTRA SETTING. This is a GUI programe so you");
	     outtextxy(130+x,220+y,"can simply operate it.You can WRITE or highlight");
	     outtextxy(130+x,235+y,"any thing in CUBE SCREEN.It is very interesting  ");
	     outtextxy(130+x,250+y,"programe if you are facing any problem with the  ");
	     outtextxy(130+x,265+y,"shape of cube.You can refresh it by REFRESH butt.");
	     outtextxy(130+x,280+y,"This program require EGAVGA.bgi file for runing ");
	     outtextxy(130+x,295+y,"and one *.chr file.You can contact me to ask any ");
	     outtextxy(130+x,310+y,"question.");
 setcolor(14);outtextxy(130+x,340+y,"     =========== THANKS TO ==========           "); setcolor(11);
	     outtextxy(130+x,355+y,"SANTOSH MULLICK  (santoshmullick@rediffmail.com) ");
	     outtextxy(130+x,370+y,"RENJITH JOSEPH   For using some of his function.");
	     setcolor(15);outtextxy(180+x,385+y,"All rights reserved.(2007 - 2008)   ");

	     delay(500);regs.x.bx=0;
	     while(regs.x.bx!=1){regs.x.ax=3;int86(0x33,&regs,&regs);}
	     setcolor(11);
	     setfillstyle(1,8);bar(125+x,177+y,415+x,400+y);
setcolor(14);outtextxy(130+x,175+y,"        XX COMMANDS ARE GIVEN BELOW XX          ");setcolor(11);
	     outtextxy(130+x,190+y,"LEFT,RIEGHT,UP etc.  To set the position of CUBE ");
	     outtextxy(130+x,205+y,"AUTO,ReightClick     For AUTOMATIC ROTASION	    ");
	     outtextxy(130+x,220+y,"X,Y,Z Rotation      <<  forward,    >>  reverse ");
	     outtextxy(130+x,235+y,"SPEED               To set the angular speed    ");
	     outtextxy(130+x,250+y,"DUAL CUBE           To show dual cube at a time ");
	     outtextxy(130+x,265+y,"REFRESH             To set  default shape of cube");
	     outtextxy(130+x,280+y,"LENGTH,SIZE etc.     ++ increase,  --  decrease ");
	     outtextxy(130+x,295+y,"COLOR               To change color of cube     ");
	     outtextxy(130+x,310+y,"LINE                To change line style of cube");
	     outtextxy(130+x,325+y,"CREDIT              To know the credit info.    ");
	     outtextxy(130+x,340+y,"HELP                For help and information    ");
	     outtextxy(130+x,355+y,"SHADOW              For showing the path of cube");
	     outtextxy(130+x,370+y,"WORKING WITH TUNE   For producing sound         ");
	     setcolor(15);outtextxy(180+x,385+y,"All rights reserved.(2007 - 2008)  ");


	     delay(500);regs.x.bx=0;
	     while(regs.x.bx!=1){regs.x.ax=3;int86(0x33,&regs,&regs);}

	    clearviewport();
	   draw_cube(edge); rotate(edge);
	   }
 //------------------------------
 void mini_window(int x,int y,char *caption)
     {
      //Drawing dialog boxes and title bar
      setfillstyle(1,7);
      bar(x,y,x+250,y+90);
      setcolor(15);
      line(x,y,x,y+90);line(x,y,x+250,y);
      setcolor(0);
      line(x+1,y+13,x+249,y+13);
      line(x,y+90,x+250,y+90);line(x+250,y+90,x+250,y);
      setfillstyle(1,8);
      bar(x+1,y+1,x+249,y+12);
      settextstyle(0,0,1);setcolor(14);
      outtextxy(x+1,y+3,"Child Window");
      setcolor(15);
      outtextxy(x+10,y+30,caption);

     }
//-------------------------
void logo(int x,int y)
{
setcolor(15); //body
moveto(15+x,10+y);
lineto(30+x,10+y);
lineto(15+x,35+y);
lineto(35+x,35+y);
lineto(23+x,23+y);
lineto(25+x,18+y);
lineto(15+x,10+y);

line(22+x,35+y,22+x,40+y);circle(22+x,40+y,1);//leg
line(28+x,35+y,28+x,40+y);circle(28+x,40+y,1);

setcolor(14);circle(22+x,12+y,1);//eye
setcolor(14);circle(23+x,25+y,19);//frame
settextstyle(2,0,3); outtextxy(7+x,20+y," K.    K");
}
