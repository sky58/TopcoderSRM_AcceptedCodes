//SRM261DIV1-250 PrimeStatistics
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
bool so[210000];int ka[1100];
class PrimeStatistics{
	public:
	int PrimeStatistics::mostCommonRemainder(int a,int b,int c){
		memset(so,false,sizeof(so));memset(ka,0,sizeof(ka));
		int i,j,out=-1,ma=-1;
		so[0]=so[1]=true;
		for(i=2;i<205000;i++){
			if(so[i]) continue;
			for(j=i*2;j<205000;j+=i) so[j]=true;
		}
		for(i=a;i<=b;i++){
			if(so[i]) continue;ka[i%c]++;
		}
		for(i=0;i<c;i++){if(ma<ka[i]){ma=ka[i];out=i;}}
		return out;
	}
};
