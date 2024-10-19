#include<bits/stdc++.h>
using namespace std;
	
	const int v0 = 17;
	const double k = 0.000125;
	const int x = 3;
	const int y = 4;
	const double z = 0.25;
	const double m = 0.032;
	const double k1 = k / m;
	const double g = 9.8;
	const double s = sqrt(x*x+y*y);
double realpoint (double theta,double v)
{
	double vx = v * cos(theta);
	double t = (exp(k1*s)-1) / (k1 * vx) ;cout<<"t:"<<t<<endl;
	double zactual = v*sin(theta)*t - 0.5*g*t*t;cout<<"此时射高"<<zactual<<endl;
	
	return zactual;
}
int main()
{
	double ztemp = z;
	double theta = atan(z/s);
	cout<<"初角度"<<theta<<endl; 
	double zactual = 0;
	for(int i =0;i<20;i++)
	{
		if(zactual<z)
		{
			zactual = realpoint(theta,v0);
			double dz=z-zactual;cout<<"误差"<<dz<<endl; 
			ztemp = ztemp + dz;cout<<"zt"<<ztemp<<endl;
			theta =atan(ztemp / s) ;
			cout<<"角度"<<theta<<endl;
			zactual = realpoint(theta,v0);
			cout<<"射高"<<zactual<<endl;
			i++;
			cout<<i; 
		}
		else break;
		
	}
	return 0;
}
