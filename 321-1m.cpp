//SRM321DIV1-500 WeirdSort
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
class WeirdSort{
	public:
	vector <int> WeirdSort::sortArray(vector <int> a){
		int n,i,j,k;n=a.size();
		vector <int> out;sort(a.begin(),a.end());
		bool sumi[55];memset(sumi,false,sizeof(sumi));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(sumi[j]) continue;
				if(i>0) if(out[i-1]+1==a[j]) continue;
				int on=0,tw=0;
				for(k=0;k<n;k++){
					if(k==j || sumi[k]) continue;
					if(a[k]==a[j]) on++;if(a[k]-1==a[j]) tw++;
				}
				if(tw==0 || on+tw<n-i-1){out.pb(a[j]);sumi[j]=true;break;}
			}
		}
		return out;
	}
};
