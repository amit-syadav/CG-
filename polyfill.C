#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void BoundFill(int x, int y, int F_color, int B_color){

	int current=getpixel(x,y);
	if(current!=B_color&&current!=F_color){
		putpixel(x,y,F_color);
		delay(2);
		BoundFill(x+1,y,F_color,B_color);
		BoundFill(x-1,y,F_color,B_color);
		BoundFill(x,y+1,F_color,B_color);
		BoundFill(x,y-1,F_color,B_color);
	}
}


void FloodFill(int x, int y, int F_color, int A_color){

	int current=getpixel(x,y);
	if(current==A_color&&current!=F_color){
		putpixel(x,y,F_color);
		delay(50);
		FloodFill(x+1,y,F_color,A_color);
		FloodFill(x-1,y,F_color,A_color);
		FloodFill(x,y+1,F_color,A_color);
		FloodFill(x,y-1,F_color,A_color);
	}
}

int main(){

	int gd=DETECT,points[10]={50,50,100,50,100,100,50,100,50,50};
	int gm=0;
	int x,y;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter coordinates of point inside given polygon:");
	scanf("%d%d",&x,&y);

	drawpoly(5,points);

	BoundFill(x,y,BLUE,WHITE);
	FloodFill(x,y,RED,BLUE);

	getch();
	closegraph();
	return 0;
}