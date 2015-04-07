//SRM324DIV1-500 TourmantPlan
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
class TournamentPlan{
	public:
	int TournamentPlan::getTravelDistance(vector <int> x,vector <int> y){
		int i,j,k,n=x.size(),out=1000000000;
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			int f=0;for(k=0;k<n;k++) f+=(abs(x[k]-x[i])+abs(y[k]-y[j]));out<?=f;
		}
		return out;
	}
};
