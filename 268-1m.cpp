//SRM268DIV1-500 MaxTrip
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
bool sumi[30];bool gr[30][30];int zi[30];int f=0;
void dfs(int a){
	if(sumi[a]) return;sumi[a]=true;if(zi[a]%2!=0) f=1;
	for(int i=0;i<26;i++){if(gr[a][i]) dfs(i);}
	return;
}
class MaxTrip{
	public:
	int MaxTrip::minBuy(string a,string b){
		int i,out=0,out2=0;
		memset(sumi,false,sizeof(sumi));memset(gr,false,sizeof(gr));memset(zi,0,sizeof(zi));
		for(i=0;i<a.size();i++){
			int x=(a[i]-'A'),y=(b[i]-'A');gr[x][y]=true;gr[y][x]=true;zi[x]++;zi[y]++;
		}
		for(i=0;i<26;i++){
			if(zi[i]<1 || sumi[i]) continue;f=0;
			dfs(i);out++;if(f==0) out2+=2;
		}
		for(i=0;i<26;i++){if(zi[i]%2!=0) out2++;}
//		cout<<out<<' '<<out2<<endl;
		return max(out-1,out2/2-1);
	}
};
