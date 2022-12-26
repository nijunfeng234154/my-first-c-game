#include<bits/stdc++.h>
using namespace std;
enum job{saber, archer, lancer, mage, none};

class Role{ 
   public:
    friend class Gamemanager;
    friend class Shop;
    friend class Team;
   	Role(int hp=5,int Atk=2,int Value=3,enum job type0=none);//构造函数,初始化生命值,攻击力,职业 
   	~Role() = default;	 
    void Attack(Role* r);//攻击函数，与另一个单位交互 
   	void reFill();//回复函数，重置生命值、攻击力等 
   	string getType();//接口返回字符串格式职业 
   	void showRole();//显示单位信息 
   	void isDead();//判断单位是否阵亡 
   	bool death();//单位阵亡状态的接口 
   private: 
    enum job type;//单位职业 
   	int HP,Atk,Value;//单位生命值，攻击力，价值属性 
   	bool Roledeath;//单位阵亡状态 
   	void setHP(int hp);//设置单位生命值 
   	void setAtk(int atk);//设置单位攻击力 
    void setJob(enum job type0);//设置单位职业 
}; 

//类名改为小写
Role::Role(int hp,int atk,int value,enum job type0){
	HP = hp;
	Atk = atk;
	Value = value;
	type = type0;
	Roledeath = 0;
}
void Role::Attack(Role *r){
	//普通攻击 
	cout.setf(std::ios::left);
    int HPtemp1 = r->Atk;
    int HPtemp2 = this->Atk;
    int ATKtemp = this->Atk-r->Atk;
	cout<<"\t"<<this->getType()<<" Attack "<<r->getType()<<"'s HP decreases"<<HPtemp2<<endl;
	cout<<"\t"<<r->getType()<<" Attack "<<this->getType()<<"'s HP decreases"<<HPtemp1<<endl;
	r->HP -= HPtemp2;
	this->HP -= HPtemp1;
	system("pause");
	//特殊攻击 
	r->isDead();
	this->isDead();
   if(this->getType()=="saber"){
	if(r->Roledeath){
	this->setAtk(this->Atk*2);
	cout<<"\t"<<"Player's Saber killed one enemy.Attack doubled."<<endl;
	}
}  
   if(r->getType()=="saber"){
	if(this->Roledeath){
	 r->setAtk(r->Atk*2);
	cout<<"\t"<<"AI's Saber killed one enemy.Attack doubled."<<endl;
	}
}  
    if(this->getType()=="archer"){
   	 r->HP-=2;
   	 cout<<"\t"<<"Archer's arrow hit enemy."<<endl;
   }
   if(this->getType()=="mage"){
   	 if(r->getType()=="saber"){
   	 	r->Roledeath = 1;
     cout<<"\t"<<"Mage killed saber easily."<<endl;
   	 }
   	 
   }
}

string Role::getType()
{   
    string name;
   	switch(type)
	{
	  case saber:
	   name="saber";
	  	 break;
	  case archer:
	  	name="archer";
	  	 break;
	  case mage:
	  	name="mage";
	  	 break;
	  case none:
	  	name="none";
	  	break;
	  	default:
	  	 break;
	}
	return name;
}
void Role::reFill(){
	switch(type)
	{
	  case saber:
	  	setJob(saber);
	   HP=5;
	   Atk=2;
	   break;
	  case archer:
	  	setJob(archer);
	  HP=3;
	  Atk=5;
	  	 break;
	  case mage:
	 	setJob(mage);
	  HP=2;
	  Atk=6;
	  	 break;
	  case none:
	 	setJob(none);
	  	break;
	  	default:
	  	Roledeath=0;
	  	 break;
	}
	 
}
void Role::setHP(int hp){
	HP = hp;
}
void Role::setAtk(int atk){
	Atk = atk;
}
void Role::setJob(enum job type0)
{
	type = type0;
}
void Role::showRole()
{
	switch(type)
	{    
	    cout<<"\v"; 
	  case saber:
	  	 cout<<"Saber:HP5,ATK2";
	  	 break;
	  case archer:
	  	 cout<<"Archer:HP3,ATK5";
	  	 break;
	  case mage:
	  	 cout<<"Mage:HP2,ATK6";
	  	 break;
	  case none:
	  	cout<<"empty.";
	  	default:
	  	 break;
	}
}
void Role::isDead()
{    
	  Roledeath = 0;
	if(HP<=0)	
	{
		this->setJob(none);
		Roledeath=1;	
	}
}
bool Role::death()
{
	return Roledeath;
}

