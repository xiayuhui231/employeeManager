#include"boss.h"


//���캯��
Boss:: Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = did;

}
//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ����ţ�  " << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ���ƣ�" << this->getDeptName()
		<< "\tְ��ְ�𣺹���˾��������" << endl;

}
//��ȡ��λ����
string Boss::getDeptName()
{
	return "�ܲ�";
}