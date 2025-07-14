#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	
	int i,j,k;
	int n;
	cout<<"please input n: ";
	cin>>n;
	
	for(i=1;i<=n;i++){
		
		for(j=0;j<i-1;j++){
			cout<<" ";
		}
		for(j=n-i;j>=0;j--){
			cout<<(char('A'+j));
		}
		for(j=1;j<=n-i;j++){
			cout<<(char('A'+j));
		}
		cout<<endl;
	}
	
	
	
	
	return 0;
}
