#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
	
	//1.如果文件不存在，则初始化
	ifstream ifs(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.如果文件存在，但数据为空
	
	char ch;
	//读一个字符，若为eof，则数据为空
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，且有数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	//更新人数
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//将文件中的数据存到数组中
	init_Emp();

	//测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_ID
	//		<< "职工姓名：" << this->m_EmpArray[i]->m_Name
	//		<< "职工职责：" << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

//统计文件中的职工人数
int  WorkerManager::get_EmpNum()
{
	ifstream ifs(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int num = 0;

	//循环判断读到的人数
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数
		num++;
	}
	return num;
}

//初始化职工
void  WorkerManager::init_Emp()
{
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;

	//循环判断读到的人数
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker *worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if(did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if(did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i=0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入删除的职工编号：" << endl;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;
			//同步到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
		system("pause");
		system("cls");

		
	}
}

////判断职工是否存在，若存在，则返回数组位置,反之返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}

	}
	return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入职工编号:" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int newdSelect = 0;
			cout << "查找到编号为：" << id << "的员工" << endl;

			cout << "请输入新职工编号：" << endl;
			cin >> newId;
			cout << "请输入新职工姓名" << endl;
			cin >> newName;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newdSelect;

			
				Worker * worker = NULL;
				switch (newdSelect)
				{
				case 1: worker = new Employee(newId, newName, newdSelect);
					break;
				case 2: worker = new Manager(newId, newName, newdSelect);
					break;
				case 3: worker = new Boss(newId, newName, newdSelect);
					break;
				default:
					
					break;
					
				}
				//更新到数组中
				this->m_EmpArray[ret] = worker;
				cout << "修改成功" << endl;
				//保存到文件中
				this->save();
			
	

		}
		else
		{
			cout << "修改失败" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "找不到文件或记录为空！" << endl;
	}
	else
	{
		cout << "请输入要查找的方式:" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;

		int select;
		cin >> select;
		if (select == 1)
		{
			cout << "输入查找职工编号：" << endl;
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找到的信息如下：" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "查找失败" << endl;
			}
		}
		else if(select == 2)
		{
			cout << "输入查找职工姓名：" << endl;
			string newName;
			cin >> newName;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == newName)
				{
					cout << "查找到的信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败" << endl;
			}

		}
		else
		{
		cout << "输入错误" << endl;
        }
	}

	system("pause");
	system("cls");

}
//排序算法
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;

		system("pause");
		system("cls");


	}
	else
	{
		cout << "请输入选择排序的方式:" << endl;
		cout << "1.按升序排列" << endl;
		cout << "2.按降序排列" << endl;
		int select = 0;
		cin >> select;

		////选择排序
		//for (int i = 0; i < m_EmpNum; i++)
		//{
		//	int minOrMax = i;
		//	for (int j = i + 1; j < m_EmpNum; j++)
		//	{
		//		if (select == 1) //升序
		//		{
		//			if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID)
		//			{
		//				minOrMax = j;
		//			}
		//		}
		//		else  //降序
		//		{
		//			if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID)
		//			{
		//				minOrMax = j;
		//			}
		//		}
		//	}

		//	if (i != minOrMax)
		//	{
		//		Worker * temp = m_EmpArray[i];
		//		m_EmpArray[i] = m_EmpArray[minOrMax];
		//		m_EmpArray[minOrMax] = temp;
		//	}

		//}

		//冒泡排序
		for (int i = m_EmpNum-1; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				if (this->m_EmpArray[j - 1]->m_ID > this->m_EmpArray[j]->m_ID)  //升序
				{
					Worker * temp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j - 1];
					this->m_EmpArray[j - 1] = temp;
				}
				else if (this->m_EmpArray[j - 1]->m_ID < this->m_EmpArray[j]->m_ID)  //降序
				{
					Worker * temp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j - 1];
					this->m_EmpArray[j - 1] = temp;
				}
			}
		}


		cout << "排序成功，结果如下：" << endl;
		this->save();
		this->Show_Emp();
	}
}

//清空文件
void WorkerManager::Clean_File()
{ 
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					//删除每个对象
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
				//删除数组
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
			}
			
		}
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);      //退出程序
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				//删除每个对象
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除数组
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
	}

}

//保存文件
void WorkerManager::save()
{
	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID<<" "
			<< this->m_EmpArray[i]->m_Name<<" "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//增加职工
void WorkerManager::Add_Emp()
{
	cout << "增加职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpeace = new Worker*[newSize];

		//将原来的放入新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpeace[i] = this->m_EmpArray[i];
			}
		}
		//输入新的数组
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "输入第" << i + 1 <<"个新职工编号"<< endl;
			cin >> id;
			cout << "输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			//判断输入是否正确
			Worker * worker = NULL;
			
				switch (dSelect)
				{
				case 1:   worker = new Employee(id, name, 1);
					break;
				case 2:   worker = new Manager(id, name, 2);
					break;
				case 3:   worker = new Boss(id, name, 3);
					break;
				default:
					cout << "输入错误，请重新输入" << endl;
					/*cin >> dSelect;
					continue;*/
					break;
				}

				newSpeace[this->m_EmpNum + i] = worker;
			
			


		}
		
		//释放原有空间
		delete[] this->m_EmpArray;
		//更新指针指向
		this->m_EmpArray = newSpeace;
		//更新新的个数
		this->m_EmpNum = newSize;
		//更新文件不为空
		this->m_FileIsEmpty = false;
		//提示信息
		cout << "成功添加" << addNum << "名职工" << endl;
		this->save();
		//break;

	}  
	else
	{
		cout << "输入错误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}