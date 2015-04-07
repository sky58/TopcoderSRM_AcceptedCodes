//SRM322DIV1-250 GroupWork
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
class GroupWork{
	public:
	long long GroupWork::bestGroup(vector <int> a,vector <int> b){
		lint out=0;int i,j,n=a.size();
		for(i=0;i<n;i++){
			lint t=0;
			for(j=0;j<n;j++){
				if(b[j]>=b[i]) t+=a[j];
			}
			out>?=t*b[i];
		}
		return out;
	}
};
