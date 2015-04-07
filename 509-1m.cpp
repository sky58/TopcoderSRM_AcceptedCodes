//SRM509DIV1-500 PalindromizationDiv1
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
lint dp[55][55],fl[55][55],fl2[55][55];lint inf=1000000000000000LL;
lint er[55],ad[55];string st;
lint cal(int a,int b){
	if(dp[a][b]>-1) return dp[a][b];lint ret=inf;int i;
	if(b<=a) return 0;
	ret<?=min(er[(st[a]-'a')],ad[(st[a]-'a')])+cal(a+1,b);
	ret<?=min(er[(st[b]-'a')],ad[(st[b]-'a')])+cal(a,b-1);
	for(i=0;i<26;i++){
		ret<?=cal(a+1,b-1)+fl[(st[a]-'a')][i]+fl[(st[b]-'a')][i];
		ret<?=cal(a+1,b)+fl[(st[a]-'a')][i]+ad[i];
		ret<?=cal(a,b-1)+fl[(st[b]-'a')][i]+ad[i];
//		cout<<fl[(st[a]-'0')][i]+fl[(st[b]-'0')][i]<<endl;
	}
//	cout<<a<<' '<<b<<' '<<ret<<endl;
	return dp[a][b]=ret;
}
class PalindromizationDiv1{
	public:
	int PalindromizationDiv1::getMinimumCost(string a,vector <string> b){
		st=a;int i,j,k,x;string s,s1;
		for(i=0;i<55;i++) for(j=0;j<55;j++){fl[i][j]=fl2[i][j]=inf;dp[i][j]=-1;}
		for(i=0;i<55;i++) fl[i][i]=fl2[i][i]=0;
		for(i=0;i<55;i++) ad[i]=er[i]=inf;
		for(i=0;i<b.size();i++){
			istringstream sin(b[i]);
			sin>>s;
			if(s=="add"){
				sin>>s>>x;ad[(s[0]-'a')]<?=x;
			}
			else if(s=="erase"){
				sin>>s>>x;er[(s[0]-'a')]<?=x;
			}
			else{
				sin>>s>>s1>>x;fl[(s[0]-'a')][(s1[0]-'a')]<?=x;fl2[(s1[0]-'a')][(s[0]-'a')]<?=x;
			}
		}
		for(k=0;k<26;k++) for(i=0;i<26;i++) for(j=0;j<26;j++){
			fl[i][j]<?=fl[i][k]+fl[k][j];fl2[i][j]<?=fl2[i][k]+fl2[k][j];
		}
		for(i=0;i<26;i++) for(j=0;j<26;j++){
			ad[i]<?=ad[j]+fl2[i][j];er[i]<?=er[j]+fl[i][j];
		}
//		cout<<fl[2][2]<<endl;
//		cout<<er[1]<<endl;
		for(i=0;i<26;i++) for(j=0;j<26;j++){
//			if(i!=j && fl2[i][j]<1) cout<<i<<' '<<j<<endl;
		}
		lint out=cal(0,a.size()-1);
		if(out>=inf) return -1;return (int)out;
	}
};
