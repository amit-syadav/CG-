#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>


void main(){

int x1,y1,x2,y2,dy,dx,x,y,dp;

int gd=DETECT;
int gm=0;
clrscr();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

printf("Enter starting pt co-ordinates: ");
scanf("%d %d",&x1,&y1);

printf("Enter end pt co-ordinates: ");
scanf("%d %d",&x2,&y2);

if(x1==x2&&y1==y2){
	putpixel(x1,y1,RED);
}else{

	dx=abs(x2-x1);
	dy=abs(y2-y1);

	dp=2*dy-dx;

	x=x1;
	y=y1;

	while(x!=x2||y!=y2){

		if(dp<0){
			x=x+1;
			dp=dp+2*dy;
		}else{
			x=x+1;
			y=y+1;
			dp=dp+2*dx-2*dy;
		}
		putpixel(x,y,RED);
	}
}
getch();
}