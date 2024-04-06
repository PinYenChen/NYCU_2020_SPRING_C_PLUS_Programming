#include <iostream>

using namespace std;

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
int binarySearch(int data[],int start,int end, int target){
    static int u=0;
    u++;
    if(start>end)return -1;
    int t=(start+end)/2;
    if(data[t]==target)return u;
    else if(data[t]<target)return binarySearch(data, start+1, end, target); //since half is too small lower+1
    else if (data[t]>target)return binarySearch(data,start,end-1,target); 
}
int num(int n,int m){
    if(n>m&&m>0){
        return num(n-1,m-1)+num(n-1,m);
    }
    if(m==0||m==n)return 1;

}


int main(){
    cout<<"1-1"<<endl;
    int n;
    cout<<"Please input the size of the array: ";
    cin>>n;
    cout<<endl;

    int *data;
    data=new int [n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    insertionSort(data,n);
    cout<<"After sorting :"<<endl;
    for(int i=0;i<n;i++){
        cout<<data[i]<<"\t";
    }
    cout<<endl;

    int target;
    cout<<"Please input the needed value: ";
    cin>>target;
    cout<<binarySearch(data,0,n-1,target)<<endl;

    delete[] data;

    cout<<"1-2"<<endl;
    cout<<"Please input the numbers of the pairs: ";
    int length;
    cin>>length;
    cout<<endl;

    int **b,x=0;

    b=new int*[length];
    for(int i=0;i<length;i++){
        b[i]=new int [2];
        for(int j=0;j<2;j++){
            cin>>b[i][j];
        }
    }

    while(x!=length){
        int n=b[x][0];
        int m=b[x][1];
        cout<<"f["<<n<<","<<m<<"]="<<num(n,m)<<endl;
        x++;
    }

    for(int j=0;j<2;j++) delete[] b[j];
    delete[] b;

    return 0;
}
