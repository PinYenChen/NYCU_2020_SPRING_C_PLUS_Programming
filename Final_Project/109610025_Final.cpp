#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

struct role_info{
    int money;
    char name[20];
    int site;
    char sign[4];
    int total; //身價
};
struct house_info{
    char city[20];
    int houseNumber;
    int price;
    bool jail;
    bool start;
    bool steuer;
    int whose;//-1代表誰都不屬於 0屬於玩加 1屬於電腦
};

void printmap(struct role_info player[],struct house_info house[]){
    //print the plate
    //======================================first line
    for(int i=0;i<5;i++){
        cout<<"---------";
    }
    cout<<endl;

    for(int i=0;i<5;i++){

        cout<<"|";
        for(int j=0;j<2;j++){
            if(player[j].site==i){
                cout<<player[j].sign;
            }else{
                cout<<" "; 
            }
        }
        cout<<house[i].city<<"  ";
    }
    cout<<"|"<<endl;

    for(int i=0;i<5;i++){
        cout<<"|";
        if(house[i].whose==0){ //belong to player
            cout<<house[i].houseNumber<<" ";
        }else{
            cout<<"  ";
        }
        if(!house[i].jail&&!house[i].start&&!house[i].steuer){
            cout<<house[i].price;
        }else{
            cout<<"   ";
        }
        
        if(house[i].whose==1){ //belong to computer
            cout<<" "<<house[i].houseNumber;
        }else{
            cout<<"  ";
        }
    }
    cout<<"|"<<endl;
    
    for(int i=0;i<5;i++){
        cout<<"---------";
    }
    cout<<endl;
    //=======================================second line
    cout<<"|";
    for(int j=0;j<2;j++){
        if(player[j].site==11){
            cout<<player[j].sign;
        }
        else{
            cout<<" "; 
        }//end of else
    }//end of for
    cout<<house[11].city;
    cout<<"  |";

    for(int i=0;i<23;i++){
        cout<<" ";
    }

    cout<<"|";
    for(int j=0;j<2;j++){
        if(player[j].site==5){
            cout<<player[j].sign;
        }else{
            cout<<" "; 
        }
    }
    cout<<house[5].city;
    cout<<"  |";
    cout<<endl;
    cout<<"|";
    if(house[11].whose==0){
        cout<<house[11].houseNumber<<" ";
    }else{
        cout<<"  ";
    }
    cout<<house[11].price;
    if(house[11].whose==1){
        cout<<" "<<house[11].houseNumber;
    }else{
        cout<<"  ";
    }
    cout<<"|";
    for(int i=0;i<23;i++){
        cout<<" ";
    }
    cout<<"|";
    if(house[5].whose==0){
        cout<<house[5].houseNumber<<" ";
    }else{
        cout<<"  ";
    }
    cout<<house[5].price;
    if(house[5].whose==1){
        cout<<" "<<house[5].houseNumber;
    }else{
        cout<<"  ";
    }
    cout<<"|";
    cout<<endl;
    //==================================================third line
    for(int i=10;i>=6;i--){
        cout<<"---------";
    }
    cout<<endl;

    for(int i=10;i>=6;i--){

        cout<<"|";
        for(int j=0;j<2;j++){
            if(player[j].site==i){
                cout<<player[j].sign;
            }else{
                cout<<" "; 
            }
        }
        cout<<house[i].city<<"  ";
    }
    cout<<"|"<<endl;

    for(int i=10;i>=6;i--){
        cout<<"|";
        if(house[i].whose==0){ //belong to player
            cout<<house[i].houseNumber<<" ";
        }else{
            cout<<"  ";
        }
        if(!house[i].jail&&!house[i].start&&!house[i].steuer){
            cout<<house[i].price;
        }else{
            cout<<"   ";
        }
        
        if(house[i].whose==1){ //belong to computer
            cout<<" "<<house[i].houseNumber;
        }else{
            cout<<"  ";
        }
    }
    cout<<"|"<<endl;
    
    for(int i=10;i>=6;i--){
        cout<<"---------";
    }
    cout<<endl;
    //=============================print to here
    
}

