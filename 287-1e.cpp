//SRM287DIV1-300 TwoEquations
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
int de(string a){
	if(a[0]=='(') return -de(a.substr(2,a.size()-3));return (a[0]-'0');
}
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "(-"+moji(-a)+")";
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
string bu(int a,int b){
//	cout<<a<<' '<<b<<endl;
	if(b<0){a*=-1;b*=-1;}
	if(a==0) b=1;
	else{int t=gcd(abs(a),b);a/=t;b/=t;}
//	cout<<a<<' '<<b<<endl;
	return moji(a)+"/"+moji(b);
}
class TwoEquations{
	public:
	string TwoEquations::solve(string a,string b){
		string x,y,z,w,v;int a1,a2,a3,b1,b2,b3;
		istringstream sin(a);sin>>x>>y>>z>>w>>v;a1=de(x.substr(0,x.size()-2));a2=de(z.substr(0,z.size()-2));a3=de(v);
		istringstream sin2(b);sin2>>x>>y>>z>>w>>v;b1=de(x.substr(0,x.size()-2));b2=de(z.substr(0,z.size()-2));b3=de(v);
//		cout<<a1<<' '<<a2<<' '<<a3<<endl;cout<<b1<<' '<<b2<<' '<<b3<<endl;
		if(a1*b2==a2*b1){
			if(a1==0 && b1==0){
				if(a2==0 && b2==0){
					if(a3==0 && b3==0) return "MULTIPLE SOLUTIONS";
					else return "NO SOLUTIONS";
				}
				else if(a2==0){
					if(a3==0) return "MULTIPLE SOLUTIONS";
					else return "NO SOLUTIONS";
				}
				else if(b2==0){
					if(b3==0) return "MULTIPLE SOLUTIONS";
					else return "NO SOLUTIONS";
				}
				else{
					if(a2*b3==b2*a3) return "MULTIPLE SOLUTIONS";
					else return "NO SOLUTIONS";
				}
			}
			else if(a2==0 && b2==0){
				if(a1==0){
					if(a3==0) return "MULTIPLE SOLUTIONS";
					else return "NO SOLUTIONS";
				}
				else if(b1==0){
					if(b3==0) return "MULTIPLE SOLUTIONS";
					else return "NO SOLUTIONS";
				}
				else{
					if(a1*b3==b1*a3) return "MULTIPLE SOLUTIONS";
					else return "NO SOLUTIONS";
				}
			}
			else{
				if(a1*b3==b1*a3) return "MULTIPLE SOLUTIONS";
				else return "NO SOLUTIONS";
			}
		}
		else{
			return "X="+bu(a3*b2-a2*b3,a1*b2-a2*b1)+" Y="+bu(a1*b3-a3*b1,a1*b2-a2*b1);
		}
	}
};
