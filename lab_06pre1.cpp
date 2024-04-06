#include <iostream>
using namespace std;
int main(int argc, char** argv) {

int x,n=0,y,sum2=1,i,sum1=0,z,u;
cout<<"Please input x ";
cin>>x;

z=x;
u=x;

    while(x>0){
        x=x/10;
        n=n+1;
    }//end of first while in order to 判斷位數    

    while((z/10)>0 || (z%10)!=0){
        y=z%10;
        for(i=1;i<=n;i++){
           sum2=y*sum2;
        }//end of for
        sum1=sum2+sum1;
        sum2=1;
        z=z/10;
    }//end of second while in order to 分離位數以及加總


    if(sum1==u){ //比較加總與原數是否相等
        cout<<"This is Armstrong value"<<endl;
    }//end of if
        else{
        cout<<"This is not Armstrong value"<<endl;
    }//end of else


	return 0;
}
