//SRM276DIV1-250 VolumeDiscount
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
int dp[210],uni[110],co[110];
class VolumeDiscount{
	public:
	int VolumeDiscount::bestDeal(vector <string> a,int b){
		int n=a.size(),i,j,out=100000000;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>uni[i]>>co[i];
		}
		for(i=0;i<210;i++) dp[i]=100000000;dp[0]=0;
		for(i=0;i<210;i++) for(j=0;j<n;j++){
			if(i+uni[j]<208) dp[i+uni[j]]<?=dp[i]+co[j];
		}
		for(i=b;i<205;i++) out<?=dp[i];return out;
	}
};
