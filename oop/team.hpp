#include"Role.hpp"
#include<bits/stdc++.h>
using namespace std; 
class Team{
	public:
	    friend class Role;//������λ��Ϊ��Ԫ�����ڷ������Ա 
		Team(int n);//���캯������ʼ�������С 
		~Team() = default;
		Team(const Team& t);//���ƹ��캯����ʵ����� 
		void addRole(Role &r,int pos);//��ӵ�λ���� 
		void deleteRole(int pos);//ɾ����λ���� 
		void showInfo();//��ʾ������Ϣ 
		void refreshTeam();//ˢ�¶��飬ÿ��λ���ÿ� 
		Role &at(int index);//�ӿڷ��������еĶ��� 
		void reFill();//�ظ��������ظ���������ĵ�λ����ֵ 
		bool isEmpty();//�ж϶����Ƿ�Ϊ�� 
		Team operator = (const Team& t2);//���صȺ�����������ڶ���ĸ�ֵ 
	private:
		int size; //����Ĵ�С 
		vector<Role> r; //Role��������� 
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

