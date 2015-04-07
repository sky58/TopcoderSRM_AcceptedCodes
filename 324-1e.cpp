//SRM324DIV1-250 PalindromeDecoding
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
class PalindromeDecoding{
	public:
	string PalindromeDecoding::decode(string a,vector <int> b,vector <int> c){
		for(int i=0;i<b.size();i++){
			string d=a.substr(b[i],c[i]);reverse(d.begin(),d.end());
			a=a.substr(0,b[i]+c[i])+d+a.substr(b[i]+c[i],a.size()-b[i]-c[i]);
		}
		return a;
	}
};
