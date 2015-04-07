//SRM242DIV1-500 DiceThrows
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
double dp1[2][21000],dp2[2][21000];
class DiceThrows{
	public:
	double DiceThrows::winProbability(int a,vector <int> b,int c,vector <int> d){
		int i,j,k;double out=0.0;
		for(i=0;i<21000;i++) dp1[0][i]=dp2[0][i]=dp1[1][i]=dp2[1][i]=0.0;dp1[0][0]=dp2[0][0]=1.0;
		for(i=0;i<a;i++){
			for(j=0;j<21000;j++) dp1[(i+1)%2][j]=0.0;
			for(j=20500;j>=0;j--) for(k=0;k<6;k++) dp1[(i+1)%2][j+b[k]]+=dp1[i%2][j]/6.0;
		}
		for(i=0;i<c;i++){
			for(j=0;j<21000;j++) dp2[(i+1)%2][j]=0.0;
			for(j=20500;j>=0;j--) for(k=0;k<6;k++) dp2[(i+1)%2][j+d[k]]+=dp2[i%2][j]/6.0;
		}
//		for(i=0;i<a;i++) for(j=20500;j>=0;j--) for(k=0;k<6;k++) dp2[j+d[k]]+=dp2[j]/6.0;
		for(i=1;i<20500;i++) dp2[c%2][i]+=dp2[c%2][i-1];
		for(i=1;i<20500;i++) out+=dp1[a%2][i]*dp2[c%2][i-1];
		return out;
	}
};
