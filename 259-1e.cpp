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
vector <int> a;
int rec(int x,int y){
	if(y<=x) return 0;int s1=0,i,j;
	for(i=x;i<y;i++){
		s1+=a[i];int s2=0;
		for(j=y;j>i;j--){
			s2+=a[j];
			if(s1==s2) return (i-x)+(y-j)+rec(i+1,j-1);
		}
	}
	return y-x;
}
class NumericalSequence{
	public:
	int NumericalSequence::makePalindrome(vector <int> A){
		a=A;return rec(0,a.size()-1);
	}
};
