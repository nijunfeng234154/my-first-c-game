#include<bits/stdc++.h>
using namespace std;
enum job{saber, archer, lancer, mage, none};

class Role{ 
   public:
    friend class Gamemanager;
    friend class Shop;
    friend class Team;
   	Role(int hp=5,int Atk=2,int Value=3,enum job type0=none);//���캯��,��ʼ������ֵ,������,ְҵ 
   	~Role() = default;	 
    void Attack(Role* r);//��������������һ����λ���� 
   	void reFill();//�ظ���������������ֵ���������� 
   	string getType();//�ӿڷ����ַ�����ʽְҵ 
   	void showRole();//��ʾ��λ��Ϣ 
   	void isDead();//�жϵ�λ�Ƿ����� 
   	bool death();//��λ����״̬�Ľӿ� 
   private: 
    enum job type;//��λְҵ 
   	int HP,Atk,Value;//��λ����ֵ������������ֵ���� 
   	bool Roledeath;//��λ����״̬ 
   	void setHP(int hp);//���õ�λ����ֵ 
   	void setAtk(int atk);//���õ�λ������ 
    void setJob(enum job type0);//���õ�λְҵ 
}; 

//������ΪСд
Role::Role(int hp,int atk,int value,enum job type0){
	HP = hp;
	Atk = atk;
	Value = value;
	type = type0;
	Roledeath = 0;
}
void Role::Attack(Role *r){
	//��ͨ���� 
	cout.setf(std::ios::left);
    int HPtemp1 = r->Atk;
    int HPtemp2 = this->Atk;
    int ATKtemp = this->Atk-r->Atk;
	cout<<"\t"<<this->getType()<<" Attack "<<r->getType()<<"'s HP decreases"<<HPtemp2<<endl;
	cout<<"\t"<<r->getType()<<" Attack "<<this->getType()<<"'s HP decreases"<<HPtemp1<<endl;
	r->HP -= HPtemp2;
	this->HP -= HPtemp1;
	system("pause");
	//���⹥�� 
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

