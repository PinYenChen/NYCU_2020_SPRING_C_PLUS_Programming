#include <iostream>
using namespace std;
int main(int argc, char** argv) {
//相除
int a,b;
bool compare;

cout<<"please input two numbers a and b: ";
cin>>a>>b;
int y,x,c,d;
x=a;y=b;
c=a;d=b;
while(b%a!=0&&a%b!=0){
    if(a>b){
        a=a%b;
        compare=true;
    }
    else if(b>a){
        b=b%a;
        compare=false;
    }
}
if(compare){
    cout<<"the gcd of "<<x<<" and "<<y<<" is "<<a<<endl;
}
if(!compare){
    cout<<"the gcd of "<<x<<" and "<<y<<" is "<<b<<endl;
}

//相減

while(c!=d){
    if(c>d){
        c=c-d;
    }
    if(d>c){
        d=d-c;
    }
}
cout<<"the gcd of "<<x<<" and "<<y<<" is "<<c<<endl;


cout<<"the LCM is "<<(x*y)/c<<endl;

return 0;
}