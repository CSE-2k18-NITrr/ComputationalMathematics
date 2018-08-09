#include <iostream>
#include<bits/stdc++.h>
using namespace std;

float error;
float prevx,curx;
float fn(float x,float a, float b,float c)
{
	float val;
	val = a*x*x+b*x+c;
	return val;
}

float biject(float r1,float r2,float a,float b,float c)
{
	int r3;
	r3 = (r1+r2)/2;
	if(fn(r3,a,b,c)>=error)
	{
		if(fn(r3,a,b,c)*fn(r1,a,b,c)<0)
		{
			r2 = r3;
		}
		else
		{
			r1 = r3;
		}
		biject(r1,r2,a,b,c);
	}
	else
		return r3;
}



int main() {
	float a,b,c, r1 ,r2,prec;
	cin>>a>>b>>c;
	cout<<"\nPlease enter the approximate interval of roots:\n";
	cin>>r1>>r2;
	cout<<"\nEnter Digits of precision\n";
	cin>>prec;
	error = pow(10,-1*prec)*0.5;
	float val1, val2;
	val1 = fn(r1,a,b,c);
	val2 = fn(r2,a,b,c);
	if(val1*val2 <0)
	{
		cout<<biject(r1,r2,a,b,c);

	}
	else
	{
		cout<<"\n Wrong Range";
	}
	return 0;
}
