//SRM256DIV1-450 CliqueCount
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
int gr[25];
class CliqueCount{
	public:
	int CliqueCount::countCliques(vector <string> a){
		int i,j,out=0,n=a.size();
		memset(gr,0,sizeof(gr));
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			if(a[i][j]=='1') gr[i]+=(1<<j);
		}
		for(i=0;i<n;i++) gr[i]+=(1<<i);
		for(i=0;i<(1<<n);i++){
			int f=1;
			for(j=0;j<n;j++){
				if(i&(1<<j)){
					if((i&gr[j])!=i) f=0;
				}
				else{
					if((i&gr[j])==i) f=0;
				}
			}
//			if(f>0) cout<<i<<endl;
			out+=f;
		}
		return out;
	}
};
