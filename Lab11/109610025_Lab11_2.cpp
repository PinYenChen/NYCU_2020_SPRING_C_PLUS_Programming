#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct info{
    char name[5];
    float scores[6];  //0-4 各科成績  scores[5]==id 
    int rate;
    float average;
};
void bubblesorting(struct info student[] ,int n, int k){ //k=0---program,k=1---elect...
    struct info teminfo;
    if(k<6){
        for(int i=n-2;i>=0;i--){
            for(int j=i;j<n-1;j++){
                if(student[j].scores[k]<student[j+1].scores[k]){
                    teminfo=student[j+1];
                    student[j+1]=student[j];
                    student[j]=teminfo;
                }
            }
        }
    }else if (k>=6){
        for(int i=n-2;i>=0;i--){
            for(int j=i;j<n-1;j++){
                if(student[j].average<student[j+1].average){
                    teminfo=student[j+1];
                    student[j+1]=student[j];
                    student[j]=teminfo;
                }
            }
        }
    }

}
void print(struct info student[],int n){
    cout<<"ID\tName\tPrgm\tElctrn\tDynmic\tBio\tNano\tSemes\trank"<<endl;
    cout<<"\n";
    for(int i=0;i<n;i++){

        cout<<"0911";
        if(student[i].scores[5]>9&&student[i].scores[5]<100)cout<<"0";
        if(student[i].scores[5]<=9)cout<<"00";
        cout<<student[i].scores[5];

        cout<<"\t";

        for(int j=0;j<3;j++){
            cout<<student[i].name[j];
        }
        cout<<"\t";

        for(int j=0;j<5;j++){
            cout<<student[i].scores[j]<<"\t";
        }
        cout<<student[i].average<<"\t";
        cout<<student[i].rate;
        cout<<endl;
    }
}
void print_for_indi(struct info student[],int i){
        cout<<"ID\tName\tPrgm\tElctrn\tDynmic\tBio\tNano\tSemes\tRank"<<endl<<endl;
            cout<<"0911";
            if(student[i].scores[5]>9&&student[i].scores[5]<100)cout<<"0";
            if(student[i].scores[5]<=9)cout<<"00";
            cout<<student[i].scores[5];

            cout<<"\t";

            for(int j=0;j<3;j++){
                cout<<student[i].name[j];
            }
            cout<<"\t";

            for(int j=0;j<5;j++){
                cout<<student[i].scores[j]<<"\t";
            }
            cout<<student[i].average<<"\t";
            cout<<student[i].rate;
            cout<<endl;
}

int binarySearch(struct info student[],int start,int end, int target){
     static int idx=0;
     idx++;
     if(start>end)return -1;
     int t=(start+end)/2;
     if(student[t].scores[5]==target)return idx;
     else if(student[t].scores[5]<target)return binarySearch(student, start+1, end, target); //since half is too small lower+1
     else if (student[t].scores[5]>target)return binarySearch(student,start,end-1,target); 
 }
int sequenSearch(struct info student[],int n,int target){
    int i;
    bool find=false;
    for(i=0;i<n;i++){
        if(student[i].scores[5]==target){
            find=true;
            break;
        }
    }
    if(find)return i;
    if(!find)return -1;

}
//   int countlines(char* filename){
//     ifstream Read;
//       int n=0;
//       string tmp;
//       Read.open(filename,ios::in);
//       if(Read.fail()){
//           return 0;
        
//       }
//       while(getline(Read,tmp,'\n')){
//           n++;
//       }
//       Read.close();
//       return n;
//   }

