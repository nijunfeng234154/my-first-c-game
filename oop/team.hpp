#include"role.hpp"
#include<bits/stdc++.h>
using namespace std; 
class team{
	public:
	    friend class role;//声明单位类为友元，便于访问其成员 
		team(int n);//构造函数，初始化队伍大小 
		~team() = default;
		team(const team& t);//复制构造函数，实现深复制 
		void addrole(role &r,int pos);//添加单位函数 
		void deleterole(int pos);//删除单位函数 
		void showInfo();//显示队伍信息 
		void refreshteam();//刷新队伍，每个位置置空 
		role &at(int index);//接口访问容器中的对象 
		void refill();//回复函数，回复整个队伍的单位生命值 
		bool empty();//判断队伍是否为空 
		team operator = (const team& t2);//重载等号运算符，用于队伍的赋值 
	private:
		int size; //队伍的大小 
		vector<role> r; //role类对象容器 
}; 
team::team(int n):size{n}{   
    r.reserve(n);
	for(int i=0;i<size;i++)
	r[i].setJob(none);
}
team::team(const team& t){
	size = t.size;
	r.reserve(size);
	for(int i=0;i<size;i++)
	r[i]=t.r[i];
}
void team::refreshteam(){
	for(int i=0;i<size;i++)
	r[i].setJob(none);
}

void team::addrole(role &r1,int pos)
{   
    if(r1.gettype()=="saber"){
    	r1.setHP(5);
    	r1.setAtk(2);
    }
    else if(r1.gettype()=="archer"){
    	r1.setHP(3);
    	r1.setAtk(5);
    }
    else if(r1.gettype()=="mage"){
    	r1.setHP(2);
    	r1.setAtk(6);
    }
    r[pos] = r1;
}
void team::deleterole(int pos)
{    
    r[pos].setJob(none);
}
void team::showInfo()
{   
    cout<<setfill('#')<<setw(50)<<"#";
    cout<<endl;
	for(int i=1;i<size;i++){
	cout<<setw(25)<<right<<setfill(' ')<<"role position:"<<i<<":";
	r[i].showRole();
	cout<<endl;
	}
	cout<<setfill('#')<<setw(50)<<"#";
    cout<<endl;
}
void team::refill()
{
	for(int i=1;i<size;i++){
		r[i].reFill();
	}
}
role &team::at(int index)
{   
	return r[index];
}
bool team::empty()
{    
    for(int i=1;i<size;i++)
    if(r[i].gettype()!="none") return false;
	return true;
}
team team::operator=(const team &t2){
	for(int i=1;i<size;i++)
	this->r[i]=t2.r[i];
	return *this;
}

