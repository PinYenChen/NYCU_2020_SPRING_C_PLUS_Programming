#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int data[1000][3],picknum[3];
	int i,j,k,n=0,n1=0;
	int select,a1,b1,a,b;
	bool compare=false;  

	srand(time(NULL));
	
	//all posibilities
	
	for(i=1;i<10;i++){
		for(j=0;j<10;j++){
			if(j==i){
				continue;
			}
			for(k=0;k<10;k++){
				if(k==j||k==i){
					continue;
				}
				data[n][0]=i;
				data[n][1]=j;
				data[n][2]=k;
				n++;
			}//end of for controlling k
		}//end of for controlling j
	}//end of for controlling i
	
	//cout<<"this is n "<<n<<endl;
	
//	for(i=0;i<n;i++){
//		cout<<"this is data :";
//		for(j=0;j<3;j++){
//			cout<<data[i][j];
//		}
//		cout<<"\t";
//	}
	

	
	do{ 
	
		select=rand()%n;
		//cout<<"this is n "<<n<<endl;
		cout<<"the answer of computer is: ";
		
		for(i=0;i<3;i++){
			cout<<data[select][i];
			picknum[i]=data[select][i];
		}//computer first random select a number as its answer
		
		cout<<endl;
		cout<<"people hint (a1)A (b1)B :";
		cin>>a>>b;
		
		n1=0;
		compare=false;
		
		for(i=0;i<n;i++){ //controlling number of n
			a1=0;
			b1=0;
			
			for(j=0;j<3;j++){ // controlling the entries of select
				for(k=0;k<3;k++){ //controlling the entries of i
					if(data[i][k]==picknum[j]&&k==j){ //site and the number are all right
						a1++;
					}//end of if for the case a
					if(data[i][k]==picknum[j]&&k!=j){ //site is not right but the number is right
						b1++;
					}//end of if for the case b
				}//end of for controlling k
				
			}//end of for controlling j
			
			if(a1==a&&b1==b){
				for(k=0;k<3;k++){
					data[n1][k]=data[i][k];
				}
				n1++;
				compare=true;
			}
			//cout<<"this is n1: "<<n1<<endl;

		}//end of for controlling i
		n=n1;
		//cout<<"this is n "<<n<<endl;
	}while(n!=0||a!=4);//if a ==4 pc got right can jump out or n不等於零時重複 
	
	if(a==4){
		cout<<"computer got right, the answer is ";
		for(i=0;i<3;i++){
			cout<<picknum[i];
		}
		cout<<endl;
	}
	if(n==0&&a!=4){
		cout<<"People LIE!!!"<<endl;
	}
	
	
	
	
	
	return 0;
}
