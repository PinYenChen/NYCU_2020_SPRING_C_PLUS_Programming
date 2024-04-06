#include <iostream>
using namespace std;
int main(int argc, char** argv) {
//Leibniz's approach
int n,i;
float x,sum1=0,sum2=0;///////
cout<<"please input the n of needed approach accuracy: ";
cin>>n;

for(i=1;i<=2*n-1;i+=4){
    x=1.0/i;
    sum1+=x;
}
//cout<<sum1<<endl;

for(i=3;i<=2*n-1;i+=4){
    x=1.0/i;
    sum2+=x;
    //cout<<sum2<<"\n\n";
}
//cout<<sum2<<endl;
sum2=-1*sum2;
cout<<"Leibniz's approach is "<<(sum1+sum2)*4<<endl;

//Nilakantha
x=1;sum1=0;sum2=0;

for(int j=2;j<=n;j+=2){
    x=1;////////
    for(i=2*j-2;i<=2*j;i++){
        //cout<<i<<"this is i and j"<<j<<endl;
        x*=i;
        //cout<<"this is x in for"<<x<<endl;
    }
    x=1.0/x;
    //cout<<"this is x"<<x;
    sum1+=x;
}
cout<<sum1<<" this is sum1 "<<endl;

x=1;
for(int k=3;k<=n;k+=2){
    x=1;//////
    for(i=2*k-2;i<=2*k;i++){
        x*=i;
    }
    x=1.0/x;
    sum2+=x;
}
sum2=sum2*-1;
//cout<<"this is sum2 "<<sum2<<endl;
cout<<"Nilakantha approach is "<<3+(sum1+sum2)*4<<endl;




return 0;
}