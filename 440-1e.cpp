//SRM440DIV1-250 IncredibleMachineÅiï âÅj
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
#include<queue>
#include<deque>
using namespace std;
class IncredibleMachine{
	public:
	double IncredibleMachine::gravitationalAcceleration(vector <int> x,vector <int> y,int t){
		double time=0.0,v=0.0;
		for(int i=0;i<x.size()-1;i++){
			double s,v2;
			s=sin(atan2(y[i]-y[i+1],x[i+1]-x[i]));
			v2=sqrt(v*v+2*(y[i]-y[i+1]));
			time+=(v2-v)/s;v=v2;
		}
		return time*time/t/t;
	}
};
