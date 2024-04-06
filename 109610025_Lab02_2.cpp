#include <iostream>
using namespace std;

int main(){
    cout<<"2-1"<<endl;
    int one,two;
    cout<<"Please input two number: ";
    cin>>one>>two;
    cout<<endl;
    int one1=one,digit1=0;
    int two1=two,digit2=0;
    int ans=one+two,digit3;

    int a[10],b[10],c[11];

    while(one1>0){
        one1=one1/10;
        digit1=digit1+1;
    }//end of first while in order to 判斷位數
    //cout<<digit1<<endl;
    while(two1>0){
        two1=two1/10;
        digit2=digit2+1;
    }//end of first while in order to 判斷位數
    //cout<<digit2<<endl;
    while(ans>0){
        ans=ans/10;
        digit3=digit3+1;
    }//end of first while in order to 判斷位數
    //cout<<digit3<<endl;
    for(int i=9;i>=0;i--){
        a[i]=one%10;
        one=one/10;
    }
    for(int i=10-digit1;i<10;i++){
        cout<<a[i];
    }
    for(int i=9;i>=0;i--){
        b[i]=two%10;
        two=two/10;
    }
    
    for(int i=9;i>=0;i--){
        c[i]=a[i]+b[i];
        //cout<<c[i];
        if(c[i]>=10){
            c[i]=(a[i]+b[i])%10;
        }
    }
    
    cout<<" + ";
    for(int i=10-digit2;i<10;i++){
        cout<<b[i];
    }
    cout<<" = ";
    for(int i=10-digit3+1;i<10;i++){
        cout<<c[i];
    }
    cout<<endl<<endl;
//============================================
    cout<<"2-2\n";

    int r;
    digit1=0;
    digit2=0;
    digit3=0;
    int e[10]={0};
    int d[10]={0};
    int f[20]={0};

    

    cout<<"Please input two integer : ";
    cin>>one>>two;
    cout<<"Please input the base: ";
    cin>>r;
    cout<<endl;

    one1=one;
    two1=two;
    ans=one1+two1;
    while(one1>0){
        one1=one1/10;
        digit1=digit1+1;
    }//end of first while in order to 判斷位數
    //cout<<digit1<<endl;
    while(two1>0){
        two1=two1/10;
        digit2=digit2+1;
    }//end of first while in order to 判斷位數
    while(ans>0){
        ans=ans/10;
        digit3=digit3+1;
    }//end of first while in order to 判斷位數

    for(int i=0;i<10;i++){
        e[i]=one%10;
        one=one/10;
        //cout<<e[i];
    }//分離位數
    for(int i=digit1-1;i>=0;i--){
        cout<<e[i];
    }
    cout<<" + ";
    for(int i=0;i<10;i++){
        d[i]=two%10;
        two=two/10;
        //cout<<d[i];
    }
    for(int i=digit2-1;i>=0;i--){
        cout<<d[i];
    }
    cout<<" = ";

    for(int i=0;i<10;i++){
        f[i]=e[i]+d[i];
        
        if(f[i]>=r){
            f[i]=(e[i]+d[i])%r;
            e[i+1]+=(e[i]+d[i])/r;
        }
        //cout<<f[i];
    }
    
    for(int i=digit3;i>=0;i--){
        cout<<f[i];
    }
    
    

    cout<<endl;
    return 0;
}