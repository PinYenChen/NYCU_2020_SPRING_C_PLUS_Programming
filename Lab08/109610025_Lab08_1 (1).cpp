#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
	
	
	int a[1000]={0},c[500];
	int i,b,j,u=0;
	
	srand(0);
	a[0]=rand()%5+1;
	
	for(i=1;i<1000;i++){
		a[i]=rand()%5+1+a[i-1];
		//cout<<a[i]<<"\t";
	}
	
	srand(100);
	for(i=0;i<500;i++){
		c[i]=rand()%5000+1; //1-5000
		//cout<<c[i]<<"\t";
	}
	for(i=0;i<500;i++){  //從c矩陣中開始一個一對
		for(j=0;j<1000;j++){  //從a矩陣中開始一個一對
			u++;
			if(c[i]==a[j]){ //the case that it do match,then it can stop the checking process and weitergehen. 
				break;
			}//end of if
		}//end of for in order to control the j (a array) 
	} //end if for in order to control the i(c array)
	cout<<u/500<<" the average of sequential search"<<endl;
	
	
	
	int up,down,sum=0;
	up=1000;
	down=0;

	
	for(i=0;i<500;i++){ //從c矩陣中開始一個一對
		up = 1000;
		down = 0;
		while(up>=down){ 
			sum++; //the time of the comparing
			if(c[i]==a[down+(up-down)/2]){
				break;
			}
			else if(c[i]>a[down+(up-down)/2]) {
				down= down+(up-down)/2+1;
			}
			else if(c[i]<a[down+(up-down)/2]){
				up=down+(up-down)/2-1;
			}
		}
	}
	
	cout<<sum/500.0<<" the average of binary searching"<<endl;
	
	
	
	return 0;	
}

