//
// Created by 25679 on 2023/6/8.
//

#include "workerManager.h"
WorkerManager::WorkerManager()
{
	// 初始化人数
	this->m_WorkNum = 0;

	// 初始化数组指针
	this->m_WorkArray = nullptr;
}

void WorkerManager::showMenu()
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

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_WorkNum; i++) {
		ofs << this->m_WorkArray[i]->m_Id << " "
			<< this->m_WorkArray[i]->m_Name << " "
			<< this->m_WorkArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

void WorkerManager::addWorker()
{
	cout << "请输入要增加职工的数量: " << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		// 计算新空间大小
		int newSize = this->m_WorkNum + addNum;

		// 开辟新空间
		Worker **newSpace = new Worker *[newSize];

		// 将原空间下内容存放到新空间下
		if (this->m_WorkArray != nullptr) {
			for (int i = 0; i < this->m_WorkNum; i++) {
				newSpace[i] = m_WorkArray[i];
			}
		}

		// 输入新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号: " << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名: " << endl;
			cin >> name;


			cout << "请选择该职工的岗位: " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker *worker = nullptr;
			switch (dSelect) {
			case 1:    // 普通职工
				worker = new Employee(id, name, 1);
				break;
			case 2:    // 经理
				worker = new Manager(id, name, 2);
				break;
			case 3:      // 老板
				worker = new Boss(id, name, 3);
				break;
			default: break;
			}

			newSpace[this->m_WorkNum + 1] = worker;
		}

		// 释放原有空间
		delete[] this->m_WorkArray;

		// 更改新空间的指向
		this->m_WorkArray = newSpace;

		// 更新员工人数
		this->m_WorkNum = newSize;

		// 提示信息
		cout << "成功添加" << addNum << "名新职工! " << endl;

		this->save();
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}


void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager()
{
	if (this->m_WorkArray != nullptr) {
		delete[] this->m_WorkArray;
		this->m_WorkArray = nullptr;
	}

}