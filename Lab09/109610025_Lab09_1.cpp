#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	srand(0);
	int** a,** b, **c;
	int m,n,p,z;
	int i,j;
	cout<<"Please input the row(m) and col(n) of a array: "<<endl;
	cin>>m>>n;

	cout<<"a:"<<endl;
	a=new int*[m];
	for(i=0;i<m;i++){
		a[i]=new int[n];
		for(j=0;j<n;j++){
			a[i][j]=rand()%6;
			cout<<a[i][j]<<"\t";
		}//end of for in order to control the column of the a array
		cout<<endl;
	}//end of for in order to control the row of the a array
	

	cout<<endl<<"Please input the col(p) of b array: "<<endl;
	cin>>p;
	cout<<"b:"<<endl;
	b=new int*[n];
	for(i=0;i<n;i++){
		b[i]=new int[p];
		for(j=0;j<p;j++){
			b[i][j]=rand()%6;
			cout<<b[i][j]<<"\t";
		}//end of for in order to control the column of the b array
		cout<<endl;
	}//end of for in order to control the row of the b array
	


	c=new int*[n];
	for(i=0;i<n;i++){
		c[i]=new int[p];	
		}//end of for in order to control the column of the b array
	
	
	cout<<"c: "<<endl;
	
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			c[i][j]={0};
			z=0;
			while(z<n){ //z<n®É­«½Æ 
				c[i][j]+=a[i][z]*b[z][j];
				z++;
			}//end of while
			cout<<c[i][j]<<"\t";
		}//end of inner for
		cout<<endl;
	}//end of outer for
	
	for(i=0;i<m;i++){
		delete[] a[i];
	}
	delete[] a;
	//delete a array
	for(i=0;i<n;i++){
		delete[] b[i];
	}
	delete[] b;
	//delete b array
	
	for(i=0;i<m;i++){
		delete[] c[i];
	}
	delete[] c;
	//delete c array

	return 0;
	}
