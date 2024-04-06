#include <iostream>

using namespace std;

int main(int argc, char** argv) {

int m,n,N[3]={0},a[40]={0},b[40]={0},x=0,t,A,t1,y=0,B,t2,c[40]={0},C,d[40],z=1,g=2; 

/*
假設N為一百位數
N為將其中一個數分離位數時所使用的矩陣
a.b.c.為分別將m與n的個、十、百位數相乘後所代表的矩陣
t1.t2 為分離位數時所使用的變數
y,z,g為分別在直式乘法中（同列及代表相同矩陣位置）因此這三個數的起始點各不相同
*/

cout<<"Please input two integer m and n: "<<endl;
cin>>m>>n;

while((n/10)>0 || (n%10)!=0){
        t=n%10; //先放進去的是個位數
        N[x++]=t;
        n=n/10;
    }//end of while in order to 分離位數

//for(int j=2;j>=0;j--){ //先印出來的是高位數
    //cout<<N[j]<<endl;
//}

A=N[0]*m;
while((A/10)>0 || (A%10)!=0){
        t1=A%10; //先放進去的是個位數
        a[y++]=t1;
        A=A/10;
    }//end of  while in order to 分離位數

B=N[1]*m;
while((B/10)>0 || (B%10)!=0){
        t2=B%10; //先放進去的是個位數
        b[z++]=t2;
        B=B/10;
    }//end of  while in order to 分離位數

y=0;
C=N[2]*m;
while((C/10)>0 || (C%10)!=0){
        t2=C%10; //先放進去的是個位數
        c[g++]=t2;
        C=C/10;
    }//end of  while in order to 分離位數

for(int u=0;u<=20;u++){  
    d[u]=a[u]+b[u]+c[u];
    if(d[u]>=10){
        a[u+1]=a[u+1]+(d[u]/10);
        d[u]=d[u]%10;
    }//end of if
}//end of for

cout<<"the answer is ";
for(int i=6;i>=0;i--){ //先印出來的是高位數
    cout<<d[i];
}
cout<<endl;



return 0;
}