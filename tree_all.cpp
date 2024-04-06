#include <iostream>
using namespace std;
int main(int argc, char** argv) {

int i,j,k,n;
cout<<"Please input n:\n";
cin>>n;

for(i=1;i<n;i++){
    for(j=n;j>i;j--){
        cout<<" ";
    }//end of blank
    for(k=1;k<=2*i-1;k++){
        cout<<"*";
    }//end of star
cout<<"\n";
}//end of 行

for(j=1;j<=n;j++){
    for(i=n-j;i>=0;i--){
    cout<<" ";
    }//blank

    for(i=j-1;i>=0;i--){
        cout<<(char)('A'+i);
    }//alphabet front

    for(i=1;i<j;i++){
        cout<<(char)('A'+i);
    }//alphabet back
    cout<<endl;
}

int m,p;
cout<<"please input m,p:"<<endl;
cin>>m>>p;
for(j=1;j<=p;j++){

    for(i=1;i<j;i++){
        cout<<" ";
    }
    for(i=1;i<=m;i++){
        cout<<"*";
    }
    for(i=p-j-1;i>=0;i--){
        cout<<"  ";
    }
    for(i=1;i<=m;i++){
        cout<<"*";
    }
    cout<<endl;
}




return 0;
}