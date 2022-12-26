#include<bits/stdc++.h>
using namespace std;
enum job{saber, archer, lancer, mage, none};

class role{ 
   public:
    friend class Gamemanager;
    friend class shop;
    friend class team;
   	role(int hp=5,int Atk=2,int Value=3,enum job type0=none);//���캯��,��ʼ������ֵ,������,ְҵ 
   	~role() = default;	 
    void attack(role* r);//��������������һ����λ���� 
   	void reFill();//�ظ���������������ֵ���������� 
   	string gettype();//�ӿڷ����ַ�����ʽְҵ 
   	void showRole();//��ʾ��λ��Ϣ 
   	void isDead();//�жϵ�λ�Ƿ����� 
   	bool death();//��λ����״̬�Ľӿ� 
   private: 
    enum job type;//��λְҵ 
   	int HP,Atk,Value;//��λ����ֵ������������ֵ���� 
   	bool roledeath;//��λ����״̬ 
   	void setHP(int hp);//���õ�λ����ֵ 
   	void setAtk(int atk);//���õ�λ������ 
    void setJob(enum job type0);//���õ�λְҵ 
}; 

//������ΪСд
role::role(int hp,int atk,int value,enum job type0){
	HP = hp;
	Atk = atk;
	Value = value;
	type = type0;
	roledeath = 0;
}
void role::attack(role *r){
	//��ͨ���� 
	cout.setf(std::ios::left);
    int HPtemp1 = r->Atk;
    int HPtemp2 = this->Atk;
    int ATKtemp = this->Atk-r->Atk;
	cout<<"\t"<<this->gettype()<<" attack "<<r->gettype()<<"'s HP decreases"<<HPtemp2<<endl;
	cout<<"\t"<<r->gettype()<<" attack "<<this->gettype()<<"'s HP decreases"<<HPtemp1<<endl;
	r->HP -= HPtemp2;
	this->HP -= HPtemp1;
	system("pause");
	//���⹥�� 
	r->isDead();
	this->isDead();
   if(this->gettype()=="saber"){
	if(r->roledeath){
	this->setAtk(this->Atk*2);
	cout<<"\t"<<"Player's Saber killed one enemy.Attack doubled."<<endl;
	}
}  
   if(r->gettype()=="saber"){
	if(this->roledeath){
	 r->setAtk(r->Atk*2);
	cout<<"\t"<<"AI's Saber killed one enemy.Attack doubled."<<endl;
	}
}  
    if(this->gettype()=="archer"){
   	 r->HP-=2;
   	 cout<<"\t"<<"Archer's arrow hit enemy."<<endl;
   }
   if(this->gettype()=="mage"){
   	 if(r->gettype()=="saber"){
   	 	r->roledeath = 1;
     cout<<"\t"<<"Mage killed saber easily."<<endl;
   	 }
   	 
   }
}

string role::gettype()
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
void role::reFill(){
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
	  	roledeath=0;
	  	 break;
	}
	 
}
void role::setHP(int hp){
	HP = hp;
}
void role::setAtk(int atk){
	Atk = atk;
}
void role::setJob(enum job type0)
{
	type = type0;
}
void role::showRole()
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
void role::isDead()
{    
	  roledeath = 0;
	if(HP<=0)	
	{
		this->setJob(none);
		roledeath=1;	
	}
}
bool role::death()
{
	return roledeath;
}


