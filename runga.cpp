#include<iostream>
#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#endif
using namespace std;
float given_function(float x,float y)
{
	return (x*y*y);
	}
	int main()
{
	
	float x,y,k[4],h,ye;
	int i;
	cout<<FYEL("Y'(X) = X*Y*Y");
	x=1;
	y=1.5;
	h=0.1;
	k[0]=h*given_function(x,y);
	k[1]=h*given_function(x+(h/2),y+(k[0]/2));
	k[2]=h*given_function(x+(h/2),y+(k[1]/2));
	k[3]=h*given_function(x+h,y+k[2]);
	cout<<FRED("\n Using Runga 4th order Y(1.1)= ")<<((k[0]+2*(k[1]+k[2])+k[3])/6)+y;
	
	h=0.01;
	ye=y;
	for(i=0;i<10;i++)
	{
		ye=ye+h*given_function(x,ye);
		}
		cout<<FGRN("\n Using Elur's Y(1.1)= ")<<ye;
		
	k[0]=h*given_function(x,y);
	k[1]=h*given_function(x+(h/2),y+(k[0]/2));
	k[2]=h*given_function(x+h,y-k[0]+(k[1]*2));
	cout<<FBLU("\n Using 3rd Order Y(1.1)= ")<<y+(1/6)*(k[0]+(4*k[1])+k[2]);
	return 0;
	}
