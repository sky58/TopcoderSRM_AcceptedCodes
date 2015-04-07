//SRM463DIV1-250(DIV2-500) RabbitNumbering
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
class RabbitNumbering{
	public:
	int RabbitNumbering::theCount(vector <int> a){
		int i,n=a.size();lint out=1;sort(a.begin(),a.end());
		for(i=0;i<n;i++){out*=(a[i]-i);out%=1000000007;}
		return out;
	}
};
