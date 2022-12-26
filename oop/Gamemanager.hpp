#include"shop.hpp"
#include<bits/stdc++.h>
using namespace std;  
class Gamemanager{
	public:
	    Gamemanager(int size=6,int coins=10);//构造函数，初始化队伍大小 
	    ~Gamemanager() = default;
	    void start();  //开始界面函数  
	    void maingame();    //游戏主体函数 
	private:
	    bool Judgegamerule(team &t1,team &t2,int &k); //判断游戏胜利以及AI自动购买操作 
	    void shopping(shop& shop,team& t);  //商店阶段函数 
	    void battle(int i,int j);  //战斗阶段函数 
		bool settlement(); //回合结算函数 
		int command;  //指示变量 
		bool end;  //游戏结束变量 
		int win,lose,nowin,again; //赢和输和平局的次数 
		team Playerteam,AIteam,tempteam1,tempteam2; //玩家队伍和AI队伍对象 
		shop shop1; //商店对象 
		role r1; //单位对象 
};
Gamemanager::Gamemanager(int size,int coins):Playerteam(size),AIteam(size),tempteam1(size),tempteam2(size),shop1(coins){
     command = 0;
     end = 0;
     win = 0;
     lose = 0;
     nowin = 0;
     again = 0;
     role r1(5,2,3,saber);
    AIteam.addrole(r1,1);
    AIteam.addrole(r1,2);
    AIteam.addrole(r1,3); 
}
void Gamemanager::start(){
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
	else start();
	 }
	}
	maingame();
}

bool Gamemanager::Judgegamerule(team& tempteam1,team& tempteam2,int &k){
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
		Playerteam.refreshteam();
		AIteam.addrole(r1,1);
        AIteam.addrole(r1,2);
      	AIteam.addrole(r1,3);
      	k=3;
      	system("cls");
	 	cout<<"\t"<<"Another game begins! Your life:"<<4<<endl;
	 	shop1.setCoins(10);
	 }
	 if(win+lose+nowin==0){
	 	Playerteam.showInfo();
	}
	 else if(win+lose+nowin!=0&&end!=1){
	 Playerteam = tempteam1;
	 AIteam = tempteam2;
	 AIteam.addrole(r1,k);	 
	 k++;
	 Playerteam.refill();
	 AIteam.refill();
	    system("cls");
	 	cout<<"\t"<<"Another round begins! Your life:"<<4-lose<<endl;
	 	Playerteam.showInfo();
     	shop1.addCoins();
	//	 k++;
	 }
	 if(cycle==1) return true;
	 return false;
}
void Gamemanager::shopping(shop& shop1,team& Playerteam){
	int command,pos,choice;
	do{
	cout.setf(std::ios::left);
	 	cin.sync();
	    cout<<"\t"<<"You are in shop now.your coins:"<<shop1.getCoins()<<endl;
	 	cout<<"Please give command:1.Buy 2.Sell 3.Goods 4.Battle!"<<endl;
	 	cin>>command;
	 	if(command==1){
		 if(shop1.getCoins()<3){//bug
    	cout<<"No enough coins."<<endl;
    	continue;
      }
	 	cout<<"Please choose roles to buy:1.saber 2.archer 3.mage"<<endl;		 
	 	cout<<"Give your choice(1-3) and position in the team(1-5):"<<endl;
	 	cin.sync();
	 	cin>>choice>>pos;	 
	 	if(choice<1||choice>3||pos<1||pos>5){
	 	cout<<"Input error."<<endl;
	 	continue;
		 }
	 	shop1.Buy(Playerteam,choice,pos);
	 	Playerteam.showInfo();
	 }
	   if(command==2){
	   	if(Playerteam.empty()) cout<<"You have no role yet."<<endl;
	   	else{
	   		cout<<"Input the position you want to sell:";
	   	    cin.sync();
	   		cin>>pos;
	   		if(Playerteam.at(pos).gettype()=="none"){
	   			cout<<"\t"<<"No role in this position."<<endl;
	   			continue;
	   		}
	   		shop1.Sell(Playerteam,pos);
	   		Playerteam.showInfo(); 
	   }
     }
       if(command==4&&Playerteam.empty()){
       	cout<<"You can't battle with no role in your team."<<endl;
       	command=0;
       	continue;
       }
	   }while(command!=4);
}
void Gamemanager::battle(int i,int j){
	    cout.setf(std::ios::left);
	    role *r1 = &Playerteam.at(i);
	    role *r2 = &AIteam.at(j);
	    while(r1->gettype()=="none") r1 = &Playerteam.at(++i);
	    while(r2->gettype()=="none") r2 = &AIteam.at(++j);
	   	if(Playerteam.at(i).gettype()!="none"&&AIteam.at(j).gettype()!="none"){ 
	   	cout<<"player team position:"<<i<<" AI team position:"<<j<<" prepare to fight."<<endl; 
	    system("pause");
	    string playerrolejob = r1->gettype();
	    string AIrolejob  = r2->gettype();
		r1->attack(r2);
	 	r1->isDead();
	    r2->isDead();		
	    if(r1->death()){
		cout<<"\t"<<"Player team position:"<<i<<" "<<playerrolejob<<" is dead."<<endl;
		r1 = &Playerteam.at(++i);
		while(r1->gettype()=="none") r1 = &Playerteam.at(++i);
		} 
	   else{
		cout<<"\t"<<"Player team position:"<<i<<" "<<r1->gettype()<<" is alive."<<endl;
    	}
	   if(r2->death()){
	   cout<<"\t"<<"AI team position:"<<j<<" "<<AIrolejob<<" is dead."<<endl;
	   r2 = &AIteam.at(++j);
	   while(r2->gettype()=="none") r2 = &AIteam.at(++j);
	   }   
	   else{
		cout<<"\t"<<"AI team position:"<<j<<" "<<r2->gettype()<<" is alive."<<endl;
	   }
	   }
}
bool Gamemanager::settlement(){
	   if(Playerteam.empty()&&AIteam.empty()){
	    	cout<<"\t"<<"No one wins the round."<<endl;
	    	system("pause");
	    	nowin++;
	    	return true;
	    }
	    else if(Playerteam.empty()&&!AIteam.empty()){
	    	cout<<"\t"<<"You team has been defeated."<<endl;
	    	cout<<"\t"<<"You lose the round."<<endl;
	    	system("pause");
	    	lose++;
	    	return true;
	    }
	    else if(!Playerteam.empty()&&AIteam.empty()){
	    	cout<<"\t"<<"AI's team has been defeated."<<endl;
	    	cout<<"\t"<<"You win the round!"<<endl;
	    	system("pause");
	    	win++;
	    	return true;
	    }
	    return false;
}
void Gamemanager::maingame()
{    
      int k=4;
     while(end!=1){
	  if(Judgegamerule(tempteam1,tempteam2,k)) 
	  continue;
	  else{	  	 
	  shopping(shop1,Playerteam);
	  tempteam1 = Playerteam;
	  tempteam2 = AIteam;
	    //战斗阶段 
		cout<<setw(25)<<right<<setfill(' ')<<"battle begins!"<<endl;
		system("cls");
		cout<<setw(25)<<right<<setfill(' ')<<"Player team"<<endl;
		Playerteam.showInfo();
		cout<<setw(25)<<right<<setfill(' ')<<"AI team"<<endl;
	 	AIteam.showInfo();
	  int i=0,j=0;
	 while(end!=1)
	 {  
	   battle(i,j);
	   //结算阶段 
	   if(settlement()) break;
	  }
	    }
	         }
}
