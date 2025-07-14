#include <iostream>

using namespace std;


int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }else{
        
    return fib(n-1)+fib(n-2);
    }
}
int fib1(int n){
    int FIB[n+1];
    FIB[0]=0;
    FIB[1]=1;
    if(n<2){
        return FIB[n];
    }else{
        int i;
        for(i=2;i<=n;i++){
            FIB[i]=FIB[i-1]+FIB[i-2];
        }
        return FIB[n];
    }
}
int main() {
    int n,u=1;
    cout<<"Please input a n :";
    cin>>n;
    cout<<"the result is : "<<fib(n+1)<<endl;
    for(int i=n-1;i>=2;i--){
        cout<<"fib("<<i<<")"<<"has been calculated "<<fib(n-i+1)<<" times "<<endl;
        u++;
    }

    cout<<"==============加分題==============="<<endl;
    u=1;
    cout<<"the result is : "<<fib1(n+1)<<endl;
    for(int i=n-1;i>=2;i--){
    cout<<"fib("<<i<<")"<<"has been calculated "<<u<<" times "<<endl;
    }
return 0;
}
