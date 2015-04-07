//SRM446.5DIV1-250 ErdosNumber
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
map<string,int> memo;
class ErdosNumber{
	public:
	vector <string> ErdosNumber::calculateNumbers(vector <string> a){
		int i,j,k,n=a.size();
		vector <int> now,next,cl;
		vector <string> out,li,lis;
		vector <vector <string> > f;
		int ka[110];int gr[110][110];bool sumi[110];
		for(i=0;i<110;i++) ka[i]=-1;
		memset(gr,0,sizeof(gr));memset(sumi,false,sizeof(sumi));
		for(i=0;i<n;i++) f.pb(li);
		
		for(i=0;i<n;i++){
			istringstream sin(a[i]);
			while(1){
				string s;sin>>s;if(s=="") break;
				li.pb(s);f[i].pb(s);
			}
		}
		sort(li.begin(),li.end());lis.pb(li[0]);
		for(i=1;i<li.size();i++){
			if(li[i]!=li[i-1]) lis.pb(li[i]);
		}
//		cout<<"a\n";
		for(i=0;i<lis.size();i++) memo[lis[i]]=i;
		for(i=0;i<n;i++){
			for(j=0;j<f[i].size();j++) for(k=0;k<f[i].size();k++){
				gr[memo[f[i][j]]][memo[f[i][k]]]=1;
			}
		}
		now.pb(memo["ERDOS"]);
//		cout<<"b\n";
		for(i=0;i<110;i++){
			for(j=0;j<now.size();j++){
				if(sumi[now[j]]) continue;sumi[now[j]]=true;ka[now[j]]=i;
				for(k=0;k<110;k++){
					if(gr[now[j]][k]==1) next.pb(k);
				}
			}
			now=next;next=cl;
		}
		for(i=0;i<lis.size();i++){
			stringstream st;st<<lis[i];
			if(ka[i]>=0) st<<' '<<ka[i];
			out.pb(st.str());
		}
		return out;
	}
};
