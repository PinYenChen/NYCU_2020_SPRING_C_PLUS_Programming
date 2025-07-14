#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
	int a,q;
	int i,j;
	float r[16]={0},s[16]={0};
	for(q=1000;q<=10000;q+=1000){
		cout<<"Sampling times " <<q<<endl;
		
		for(j=0;j<16;j++){
			r[j]=0;
		}
		for(i=0;i<q;i++){
		a=rand()%6+1+rand()%6+1+rand()%6+1;//in order to make the 3 dices dots
		//cout<<a[i]<<"\t";
	
		switch(a){
			case 3:
				r[0]++;
				break;
			case 4:
				r[1]++;
				break;
			case 5:
				r[2]++;
				break;
			case 6:
				r[3]++;
				break;
			case 7:
				r[4]++;
				break;
			case 8:
				r[5]++;
				break;
			case 9:
				r[6]++;
				break;
			case 10:
				r[7]++;
				break;
			case 11:
				r[8]++;
				break;
			case 12:
				r[9]++;
				break;
			case 13:
				r[10]++;
				break;
			case 14:
				r[11]++;
				break;
			case 15:
				r[12]++;
				break;
			case 16:
				r[13]++;
				break;
			case 17:
				r[14]++;
				break;
			case 18:
				r[15]++;
				break;
		}
	}//end of for
		for(i=0;i<16;i++){
			cout<<r[i]<<"\t";//need to printed
			cout<<","<<i+3<<"|";
			for(j=0;j<=r[i]/q*500;j++){
				cout<<"*";
			}//end of for in order to draw the picture
			cout<<endl;
		}//end of for
	}//end of big for
	
	
	
	
	return 0;
}
	
	
	
	
	
