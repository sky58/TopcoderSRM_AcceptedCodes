//SRM332DIV1-250 SantaGifts
#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
class SantaGifts{
	public:
	vector <string> SantaGifts::distribute(vector <string> a,int b){
		int i;vector <string> out;
		string c;
		for(i=0;i<b;i++) out.push_back(c);
		for(i=0;i<4*b && i<a.size();i++){
			if(out[i%b].size()>0) out[i%b]+=" ";
			out[i%b]+=a[i];
		}
		return out;
	}
};
