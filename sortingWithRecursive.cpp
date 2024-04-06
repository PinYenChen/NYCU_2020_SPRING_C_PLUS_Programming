#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

void bubbleSort(int a[],int n){
    int t;
    static int start=0;
    if(n==1){
        return;
    }
    else{
        if(start==n-1){
            start=0;
            bubbleSort(a,n-1);
            return;
        }
        else{
            if(a[start]>a[start+1]){
                t=a[start];
                a[start]=a[start+1];
                a[start+1]=t;
            }
        start++;
        bubbleSort(a,n);
        }
    }
}
void insertionSort(int a[],int n){
    int i,t;
    static int start=1;
    static int start1=n-1;
    if(n==start){
        return;
    }
    else{
        if(start1==0){
            start1=n-1;
            start++;
            insertionSort(a,n);
            return;
        }else{
            if(a[start1]<a[start1-1]){
                t=a[start1];
                a[start1]=a[start1-1];
                a[start1-1]=t;
            }//end of if
            start1--;
            insertionSort(a,n);
        }//end of else
    }
}

int mIndex1(int a[], int n, int minsite, bool init = true){
    static int idx = minsite;
    if(init){
        idx = minsite;
    }
    if(minsite>=n-1){
        return idx;
    }
    if(a[idx] > a[minsite+1]) idx = minsite+1;
    mIndex1(a,n,++minsite,false);
}
void selectionSort(int a[],int n,int start){
    int t,minIndex;
    if(start==n)return;

  minIndex = mIndex1(a,n,start);
  
    t=a[start];
    a[start]=a[minIndex];
    a[minIndex]=t;

    selectionSort(a,n,++start);
}



int main(){
    srand(time(NULL));
    int a[20];
    int n=20;
    int i;

    cout<<"============ bubble ==================="<<endl;
    cout<<"die vorherigen : "<<endl;
    for(i=0;i<n;i++){
        a[i]=rand()%10;
    }
    print(a,n);

    bubbleSort(a,n);
    cout<<"nachherigen: "<<endl;
    print(a,n);

    cout<<"============ insertion ================="<<endl;
    cout<<"die vorherigen : "<<endl;
    for(i=0;i<n;i++){
        a[i]=rand()%100;
    }
    print(a,n);

    insertionSort(a,n);
    cout<<"nachherigen: "<<endl;
    print(a,n);

    cout<<"============ selection ================="<<endl;
    cout<<"die vorherigen : "<<endl;
    for(i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    print(a,n);
    selectionSort(a,n,0);
    cout<<"nachherigen: "<<endl;
    print(a,n);
return 0;
}
