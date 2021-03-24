#pragma once   //防止头文件重复包含
#include<iostream>  //包含输入输出流头文件
using namespace std;   //使用标准命名空间
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"


class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//退出系统
	void ExitSystem();
	//析构函数
	~WorkerManager();

	//增加成员
	void Add_Emp();

	//显示成员
	void Show_Emp();

	//保存文件
	void save();

	//记录文件中的人数
	int m_EmpNum;

	//员工数组的指针
	Worker ** m_EmpArray;

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的职工人数
	int  get_EmpNum();

	//初始化职工
	void init_Emp();

	//删除职工
	void Del_Emp();
	//判断职工是否存在，若存在，则返回数组位置,反之返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序算法
	void Sort_Emp();

	//清空文件
	void Clean_File();

};