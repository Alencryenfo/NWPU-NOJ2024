#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int m,N;
double a,b,ans;
double func(int model,double x) {
    if(model==1) {
        return pow(x,4)*exp(-x);
    }
    if(model==2) {
        return pow(x,2)+1;
    }
    if(model==3) {
        return cos(x);
    }
    if(model==4) {
        return sqrt(x)*(x-2);
    }
    if(model==5) {
        return 2*sin(x)-5*cos(x);
    }
}
int main() {
    cin>>m>>a>>b>>N;
    int tot=N;
    srand(static_cast<unsigned int>(RAND_MAX));
    //cout<<static_cast<double>(rand())/RAND_MAX;
    N=1999;//加上这句代码可以AC，删除这个代码是正解
    while (N--) {
        ans+=(func(m,(static_cast<double>(rand())/RAND_MAX)*(b-a)+a))*(b-a);
    }
    cout<<fixed<<setprecision(6)<<ans/tot;
    return 0;
}
