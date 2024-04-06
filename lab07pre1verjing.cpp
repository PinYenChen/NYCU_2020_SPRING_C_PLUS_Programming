#include <iostream>

using namespace std;
//444444*555555=2469...
int main(int argc, char** argv) {

bool msign=false;
bool nsign=false;

int m,n,N[20]={0},X[20][25]={0},t,x=0,t1,y=0,digit=0,A,d[25]={0},b,digitOfN=0; 

/*
假設N為一不超過二十位數
N為將其中一個數分離位數時所使用的矩陣
X為隨N的位數多寡而決定的矩陣
*/

cout<<"Please input two integer m and n: "<<endl;
cin>>m>>n;


//判斷m n 是正還是負 
	msign = m > 0 ? false : true;
	nsign = n > 0 ? false : true;

if(msign){
	m = -m;
}
if(nsign){
	n = -n;
}
b=n;

while(b>0){
        b=b/10;
        digitOfN=digitOfN+1;
    }//end of first while in order to 判斷位數

while((n/10)>0 || (n%10)!=0){
        t=n%10; //先放進去的是個位數
        N[x++]=t;
        n=n/10;
    }//end of while in order to 分離位數(n)

//for(int j=digitOfN-1;j>=0;j--){ //先印出來的是高位數
//    cout<<N[j]<<endl;
//}


for(int i=0;i<=digitOfN-1;i++){
    A=N[i]*m;
    int z=i;
    while(A){
        t1=A%10; //先放進去的是個位數
        X[i][z]=t1;
        A=A/10;
        digit=z+1;
        z++;
    }//end of while in order to calculate the 位數of answer and 放入矩陣中
}//end of for


for(int u=0;u<=digit;u++){  
    for(int j=0;j<=digit;j++){
        d[u]+=X[j][u];
        if(d[u]>=10){
            X[0][u+1]+=d[u]/10;
            d[u]=d[u]%10;
        }// end of if in order to deal with 進位
    }//end of inner for
}//end of outer for

cout<<"the answer is ";
if(msign&&!nsign||nsign&&!msign){
    cout<<"-";
}

for(int w=digit-1;w>=0;w--){ //先印出來的是高位數比較晚放入矩陣
    cout<<d[w];
}
cout<<endl;



return 0;
}