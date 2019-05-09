#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int sign(int x){
     if(x<0){
     return -1;
     }
     else if(x==0){
     return 0;
     }else{
     return 1;
     }
}

void main(){

int x1,y1,x2,y2,dy,dx,x,y,step,i=1,ch,th,j;

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

	if(dx>=dy){
	  step=dx;
	}else{
	  step=dy;
	}

	dx=(x2-x1)/step;
	dy=(y2-y1)/step;

	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);

	printf("Line type: 1.Normal 2.Dashed 3.Dotted 4.Thick :");
	scanf("%d",&ch);

	switch(ch){

	case 1:
		while(i<=step){
		x=x+dx;
		y=y+dy;
		putpixel(x,y,RED);
		i++;
		}
		break;

	case 2:
		while(i<=step){
		x=x+dx;
		y=y+dy;
		if(x%5==0){
		continue;
		}
		putpixel(x,y,RED);
		i++;
		}
		break;

	case 3:
		while(i<=step){
		x=x+dx;
		y=y+dy;
		if(x%2==0){
		continue;
		}
		putpixel(x,y,RED);
		i++;
		}
		break;

	case 4:
		printf("Enter Thickness(pixels): ");
		scanf("%d",&th);
		while(i<=step){
		x=x+dx;
		y=y+dy;
		putpixel(x,y,RED);
		for(j=th;j>=0;j--){
		putpixel(x+j,y,RED);
		}
		i++;
		}
		break;
      }
 }

getch();
}