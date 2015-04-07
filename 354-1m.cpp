//SRM354DIV1-500 RemissiveSwaps
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
int zyo[7]={1,10,100,1000,10000,100000,1000000};
bool sumi[1100000];
class RemissiveSwaps{
	public:
	int RemissiveSwaps::findMaximum(int a){
		int i,j,k;vector <int> now,next,cl;
		if(a==1000000) return 1000000;
		memset(sumi,false,sizeof(sumi));now.pb(a);sumi[a]=true;
		while(now.size()){
			for(k=0;k<now.size();k++){
//				cout<<now[k]<<endl;
				for(i=0;i<5;i++) for(j=i+1;j<6;j++){
					int s=(now[k]/zyo[i])%10,t=(now[k]/zyo[j])%10,u=now[k]-zyo[i]*(s-t+1)-zyo[j]*(t-s+1);
					if(s==0 || t==0) continue;
					if(!sumi[u]){sumi[u]=true;next.pb(u);}
				}
			}
			now=next;next=cl;
		}
		for(i=999999;i>=0;i--){
			if(sumi[i]) return i;
		}
	}
};
