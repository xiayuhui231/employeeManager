#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main() {
	//ʵ�����������
	WorkerManager wm;
	int chioce = 0;  //�����û��Ĳ���ָ��


	//���Դ���
	
	
		/*Worker *worker = NULL;
		worker = new Boss(1, "����", 1);
		worker->ShowInfo();
*/
	

	while (true)
	{
		//����չʾ�˵���Ա����
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> chioce;
		switch (chioce)
		{
		case 0: //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: //���ְ��
			wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			wm.Show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: //����ְ��
			wm.Sort_Emp();
			break;
		case 7: //����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}