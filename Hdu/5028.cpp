#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;
int sign( double x ) {return x<-eps?-1:x>eps;}
struct spt {
	double x,y,z;
	spt(double _x=0,double _y=0,double _z=0):x(_x),y(_y),z(_z) {}
	spt operator +(spt &s) {return spt(x+s.x,y+s.y,z+s.z);}
	spt operator -(spt &s) {return spt(x-s.x,y-s.y,z-s.z);}
	spt operator *(double d) {return spt(x*d,y*d,z*d);}
	spt operator /(double d) {return spt(x/d,y/d,z/d);}
	double len()const {return sqrt(SQ(x)+SQ(y)+SQ(z));}
	double operator *(spt s) {return x*s.x+y*s.y+z*s.z;}   //���
	spt normal(){double d=(*this).len();return (*this)/d;}
	spt operator ^(spt s) {	//���
		spt ret;
		ret.x=y*s.z-z*s.y;
		ret.y=z*s.x-x*s.z;
		ret.z=x*s.y-y*s.x;
		return ret;
	}
	bool operator < (const spt &s)const {
		if(sign(s.x-x)!=0)return sign(x-s.x)<0;
		if(sign(s.y-y)!=0)return sign(y-s.y)<0;
		return sign(z-s.z)<0;
	}
	bool operator ==(const spt &s)const {
		return sign(s.x-x)==0&&sign(s.y-y)==0&&sign(s.z-z)==0;
	}
	void read() {scanf("%lf%lf%lf",&x,&y,&z);}
	void output() {printf("(%.6f %.6f %.6f)\n",x,y,z);}
} Orz(0,0,0);
struct sfl {
	spt p,o;
	sfl() {}
	sfl(spt _p,spt _o):p(_p),o(_o) {}
	sfl(spt u,spt v,spt w) {p=u,o=((v-u)^(w-u)).normal();}
};
spt p[55];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	while(~scanf("%d",&n)) {
		for(i=0; i<n; i++)p[i].read();
		LL sumF=0;
		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)
				for(k=j+1; k<n; k++) {
					sfl F(p[i],p[j],p[k]);
					int a=0,b=0;
					for(int t=0;t<n;t++)if(t!=i&&t!=j&&t!=k){
						int foo=sign((p[t]-F.p)*F.o);
						if(foo==1)a++;
						else b++;
					}
					sumF+=((1LL<<a)-1)%MOD;
					sumF+=((1LL<<b)-1)%MOD;
				}
		LL m=n;
		LL ans=4*((1LL<<n)-1-m-m*(m-1)/2-m*(m-1)*(m-2)/6);
		ans+=sumF;
		ans=(ans%MOD+MOD)%MOD;
		ans*=(MOD+1)/2;
		printf("%I64d\n",ans%MOD);
	}
	return 0;
}
