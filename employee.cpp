#include"employee.h"



Employee::Employee(int id,string name,int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息
void Employee::ShowInfo()
{
	cout << "职工编号：  " << this->m_ID
		<< "\t职工姓名：" << this->m_Name
		<<"\t岗位名称："<<this->getDeptName()
		<< "\t职工职责：听从经理的安排" << endl;
}

//获取岗位名称
string Employee::getDeptName()
{
	return string("员工");
}
