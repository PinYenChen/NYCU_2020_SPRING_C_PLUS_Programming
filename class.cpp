#include <fstream>
#include <iostream>
using namespace std;
int main(){
    int id[1000];
    int data[1000];
    int n;
    cout<<"Please input n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        bool repeat=false;
        id[i]=rand()%20;
        if(i==0){
            data[i]=id[i];
        }else if(i!=0){
            do{
                repeat=false;
                for(int j=i-1;j>=0;j--){
                    if(data[j]==id[i]){
                        repeat=true;
                        break;
                    }
                }//比對每一筆資料庫的數據
                if(repeat){
                    id[i]=rand()%20;
                }

            }while(repeat);
            data[i]=id[i];
        }//in order to avoid repeat case
    }
    for(int i=0;i<n;i++){
        cout<<id[i]<<"\t";
    }
    return 0;
}