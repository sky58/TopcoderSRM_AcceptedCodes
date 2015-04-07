//SRM424DIV1-900 ProductOfPrices

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
using namespace std;

template <class typ> struct BIT{
	vector<typ> x;
	BIT(int n):x(n,0){}
	typ sum(int a,int b){
		if(a==0){
			typ s=0;
			for(int i=b;i>=0;i=(i&(i+1))-1) s+=x[i];
			return s;
		}
		else return sum(0,b)-sum(0,a-1);
	}
	void add(int ind,typ f){
		for(int i=ind;i<x.size();i|=i+1) x[i]+=f;
	}
};

class ProductOfPrices{
	public:
	int ProductOfPrices::product(int n,int l,int x0,int a,int b){
		BIT<long long> bit1(210000),bit2(210000);vector <long long> x;
		int i,mo=1000000007;long long bs,bk,fs,fk,out=1,kyo;
		
		x.push_back((long long)x0%l);
		for(i=1;i<n;i++) x.push_back((x[i-1]*a+b)%l);
		bit1.add(x[0],x[0]);bit2.add(x[0],1);
		for(i=1;i<n;i++){
			fs=bit1.sum(x[i]+1,201000);fk=bit2.sum(x[i]+1,201000);
			bs=bit1.sum(0,x[i]-1);bk=bit2.sum(0,x[i]-1);
			kyo=(fs-fk*x[i])+(bk*x[i]-bs);
			out=out*(kyo%mo)%mo;
			bit1.add(x[i],x[i]);bit2.add(x[i],1);
		}
		return (int)out;
	}
};
