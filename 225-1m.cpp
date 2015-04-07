//SRM225DIV1-500 ComboBoxKeystrokes
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
int dp[55][55];
class ComboBoxKeystrokes{
	public:
	int ComboBoxKeystrokes::minimumKeystrokes(vector <string> a){
		int out=0,i,j,k,n=a.size();
		for(i=0;i<55;i++) for(j=0;j<55;j++) dp[i][j]=100;for(i=0;i<55;i++) dp[i][i]=0;
		for(i=0;i<n;i++) for(j=0;j<26;j++){
			for(k=i+1;k<i+n;k++){if(a[k%n][0]==(j+'a') || a[k%n][0]==(j+'A')) break;}
			if(k<i+n) dp[i][k%n]=1;
		}
		for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) dp[i][j]<?=dp[i][k]+dp[k][j];
		for(i=0;i<n;i++) for(j=0;j<n;j++) out>?=dp[i][j];
		return out;
	}
};
