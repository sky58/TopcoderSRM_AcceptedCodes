//SRM351DIV1-250 CoinExchange
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
class CoinsExchange{
	public:
	int CoinsExchange::countExchanges(int g1,int s1,int b1,int g2,int s2,int b2){
		int out=0;
		if(g1>=g2 && s1>=s2 && b1>=b2) return 0;
		if(g1<g2){
			while(g1*11+s1<g2*11+s2){
				b1-=11;out++;s1++;if(b1<b2) return -1;
			}
			if(b1>=b2) return out+(g2-g1);
			out+=(g2-g1);s1-=11*(g2-g1);
			while(b1<b2){
				b1+=9;s1--;out++;if(s1<s2) return -1;
			}
			return out;
		}
		else if(g1==g2){
			if(s1<s2){
				while(s1<s2){
					b1-=11;s1++;out++;if(b1<b2) return -1;
				}
				return out;
			}
			if(b1<b2){
				while(b1<b2){
					b1+=9;s1--;out++;if(s1<s2) return -1;
				}
				return out;
			}
		}
		else{
			if(b1<b2){
				while(s1*9+b1<s2*9+b2){
					s1+=9;g1--;out++;if(g1<g2) return -1;
				}
				out+=(b2-b1)/9;if((b2-b1)%9!=0) out++;return out;
			}
			while(g1>g2){
				s1+=9;g1--;out++;if(s1>=s2) return out;
			}
			while(s1<s2){
				s1++;b1-=11;out++;if(b1<b2) return -1;
			}
			return out;
		}
	}
};
