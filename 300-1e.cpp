//SRM300DIV1-250 Dating
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
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
bool sumi[55];
class Dating{
	public:
	string Dating::dates(string a,int b){
		int n=a.size(),m=0,f,i,j,t=0,s;string ret="";memset(sumi,false,sizeof(sumi));
		for(i=0;i<n;i++){if(a[i]<='z' && a[i]>='a') m++;}f=n-m;
		for(i=0;i<m && i<f;i++){
			s=b;for(;;t++){if(!sumi[t%n]) s--;if(s<1) break;}
			if(a[t%n]<='z' && a[t%n]>='a'){
				char mi='Z'+1;int mii=-1;
				for(j=0;j<n;j++){
					if(a[j]<='Z' && a[j]>='A' && !sumi[j]){if(mi>a[j]){mi=a[j];mii=j;};}
				}
				ret+=a[t%n];ret+=a[mii];sumi[t%n]=true;sumi[mii]=true;
			}
			else{
				char mi='z'+1;int mii=-1;
				for(j=0;j<n;j++){
					if(a[j]<='z' && a[j]>='a' && !sumi[j]){if(mi>a[j]){mi=a[j];mii=j;};}
				}
				ret+=a[t%n];ret+=a[mii];sumi[t%n]=true;sumi[mii]=true;
			}
			if(i<m-1 && i<f-1) ret+=' ';
		}
		return ret;
	}
};