int main(){
    srand(time(NULL));
    int input;
    cout<<"Please input the function number: ";
    cin>>input;
    int data[1000]; //0-999
    int n;
    info *student;


    bool s=true; //true ---sequential false---binary

    bool produce=false;

    while(input!=0){

        if(input==1){
            
            cout<<"Please input the number of the students: ";
            cin>>n;
            cout<<endl;
            student=new info[n];

            //id process
            for(int i=0;i<n;i++){
                bool repeat=false;
                student[i].scores[5]=rand()%1000;
                if(i==0){
                    data[i]=student[i].scores[5];
                }else if(i!=0){
                    do{
                        repeat=false;
                        for(int j=i-1;j>=0;j--){
                            if(data[j]==student[i].scores[5]){
                                repeat=true;
                                break;
                            }
                        }//比對每一筆資料庫的數據
                        if(repeat){
                            student[i].scores[5]=rand()%1000;
                        }

                    }while(repeat);
                    data[i]=student[i].scores[5];
                }//in order to avoid repeat case
            

            //name process
                for(int j=0;j<3;j++){
                    student[i].name[j]=char('A'+rand()%26);
                }

                //scores process
                for(int j=0;j<5;j++){
                    student[i].scores[j]=rand()%101;
                }
                student[i].average = ((student[i].scores[0]+student[i].scores[1]+student[i].scores[2])*3 + student[i].scores[3]*2 + student[i].scores[4])/12;
                }
                produce=true;//已建立資料
                bubblesorting(student,n,6); 
                for(int j=0;j<n;j++){
                    int acc=1;
                    for(int q=j-1;q>=0;q--){
                        if(student[j].average<student[q].average){
                            acc++;
                        }
                    }
                    student[j].rate=acc;
                }//產生學期成績的排名
        }
        if(input==9){
            fstream file;
            file.open("classScoresAndInfo.txt",ios::in);
            if(!file){
                cout<<"Sorry. We couldn't open the file."<<endl;
                return 0;
            }
            int i=0;
            file>>n;
            student = new info[n];
            
            while(file>>student[i].scores[5]>>student[i].name>>
                student[i].scores[0]>>student[i].scores[1]>>
                student[i].scores[2]>>student[i].scores[3]>>
                student[i].scores[4]>>student[i].average>>student[i].rate){
                i++;
            }
            file.close();
            produce=true; 
        }
        if(produce){

            if(input==6){
                print (student,n);
            }
            if(input==2){
                bubblesorting(student,n,5); //排名id
                cout<<"-------------------------id ranking---------------------------------------"<<endl;
                print(student,n);
            }
            if(input==3){
                bubblesorting(student,n,6); 
                cout<<"-------------------------semester score ranking---------------------------------------"<<endl;
                print(student,n);
            }
            if(input==4){
                bubblesorting(student,n,0); 
                cout<<"-------------------------program ranking---------------------------------------"<<endl;
                print(student,n);
            }
            if(input==5){
                bubblesorting(student,n,4); 
                cout<<"-------------------------Nanotech ranking---------------------------------------"<<endl;
                print(student,n);
            }
            if(input==7){
                cout<<"Please input the last three digits of id number from the student(0911XXX): ";
                int search;
                cin>>search;
                cout<<endl;
                if(s){
                    if(sequenSearch(student,n,search)==-1){
                        cout<<"Sorry. We couldn't find the infomation of the student!"<<endl;
                    }
                    else if(sequenSearch(student,n,search)!=-1){
                        int idx=sequenSearch(student,n,search);
                        print_for_indi(student,idx);
                    }
                }else if(!s){
                  if(binarySearch(student,0,n,search)==-1){
                      cout<<"Sorry. We couldn't find the infomation of the student!"<<endl;
                  }
                    else if(binarySearch(student,0,n,search)!=-1){
                        int idx=binarySearch(student,0,n,search);
                        print_for_indi(student,idx);
                    }  
                }

            }
             if(input==8){
                ofstream out("classScoresAndInfo.txt");
                out << n << endl;
                for(int i=0;i<n;i++){
                    if(student[i].scores[5]>9&&student[i].scores[5]<100)out<<"0";
                    if(student[i].scores[5]<=9)out<<"00";
                    out<<student[i].scores[5];

                    out<<"\t";

                    for(int j=0;j<3;j++){
                        out<<student[i].name[j];
                    }
                    out<<"\t";

                    for(int j=0;j<5;j++){
                        out<<student[i].scores[j]<<"\t";
                    }
                    out<<student[i].average<<"\t";
                    out<<student[i].rate;
                    out<<endl;
                }
                out.close();
             }

        }else if (!produce){
            cout<<"Sorry. You haven't establisch the infos. Please input 1 or 9."<<endl;
        }
        cout<<"Please input the function number: ";
        cin>>input;
        s=true;
    }

    cout<<"Thnaks for using this service. See you next time. Tschüss~~~"<<endl;

    delete[] student;
    return 0;
}