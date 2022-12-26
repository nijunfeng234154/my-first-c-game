#include"Shop.hpp"
#include<bits/stdc++.h>
using namespace std;  
class Gamemanager{
	public:
	    Gamemanager(int size=6,int coins=10);//构造函数，初始化队伍大小 
	    ~Gamemanager() = default;
	    void Start();  //开始界面函数  
	    void Maingame();    //游戏主体函数 
	private:
	    bool judgeEnd(Team &t1,Team &t2,int &k); //判断游戏胜利以及AI自动购买操作 
	    void Shopping(Shop& Shop,Team& t);  //商店阶段函数 
	    void Battle(int i,int j);  //战斗阶段函数 
		bool Settlement(); //回合结算函数 
		int command;  //指示变量 
		bool end;  //游戏结束变量 
		int win,lose,nowin,again; //一回合赢和输和平局的次数 
		Team playerteam,AIteam,tempteam1,tempteam2; //玩家队伍和AI队伍对象 
		Shop shop1; //商店对象 
		Role r1; //单位对象 
};
Gamemanager::Gamemanager(int size,int coins):playerteam(size),AIteam(size),tempteam1(size),tempteam2(size),shop1(coins){
     command = 0;
     end = 0;
     win = 0;
     lose = 0;
     nowin = 0;
     again = 0;
     Role r1(5,2,3,saber);
    AIteam.addRole(r1,1);
    AIteam.addRole(r1,2);
    AIteam.addRole(r1,3); 
}
void Gamemanager::Start(){
	cout<<setfill('#')<<setw(50)<<"#";
    cout<<endl;
    cout<<"\t"<<"Welcome!Please choose."<<endl;
    cout<<"\t"<<"1.start game"<<endl;
    cout<<"\t"<<"2.exit game"<<endl;
    cout<<"\t"<<"3.game rule"<<endl;
    cout<<setfill('#')<<setw(50)<<"#";
    cout<<endl;
	while(cin>>command){	
	if(command==1){
	cout<<"\t"<<"Game start!";
	system("cls");
	break;
	}
	if(command==2) exit(1);
	if(command==3){
	ifstream in("rule.txt");
	if(!in.is_open()){
		cout<<"open file failed."<<endl;
		exit(1);
	}
	string temp;
	while(getline(in,temp)){
		cout<<temp<<endl;
	}
	cout<<endl;
	in.close();
	system("pause");
	cout<<"exit? 1.yes 2.no"<<endl;
	cin>>command;
	if(command==1) exit(1);
	else Start();
	 }
	}
	Maingame();
}

