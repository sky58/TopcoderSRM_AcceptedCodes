//SRM240DIV1-900 MailArchiving
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
int dp[55][55][55];vector <string> s;
int rec(int a,int b,int c){
	if(a<0 || a>=s.size() || b<0 || b>=s.size()) return 0;
	if(dp[a][b][c]>-1) return dp[a][b][c];
	if(a>b) return 0;
	int ret=1000,i;
	ret<?=min(rec(a+1,b,c),rec(a+1,b,a))+(s[a]==s[c]?0:1);
	ret<?=min(rec(a,b-1,c),rec(a,b-1,b))+(s[b]==s[c]?0:1);
	for(i=a;i<b;i++) ret<?=rec(a,i,c)+rec(i+1,b,c);
//	cout<<a<<' '<<b<<' '<<c<<' '<<ret<<endl;
	return dp[a][b][c]=ret;
}
class MailArchiving{
	public:
	int MailArchiving::minSelections(vector <string> a){
		int i,j,k;for(i=0;i<55;i++) for(j=0;j<55;j++) for(k=0;k<55;k++) dp[i][j][k]=-1;
		s.pb(a[0]);for(i=1;i<a.size();i++){if(a[i]!=a[i-1]) s.pb(a[i]);}
//		for(i=0;i<s.size();i++) cout<<s[i]<<endl;
		return min(rec(0,s.size()-2,s.size()-1),rec(1,s.size()-1,0))+1;
	}
};
