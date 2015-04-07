//SRM401DIV1-550 ParticleCollision

#include<stdio.h>
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;
#define pb push_back
bool kei(double a,double b){
	if(fabs(a-b)<10e-12) return true;
	return false;
}

class ParticleCollision{
	public:
	vector <double> ParticleCollision::collision(int vx,int vy,int vz,int x0,int y0,int z0){
		vector <double> out;int a,b,c;double t1,t2,t,z1,pi=3.14159265358979323846;
		
		a=vx*vx+vy*vy;b=(vx*x0+vy*y0)*2;c=x0*x0+y0*y0-1;
		if(a==0){
			if(c!=0) return out;
			if(vz!=0){out.pb(0.0);out.pb(0.0);out.pb(0.0);return out;}
			if((abs(z0)%2==0 && x0==1) || (abs(z0)%2==1 && x0==-1)){
				out.pb((double)x0);out.pb((double)y0);out.pb((double)z0);
			}
			return out;
		}
		
		if(b*b==4*a*c){
			t=(double)-b/a/2;z1=vz*t+z0;
			if(kei(sin(pi*z1),vy*t+y0) && kei(cos(pi*z1),vx*t+x0)){
				out.pb(vx*t+x0);out.pb(vy*t+y0);out.pb(z1);return out;
			}
			return out;
		}
		
		if(b*b<4*a*c) return out;
		t1=-sqrt((double)b*b-4*a*c)-b;t1/=(2*a);
		t2=sqrt((double)b*b-4*a*c)-b;t2/=(2*a);
		z1=vz*t1+z0;
		if(kei(sin(pi*z1),vy*t1+y0) && kei(cos(pi*z1),vx*t1+x0)){
			out.pb(vx*t1+x0);out.pb(vy*t1+y0);out.pb(z1);
		}
		z1=vz*t2+z0;//out.pb(vx*t2+x0);out.pb(vy*t2+y0);out.pb(z1);return out;
//		out.pb(cos(pi*z1));out.pb(sin(pi*z1));out.pb(z1);return out;
		if(!kei(sin(pi*z1),vy*t2+y0) || !kei(cos(pi*z1),vx*t2+x0)) return out;
		if(out.size()==3){
			out[0]=0.0;out[1]=0.0;out[2]=0.0;return out;
		}
		out.pb(vx*t2+x0);out.pb(vy*t2+y0);out.pb(z1);
		return out;
	}
};