bool Gamemanager::judgeEnd(Team& tempteam1,Team& tempteam2,int &k){
	 int cycle=0;
	 cout.setf(std::ios::left);	
	 if(lose==4){	   
	   	cout<<"\t"<<"You lose the game.Please choose:1.exit 2.play again"<<endl;
		   cin>>command;
		   if(command==1){
		   		end=1;
		   		cycle=1;
		   } 
		   	else{
		   		again=1;
		   		lose=0;
		   		end=0;
		   		cycle=1;
		   		
		   	}
	   }
	   if(win==4){
	   	cout<<"\t"<<"You win the game!Please choose:1.exit 2.play again"<<endl;
	   	  cin>>command;
	   	  if(command==1){
	   	  	end=1;
	   	  	cycle=1;
	   	  }
		  	else{
		  		again=1;
		  		end=0;
		  		win=0;
		  	//	continue;
		  	cycle=1;
		  	}
	   }
     if(again==1){
	 	 win=0;
		 lose=0;
		 nowin=0;
		 again=0;
		playerteam.refreshTeam();
		Role r1(5,2,3,saber); 
		AIteam.addRole(r1,1);
        AIteam.addRole(r1,2);
      	AIteam.addRole(r1,3);
      	k=3;
      	system("cls");
	 	cout<<"\t"<<"Another game begins! Your life:"<<4<<endl;
	 	shop1.setCoins(10);
	 }
	 if(win+lose+nowin==0){
	 	playerteam.showInfo();
	}
	 else if(win+lose+nowin!=0&&end!=1){
	 playerteam = tempteam1;
	 AIteam = tempteam2;
	 AIteam.addRole(r1,k);	 
	 k++;
	 playerteam.reFill();
	 AIteam.reFill();
	    system("cls");
	 	cout<<"\t"<<"Another round begins! Your life:"<<4-lose<<endl;
	 	playerteam.showInfo();
     	shop1.addCoins();
	//	 k++;
	 }
	 if(cycle==1) return true;
	 return false;
}
void Gamemanager::Shopping(Shop& shop1,Team& playerteam){
	int command,pos,choice;
	do{
	cout.setf(std::ios::left);
	 	cin.sync();
	    cout<<"\t"<<"You are in Shop now.your coins:"<<shop1.getCoins()<<endl;
	 	cout<<"Please give command:1.Buy 2.Sell 3.Goods 4.Battle!"<<endl;
	 	cin>>command;
	 	if(command==1){
		 if(shop1.getCoins()<3){//bug
    	cout<<"No enough coins."<<endl;
    	continue;
      }
	 	cout<<"Please choose Roles to buy:1.saber 2.archer 3.mage"<<endl;		 
	 	cout<<"Give your choice(1-3) and position in the Team(1-5):"<<endl;
	 	cin.sync();
	 	cin>>choice>>pos;	 
	 	if(choice<1||choice>3||pos<1||pos>5){
	 	cout<<"Input error."<<endl;
	 	continue;
		 }
	 	shop1.Buy(playerteam,choice,pos);
	 	playerteam.showInfo();
	 }
	   if(command==2){
	   	if(playerteam.isEmpty()) cout<<"You have no Role yet."<<endl;
	   	else{
	   		cout<<"Input the position you want to sell:";
	   	    cin.sync();
	   		cin>>pos;
	   		if(playerteam.at(pos).getType()=="none"){
	   			cout<<"\t"<<"No Role in this position."<<endl;
	   			continue;
	   		}
	   		shop1.Sell(playerteam,pos);
	   		playerteam.showInfo(); 
	   }
     }
       if(command==4&&playerteam.isEmpty()){
       	cout<<"You can't Battle with no Role in your Team."<<endl;
       	command=0;
       	continue;
       }
	   }while(command!=4);
}
void Gamemanager::Battle(int i,int j){
	    cout.setf(std::ios::left);
	    Role *r1 = &playerteam.at(i);
	    Role *r2 = &AIteam.at(j);
	    while(r1->getType()=="none") r1 = &playerteam.at(++i);
	    while(r2->getType()=="none") r2 = &AIteam.at(++j);
	   	if(playerteam.at(i).getType()!="none"&&AIteam.at(j).getType()!="none"){ 
	   	cout<<"player Team position:"<<i<<" AI Team position:"<<j<<" prepare to fight."<<endl; 
	    system("pause");
	    string playerRolejob = r1->getType();
	    string AIRolejob  = r2->getType();
		r1->Attack(r2);
	 	r1->isDead();
	    r2->isDead();		
	    if(r1->death()){
		cout<<"\t"<<"Player Team position:"<<i<<" "<<playerRolejob<<" is dead."<<endl;
		r1 = &playerteam.at(++i);
		while(r1->getType()=="none") r1 = &playerteam.at(++i);
		} 
	   else{
		cout<<"\t"<<"Player Team position:"<<i<<" "<<r1->getType()<<" is alive."<<endl;
    	}
	   if(r2->death()){
	   cout<<"\t"<<"AI Team position:"<<j<<" "<<AIRolejob<<" is dead."<<endl;
	   r2 = &AIteam.at(++j);
	   while(r2->getType()=="none") r2 = &AIteam.at(++j);
	   }   
	   else{
		cout<<"\t"<<"AI Team position:"<<j<<" "<<r2->getType()<<" is alive."<<endl;
	   }
	   }
}
bool Gamemanager::Settlement(){
	   if(playerteam.isEmpty()&&AIteam.isEmpty()){
	    	cout<<"\t"<<"No one wins the round."<<endl;
	    	system("pause");
	    	nowin++;
	    	return true;
	    }
	    else if(playerteam.isEmpty()&&!AIteam.isEmpty()){
	    	cout<<"\t"<<"You Team has been defeated."<<endl;
	    	cout<<"\t"<<"You lose the round."<<endl;
	    	system("pause");
	    	lose++;
	    	return true;
	    }
	    else if(!playerteam.isEmpty()&&AIteam.isEmpty()){
	    	cout<<"\t"<<"AI's Team has been defeated."<<endl;
	    	cout<<"\t"<<"You win the round!"<<endl;
	    	system("pause");
	    	win++;
	    	return true;
	    }
	    return false;
}
void Gamemanager::Maingame()
{    
      int k=4;
     while(end!=1){
	  if(judgeEnd(tempteam1,tempteam2,k)) {
	  continue;
  } 
	  else{	  	 
	  Shopping(shop1,playerteam);
	  tempteam1 = playerteam;
	  tempteam2 = AIteam;
	    //战斗阶段 
		cout<<setw(25)<<right<<setfill(' ')<<"Battle begins!"<<endl;
		system("cls");
		cout<<setw(25)<<right<<setfill(' ')<<"Player Team"<<endl;
		playerteam.showInfo();
		cout<<setw(25)<<right<<setfill(' ')<<"AI Team"<<endl;
	 	AIteam.showInfo();
	  int i=0,j=0;
	 while(end!=1)
	 {  
	   Battle(i,j);
	   //结算阶段 
	   if(Settlement()) break;
	 }
	     }
	      }
}

