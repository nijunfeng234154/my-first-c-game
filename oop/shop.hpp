#include"Team.hpp" 
#include<bits/stdc++.h>
using namespace std;
class Shop{
	public: 
		Shop(int coins=7);//��ʼ����ʼ�غϽ�� 
		~Shop()=default;
		int getCoins()const;//��ȡ������Ľӿ� 
		void addCoins();//ÿ�غ���ӽ�� 
		void setCoins(int coins);//���ý���� 
        void Buy(Team& t,int choice,int pos);//����λ���� 
        void Sell(Team& t,int pos);//���۵�λ���� 
    private:
    	int Coins;//����� 
    	int choice;//ѡ����������ڹ�����ۺ��� 
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



