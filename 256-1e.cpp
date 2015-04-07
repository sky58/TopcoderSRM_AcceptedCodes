//SRM256DIV1-250 MagicCube
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
int cal(vector <int> a){
	int i,ma=0,mi=10000;
	for(i=0;i<9;i++){
		ma>?=a[i]+a[i+9]+a[i+18];mi<?=a[i]+a[i+9]+a[i+18];
		ma>?=a[i*3]+a[i*3+1]+a[i*3+2];mi<?=a[i*3]+a[i*3+1]+a[i*3+2];
		ma>?=a[i%3+(i/3)*9]+a[i%3+(i/3)*9+3]+a[i%3+(i/3)*9+6];mi<?=a[i%3+(i/3)*9]+a[i%3+(i/3)*9+3]+a[i%3+(i/3)*9+6];
	}
	return ma-mi;
}
class MagicCube{
	public:
	int MagicCube::getScore(vector <int> a){
		int out=10000,i,j;out<?=cal(a);
		for(i=0;i<27;i++) for(j=0;j<27;j++){
			vector <int> b=a;int d=b[i];b[i]=b[j];b[j]=d;out<?=cal(b);
		}
		return out;
	}
};
