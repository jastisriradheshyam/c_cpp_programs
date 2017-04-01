#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;
struct prob
{
	int v;
	double p;
	double val;
};
class deviation
	{
		double mean,tmean,std_dev,z,P,val;
		int opt,sample;
		prob obj;
		public:
		void menu();
		void input();
		void calculate();
		void tdist(int v,double p);
		void ndist(int n);
		void show();
	};
	void deviation::input()
	{
		cout<<"Enter sample size:";
		cin>>sample;
		cout<<"Enter its mean:";
		cin>>mean;
		cout<<"Enter mean of the population:";
		cin>>tmean;
		cout<<"Enter the standard deviation:";
		cin>>std_dev;
		z=(mean-tmean)/(std_dev);
		calculate();
	}
	void deviation::menu()
	{
		
		if(sample<=30)
		{
			cout<<"\nEnter P as ( 0.50 ) or ( 0.10 ) or ( 0.05 ) or ( 0.02 ) or(  0.01 ) : ";
			cin>>P;
			tdist((sample-1),P);
		}
		else
		{
			cout<<"\n1) for 5% level of significance";
			cout<<"\n2) for 1% level of significance";
			cin>>opt;
			ndist(opt);
		}
	}
	void deviation::calculate()
	{
			if(sample>30)
		{
			z=z*sqrt(sample);
		}
		else
		{
			z=z*sqrt(sample-1);
		}
	}
	
	void deviation::tdist(int v,double p)
	{
		
		fstream f("ttable.txt",ios::in|ios::binary);
		while(f.read((char*)&obj,sizeof(obj)))
		{
			
			if((obj.v == v))
			{
				if(obj.p <= p)
				{val=obj.val;
				break;}
			}
		}
		f.close(); 
	}
	void deviation::ndist(int n)
	{
		val=1.96;
		if(opt==1)
		val=1.96;
		else if(opt==2)
		val=2.58;
	}
	void deviation::show()
	{
		if(z<0)
		{
			z=(-z);
			}
		cout<<"\nz ="<<z<<" and value="<<val;
		cout<<"\nSelected or not selected:";
		if(sample<=30)
		{
			if(z<=val)
			{
				cout<<" SELECTED";
			}
			else
			{
				cout<<" NOT SELECTED";
			}
		}
		if(sample>30)
		{
			if(z<=val)
			{
				cout<<" SELECTED";
			}
			else
			{
				cout<<" NOT SELECTED";
			}
		}
	}
int main()
{
	deviation obj;
	char y;
	do{
	obj.input();
	obj.menu();
	obj.show();
	cout<<"Enter Y/N to do another calculation:";
	cin>>y;
	}while(y=='y'||y=='Y');
	return 0;
}

