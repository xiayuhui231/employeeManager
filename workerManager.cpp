#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()
{
	
	//1.����ļ������ڣ����ʼ��
	ifstream ifs(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.����ļ����ڣ�������Ϊ��
	
	char ch;
	//��һ���ַ�����Ϊeof��������Ϊ��
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ���������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	//��������
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//���ļ��е����ݴ浽������
	init_Emp();

	//���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_ID
	//		<< "ְ��������" << this->m_EmpArray[i]->m_Name
	//		<< "ְ��ְ��" << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

//ͳ���ļ��е�ְ������
int  WorkerManager::get_EmpNum()
{
	ifstream ifs(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int num = 0;

	//ѭ���ж϶���������
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//ͳ������
		num++;
	}
	return num;
}

//��ʼ��ְ��
void  WorkerManager::init_Emp()
{
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;

	//ѭ���ж϶���������
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i=0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int id = 0;
		cout << "������ɾ����ְ����ţ�" << endl;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;
			//ͬ�����ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		system("pause");
		system("cls");

		
	}
}

////�ж�ְ���Ƿ���ڣ������ڣ��򷵻�����λ��,��֮����-1
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

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "������ְ�����:" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int newdSelect = 0;
			cout << "���ҵ����Ϊ��" << id << "��Ա��" << endl;

			cout << "��������ְ����ţ�" << endl;
			cin >> newId;
			cout << "��������ְ������" << endl;
			cin >> newName;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
				//���µ�������
				this->m_EmpArray[ret] = worker;
				cout << "�޸ĳɹ�" << endl;
				//���浽�ļ���
				this->save();
			
	

		}
		else
		{
			cout << "�޸�ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�Ҳ����ļ����¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ���ҵķ�ʽ:" << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;

		int select;
		cin >> select;
		if (select == 1)
		{
			cout << "�������ְ����ţ�" << endl;
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҵ�����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
		else if(select == 2)
		{
			cout << "�������ְ��������" << endl;
			string newName;
			cin >> newName;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == newName)
				{
					cout << "���ҵ�����Ϣ���£�" << endl;
					flag = true;
					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ��" << endl;
			}

		}
		else
		{
		cout << "�������" << endl;
        }
	}

	system("pause");
	system("cls");

}
//�����㷨
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

		system("pause");
		system("cls");


	}
	else
	{
		cout << "������ѡ������ķ�ʽ:" << endl;
		cout << "1.����������" << endl;
		cout << "2.����������" << endl;
		int select = 0;
		cin >> select;

		////ѡ������
		//for (int i = 0; i < m_EmpNum; i++)
		//{
		//	int minOrMax = i;
		//	for (int j = i + 1; j < m_EmpNum; j++)
		//	{
		//		if (select == 1) //����
		//		{
		//			if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID)
		//			{
		//				minOrMax = j;
		//			}
		//		}
		//		else  //����
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

		//ð������
		for (int i = m_EmpNum-1; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				if (this->m_EmpArray[j - 1]->m_ID > this->m_EmpArray[j]->m_ID)  //����
				{
					Worker * temp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j - 1];
					this->m_EmpArray[j - 1] = temp;
				}
				else if (this->m_EmpArray[j - 1]->m_ID < this->m_EmpArray[j]->m_ID)  //����
				{
					Worker * temp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j - 1];
					this->m_EmpArray[j - 1] = temp;
				}
			}
		}


		cout << "����ɹ���������£�" << endl;
		this->save();
		this->Show_Emp();
	}
}

//����ļ�
void WorkerManager::Clean_File()
{ 
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

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
					//ɾ��ÿ������
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
				//ɾ������
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
			}
			
		}
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);      //�˳�����
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				//ɾ��ÿ������
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ������
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
	}

}

//�����ļ�
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

//����ְ��
void WorkerManager::Add_Emp()
{
	cout << "����ְ������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpeace = new Worker*[newSize];

		//��ԭ���ķ����¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpeace[i] = this->m_EmpArray[i];
			}
		}
		//�����µ�����
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�����" << i + 1 <<"����ְ�����"<< endl;
			cin >> id;
			cout << "�����" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			//�ж������Ƿ���ȷ
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
					cout << "�����������������" << endl;
					/*cin >> dSelect;
					continue;*/
					break;
				}

				newSpeace[this->m_EmpNum + i] = worker;
			
			


		}
		
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//����ָ��ָ��
		this->m_EmpArray = newSpeace;
		//�����µĸ���
		this->m_EmpNum = newSize;
		//�����ļ���Ϊ��
		this->m_FileIsEmpty = false;
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "��ְ��" << endl;
		this->save();
		//break;

	}  
	else
	{
		cout << "�����������������" << endl;
	}

	system("pause");
	system("cls");
}