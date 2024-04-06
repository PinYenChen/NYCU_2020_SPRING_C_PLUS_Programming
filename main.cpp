#include <iostream>
using namespace std;

int main(){



int i,u=0,j,t,A[1000];
srand(0);

for(int k=0;k<500;k++){
    for(i=0;i<1000;i++){
    	A[i]=rand();  
    //cout<<A[i]<<"\t";
	}//end of for in order to make the A array
//cout<<"  the original array"<<endl;

    for(i=0;i<999;i++){
        for(j=998;j>=i;j--){
            if(A[j]<A[j+1]){
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
                u++;
            }
        }
    }
}


cout<<u/500.0<<endl;

    // for(i=0;i<5;i++){  
    // cout<<A[i]<<"\t";
	// }//end of for in order to make the A array
     return 0;

}