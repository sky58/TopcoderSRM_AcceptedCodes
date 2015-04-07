//SRM419DIV1-250(DIV2-500) Undo
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
using namespace std;

class Undo{
	public:
	string Undo::getText(std::vector <string> cc, std::vector <int> t){
		vector <string> a;vector <string> b;
		string com, out="";
		int n, rim=1000000001, i, j, comm;
		n=cc.size();
		for(i=0;i<n;i++){
			com="";for(j=0;j<4;j++) com+=cc[i][j];a.push_back(com);com="";
			for(j=5;j<cc[i].size();j++) com+=cc[i][j];b.push_back(com);
		}
		
		for(i=n-1;i>=0;i--){
			if(t[i]>=rim) t[i]=0;
			else{
				if(a[i]=="undo"){
					sscanf(b[i].c_str(),"%d",&comm);rim=t[i]-comm;
				}
			}
		}
		for(i=0;i<n;i++){
			if(t[i]>0){
				if(a[i]=="type") out+=b[i];
			}
		}
		return out;
	}
};
