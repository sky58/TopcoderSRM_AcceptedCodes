//SRM311DIV1-600 SumThemAll
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
lint dec(int a){
	lint ret=0;
	while(a>0){ret+=a%10;a/=10;}
	return ret;
}
lint calc(lint a,lint b){
	if(b<=0) return 0;lint ret=0;
	for(int i=1;i<=b%10;i++) ret+=dec(b-i);
	return (ret+(b/10)*45)*a+calc(a*10,b/10);
}
class SumThemAll{
	public:
	long long SumThemAll::getSum(int a,int b){
		return calc(1,b+1)-calc(1,a);
	}
};
