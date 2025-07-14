#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int a,b,x,LCM,y;
	cout<<"1-1\n"<<"Please input two numbers: ";
	cin>>a>>b;
	
	
	x=a;
	y=b;
	
	while(b%a!=0){
		
		if(a>b){
			a=a%b;
		}
		else{
			b=b%a;
		}
	}
	
	cout<<"the gcd is:"<<a<<endl; //a is GCD
	
	LCM=(x*y)/a;
	cout<<"the lcm is:"<<LCM<<endl;
	

	
	int n,digit,sum1=1,sum2=0,g;
	
	cout<<"1-2\n";
    
    do{
    	cout<<"Please input a integer: ";
    	cin>>n;
    	g=n;
    	
    	while((n/10)>0 || (n%10)!=0){
        	digit=n%10;
        	sum1=digit*sum1;//乘積
			sum2=sum2+digit; //addition
        	n=n/10;
    	}//end of while in order to 分離位數以及加總
    	if(sum2==sum1){
    		cout<<"the sum and the production of "<<g<<" = "<<sum1<<endl;
		}
		sum1=1;
		sum2=0;		
	}while(g>0);
	
	
	
	
	
	

	
    


	return 0;
}

