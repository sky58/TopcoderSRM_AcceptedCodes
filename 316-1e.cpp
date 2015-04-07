//SRM316DIV1-250 InboxCleanup
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
int calc(string a){
	int i,n=a.size(),k=0;
	for(i=0;i<n;i++){
		if(a[i]=='D') k++;
	}
	if(k==0) return 0;
	return 1+min(k,n-k+1);
}
class InboxCleanup{
	public:
	int InboxCleanup::fewestClicks(string a,int b,int c){
		int i,j,out=100000,n=a.size();
		for(i=b;i<=c;i++){
			int s=0;
			for(j=0;j<n;j+=i) s+=calc(a.substr(j,min(i,n-j)));
			out<?=s+(n-1)/i;
		}
		return out;
	}
};
