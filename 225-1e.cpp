//SRM225DIV1-250 ParameterSubstitution
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
class ParameterSubstitution{
	public:
	string ParameterSubstitution::processParams(string a,vector <string> b){
		string out="";int i,j,n=b.size();
		for(i=0;i<a.size();i++){
			if(a[i]=='$'){
				int t=0,it=i+1;
				while(1){
					if(it>=a.size()) break;
					if(a[it]>'9' || a[it]<'0') break;
					if(t*10+(a[it]-'0')>n) break;
					if(t<1 && a[it]=='0') break;
					t=t*10+(a[it]-'0');it++;
				}
				if(t>0 && t<=n) out+=b[t-1];
				else{
					for(j=i;j<it;j++) out+=a[j];
				}
				i=it-1;
			}
			else out+=a[i];
		}
		return out;
	}
};
