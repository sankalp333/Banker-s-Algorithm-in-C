
//Bankers algorithm for 5 processes with 3 resources

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
//Declaring the variables
int gd=DETECT,gm,i,j,k,l,m,s,num=5,temp[5]={0,0,0,0,0},counter=0,counter1=0,left,right,top,x,y,msg1[50],alloc[5][3],max[5][3],need[5][3],available[1][3],xcor[5],ycor[5],x1cor[3],y1cor[3];
char msg[10];
clrscr();
//Giving input to the allocation matrix
for(i=0;i<5;i++)
{
for(j=0;j<3;j++)
{
  printf("\nEnter the allocation matrix value for process(%d)-Resource(%d) :",(i+1),(j+1));
  scanf("%d",&alloc[i][j]);
}
}
//Giving input to the max matrix
for(i=0;i<5;i++)
{
for(j=0;j<3;j++)
{
printf("\nEnter the max matrix value for process(%d)-Resource(%d) :",(i+1),(j+1));
scanf("%d",&max[i][j]);
}
}
//Giving input to the available matrix
for(i=0;i<1;i++)
{
for(j=0;j<3;j++)
{
printf("\nEnter the available matrix value-Resource(%d) :",(j+1));
scanf("%d",&available[i][j]);
}
}
//Finding out the need matrix
for(i=0;i<5;i++)
{
for(j=0;j<3;j++)
{
need[i][j]=max[i][j]-alloc[i][j];
}
}
//Initialising the graphics mode
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
cleardevice();
setcolor(BLUE);
left=getx();
top=gety();
//Printing out the allocation matrix table
outtextxy(25,10,"Process");
outtextxy(135,10,"A");
outtextxy(210,10,"B");
outtextxy(270,10,"C");
rectangle(left,top,left+300,top+200);
rectangle(left,top,left+180,top+200);
rectangle(left,top,left+100,top+200);
rectangle(left,top,left+250,top+200);
rectangle(left,top,left+300,top+35);
x=getx()+35;
y=gety()+45;
for(i=0;i<5;i++)
{
sprintf(msg,"P[%d]",(i+1));
moveto(x,y);
outtext(msg);
y=y+35;
}
x=x+100;
y=y-175;
for(i=0;i<5;i++)
{
for(j=0;j<3;j++)
{
sprintf(msg,"%d",alloc[i][j]);
moveto(x,y);
outtext(msg);
x=x+70;
}
x=x-(3*70);
y=y+35;
}
outtextxy(x-40,y,"Allocation Matrix");
//Printing out the max matrix table
setcolor(RED);
left=getx()+40;
top=gety()-185;
outtextxy(345,10,"Process");
outtextxy(460,10,"A");
outtextxy(535,10,"B");
outtextxy(595,10,"C");
rectangle(left,top,left+300,top+200);
rectangle(left,top,left+180,top+200);
rectangle(left,top,left+100,top+200);
rectangle(left,top,left+250,top+200);
rectangle(left,top,left+300,top+35);
x=getx()+75;
y=gety()-141;
for(i=0;i<5;i++)
{
sprintf(msg,"P[%d]",(i+1));
moveto(x,y);
outtext(msg);
y=y+35;
}
x=x+105;
y=y-175;
for(i=0;i<5;i++)
{
for(j=0;j<3;j++)
{
sprintf(msg,"%d",max[i][j]);
moveto(x,y);
outtext(msg);
x=x+70;
}
x=x-(3*70);
y=y+35;
}
outtextxy(x-20,y,"Max Matrix");
//Printing out the need matrix table
setcolor(GREEN);
left=getx()-610;
top=gety()+50;
outtextxy(25,245,"Process");
outtextxy(135,245,"A");
outtextxy(210,245,"B");
outtextxy(270,245,"C");
rectangle(left,top,left+300,top+200);
rectangle(left,top,left+180,top+200);
rectangle(left,top,left+100,top+200);
rectangle(left,top,left+250,top+200);
rectangle(left,top,left+300,top+35);
x=getx()-575;
y=gety()+95;
for(i=0;i<5;i++)
{
sprintf(msg,"P[%d]",(i+1));
moveto(x,y);
outtext(msg);
y=y+35;
}
x=x+100;
y=y-175;
for(i=0;i<5;i++)
{
for(j=0;j<3;j++)
{
sprintf(msg,"%d",need[i][j]);
moveto(x,y);
outtext(msg);
x=x+70;
}
x=x-(3*70);
y=y+35;
}
outtextxy(x-20,y,"Need Matrix");
//To print the available matrix
setcolor(YELLOW);
rectangle(430,260,530,240);
rectangle(430,260,460,240);
rectangle(430,260,490,240);
outtextxy(407,270,"Available Resources");
for(i=0;i<3;i++)
{
y1cor[i]=247;
}
x1cor[0]=440;
x1cor[1]=470;
x1cor[2]=505;
for(i=0;i<3;i++)
{
moveto(x1cor[i],y1cor[i]);
sprintf(msg,"%d",available[0][i]);
outtext(msg);
}
//To print the execution order
setcolor(MAGENTA);
rectangle(430,360,580,330);
rectangle(430,360,550,330);
rectangle(430,360,520,330);
rectangle(430,360,490,330);
rectangle(430,360,460,330);
outtextxy(445,370,"Execution Order");
for(i=0;i<5;i++)
{
ycor[i]=343;
}
xcor[0]=440;
xcor[1]=467;
xcor[2]=497;
xcor[3]=527;
xcor[4]=557;
getch();
s=0;
 for(k=0;k<3;k++)
 {
 for(i=0;i<5;i++)
 {
 if(temp[i]!=1)
 {
 for(j=0;j<3;j++)
 {
 if(need[i][j]<=available[0][j])
 {
 counter++;
 }
 }
 if(counter==3)
 {
  temp[i]=1;
  counter1++;
  for(m=0;m<3;m++)
  {
  available[0][m]+=alloc[i][m];
  }
  setcolor(YELLOW);
  setfillstyle(SOLID_FILL,BLACK);
  bar(420,260,530,240);
  rectangle(430,260,530,240);
  rectangle(430,260,460,240);
  rectangle(430,260,490,240);
  moveto(xcor[s],ycor[s]);
  sprintf(msg,"P%d",i);
  outtext(msg);
  for(l=0;l<3;l++)
  {
  moveto(x1cor[l],y1cor[l]);
  sprintf(msg,"%d",available[0][l]);
  outtext(msg);
  }
  s++;
 }
 counter=0;
 getch();
 }
 }
 }
 if(counter1==5)
 {
 setcolor(GREEN);
 outtextxy(420,420,"Result:Steady State");
 }
 else
 {
 setcolor(RED);
 outtextxy(420,420,"Result:Deadlock");
 }
getch();
closegraph();
}
