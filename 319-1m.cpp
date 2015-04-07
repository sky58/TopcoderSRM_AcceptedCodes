//SRM319DIV1-500 ConstructBST
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
map<int,pint> memo;
map<int,int> me;
lint com[30][30];
lint dfs(int ke){
	if(!me[ke]) return 1;
	return dfs(ke*2)*dfs(ke*2+1)*com[memo[ke].fi+memo[ke].se][memo[ke].fi];
}
class ConstructBST{
	public:
	long long ConstructBST::numInputs(vector <int> a){
		sort(a.begin(),a.end());int i,j,n=a.size();
		for(i=n-1;i>=0;i--){
			me[a[i]]++;
			memo[a[i]]=mp(memo[a[i]*2].fi+memo[a[i]*2].se+me[a[i]*2],memo[a[i]*2+1].fi+memo[a[i]*2+1].se+me[a[i]*2+1]);
		}
		for(i=0;i<30;i++) for(j=0;j<30;j++) com[i][j]=0;com[0][0]=1;
		for(i=1;i<30;i++) for(j=0;j<=i;j++){
			com[i][j]+=com[i-1][j];if(j>0) com[i][j]+=com[i-1][j-1];
		}
		map<int,pint>::iterator it=memo.begin();
//		while(it!=memo.end()){cout<<(*it).fi<<' '<<(*it).se.fi<<' '<<(*it).se.se<<endl;it++;}
		return dfs(1);
	}
};
