#include"team.hpp" 
#include<bits/stdc++.h>
using namespace std;
class shop{
	public: 
		shop(int coins=7);//��ʼ����ʼ�غϽ�� 
		~shop()=default;
		int getCoins()const;//��ȡ������Ľӿ� 
		void addCoins();//ÿ�غ���ӽ�� 
		void setCoins(int coins);//���ý���� 
        void Buy(team& t,int choice,int pos);//����λ���� 
        void Sell(team& t,int pos);//���۵�λ���� 
    private:
    	int Coins;//����� 
    	int choice;//ѡ����������ڹ�����ۺ��� 
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
