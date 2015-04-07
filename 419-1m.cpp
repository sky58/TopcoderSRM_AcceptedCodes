//SRM419DIV1-500 NimForK
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
int memo[55][25];
bool ka[55][55];
int k;
int kei(int a,int b){
	if(memo[a][b]>-1) return memo[a][b];
	if(a==0) return (1<<((b+k-1)%k));
	int ret=(1<<k),i,f=0;
	for(i=1;i<=a;i++){
		if(!ka[a][i]) continue;
//		if(a==i){ret=(1<<b);break;}
//		if(a==i) return (1<<b);
		int t=kei(a-i,(b+1)%k);
		if(t==(1<<b)){ret=t;break;}
		if(t&(1<<b)){
			if(ret&(1<<b)) ret=ret|t;
			else ret=t;
		}
		else{
			if(!(ret&(1<<b))){
				if(f==0) ret=t;else ret=ret|t;
			}
		}
		f=1;
	}
//	printf("%d %d %d\n",a,b,ret);
	return memo[a][b]=ret;
}
class NimForK{
	public:
	vector <int> NimForK::winners(int n,int K,vector <string> a){
		int i,j,ret,inf;vector <int> out;k=K;
		
		for(i=0;i<55;i++) for(j=0;j<25;j++) memo[i][j]=-1;
		for(i=0;i<n;i++){
			vector <int> b;istringstream sin(a[i]);
			for(int v;sin>>v;b.push_back(v));
			for(j=0;j<b.size();j++) ka[i+1][b[j]]=true;
		}
//		for(i=0;i<n;i++) for(j=0;j<n;j++) if(ka[i][j]) cout<<i<<' '<<j<<'\n';
		ret=kei(n,0);
		for(i=0;i<k;i++){
			if(ret&(1<<i)) out.push_back(i+1);
		}
//		cout<<(9|5);
		return out;
	}
};
