#include <iostream>
#include <time.h>
using namespace std;
int main(int argc, char** argv) {

srand(time(NULL));
//selection 
int a[10];
int i,j,mini,m,t;

cout<<"vorherigen : "<<endl;
for(i=0;i<10;i++){
    a[i]=rand()%20;
    cout<<a[i]<<"\t";
}
cout<<endl;

cout<<"nach sorting: "<<endl;

for(i=0;i<9;i++){
    mini=a[i];
    m=i;
    for(j=i+1;j<10;j++){
        if(mini>a[j]){
            m=j;
            mini=a[j];
        }
    }
    if(a[i]>a[m]){
        t=a[m];
        a[m]=a[i];
        a[i]=t;
    }
}

for(i=0;i<10;i++){
    cout<<a[i]<<"\t";
}
cout<<endl;

//bubble
cout<<"vorherigen : "<<endl;
for(i=0;i<10;i++){
    a[i]=rand()%20;
    cout<<a[i]<<"\t";
}
cout<<endl;

for(i=0;i<9;i++){
    for(j=0;j<9;j++){
        if(a[j]>a[j+1]){
            t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;
        }
    }
}
cout<<"nach sorting: "<<endl;
for(i=0;i<10;i++){
    cout<<a[i]<<"\t";
}
cout<<endl;


//insertion
cout<<"vorherigen : "<<endl;
for(i=0;i<10;i++){
    a[i]=rand()%20;
    cout<<a[i]<<"\t";
}
cout<<endl;

for(i=1;i<10;i++){
        while(a[i]<a[i-1]&&i>=1){
            t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
            i--;
        }
    }

cout<<"nach sorting: "<<endl;
for(i=0;i<10;i++){
    cout<<a[i]<<"\t";
}

cout<<endl<<"================================================================"<<endl;
//seleciton
mini=0;m=0;
cout<<endl;
cout<<"vorherigen : "<<endl;
for(i=0;i<10;i++){
    a[i]=rand()%20;
    cout<<a[i]<<"\t";
}
cout<<endl;
for(i=0;i<9;i++){
    mini=a[i];
    m=i;
    for(j=i+1;j<10;j++){
        if(mini>a[j]){
            mini=a[j];
            m=j;
        }
    }
    if(a[m]<a[i]){
        t=a[m];
        a[m]=a[i];
        a[i]=t;
    }
}

cout<<"nach sorting: "<<endl;
for(i=0;i<10;i++){
    cout<<a[i]<<"\t";
}

cout<<endl;
//bubble
cout<<"vorherigen : "<<endl;
for(i=0;i<10;i++){
    a[i]=rand()%20;
    cout<<a[i]<<"\t";
}
cout<<endl;
for(i=0;i<9;i++){
    for(j=0;j<9-i;j++){
        if(a[j]>a[j+1]){
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    }
}
cout<<"nach sorting: "<<endl;
for(i=0;i<10;i++){
    cout<<a[i]<<"\t";
}
cout<<endl;
//insertion
cout<<"vorherigen : "<<endl;
for(i=0;i<10;i++){
    a[i]=rand()%20;
    cout<<a[i]<<"\t";
}
cout<<endl;
for(i=0;i<10;i++){
    while(a[i-1]>a[i]&&i>0){
        t=a[i-1];
        a[i-1]=a[i];
        a[i]=t;
        i--;
    }
}
cout<<"nach sorting: "<<endl;
for(i=0;i<10;i++){
    cout<<a[i]<<"\t";
}
return 0;
}
