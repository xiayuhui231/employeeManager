#include"manager.h"

//���캯��
Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = did;

}
//��ʾ������Ϣ
 void Manager::ShowInfo()
{
	 cout << "ְ����ţ�  " << this->m_ID
		 << "\tְ��������" << this->m_Name
		 << "\t��λ���ƣ�" << this->getDeptName()
		 << "\tְ��ְ������ϰ彻��������,���·������Ա��" << endl;

}
//��ȡ��λ����
 string Manager::getDeptName()
{
	 return string("����");

}