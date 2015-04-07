//SRM449.5DIV1-300 TwistedMatrix
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
class TwistedMatrix{
	public:
	vector <string> TwistedMatrix::solve(vector <string> a,vector <string> bb){
		int n=a.size(),m=a[0].size(),i,j,k,l;
		vector <string> out,s;string c;
		for(i=0;i<m;i++) c+='2';for(i=0;i<n;i++) out.pb(c);
		for(i=0;i<n-1;i++) for(j=0;j<m-1;j++){
			vector <string> d=a,b=bb;int f=0;
			char e=d[i][j];d[i][j]=d[i+1][j];d[i+1][j]=d[i+1][j+1];d[i+1][j+1]=d[i][j+1];d[i][j+1]=e;
			for(l=0;l<n;l++) for(k=0;k<m;k++){
				if((d[l][k]=='0' && b[l][k]=='1') || (d[l][k]=='1' && b[l][k]=='0')){f=1;break;}
				if(d[l][k]=='?' && b[l][k]=='?') d[l][k]='0';
				if(d[l][k]=='?') d[l][k]=b[l][k];if(b[l][k]=='?') b[l][k]=d[l][k];
			}
			if(f==1) continue;
			for(l=0;l<n;l++){
				if(out[l]>d[l]){out=d;break;}
				if(out[l]<d[l]) break;
			}
		}
		for(i=0;i<n-1;i++) for(j=0;j<m-1;j++){
			vector <string> d=a,b=bb;int f=0;
			char e=d[i][j];d[i][j]=d[i][j+1];d[i][j+1]=d[i+1][j+1];d[i+1][j+1]=d[i+1][j];d[i+1][j]=e;
			for(l=0;l<n;l++) for(k=0;k<m;k++){
				if((d[l][k]=='0' && b[l][k]=='1') || (d[l][k]=='1' && b[l][k]=='0')){f=1;break;}
				if(d[l][k]=='?' && b[l][k]=='?') d[l][k]='0';
				if(d[l][k]=='?') d[l][k]=b[l][k];if(b[l][k]=='?') b[l][k]=d[l][k];
			}
			if(f==1) continue;
			for(l=0;l<n;l++){
				if(out[l]>d[l]){out=d;break;}
				if(out[l]<d[l]) break;
			}
		}
		if(out[0][0]=='2') return s;
		return out;
	}
};
