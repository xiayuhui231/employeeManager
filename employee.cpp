#include"employee.h"



Employee::Employee(int id,string name,int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ����ţ�  " << this->m_ID
		<< "\tְ��������" << this->m_Name
		<<"\t��λ���ƣ�"<<this->getDeptName()
		<< "\tְ��ְ�����Ӿ���İ���" << endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}
