#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int*a;
	int n,i;
	
	cout<<"Please input the number of students:¡@"<<endl;
	cin>>n;
	a=new int[n];
	
	for(i=0;i<n;i++){
		cin>>a[i];
	}//in order to input the score of student
	
//	for(i=0;i<n;i++){
//		cout<<a[i]<<"\t";
//	}//in order to check
//	
	
	int sum=0,average;
	
	
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	average=sum/n;
	cout<<"the average is "<<average<<endl;
	
	//bubble sorting
	int t,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(a[j]<a[j+1]){
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}//end of if
		}//end of for controlling j
	}//end of for controlling i
	
	for(i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}//end of for in order to check the sorting
	
	cout<<endl;
	
	int q1, half, q3,sum1=0,sum2=0,sum3=0;
	q1=n/4;
	half=n/2;
	q3=n-q1;
//	cout<<q1<<" this is q1 "<<half<<" this is half "<<q3<<" this is q3 "<<endl;

	for(i=0;i<q1;i++){
		sum1+=a[i];
	}
	cout<<"«e25¢H average is "<<sum1/q1<<endl;
	
	for(i=0;i<half;i++){
		sum2+=a[i];
	}
	cout<<"«e50¢H average is "<<sum2/half<<endl;
	
	for(i=0;i<q3;i++){
		sum3+=a[i];
	}
	cout<<"«e75¢H average is "<<sum3/q3<<endl;
	
	
	delete[] a;
	
	return 0;
}
