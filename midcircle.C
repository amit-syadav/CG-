#include<stdio.h>
#include<conio.h>
#include<graphics.h>


void main()
{
 int x,y,xc,yc,dp,r;
 int gd=DETECT;
 int gm=0;
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");;

 clrscr();

 printf("Enter center co ordinates of circle: ");
 scanf("%d %d",&xc,&yc);

 printf("\n Enter radius of circle: ");
 scanf("%d",&r);

 x=0;
 y=r;

 dp=(5-(4*r))/4;

 do{

	putpixel(x+xc,y+yc,BLUE);
	putpixel(x+xc,-y+yc,BLUE);
	putpixel(-x+xc,y+yc,BLUE);
	putpixel(-x+xc,-y+yc,BLUE);
	putpixel(y+xc,x+yc,BLUE);
	putpixel(y+xc,-x+yc,BLUE);
	putpixel(-y+xc,x+yc,BLUE);
	putpixel(-y+xc,-x+yc,BLUE);

	if(dp<0){
		x+=1;
		dp+=2*x+3;
	}else{
		x+=1;
		y-=1;
		dp+=2*x-2*y+5;
	}

 }while(x<=y);

 getch();

 }