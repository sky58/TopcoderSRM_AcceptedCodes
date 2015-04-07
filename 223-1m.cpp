//SRM223DIV1-500 PrimeAnagrams
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
bool go(int a){
	if(a<2) return true;
	for(int i=2;i*i<=a;i++){
		if(a%i<1) return true;
	}
	return false;
}
vector <int> cal(vector <int> a,vector <int> b){
	if(a.size()<1) return b;int x=1,y=1;
	for(int i=0;i<3;i++){
//		if(a[i]<b[i]) return a;
//		if(a[i]>b[i]) return b;
		x*=a[i];y*=b[i];
	}
	if(x<y) return a;return b;
}
class PrimeAnagrams{
	public:
	vector <int> PrimeAnagrams::primes(string a){
		sort(a.begin(),a.end());int i,j,k,n=a.size();vector <int> out;
		while(1){
			for(i=1;i<n-1;i++) for(j=i+1;j<n;j++){
				if(a[0]=='0' || a[i]=='0' || a[j]=='0') continue;
				int t1=0,t2=0,t3=0;
				for(k=0;k<i;k++) t1=t1*10+(a[k]-'0');
				for(k=i;k<j;k++) t2=t2*10+(a[k]-'0');
				for(k=j;k<n;k++) t3=t3*10+(a[k]-'0');
				if(go(t1) || go(t2) || go(t3)) continue;
				vector <int> t;t.pb(t1);t.pb(t2);t.pb(t3);
				sort(t.begin(),t.end());
				out=cal(out,t);
			}
			if(!next_permutation(a.begin(),a.end())) break;
		}
		return out;
	}
};
