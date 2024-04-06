#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    
//übung of 2d static array declaration

int **a,m,n,x=0;
cout<<"please input the m and n: (m means the line, n means the lying) ";
cin>>m>>n;

a=new int*[m];
for(int i=0;i<m;i++){
    a[i]=new int [n];
    for(int j=0;j<n;j++){
        a[i][j]=x;
        cout<<"a["<<i<<"]["<<j<<"]="<<x<<"\t";
        x++;
    }
    cout<<endl;
}

for(int i=0;i<m;i++){
    delete[] a[i];
}
delete[]a;




int **b,q,y,i,j;
cout<<"please the x and the y: "<<endl;
cin>>q>>y;
x=0;
b=new int*[q];
for(i=0;i<q;i++){
    b[i]=new int [q];
    for(j=0;j<y;j++){
        b[i][j]=x;
        cout<<"b["<<i<<"]["<<j<<"]="<<b[i][j]<<"\t";
        x++;
    }
    cout<<endl;
}
for(j=0;j<y;j++) delete[] b[j];
delete[] b;


int *c;
x=0;
cout<<"please input n: ";
cin>>n;
c=new int [n];
for(i=0;i<n;i++){
    c[i]=x;
    cout<<"c["<<i<<"]="<<c[i]<<"\t";
    x++;

}
delete[] c;

return 0;
}