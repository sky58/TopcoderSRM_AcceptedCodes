//SRM307DIV1-250 PartSorting
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
class PartSorting{
	public:
	vector <int> PartSorting::process(vector <int> a,int b){
		int i,d,j,n=a.size();
		for(i=0;i<n-1;i++){
			int ma=a[i],ind=0;
			for(j=1;i+j<n;j++){
				if(j<=b && ma<a[i+j]){ind=j;ma=a[i+j];}
			}
			for(j=ind-1;j>=0;j--){d=a[i+j];a[i+j]=a[i+j+1];a[i+j+1]=d;}
			b-=ind;
		}
		return a;
	}
};
