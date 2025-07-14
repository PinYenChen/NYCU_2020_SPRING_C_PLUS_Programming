#include <iostream>
using namespace std;
int main(int argc, char** argv) {

int x,y,z,n,m;
cout<<"Please input m and n:\n";
cin>>m>>n;

for(x=2;x<m+1;x+=n){
    for(y=1;y<m+1;y++){
        for(z=x;z<x+n;z++){
            if (z<=m){
                cout<<z<<"*"<<y<<"="<<z*y<<"\t";
            }  //end of if
            else{
                break;
            }  //end of else
        } // end of inner for
        cout<<"\n";
    } //end of middle for
    cout<<"\n";    
} //end of outer for

return 0;
}

