#include<iostream>
#include<fstream>
using namespace std;
struct prob
{
	int v;
	double p;
	double val;
};
int main()
{
	char y;int i=1;
	prob obj;
	fstream f("ttable.txt",ios::out|ios::app|ios::binary);
	do
	{
		cout<<"Enter v:";
		cout<<i;
		obj.v=i;
		cout<<"\n P: 0.50";
		obj.p=0.50;
		cout<<"\nEnter value:";
		cin>>obj.val;
		f.write((char*)&obj,sizeof(prob));
		cout<<"\n P: 0.10";
		obj.p=0.10;
		cout<<"\nEnter value:";
		cin>>obj.val;
		f.write((char*)&obj,sizeof(prob));
		cout<<"\n P: 0.05";
		obj.p=0.05;
		cout<<"\nEnter value:";
		cin>>obj.val;
		f.write((char*)&obj,sizeof(prob));
		cout<<"\n P: 0.02";
		obj.p=0.02;
		cout<<"\nEnter value:";
		cin>>obj.val;
		f.write((char*)&obj,sizeof(prob));
		cout<<"\n P: 0.01";
		obj.p=0.01;
		cout<<"\nEnter value:";
		cin>>obj.val;
		f.write((char*)&obj,sizeof(prob));
		cout<<"Enter more:";
		cin>>y;
		i++;
	}while(y=='y'||y=='Y');
	f.close();
	return 0;
}
