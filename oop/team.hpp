#include"role.hpp"
#include<bits/stdc++.h>
using namespace std; 
class team{
	public:
	    friend class role;//������λ��Ϊ��Ԫ�����ڷ������Ա 
		team(int n);//���캯������ʼ�������С 
		~team() = default;
		team(const team& t);//���ƹ��캯����ʵ����� 
		void addrole(role &r,int pos);//��ӵ�λ���� 
		void deleterole(int pos);//ɾ����λ���� 
		void showInfo();//��ʾ������Ϣ 
		void refreshteam();//ˢ�¶��飬ÿ��λ���ÿ� 
		role &at(int index);//�ӿڷ��������еĶ��� 
		void refill();//�ظ��������ظ���������ĵ�λ����ֵ 
		bool empty();//�ж϶����Ƿ�Ϊ�� 
		team operator = (const team& t2);//���صȺ�����������ڶ���ĸ�ֵ 
	private:
		int size; //����Ĵ�С 
		vector<role> r; //role��������� 
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

