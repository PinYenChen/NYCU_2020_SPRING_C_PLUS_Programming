#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int j,n;
    float sum3,sum5,sum4=0, sum6=0;

    cout<<"Please input n \n";
    cin>>n;

    for(j=1;j<2*n;j+=2){
        if(j%4==1){
            sum3=(1.0/j);
            sum4=sum3+sum4;
        }//end of if
        if (j%4==3){  //j%4==3
            sum5=(1.0/j);
            sum6=sum5+sum6;
        }//end of if
    }//end of for
    cout<<"The answer is (Leibniz) : "<<4*(sum4-sum6)<<endl;
    
    int demo;
    float sum7,sum8=0,sum9,sum10=0;
    
    for(j=1;j<n;j++){
        demo=(2*j)*(2*j+1)*(2*j+2);
        if(j%2==1){
            sum7=1.0/demo;
            sum8=sum7+sum8;
        }//end of if
        else{
            sum9=1.0/demo;
            sum10=sum9+sum10;
        }//end of else
        
    }//end of for
    cout<<"The answer is (Nilakantha): "<<3+4*(sum8-sum10)<<endl;
    
    
    return 0;
}
