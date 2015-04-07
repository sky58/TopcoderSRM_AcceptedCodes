//SRM302DIV1-500 IntegerPalindrome
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
lint gy(lint a){
	lint ret=0;
	while(a>0){ret=ret*10+a%10;a/=10;}
	return ret;
}
class IntegerPalindrome{
	public:
	long long IntegerPalindrome::findByIndex(int a){
		vector <lint> zyo;zyo.pb(1);int i;
		for(i=0;i<18;i++) zyo.pb(zyo[i]*10);
		for(i=1;i<=18;i++){
			if(a<9*zyo[(i-1)/2]){
				a+=zyo[(i-1)/2];
				if(i%2==0) return a*zyo[i/2]+gy(a);
				return a*zyo[i/2]+gy(a)%zyo[i/2];
			}
			else a-=9*zyo[(i-1)/2];
		}
		return -1;
	}
};
