//SRM211DIV2-900 grafixGlobs
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
int ar[1100],ci[1100],po[1100];
//map<lint,int> ar,ci,po;
class grafixGlobs{
	public:
	vector <int> grafixGlobs::execute(vector <string> a,int b){
		int i,j,x,y;string s;vector <int> out;
		for(i=0;i<1100;i++) ar[i]=ci[i]=po[i]=0;
		for(i=0;i<a.size();i++){
			istringstream sin(a[i]);sin>>s;
			if(s=="make"){
				for(j=0;;j++){if(ar[j]+ci[j]+po[j]<1) break;}
				sin>>s;if(s=="arc") ar[j]++;if(s=="circle") ci[j]++;if(s=="polygon") po[j]++;
			}
			if(s=="delete"){
				sin>>x;ar[x]=ci[x]=po[x]=0;
			}
			if(s=="merge"){
				sin>>x>>y;ar[x]+=ar[y];ci[x]+=ci[y];po[x]+=po[y];ar[y]=po[y]=ci[y]=0;
			}
			if(s=="split"){
				sin>>x;int t1=ar[x],t2=ci[x],t3=po[x];ar[x]=ci[x]=po[x]=0;
				for(j=0;t1+t2+t3>0;j++){
					if(ar[j]+ci[j]+po[j]>0) continue;
					if(t1>0){ar[j]++;t1--;}else if(t2>0){ci[j]++;t2--;}else{po[j]++;t3--;}
				}
			}
//			cout<<ci[0]<<' '<<po[0]<<' '<<ci[1]<<' '<<po[1]<<' '<<ci[2]<<' '<<po[2]<<endl;
		}
		if(ar[b]+ci[b]+po[b]<1) return out;
		out.pb(ar[b]);out.pb(ci[b]);out.pb(po[b]);return out;
	}
};
