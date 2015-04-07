//SRM490DIV1-550 QuickT9
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
int dp[55],ka[55][55],te[2550][55];
map<string,int> me;
string en[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
string nu="0123456789";
char de2(char a){
	for(int i=2;i<=9;i++){
		for(int j=0;j<en[i].size();j++){
			if(en[i][j]==a) return (i+'0');
		}
	}
}
class QuickT9{
	public:
	int QuickT9::minimumPressings(vector <string> A,string b){
		int n=b.size(),i,j,k,l,m,inf=100000000;vector <string> a,da;string s;
		memset(te,0,sizeof(te));for(i=0;i<55;i++) dp[i]=inf;dp[0]=0;
		for(i=0;i<55;i++) for(j=0;j<55;j++) ka[i][j]=inf;
		for(i=0;i<A.size();i++){
			istringstream sin(A[i]);
			while(sin>>s){
				string s1="";for(j=0;j<s.size();j++) s1+=de2(s[j]);a.pb(s);da.pb(s1);
			}
		}
		m=a.size();
		for(i=0;i<m;i++) for(j=1;j<=a[i].size();j++){
			me.clear();
			for(k=0;k<m;k++){
				if(a[k].size()>=j) if(da[k].substr(0,j)==da[i].substr(0,j)) if(a[k].substr(0,j)<a[i].substr(0,j)) if(!me[a[k].substr(0,j)]){me[a[k].substr(0,j)]=1;te[i][j]++;}
			}
//			cout<<i<<' '<<j<<' '<<te[i][j]<<endl;
		}
		for(i=0;i<n;i++) for(j=i+1;j<=n;j++){
			int t=j-i;string c=b.substr(i,t);
//			cout<<c<<endl;
			for(k=0;k<m;k++){
				if(a[k].size()>=t){
					if(a[k].substr(0,t)==c){
						for(l=t;l<=a[k].size();l++){
							ka[i][j]<?=l+te[k][l]+max(1,l-t);
						}
					}
				}
			}
//			cout<<i<<' '<<j<<' '<<ka[i][j]<<endl;
		}
		for(i=0;i<n;i++) for(j=i+1;j<=n;j++) dp[j]<?=dp[i]+ka[i][j];if(dp[n]>=inf) return -1;return dp[n];
	}
};
