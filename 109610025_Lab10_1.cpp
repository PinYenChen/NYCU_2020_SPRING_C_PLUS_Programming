#include <iostream>

using namespace std;

void plant(int a, int b){
    int sum[30]={0},u=0,sum1=0;
    for(int i=a;i<=b;i++){
        int n=0;
        for(int j=i;j>0;j--){
            if(i%j==0){
                n++;
            }
        }
        if(n==2){
            sum[u]=i;
            u++;
        }//代表能整除的只有自己跟一
        //cout<<"this is "<<i<<" and the number of the n "<<n<<endl;
    }
    //cout<<u<<endl;
    cout<<"Between "<<a<<" and "<<b<<" are "<<u<<" 個 and the sum is :";
    for(int i=0;i<u;i++){
        cout<<sum[i]<<"+";
    }
    cout<<"\b"<<"=";
    for(int i=0;i<u;i++){
        sum1+=sum[i];
    }
    cout<<sum1<<endl;
}

int main (){
    int number;
    int start=0;
    cout<<"please input the number of the pairs : ";
    cin>>number;

    int **b,y,i,j;
    b=new int*[number];

    for(i=0;i<number;i++){
        b[i]=new int [2];
        for(j=0;j<2;j++){
            cin>>b[i][j];
            //cout<<"b["<<i<<"]["<<j<<"]="<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
//cout<<start<<endl;

    while(start!=number){
        int a,c;
        a=b[start][0];
        c=b[start][1];
        plant(a,c);
        start++;
    }


for(j=0;j<2;j++) delete[] b[j];
delete[] b;

    return 0;
}