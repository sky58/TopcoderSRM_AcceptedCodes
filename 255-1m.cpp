//SRM255DIV1-600 PluCodeGenerator
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
int dp[12][5];
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
int cal(string a){
	reverse(a.begin(),a.end());int i,n=a.size();
	for(i=0;i<n-2;i++){if(a[i]==a[i+1] && a[i]==a[i+2]) return 3;}
	for(i=1;i<n;i++){if(a[i]!=a[0]) break;}
	return i;
}
class PluCodeGenerator{
	public:
	int PluCodeGenerator::countInvalidCodes(int a){
		int i,j,k,out=0;
		memset(dp,0,sizeof(dp));dp[0][3]=1;
		for(j=1;j<10;j++) dp[j][3]=dp[j-1][3]*10;
		for(j=1;j<10;j++) for(k=1;k<3;k++) dp[j][k]=dp[j-1][k+1]+dp[j-1][1]*9;
		string s=moji(a);int n=s.size();
		for(i=0;i<n;i++){
			for(char t='0';t<s[i];t++){
				if(i==0 && t=='0') continue;
				out+=dp[n-i-1][cal(s.substr(0,i)+t)];
//				cout<<i<<' '<<t<<' '<<' '<<s.substr(0,i)+t<<' '<<cal(s.substr(0,i)+t)<<endl;
			}
		}
		for(i=0;i<n-1;i++) out+=dp[i][1]*9;
		return out;
	}
};
