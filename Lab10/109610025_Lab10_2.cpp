#include <iostream>

using namespace std;

float c(int n, int k){
    int i,j;
    float sum1=1,sum2=1,sum3=1;
    float sum4;
    for(i=1;i<=n;i++){ 
        sum1*=i;
    }
//    cout<<sum1<<endl;
    for(i=1;i<=k;i++){
        sum2*=i;
    }
//    cout<<sum2<<endl;
    int q=n-k;
    for(i=1;i<=q;i++){
        sum3*=i;
    }
//    cout<<sum3<<endl;
    sum4=sum2*sum3;
    return sum1/sum4;
}

float h(int n,int k){
    int x=n+k-1;
    return c(x,k);
}

int main(){
    int n,k,cans,hans;
        cout<<"Please enter [n, k] :";
        cin>>n>>k;
    if(k<=n){
        do{
        cans=c(n,k);
        cout<<"c["<<n<<","<<k<<"] = "<<cans<<endl;
        hans=h(n,k);
        cout<<"h["<<n<<","<<k<<"] = "<<hans<<endl;
        cout<<"Please enter [n, k] : ";
        cin>>n>>k;
        } while (k<=n); //重複條件為n<k
    }
    return 0;
}