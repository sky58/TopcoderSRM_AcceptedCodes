//SRM365DIV1-300 PointsOnCircle
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
typedef long long lint;
#define pb push_back
class PointsOnCircle{
	public:
	long long PointsOnCircle::count(int a){
		vector <lint> ya,ya2;
		int iti=0,san=0,i,j,n;
		while(a%2==0) a/=2;
		for(i=1;i*i<=a;i++){
			if(a%i==0) ya.pb(i);
		}
		n=ya.size();for(i=0;i<n;i++) ya.pb(a/ya[i]);
		for(i=0;i<ya.size();i++) for(j=0;j<ya.size();j++) ya2.pb(ya[i]*ya[j]);
		sort(ya2.begin(),ya2.end());
//		for(i=0;i<ya2.size();i++) cout<<ya2[i]<<'\n';
		if(ya2[0]%4==1) iti++;else san++;
		for(i=1;i<ya2.size();i++){
			if(ya2[i]==ya2[i-1]) continue;
			if(ya2[i]%4==1) iti++;else san++;
		}
		return 4*(iti-san);
	}
};
