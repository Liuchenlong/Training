#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define _LL long long
//��չEuclid���gcd(a,b)=ax+by
_LL ext_gcd(_LL a,_LL b,_LL &x,_LL &y){
    _LL t,ret;
    if(!b){x=1;y=0;return a;}
    ret=ext_gcd(b,a%b,x,y);
    t=x;x=y;y=t-a/b*y;
    return ret;
}
//����m^a
_LL exponent(_LL m,_LL a){
    _LL ret=1;
    while(a){
        if(a&1)ret*=m;
        a>>=1;
        m*=m;
    }
    return ret;
}
//����m^a%mod
_LL mod_exponent(_LL m,_LL a,_LL mod){
    _LL ret=1;
    m%=mod;
    while(a){
        if(a&1)ret*=m;
        a>>=1;
        m*=m;
        m%=mod;
        ret%=mod;
    }
    return ret;
}
//���ģ���Է���ax=b (% mod)
//���ؽ�ĸ���,�Ᵽ����sol[]��
//Ҫ��n>0,��ķ�Χ0..n-1
_LL mod_linear(_LL a,_LL b,_LL mod,_LL *sol){
	_LL d,e,x,y,i;
	d=ext_gcd(a,mod,x,y);
	if (b%d)
		return 0;
	e=(x*(b/d)%mod+mod)%mod;
//	for (i=0;i<d;i++)
//		sol[i]=(e+i*(mod/d))%mod;
    sol[0]=e%mod;
	return d;
}
int main() {
    _LL x,y,m,n,L;
    while(cin>>x>>y>>m>>n>>L){
        _LL dis=(y-x+L)%L;
        _LL der=(m-n+L)%L;
        _LL sol[10];
        _LL res=mod_linear(der,dis,L,sol);
        if(res)cout<<sol[0]<<endl;
        else cout<<"Impossible\n";
    }
return 0;}
