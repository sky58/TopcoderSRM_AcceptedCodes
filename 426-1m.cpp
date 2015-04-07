//SRM426DIV1-500 CatchTheMice

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
class CatchTheMice{
	public:
	double CatchTheMice::largestCage(std::vector <int> xp, std::vector <int> yp, std::vector <int> xv, std::vector <int> yv){
		double l=0.0, r=3000.0, a, b, amax, bmax, xmax, ymax, x, y, xmin, ymin;
		int i, n=xp.size();
		while(1){
			a=(l*2+r)/3, b=(l+r*2)/3;
			xmax=-10000000.0;ymax=xmax;xmin=10000000.0;ymin=xmin;
			for(i=0;i<n;i++){
				x=xp[i]+xv[i]*a;y=yp[i]+yv[i]*a;
				xmax=max(x,xmax);xmin=min(x,xmin);
				ymax=max(y,ymax);ymin=min(y,ymin);
			}
			amax=max(xmax-xmin,ymax-ymin);
			xmax=-10000000.0;ymax=xmax;xmin=10000000.0;ymin=xmin;
			for(i=0;i<n;i++){
				x=xp[i]+xv[i]*b;y=yp[i]+yv[i]*b;
				xmax=max(x,xmax);xmin=min(x,xmin);
				ymax=max(y,ymax);ymin=min(y,ymin);
			}
			bmax=max(xmax-xmin,ymax-ymin);
			if(r-l<10e-13) return amax;
			if(amax>bmax) l=a;else r=b;
		}
	}
};