bool canbuy(struct house_info house[], int site){
    bool buy=false;
    if(!house[site].jail && !house[site].start && !house[site].steuer){
        if(house[site].houseNumber >= 0 && house[site].houseNumber < 4){
            buy = true;
        }
    }
    return buy; //it aprrove the player to buy the house
}
void totalCal(struct house_info house[], struct role_info player[], int who){
    // !operator---(-) operator---(+)
    int i=0;
    player[who].total=0; //重新計算
    for(i=0;i<12;i++){
        if(house[i].whose==who)
        player[who].total+=house[i].price;
    }
    player[who].total*=0.75;
}

void pay_bank(struct house_info house[], struct role_info player[],int buyer,int site, bool firstbuy){
    if(firstbuy){
        player[buyer].money = player[buyer].money - house[site].price;
        house[site].whose=buyer;  
    }//第一次買的時候
    else{ //增加房子
        player[buyer].money = player[buyer].money - 100;
    }
    house[site].price+=100;
    house[site].houseNumber++;
}

void trade_player(struct house_info house[], struct role_info player[], int buyer, int gekauft, 
int site ,bool buy){
    if(!buy){ //只是一班的繳錢沒有收購
        player[buyer].money=player[buyer].money-house[site].price;
        player[gekauft].money=player[gekauft].money+house[site].price;
    }else{ //收購的話價格是土地的1.5倍
        player[buyer].money=player[buyer].money-house[site].price*1.5;
        player[gekauft].money=player[gekauft].money+house[site].price*1.5;
        house[site].whose=buyer;//過戶
    }
}

void taxpay(struct role_info player[],int who){
    player[who].money-=100;
}//踩到繳稅要扣錢

void getmoney(struct role_info player[], int who){
    player[who].money+=150;
}

void printplayer(struct role_info player[]){
    cout<<"Name\tMoney\tTotal\n";
    cout<<"--------------------------\n";
    for(int i=0;i<2;i++){
        cout<<player[i].name<<"\t"<<player[i].money<<"\t"<<player[i].total<<endl;
    }
}

void sell(struct house_info house[],struct role_info player[],int seller){
    int no;
    cout<<"Please select the sold city: ";
    cin>>no;
    player[seller].money=player[seller].money+house[no].price*0.75;
    
    house[no].price=house[no].price-(house[no].houseNumber*100); //回到原本價格
    house[no].houseNumber=0;
    house[no].whose=-1; //還給銀行
    totalCal(house,player,0);
}
void sellpc(struct house_info house[], struct role_info player[], int seller){
    int number[12];
    int x=0;
    for(int i=0;i<11;i++){
        if(house[i].whose==1){
            number[x]=i;
            x++;
        }
    }//每次進來這個函式都先檢查什麼房子可以賣 先從低價的開始賣
    
    player[seller].money=player[seller].money+house[number[0]].price*0.75;
    
    house[number[0]].price=house[number[0]].price-(house[number[0]].houseNumber*100); //回到原本價格
    house[number[0]].houseNumber=0;
    house[number[0]].whose=-1; //還給銀行
    totalCal(house,player,1);
}

