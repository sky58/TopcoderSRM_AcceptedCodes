//SRM301DIV1-450 EscapingJail
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
int di[55][55];
class EscapingJail{
	public:
	int EscapingJail::getMaxDistance(vector <string> a){
		int i,j,k,n=a.size(),out=0,inf=1000000;
		for(i=0;i<55;i++) for(j=0;j<55;j++) di[i][j]=inf;
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			if(a[i][j]<='9' && a[i][j]>='0') di[i][j]=(a[i][j]-'0');
			else if(a[i][j]<='z' && a[i][j]>='a') di[i][j]=(a[i][j]-'a')+10;
			else if(a[i][j]<='Z' && a[i][j]>='A') di[i][j]=(a[i][j]-'A')+36;
		}
		for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) di[i][j]<?=di[i][k]+di[k][j];
		for(i=0;i<n;i++) for(j=0;j<n;j++) out>?=di[i][j];
		if(out>=inf) return -1;return out;
	}
};
