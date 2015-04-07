//SRM381DIV1-500 TheHomework

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
int kei(int a,int b){
	if(b==0) return 0;
	if(b*2<=a) return 1;
	return kei(a-a/2,b-a/2)+1;
}

class TheHomework{
	public:
	int TheHomework::transform(vector <int> a,vector <int> b){
		int aa[1100],bb[1100];int f=0,out=1000,s=0,n,i;
		
		for(i=0;i<1100;i++){aa[i]=0;bb[i]=0;}
		for(i=0;i<a.size();i++) aa[a[i]]++;
		for(i=0;i<b.size();i++) bb[b[i]]++;
		for(i=0;i<=1000;i++){
			if(aa[i]>bb[i]) f+=(aa[i]-bb[i]);
			if(aa[i]<bb[i]) s+=(bb[i]-aa[i]);
		}
		n=a.size()-f;
		if(f==0 && s==0) return 0;
		int c[110];for(i=0;i<110;i++) c[i]=0;
//		for(i=1;i<=a.size();i++) c[i]=1;
		for(i=1;i<=a.size();i++) c[i]=0;
		for(i=a.size()+1;i<110;i++) c[i]=c[(i+1)/2]+1;
		
		for(i=0;i<=s;i++){
			if(f+i<s || n+f+i==1) continue;
			int t=0,k=n+f+i;t=c[k];
			t+=(s-i)/(k/2);
			if((s-i)%(k/2)!=0) t++;
			t+=kei(k,f+i-s);
			out=min(t,out);
		}
		
		return out;
	}
};
