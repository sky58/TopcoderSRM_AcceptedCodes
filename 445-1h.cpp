//SRM445DIV1-1000 TheEncryptionDivOne
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
int sia[55],sib[55];
lint kai[55];
lint mo=1234567891;
int enc(char a){
	if('A'<=a && 'Z'>=a) return (a-'A');
	return 26+(a-'a');
}
class TheEncryptionDivOne{
	public:
	int TheEncryptionDivOne::count(string a,string b){
		int i,j,n=a.size();lint out=0;vector <int> kab;
		for(i=0;i<55;i++){sia[i]=1;sib[i]=1;}
		kai[0]=1;for(i=1;i<55;i++) kai[i]=(kai[i-1]*i)%mo;
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
			if(a[i]==a[j] && b[i]!=b[j]) return 0;
			if(a[i]!=a[j] && b[i]==b[j]) return 0;
		}
		for(i=0;i<n;i++){if(enc(a[i])%26==enc(b[i])%26) return 0;}
		for(i=0;i<n;i++){sia[enc(a[i])]=0;sib[enc(b[i])]=0;}
		for(i=0;i<26;i++) kab.pb((sia[i]+sia[26+i])*(sib[i]+sib[26+i]));
//		for(i=0;i<26;i++) cout<<kab[i]<<endl;
		lint dp[30][55];memset(dp,0,sizeof(dp));dp[0][0]=1;
		for(i=0;i<26;i++) for(j=0;j<53;j++){
			dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mo;
			dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*kab[i])%mo;
			if(kab[i]>3) dp[i+1][j+2]=(dp[i+1][j+2]+dp[i][j]*2)%mo;
		}
		int f=1,m=52;for(i=0;i<52;i++) m-=sia[i];
		for(i=0;i<53-m;i++){out=(out+mo+dp[26][i]*kai[52-m-i]*f)%mo;f*=-1;}
		return out%mo;
	}
};
