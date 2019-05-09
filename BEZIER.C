//100 100,200 200,300,200,400,100//
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void curve(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd)
{
	int xab,yab,xbc,ybc,xcd,ycd,xabc,yabc,xbcd,ybcd,xabcd,yabcd;
	xab=(xa+xb)/2;
	yab=(ya+yb)/2;
	putpixel(xab,yab,100);

	xbc=(xb+xc)/2;
	ybc=(yb+yc)/2;
	putpixel(xbc,ybc,100);

	xcd=(xc+xd)/2;
	ycd=(yc+yd)/2;
	putpixel(xcd,ycd,100);

	line(xab,yab,xbc,ybc);
	line(xbc,ybc,xcd,ycd);

	xabc=(xab+xbc)/2;
	yabc=(yab+ybc)/2;
	putpixel(xabc,yabc,100);

	xbcd=(xbc+xcd)/2;
	ybcd=(ybc+ycd)/2;
	putpixel(xbcd,ybcd,100);

	line(xabc,yabc,xbcd,ybcd);

	xabcd=(xabc+xbcd)/2;
	yabcd=(yabc+ybcd)/2;
	putpixel(xabcd,yabcd,100);

	if(xa==xabcd && ya==yabcd)
	return;

	if (xd==xabcd && yd==yabcd)
	return;

	curve(xa,ya,xab,yab,xabc,yabc,xabcd,yabcd);
	curve(xabcd,yabcd,xbcd,ybcd,xcd,ycd,xd,yd);

}
void main()
{
	int gd=DETECT,gm=0;
	int xa,ya,xb,yb,xc,yc,xd,yd;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter 1st Control Point ");
	scanf("%d %d",&xa,&ya);
	printf("ENter 2nd Control Point ");
	scanf("%d %d",&xb,&yb);
	printf("Enter 3rd Control Point ");
	scanf("%d %d",&xc,&yc);
	printf("Enter 4th Control Point ");
	scanf("%d %d",&xd,&yd);

	line(xa,ya,xb,yb);
	line(xb,yb,xc,yc);
	line(xc,yc,xd,yd);

	curve(xa,ya,xb,yb,xc,yc,xd,yd);
	getch();
}

