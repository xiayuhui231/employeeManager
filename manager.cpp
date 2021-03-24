#include"manager.h"

//构造函数
Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = did;

}
//显示个人信息
 void Manager::ShowInfo()
{
	 cout << "职工编号：  " << this->m_ID
		 << "\t职工姓名：" << this->m_Name
		 << "\t岗位名称：" << this->getDeptName()
		 << "\t职工职责：完成老板交给的任务,并下发任务给员工" << endl;

}
//获取岗位名称
 string Manager::getDeptName()
{
	 return string("经理");

}