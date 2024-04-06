#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char** argv) {

int A[1000],k,i,t,u=0,x,j;

//insert 
srand(0);
u=0;
for(k=0;k<500;k++){
	for(i=0;i<1000;i++){
        A[i]=rand();  
        //cout<<A[i]<<"\t";
	}//end of for in order to make the A array
    cout<<endl;
for(x=1;x<1000;x++){
    while(A[x]>A[x-1]&&x>=1){
            t=A[x-1];
            A[x-1]=A[x];
            A[x]=t;
            x--;
            u++;
        }//end of while
    } //repeat conditions
}

// for(i=0;i<5;i++){  
//     cout<<A[i]<<"\t";
// }//end of for in order to make the A array

cout<<"insert"<<u/500<<endl;

//bubble
srand(0);
k=0;i=0;j=0;u=0;

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


cout<<"bubble"<<u/500.0<<endl;

    // for(i=0;i<5;i++){  
    // cout<<A[i]<<"\t";
	// }//end of for in order to make the A array

return 0;
}