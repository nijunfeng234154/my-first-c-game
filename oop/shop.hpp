#include"Team.hpp" 
#include<bits/stdc++.h>
using namespace std;
class Shop{
	public: 
		Shop(int coins=7);//初始化开始回合金币 
		~Shop()=default;
		int getCoins()const;//获取金币数的接口 
		void addCoins();//每回合添加金币 
		void setCoins(int coins);//设置金币数 
        void Buy(Team& t,int choice,int pos);//购买单位函数 
        void Sell(Team& t,int pos);//出售单位函数 
    private:
    	int Coins;//金币数 
    	int choice;//选项变量，用于购买出售函数 
};
Shop::Shop(int coins):Coins{coins}{}
void Shop::addCoins(){
	Coins += 3;
}
void Shop::setCoins(int coins){
	Coins = coins;
}
int Shop::getCoins()const{
    return Coins;
}
void Shop::Buy(Team &t,int choice,int pos)
{   
	if(choice==1){
	   Role r1(5,3);
	   r1.setJob(saber);
	   t.addRole(r1,pos);
		Coins-=3;
	}
	else if(choice==2){
		Role r2;
		r2.setJob(archer);
		t.addRole(r2,pos);
		Coins-=3;
	}
	else if(choice==3){
		Role r3;
		r3.setJob(mage);
		t.addRole(r3,pos);
		Coins-=3;
	}
}
void Shop::Sell(Team &t,int pos)
{
      Coins+=1;
      t.deleteRole(pos);
}



