#include <iostream>
using namespace std;
int main(int argc, char** argv) {

int m,n,i=0,j,k,x=1,sum=0;   //i 表位數
int p,a[20]={0},s;
cout<<"please input the m(in decimal) and the needed transfer n: ";
cin>>m>>n;
s=m;
while(m>0){
    p=m%n;
    a[i]=p;
    i++;
    m=m/n;
}
cout<<s<<" (decimal) in "<<n<<" is: ";
for(j=i-1;j>=0;j--){
    cout<<a[j];
}
cout<<endl;

for(j=0;j<i;j++){
    x=1;
    for(k=0;k<j;k++){
        x*=n;
    }
    sum+=a[j]*x;
}
cout<<"the reverse is "<<sum<<endl;
return 0;
}