//SRM281DIV1-250 IntegerGenerator
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
bool ka[15];
class IntegerGenerator{
	public:
	string IntegerGenerator::nextInteger(vector <int> a,string b){
		int i,j,k,n=b.size();memset(ka,false,sizeof(ka));
		for(i=0;i<a.size();i++) ka[a[i]]=true;sort(a.begin(),a.end());
//		for(i=0;i<n;i++){if(b[i]!='0') t++;}if(t<1) return "INVALID INPUT";
		if(b[0]=='0') return "INVALID INPUT";
		if(b.size()<1) return "INVALID INPUT";if(a.size()<1) return "INVALID INPUT";
		if(a.size()<2 && a[0]==0) return "INVALID INPUT";
		for(i=0;i<n;i++){if(!ka[b[i]-'0']) return "INVALID INPUT";}
		for(i=n-1;i>=0;i--){
			for(j=(b[i]-'0')+1;j<=9;j++){
				if(ka[j]){
//					cout<<i<<' '<<j<<endl;
					b[i]=(j+'0');
					for(k=i+1;k<n;k++) b[k]=(a[0]+'0');return b;
				}
			}
		}
		string out="a";if(a[0]<1) out[0]=(a[1]+'0');else out[0]=(a[0]+'0');
		for(i=0;i<n;i++) out+=(a[0]+'0');
		return out;
	}
};
