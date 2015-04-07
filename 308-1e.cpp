//SRM308DIV1-200 HuffmanDecoding
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
class HuffmanDecoding{
	public:
	string HuffmanDecoding::decode(string a,vector <string> b){
		string out="";int i,it=0,n=a.size();
		while(it<n){
			for(i=0;i<b.size() && it<n;i++){
				int t=b[i].size();
				if(a.substr(it,t)==b[i]){out+=(i+'A');it+=t;}
			}
		}
		return out;
	}
};
