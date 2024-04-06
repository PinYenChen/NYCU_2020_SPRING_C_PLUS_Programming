#include <iostream>
using namespace std;
int main(int argc, char** argv) {
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
	
	return 0;
}
