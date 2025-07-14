#include <iostream>
using namespace std;
int main(int argc, char** argv) {

int i,j,k,p,q,m,n,r;
cout<<"Please input n and m:\n";
cin>>n>>m;

for(j=1;j<n+1;j++){
	
	for(i=1;i<=j-1;i++){
		cout<<" ";
	}//end of blank in front
	
	for(k=1;k<m+1;k++){
		cout<<"*";
	}//end of star in the middle
	
	for(p=1;p<=2*m-j;p++){
		cout<<"  ";
	}//end of blank in the middle part
			
	for(q=2*m+j;q<=2*m+j+m-1;q++){
		cout<<"*";
	}//end of the star back
	
	cout<<"\n";
}//end of the line



 i=0;j=0;k=0;n=0;m=0;
cout<<"Please input n :\n";
cin>>n;

for(j=1;j<=n;j++){
	
	for(i=1;i<=n-j;i++){
		cout<<" ";
	}//end of blank in front
	
	for(k=1;k<=j;k++){
		cout<<(char)('A'+ (j-k));
	}//end of alphabet
	
	for(m=n+1;m<n+j;m++){
		cout<<(char)('A'+ (m-n));
	}//end of alphabet2
		
	cout<<"\n";
}//end of the line

return 0;
}
