//SRM272DIV1-250 FewestFactors
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
class FewestFactors{
	public:
	int FewestFactors::number(vector <int> a){
		int i,n=a.size(),out=-1,mi=100000000;sort(a.begin(),a.end());
		while(1){
			int b=0,c=0;
			for(i=0;i<n;i++) b=b*10+a[i];
			for(i=1;i*i<=b;i++){
				if(b%i==0){
					if(i*i==b) c++;else c+=2;
				}
			}
			if(mi>c){mi=c;out=b;}
			if(!next_permutation(a.begin(),a.end())) break;
		}
		return out;
	}
};
