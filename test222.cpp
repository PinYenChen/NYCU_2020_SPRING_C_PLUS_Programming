#include <iostream>


using namespace std;
int main(){

    cout<<"plus";
    int u=0;
    int sum12=0;
    int sum14=0;
    int sum13,sum11;
    int j;

    do{
        u++;
        for(j=1;j<2*u;j+=2){
            if(j%4==1){
                sum11=(1.0/j);
                sum12=sum11+sum12;
            }//end of if
            if (j%4==3){  //j%4==3
                sum13=(1.0/j);
                sum14=sum13+sum14;
            }//end of if
        }//end of for
    }while(4*(sum12-sum14)-3.1415>0.00005);

    cout<<"The answer for Leibniz approach is "<<u<<"!!!";
    
}