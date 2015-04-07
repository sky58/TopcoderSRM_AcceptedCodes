//SRM302DIV1-250 DivisorInc
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
bool sumi[110000];
class DivisorInc{
	public:
	int DivisorInc::countOperations(int n,int m){
		int i,j,k;
		vector <int> now,next,cl;now.pb(n);memset(sumi,false,sizeof(sumi));sumi[n]=true;
		for(i=0;;i++){
			for(j=0;j<now.size();j++){
				if(now[j]==m) return i;
				for(k=2;k*k<=now[j];k++){
					if(now[j]%k==0){
//						cout<<' '<<i<<' '<<now[j]<<' '<<k<<endl;
						if(now[j]+k<105000) if(!sumi[now[j]+k]){sumi[now[j]+k]=true;next.pb(now[j]+k);}
						if(now[j]+now[j]/k<=105000) if(!sumi[now[j]+now[j]/k]){sumi[now[j]+now[j]/k]=true;next.pb(now[j]+now[j]/k);}
					}
				}
			}
			now=next;next=cl;if(now.size()<1) return -1;
		}
		return -1;
	}
};
