//SRM294DIV1-250 Shuffling
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
class Shuffling{
	public:
	int Shuffling::position(int n,vector <int> a){
		vector <int> b;int i,j;
		for(i=0;i<n-1;i++) b.pb(1);b.pb(0);
		for(i=0;i<a.size();i++){
			vector <int> c;
			if(a[i]<0){
				for(j=0;j<abs(a[i]);j++) c.pb(b[n/2+j]);
				for(j=0;j<n/2-abs(a[i]);j++){
					c.pb(b[j]);c.pb(b[n/2+abs(a[i])+j]);
				}
				for(j=0;j<abs(a[i]);j++) c.pb(b[n/2-abs(a[i])+j]);
			}
			else{
				for(j=0;j<a[i];j++) c.pb(b[j]);
				for(j=0;j<n/2-a[i];j++){c.pb(b[n/2+j]);c.pb(b[a[i]+j]);}
				for(j=0;j<a[i];j++) c.pb(b[n-a[i]+j]);
			}
			b=c;
		}
		for(i=0;i<n;i++){if(b[i]==0) return n-1-i;}
	}
};
