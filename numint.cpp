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
class numint{
int n,num,i,opt;
double intr,upper,lower,val,ans,arr[52],ans1;
public:
void menu();
void tap();
void simot();
void simte();
};
void numint::menu()
{cout<<BOLD(FGRN("Enter no of intervals:"));
	cin>>n;
	cout<<BOLD(FGRN("Enter the Upper limit:"));
	cin>>upper;
	cout<<BOLD(FGRN("Enter the Lower limit:"));
	cin>>lower;
	intr=(upper-lower)/n;
	val=lower;
	cout<<BOLD(FBLU("\nEnter the output at given interval:"))<<endl;
	for(i=0;i<=n;i++)
	{
		
		cout<<FMAG("Interval:")<<"\x1B[32m"<<i+1<<FMAG(":F(")<<"\x1B[32m"<<val<<FMAG("):");
		cin>>arr[i];
		val=val+intr;
		}
		cout<<endl<<FRED("1)Trapezoidal rule")
		<<endl<<FGRN("2)Simpson's 1/3 rule")
		<<endl<<FMAG("3)Simpson's 3/8 rule")
		<<endl<<FCYN("4)By all three rules")
		<<endl<<"Enter through which rule you want integrate:";
		cin>>opt;
		switch(opt)
		{
			case 1:tap();
				break;
			case 2:simot();
			break;
			case 3:simte();
			break;
			case 4:	tap();
						simot();
						simte();
						break;
		}
		
	}
	void numint::tap()
	{
		ans=0;
		for(i=1;i<n;i++)
		{
			ans=ans+arr[i];
			}
		ans=2*ans;
		ans=ans+arr[0]+arr[n];
		ans=(intr/2)*ans;
		cout<<endl<<FRED("By Trapezoidal Answer is :")<<ans;
		}
	void numint::simot()
	{
		ans=0;
		ans1=0;
		for(i=1;i<n;i++)
		{if(i%2==0)
			{
				ans=ans+arr[i];
				}
				else
				{
					ans1=ans1+arr[i];
					}
			}
			ans=2*ans;
			ans1=ans1*4;
			ans=(intr/3)*(arr[0]+arr[n]+ans+ans1);
			cout<<endl<<FGRN("By Simpson's 1/3 Answer is:")<<ans;
		}
	void numint::simte()
	{
		ans=0;
		ans1=0;
		for(i=1;i<n;i++)
		{if(i%3==0)
			{
				ans=ans+arr[i];
				}
				else
				{
					ans1=ans1+arr[i];
					}
			}
			ans=2*ans;
			ans1=ans1*3;
			ans=(intr*3/8)*(arr[0]+arr[n]+ans+ans1);
			cout<<endl<<FMAG("By Simpson's 3/8 Answer is:")<<ans;
		}
int main()
{
numint obj;
obj.menu();
return 0;
}
