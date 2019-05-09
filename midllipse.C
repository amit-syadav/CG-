#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
void main()
{
	float rx,ry,xc,yc,xk,yk,x0,y0,pk1,pk2;
	int gd=DETECT;
	int gm=0;

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	printf("Enter the radius of minor and major axis:\n");
	scanf("%f%f",&rx,&ry);
	printf("Enter center co-ordinates of ellipse\n");
	scanf("%f%f",&xc,&yc);

	x0=0;
	y0=ry;
	xk=x0;
	yk=y0;

	pk1=(ry*ry)-rx*rx*ry+(1/4)*rx*rx;

	//Region 1
	while(2*xk*ry*ry<2*yk*rx*rx) {

		putpixel(xk+xc,yk+yc,BLUE);
		putpixel(xk+xc,-yk+yc,BLUE);
		putpixel(-xk+xc,yk+yc,BLUE);
		putpixel(-xk+xc,-yk+yc,BLUE);

		if(pk1<0) {
			xk+=1;
			yk=yk;
			pk1=pk1+(2*ry*ry)*xk+(ry*ry);
		}else{
			xk+=1;
			yk-=1;
			pk1+=(2*ry*ry)*xk-(2*rx*rx)*yk+(ry*ry);
		}
	}
	//Region 2

	pk2=(ry*ry*(x0+0.5)*(x0+0.5))+(rx*rx*(y0-1)*(y0-1))-(rx*rx*ry*ry);
	while(yk>0) {

	putpixel(xk+xc,yk+yc,BLUE);
	putpixel(xk+xc,-yk+yc,BLUE);
	putpixel(-xk+xc,yk+yc,BLUE);
	putpixel(-xk+xc,-yk+yc,BLUE);

		if(pk2>0) {
			xk=xk;
			yk-=1;
			pk2-=(2*rx*rx)*yk+(rx*rx);
		}else{
			xk+=1;
			yk-=1;
			pk2+=((2*ry*ry)*xk)-((2*rx*rx)*yk)+(rx*rx);
		}
	}
	getch();
	closegraph();
}