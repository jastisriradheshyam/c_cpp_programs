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
double fun_newton(double x)  //Enter desired function
{
	return ((x*x*x*x)-x-10);
	}
double fun_newton_der(double x) //Enter the function derivative
{
	return (4*(x*x*x)-1);
	} 
int precision(float x1,float x2,int pre) //check the precision of the output floating point number.
{
	int p1,p2,i;
	p1=x1;
	p2=x2;
	if(p1==p2)
	{
		for(i=0;;i++)
		{
			x1=x1-p1;
			x2=x2-p2;
			p1=x1*10;
			p2=x2*10;
			if(p1!=p2||pre==i)
			{
				return i;
				}
			}
		}
		else
		{
			return pre+1;
			}
	}
int main() //main function
{
	int pre,i=0;
	double x,last_x;
	cout<<"Enter the precision:";
	cin>>pre;
	cout<<"Enter expected value:";
	cin>>x;
	do{
		last_x=x;
		i++;
		x=x-fun_newton(x)/fun_newton_der(x);
		cout<<FGRN("\n X=")<<x<<FBLU(" iteration:")<<i;
		}while(precision(x,last_x,pre)!=pre);
		cout<<FRED("\n Last value=")<<x;
}
