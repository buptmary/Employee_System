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
	std::cout << "********************************************" << std::endl;
	std::cout << "*********  欢迎使用职工管理系统！ **********" << std::endl;
	std::cout << "*************  0.退出管理程序  *************" << std::endl;
	std::cout << "*************  1.增加职工信息  *************" << std::endl;
	std::cout << "*************  2.显示职工信息  *************" << std::endl;
	std::cout << "*************  3.删除离职职工  *************" << std::endl;
	std::cout << "*************  4.修改职工信息  *************" << std::endl;
	std::cout << "*************  5.查找职工信息  *************" << std::endl;
	std::cout << "*************  6.按照编号排序  *************" << std::endl;
	std::cout << "*************  7.清空所有文档  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
}

void WorkerManager::addWorker()
{
	std::cout << "请输入要增加职工的数量: " << std::endl;
	int addNum = 0;
	std::cin >> addNum;

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
			std::string name;
			int dSelect;

			std::cout << "请输入第 " << i + 1 << " 个新职工编号: " << std::endl;
			std::cin >> id;


			std::cout << "请输入第 " << i + 1 << " 个新职工姓名: " << std::endl;
			std::cin >> name;


			std::cout << "请选择该职工的岗位: " << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;
			std::cin >> dSelect;

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

			newSpace[this->m_WorkNum + i] = worker;
		}

		// 释放原有空间
		delete[] this->m_WorkArray;

		// 更改新空间的指向
		this->m_WorkArray = newSpace;

		// 更新员工人数
		this->m_WorkNum = newSize;

		// 提示信息
		std::cout << "成功添加" << addNum << "名新职工! " << std::endl;

		this->save();
	}
	else {
		std::cout << "输入有误" << std::endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME);

	if (!ofs.is_open()) {
		std::cout << "Failed to open the file for writing." << std::endl;
		return;
	}

	for (int i = 0; i < this->m_WorkNum; i++) {
		ofs << this->m_WorkArray[i]->m_Id << " "
			<< this->m_WorkArray[i]->m_Name << " "
			<< this->m_WorkArray[i]->m_DeptId << std::endl;
	}

	ofs.close();
}

void WorkerManager::exitSystem()
{
	std::cout << "欢迎下次使用!" << std::endl;
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