int main(){
    srand(time(NULL));
    int function;
    char filename[20];
    char readfile[20];
    bool info=false;
    cout<<"Do you want to start a new game?(0---no,1---yes): ";
    cin>>function;
    bool atjail=false;
    int x=0; //暫停的回合數 在二的時候出來
    bool pcjail=false;
    int y=0; //暫停的回合數 在二的時候出來
    int u=0;

    role_info player[2]={{150,"people",0,"a",0},
        {150,"pc",0,"c",0}
    };

    //establisch the informations of the plate
    house_info house[12]={{"Srt", 0,9999999, false,true,false,-1},
    {"TPE",0,100,false,false,false,-1},{"TKY",0,150,false,false,false,-1},
    {"SUL",0,200,false,false,false,-1},{"JAL",0,9999999,true,false,false,-1},
    {"BLN",0,250,false,false,false,-1},{"LDN",0,300,false,false,false,-1},
    {"MRD",0,350,false,false,false,-1},{"TAX",0,9999999,false,false,true,-1},
    {"NYK",0,400,false,false,false,-1},{"PRS",0,450,false,false,false,-1},
    {"ROM",0,500,false,false,false,-1}
    };
    info=true;

    if(function==0){
        fstream file;


        cout<<"Please input the filename: ";
        cin>>readfile;
        cout<<endl;

        file.open(readfile,ios::in);
        if(!file){
            cout<<"Sorry. We couldn't open the file."<<endl;
            return 0;
        }
        
        for(int i=0;i<12;i++){
            file>>house[i].city>>house[i].houseNumber>>house[i].price>>house[i].jail
            >>house[i].start>>house[i].steuer>>house[i].whose;
        }
        
        for(int i=0;i<2;i++){
            file>>player[i].money>>player[i].name>>player[i].site>>player[i].sign>>player[i].total;
        }
        file>>atjail>>x;
        file>>pcjail>>y;
        file>>u;
        file.close();
        info=true;
    }
    
    int dice;
    int people_site,computer_site;
    int buy;
    bool peolose=false;
    bool pclose=false;
    int origin;
    bool firstbuy=false;
    bool firstbuy1=false;
    bool pay=false;
    int inter;

    
    cout<<"Game Start!!!"<<endl;
    printmap(player,house);
    printplayer(player);
    cout<<"\n\n\n";

    do{

        u++;
        cout<<"===================The "<<u<<" round===================\n"<<endl;
        if(atjail&&x!=2){
            x++;
        }
        if(x==2 && atjail){
            atjail=false;
            x=0; //歸零等待下次進監獄
        }
        
        if(!atjail){
            cout<<"--------Player's turn--------"<<endl;
            dice=rand()%6+1; //0-5---1-6
            cout<<"People got "<<dice<<" steps"<<endl;
            player[0].site+=dice;
            origin=player[0].site;
            player[0].site=player[0].site%12;
            people_site=player[0].site%12;
            printmap(player,house);
            printplayer(player);

            if(people_site!=0 && origin/12==1){
                cout<<"You got 150 dollars!"<<endl;
                getmoney(player,0); 
                printplayer(player);               
            }
            

            //踩到地有五種結果 監獄 開始 繳稅 買地 繳過路費
            if(canbuy(house,people_site)){ //這塊地不是監獄繳稅以及開始 然後房子數<4&&>=0
                buy=0;
                firstbuy=false;
                cout<<"Do you want to buy the city or bau the house(0---no,1---yes) ";
                cout<<"\n(Remind: If you want to buy the from the others, it costs ";
                cout<<1.5*house[people_site].price<<" ? ";
                cin>>buy;
                cout<<endl;
                if(buy==1){
                    firstbuy=false;
                    if(house[people_site].houseNumber==0&&house[people_site].whose==-1){
                        if(player[0].money>=house[people_site].price){
                            cout<<"people case 1"<<endl;
                            /////people
                            pay_bank(house,player,0,people_site,true);
                            totalCal(house,player,0);
                            firstbuy=true;
                        }else{
                            cout<<"People case 2"<<endl;
                            cout<<"Sorry! You don't have enough money to buy"<<endl;
                        }   
                    }//代表沒有人買過
                    if(house[people_site].houseNumber<4&&house[people_site].houseNumber!=0){
                        if(house[people_site].whose!=0){ //有買過了且地不屬於人的
                            if(player[0].money>=1.5*house[people_site].price){
                                cout<<"people case 3"<<endl;
                                cout<<"Player buys the city from the computer!"<<endl;
                                trade_player(house,player,0,1,people_site,true); //人向電腦買
                                totalCal(house,player,1);
                                totalCal(house,player,0);
                            }else{ //player[0].money<=1.5*house[people_site].price
                                cout<<"people case 4 "<<endl;
                                cout<<"Sorry! You don't have enough money to buy!"<<endl;
                                cout<<"You have to pay the fee!"<<endl;
                                //沒有足夠的錢買房子的話就要繳過路費
                                
                                if(player[0].money>=house[people_site].price){
                                    cout<<"people case 5"<<endl;
                                    trade_player(house,player,0,1,people_site,false);//沒有要買的話只是單純繳錢
                                }else{
                                    cout<<"people case 6"<<endl;
                                    cout<<"You don't have enough money to pay the fee!"<<endl;
                                    
                                    while(player[0].total>0 && player[0].money<house[people_site].price){
                                        sell(house,player,0);
                                    }//先賣房子 如果錢超過150 或者是沒房子賣時跳出

                                    trade_player(house,player,0,1,people_site,false);//沒有要買的話只是單純繳錢
                                //不管賣完房子之後可不可以繳錢都扣 當錢變負數就是破產
                                }                            
                            }
                        }else if(house[people_site].whose==0&&house[people_site].houseNumber<4
                                &&!firstbuy && 100<=player[0].money){ //地原本屬於人的
                                cout<<"people case 7"<<endl;
                            pay_bank(house,player,0,people_site,false);
                            totalCal(house,player,0);
                        }
                    }//有人有買過
                }//end of want buy
                if(buy==0 && house[people_site].whose==1){
                    if(player[0].money>=house[people_site].price){
                        cout<<"people case 8"<<endl;
                        trade_player(house,player,0,1,people_site,false);//沒有要買的話只是單純繳錢
                    }else{
                        cout<<"people case 9"<<endl;
                        cout<<"You don't have enough money to pay the fee!"<<endl;
                        
                        while(player[0].total>0 && player[0].money<house[people_site].price){
                            sell(house,player,0);
                        }//先賣房子 如果錢超過150 或者是沒房子賣時跳出

                        trade_player(house,player,0,1,people_site,false);//沒有要買的話只是單純繳錢
                    //不管賣完房子之後可不可以繳錢都扣 當錢變負數就是破產
                    }//end of else
                }//end of if
            }//end of if canbuy
            
            if(house[people_site].jail){
                x=0;
                cout<<"player is going to jail! Now is at the "<<u<<" round"<<endl;
                atjail=true;
                
            }

            if(house[people_site].steuer){
                cout<<"You have to pay the tax!!!"<<endl;
                if(player[0].money>=100){
                    taxpay(player,0);
                }else{
                    cout<<"You don't have enough money to pay the tax!"<<endl;
                    
                    while(player[0].total>0 && player[0].money<100){
                        sell(house,player,0);
                    }//先賣房子 如果錢超過150 或者是沒房子賣時跳出

                    taxpay(player,0);
                    //不管賣完房子之後可不可以繳錢都扣 當錢變負數就是破產
                }
            }
            
            if(house[people_site].start){
                getmoney(player,0);
                cout<<"You got 150 dollars!"<<endl;
            }

            if(house[people_site].houseNumber==4 && house[people_site].whose!=0){
                if(player[0].money>=house[people_site].price){
                    trade_player(house,player,0,1,people_site,false); //單純繳錢
                }else{
                    cout<<"You don't have enough money to pay the fee!"<<endl;
                    
                    while(player[0].total>0 && player[0].money<150){
                        sell(house,player,0);
                    }//先賣房子 如果錢超過150 或者是沒房子賣時跳出

                    trade_player(house,player,0,1,people_site,false); 
                    //不管賣完房子之後可不可以繳錢都扣 當錢變負數就是破產
                }
            }
            printmap(player,house);
            printplayer(player);
        }//end of if !atjail
        
        if(player[0].money<0){
            peolose=true;
            break; //if people is bankrupt, the game is over
        }//人的做完就先檢查是否破產

        if(pcjail && y!=2){
            y++;
        }

        if(y==2 && pcjail){
            pcjail=false;
            y=0; //歸零等待下次進監獄
        }
        cout<<"\n\n";

        if(!pcjail){
            firstbuy1=false;
            cout<<"--------PC's turn--------"<<endl;
            dice=rand()%6+1; //0-5---1-6
            cout<<"Computer got "<<dice<<" steps"<<endl;
            player[1].site+=dice;
            origin=player[1].site;
            player[1].site=player[1].site%12;
            computer_site=player[1].site%12;
            pay=false;
            printmap(player,house);
            printplayer(player);

            if(computer_site!=0 && origin/12==1){
                cout<<"Computer got 150 dollars!"<<endl;
                getmoney(player,1); 
                printplayer(player);               
            }
            
            //踩到地有四種結果 監獄 開始 繳稅 踩到地
            if(player[1].money>=house[computer_site].price && house[computer_site].whose==-1){
                cout<<"computer case 1"<<endl;
                pay_bank(house,player,1,computer_site,true);
                totalCal(house,player,1);
                firstbuy=true;
            }//有足夠的錢才可以買沒人買的地

            if(player[1].money>=1.5*house[computer_site].price && house[computer_site].whose==0){//收購人的地
                cout<<"computer case 2"<<endl;
                trade_player(house,player,1,0,computer_site,true);
                totalCal(house,player,1);
                totalCal(house,player,0);
            }else if(player[1].money<1.5*house[computer_site].price && house[computer_site].whose==0 
            &&player[1].money>=house[computer_site].price){
                cout<<"computer case 3"<<endl;
                trade_player(house,player,1,0,computer_site,false);
                pay=true;
                
            }//如果沒有要買的話要繳過路費(收購金不夠)

            if(player[1].money<house[computer_site].price && house[computer_site].whose==0&&!pay){
                cout<<"computer case 4"<<endl;
                while(player[1].money<house[computer_site].price && player[1].total>0){
                    //當沒錢付的時候要一直賣直到有錢了或者是沒有錢沒有地可以賣了（小於過路費時重複以及有地可以賣時重複）
                    //反正就算跳出來會扣一次錢如果變負的話就破產了
                    sellpc(house,player,1);
                }
                trade_player(house,player,1,0,computer_site,false);
            }//沒錢付過路費要去賣地
            
            if(house[computer_site].whose==1 &&player[1].money>=100 && !firstbuy1){
                pay_bank(house,player,1,computer_site,false);
            }//如果地已經是自己的話可以加蓋

            if(house[computer_site].jail){//踩到監獄
                y=0;
                pcjail=true;
                cout<<"Computer goes to the jail!!! Now is at "<<u<<" round"<<endl;
            }
            if(house[computer_site].start){
                cout<<"Computer got 150 dollars!!!"<<endl;
                getmoney(player,1);
            }
            if(house[computer_site].steuer){
                cout<<"Computer have to pay the tax!!!"<<endl;
                if(player[1].money>=100){
                    taxpay(player,1);
                }else{
                    cout<<"Computer don't have enough money to pay the tax!!!"<<endl;
                    while(player[1].money<100 && player[1].total>0){
                        sellpc(house,player,1);
                    }
                    taxpay(player,1);
                }
            }
            printmap(player,house);
            printplayer(player); 
        }
        
        if(player[1].money<0){
            pclose=true;
            break; //if people is bankrupt, the game is over
        }//電腦的做完就先檢查是否破產    
        cout<<"\n\n\n\n";
        cout<<"Do you want to break the game?(0---no,1---yes): ";
        cin>>inter;
        cout<<endl;

    }while(!peolose&&!pclose&&inter!=1); //在兩人還沒破產前都一直回圈 或者是不要存擋時
    


    if(peolose){
        cout<<"Computer wins the game!!!"<<endl;
    }
    if(pclose){
        cout<<"People wins the game!!!"<<endl;
    }
    if(inter==1){
        cout<<"Please input the name of file: ";
        cin>>filename;
        ofstream out (filename);

        //存地圖資訊
        for(int i=0;i<12;i++){
            out<<house[i].city<<"\t"<<house[i].houseNumber<<"\t"<<house[i].price<<"\t"<<house[i].jail
            <<"\t"<<house[i].start<<"\t"<<house[i].steuer<<"\t"<<house[i].whose<<"\n";
        }
        for(int i=0;i<2;i++){
            out<<player[i].money<<"\t"<<player[i].name<<"\t"<<player[i].site<<"\t"<<player[i].sign
            <<"\t"<<player[i].total<<"\n";
        }
        out<<atjail<<"\t"<<x<<"\n";
        out<<pcjail<<"\t"<<y<<"\n";
        out<<u<<"\n";

        out.close();
    }
    cout<<"Thank u for playing the game"<<endl;
    return 0;
}