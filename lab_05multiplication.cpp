#include <iostream>
using namespace std;
int main(int argc, char** argv) {

int i,j,solution;

for(i=2;i<10;i++){
    for(j=1;j<10;j++){
        solution=i*j;
        cout<<i<<"*"<<j<<"="<<solution<<" ";
    }//end of j
    cout<<endl;
}//end of i


return 0;
}