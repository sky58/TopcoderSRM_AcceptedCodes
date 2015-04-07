//SRM319DIV1-250 BusSeating
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
double dist(int a,int b){
	int ax=a%10,ay=(a/10)*2,bx=b%10,by=(b/10)*2;
	return sqrt(1.0*(ax-bx)*(ax-bx)+1.0*(ay-by)*(ay-by));
}
class BusSeating{
	public:
	double BusSeating::getArrangement(string a,string b){
		a+=b;int i,j,k;double out=1e10;
		for(i=0;i<18;i++) for(j=i+1;j<19;j++) for(k=j+1;k<20;k++){
			if(a[i]=='X' || a[j]=='X' || a[k]=='X') continue;
			out<?=dist(i,j)+dist(j,k)+dist(k,i);
		}
		return out;
	}
};
