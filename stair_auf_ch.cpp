#include <iostream>
using namespace std;
int main(int argc, char** argv) {

int i,j,n,x=1,sum1=0,sum2=0,sum3=0;
cout<<"please input the needed n:" ;
cin>>n;

for(i=1;i<=n;i++){
    x=1;
    for(j=1;j<=i;j++){
        x*=j;
    }
    sum1+=x;
}
cout<<"the answer is "<<sum1<<endl;


for(i=1;i<=n;i+=2){
    x=1;
    for(j=1;j<=i;j++){
        x*=j;
    }
    
    sum2+=x;
}
for(i=2;i<=n;i+=2){
    x=1;
    for(j=1;j<=i;j++){
        x*=j;
    }
    //cout<<"this is x "<<x<<endl;
    sum3+=x;
}
sum3=sum3*-1;
// cout<<"this is sum2 "<<sum2<<endl;
// cout<<"this is sum3 "<<sum3<<endl;
cout<<"the answer is "<<sum2+sum3<<endl;

return 0;
}