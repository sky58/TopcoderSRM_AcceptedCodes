//SRM518DIV1-250
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
class LargestSubsequence{
	public:
	string LargestSubsequence::getLargest(string a){
		int n=a.size(),it=0,i;string out="";
		while(it<n){
			char b='a'-1;int in=-1;
			for(i=it;i<n;i++){
				if(a[i]>b){b=a[i];in=i;}
			}
			out+=b;it=in+1;
		}
		return out;
	}
};
