//SRM236DIV1-250 BusinessTasks
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
bool sumi[55];
class BusinessTasks{
	public:
	string BusinessTasks::getTask(vector <string> a,int b){
		int i,j,n=a.size(),it=0;
		memset(sumi,false,sizeof(sumi));
		for(i=0;i<n-1;i++){
			int f=b%(n-i);if(f<1) f=n-i;
			while(1){
				if(!sumi[it%n]) f--;if(f<1) break;it++;
			}
			sumi[it%n]=true;
		}
		for(i=0;i<n;i++){
			if(!sumi[i]) return a[i];
		}
	}
};
