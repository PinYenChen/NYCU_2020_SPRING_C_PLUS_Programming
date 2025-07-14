#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"2-1"<<endl;
    //1!+2!+3!
    int i,sum1=1,sum2=0,n;
    cout<<"Please input n:\n";
    cin>>n;
    for(i=1;i<=n;i++){
        sum1=i*sum1;
        sum2+=sum1;
    }
    cout<<sum2<<endl;

	int j,m,k,l,sum3=1,sum5=1,sum4=0,sum6=0;
//1!-2!+3!
	
	for(j=2;j<=n;j+=2){
		for(m=1;m<=j;m++){
			sum3*=m;
		}
        sum4=sum3+sum4;
        sum3=1;
	}
	for(k=1;k<=n;k+=2){
		for(l=1;l<=k;l++){
			sum5=l*sum5;
		}
		sum6=sum5+sum6;
        sum5=1;
	}
	cout<<sum6-sum4<<endl;

    cout<<"2-2"<<endl;
    float sum11,sum12=0,sum13, sum14=0;

    cout<<"Please input n \n";
    cin>>n;

    for(j=1;j<2*n;j+=2){
        if(j%4==1){
            sum11=(1.0/j);
            sum12=sum11+sum12;
        }//end of if
        if (j%4==3){  //j%4==3
            sum13=(1.0/j);
            sum14=sum13+sum14;
        }//end of if
    }//end of for
    cout<<"The answer is (Leibniz) : "<<4*(sum12-sum14)<<endl;
    
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
    
    cout<<"加分題\n";
    int u=0;
    sum12=0;
    sum14=0;

    do{
        u++;
        sum12=0;
        sum14=0;
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
        //cout<<"The answer is (Leibniz) : "<<4*(sum12-sum14)<<endl;
    }while(abs(4*(sum12-sum14)-3.14159)>0.00005);

    cout<<"The answer for Leibniz approach is "<<u<<"!!!";
    int r=0;
    do{
        r++;
        sum8=0;
        sum10=0;

        for(j=1;j<r;j++){
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
    }while(abs(3+4*(sum8-sum10)-3.14159)>0.00005);

    cout<<"\nThe answer for Nilakantha approach is "<<r<<"!!!";
    
    

    return 0;
}