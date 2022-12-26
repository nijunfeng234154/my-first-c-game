#include"team.hpp" 
#include<bits/stdc++.h>
using namespace std;
class shop{
	public: 
		shop(int coins=7);//初始化开始回合金币 
		~shop()=default;
		int getCoins()const;//获取金币数的接口 
		void addCoins();//每回合添加金币 
		void setCoins(int coins);//设置金币数 
        void Buy(team& t,int choice,int pos);//购买单位函数 
        void Sell(team& t,int pos);//出售单位函数 
    private:
    	int Coins;//金币数 
    	int choice;//选项变量，用于购买出售函数 
};
shop::shop(int coins):Coins{coins}{}
void shop::addCoins(){
	Coins += 3;
}
void shop::setCoins(int coins){
	Coins = coins;
}
int shop::getCoins()const{
    return Coins;
}
void shop::Buy(team &t,int choice,int pos)
{   
	if(choice==1){
	   role r1(5,3);
	   r1.setJob(saber);
	   t.addrole(r1,pos);
		Coins-=3;
	}
	else if(choice==2){
		role r2;
		r2.setJob(archer);
		t.addrole(r2,pos);
		Coins-=3;
	}
	else if(choice==3){
		role r3;
		r3.setJob(mage);
		t.addrole(r3,pos);
		Coins-=3;
	}
}
void shop::Sell(team &t,int pos)
{
      Coins+=1;
      t.deleterole(pos);
}
