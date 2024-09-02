#include"Role.hpp"
#include<bits/stdc++.h>
using namespace std; 
class Team{
	public:
	    friend class Role;//声明单位类为友元，便于访问其成员 
		Team(int n);//构造函数，初始化队伍大小 
		~Team() = default;
		Team(const Team& t);//复制构造函数，实现深复制 
		void addRole(Role &r,int pos);//添加单位函数 
		void deleteRole(int pos);//删除单位函数 
		void showInfo();//显示队伍信息 
		void refreshTeam();//刷新队伍，每个位置置空 
		Role &at(int index);//接口访问容器中的对象 
		void reFill();//回复函数，回复整个队伍的单位生命值 
		bool isEmpty();//判断队伍是否为空 
		Team operator = (const Team& t2);//重载等号运算符，用于队伍的赋值 
	private:
		int size; //队伍的大小 
		vector<Role> r; //Role类对象容器 
}; 
Team::Team(int n):size{n}{   
    r.reserve(n);
	for(int i=0;i<size;i++)
	r[i].setJob(none);
}
Team::Team(const Team& t){
	size = t.size;
	r.reserve(size);
	for(int i=0;i<size;i++)
	r[i]=t.r[i];
}
void Team::refreshTeam(){
	for(int i=0;i<size;i++)
	r[i].setJob(none);
}

void Team::addRole(Role &r1,int pos)
{   
    if(r1.getType()=="saber"){
    	r1.setHP(5);
    	r1.setAtk(2);
    }
    else if(r1.getType()=="archer"){
    	r1.setHP(3);
    	r1.setAtk(5);
    }
    else if(r1.getType()=="mage"){
    	r1.setHP(2);
    	r1.setAtk(6);
    }
    r[pos] = r1;
}
void Team::deleteRole(int pos)
{    
    r[pos].setJob(none);
}
void Team::showInfo()
{   
    cout<<setfill('#')<<setw(50)<<"#";
    cout<<endl;
	for(int i=1;i<size;i++){
	cout<<setw(25)<<right<<setfill(' ')<<"Role position:"<<i<<":";
	r[i].showRole();
	cout<<endl;
	}
	cout<<setfill('#')<<setw(50)<<"#";
    cout<<endl;
}
void Team::reFill()
{
	for(int i=1;i<size;i++){
		r[i].reFill();
	}
}
Role &Team::at(int index)
{   
	return r[index];
}
bool Team::isEmpty()
{    
    for(int i=1;i<size;i++)
    if(r[i].getType()!="none") return false;
	return true;
}
Team Team::operator=(const Team &t2){
	for(int i=1;i<size;i++)
	this->r[i]=t2.r[i];
	return *this;
}

