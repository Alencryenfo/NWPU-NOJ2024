#include <bits/stdc++.h>
 
using namespace std;
 
string out[100];
int k=0;
 
int check(string str){
    int i,result;
 
    for(result=str[1],i=2;str[i]!='*';i++)
    {
        result^=str[i];
    }
    return result;
}
 
int convert(string str){
    int res=0;
    res=stoi(str,0,16);
    return res;
}
 
 
void convert_BeingTime(string utcTime){
    int  hour=stoi(utcTime.substr(0,2));
    int  B_hour=(hour+8)%24;
    if(B_hour/10==0)
        out[k++]="0"+to_string(B_hour)+":"+utcTime.substr(2,2)+":"+utcTime.substr(4,2);
    else
        out[k++]=to_string(B_hour)+":"+utcTime.substr(2,2)+":"+utcTime.substr(4,2);
 
}
 
int main(){
    string str;
    while(cin>>str){
        if(str=="END") break;
        if(str.compare(0,6,"$GPRMC")==0){
            size_t asteriskPos = str.find('*');
            if(asteriskPos!=string::npos){
                int checksum=check(str);
                
                int senchecksum=convert(str.substr(asteriskPos + 1, 2));
                if(checksum!=senchecksum) {
                    out[k++]="error";
          
                }
                else{
                    string utcTime = str.substr(7, 6);
     
                    convert_BeingTime(utcTime);
                }
            }
        }
 
    }
    for(int i=0;i<k;i++){
        cout<<out[i]<<endl;
    }
}//来自https://blog.csdn.net/annesede/article/details/133761873，使用了C++风格字符串，不知道为什么自己写的C风格没过，网上也没有C的代码，评测机NT
