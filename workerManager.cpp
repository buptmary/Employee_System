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

	std::ifstream ifs;
	ifs.open(FILENAME);

	// 判断文件是否不存在
	if (!ifs.is_open()) {
		std::cout << "worker_file.txt 文件不存在! " << std::endl;
		this->m_WorkNum = 0;    // 初始化人数
		this->m_FileIsEmpty = true;    // 文件为空

		this->m_WorkArray = nullptr;
		ifs.close();
		return;
	}
	else if (ifs.eof()) {
		std::cout << "worker_file.txt 文件为空! " << std::endl;
		this->m_WorkNum = 0;    // 初始化人数
		this->m_FileIsEmpty = true;    // 文件为空

		this->m_WorkArray = nullptr;
		ifs.close();
		return;
	}
	else {
		this->m_FileIsEmpty = false;
		std::cout << "worker_file.txt 文件存在，开始导入数据! " << std::endl;
		this->m_WorkNum = this->getWorkerNum();
		// 根据职工数量创建数组
		this->m_WorkArray = new Worker *[this->m_WorkNum];

		// 初始化职工列表
		this->initWorker();

		std::cout << "导入成功，共导入" << this->m_WorkNum << "名职工 " << std::endl;
	}
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

			int maxId = this->m_WorkArray[this->m_WorkNum - 1]->m_Id;
			std::cout << "请输入第 " << i + 1 << " 个新职工编号，"
					  << "推荐为 " << maxId + 1 << " : " << std::endl;

			std::cin >> id;
			while (isExist(id) != -1) {
				std::cout << "此id已存在，请重新输入: " << std::endl;
				std::cin >> id;
			}

			std::cout << "id: " << id << " 不存在，可以使用! " << std::endl;
			std::cout << "请输入第 " << i + 1 << " 个新职工姓名: " << std::endl;
			std::cin >> name;


			std::cout << "请选择该职工的岗位: " << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;

			std::cin >> dSelect;
			while (dSelect != 1 && dSelect != 2 && dSelect != 3) {
				std::cout << "岗位编号错误，请重新输入: " << std::endl;
				std::cin >> dSelect;
			}

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

		// 更新文件为空标志
		this->m_FileIsEmpty = false;

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

void WorkerManager::showWorker()
{
	if (this->m_WorkNum == 0) {
		std::cout << "系统里还没有职工，请添加! " << std::endl;
	}
	else {
		std::cout << "职工人数为: " << this->m_WorkNum << std::endl;
		for (int i = 0; i < this->m_WorkNum; i++) {
			this->m_WorkArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_WorkNum; ++i) {
		if (this->m_WorkArray[i]->m_Id == id) {
			std::cout << "id: " << id << " 存在! " << std::endl;
//			this->m_WorkArray[i]->showInfo();
			index = i;
			return index;
		}
	}
//	std::cout << "id: " << id << " 不存在! " << std::endl;
	return -1;
}

void WorkerManager::deleteWorker()
{
	if (this->m_FileIsEmpty) {
		std::cout << "文件不存在或记录为空！" << std::endl;
	}
	else {
		// 按职工编号删除
		std::cout << "请输入要删除的职工的编号: " << std::endl;
		int id = -1;
		std::cin >> id;

		int index = isExist(id);
		if (index == -1) {
			std::cout << "该职工不存在! " << std::endl;
		}
		else {
			this->m_WorkArray[index]->showInfo();
			std::cout << "确认要删除该职工? (Y / N)" << std::endl;
			char key = 'N';
			std::cin >> key;

			if (key == 'Y' || key == 'y') {
				delete this->m_WorkArray[index];
				for (int i = index; i < this->m_WorkNum - 1; i++) {
					this->m_WorkArray[i] = this->m_WorkArray[i + 1];
				}
				this->m_WorkNum -= 1;
				std::cout << "删除成功! " << std::endl;
				this->save();    // 删除数据后同步到文件中
			}
			else {
				return;
			}

		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::modifyWorker()
{
	if (this->m_FileIsEmpty) {
		std::cout << "文件不存在或记录为空！" << std::endl;
	}
	else {
		std::cout << "请输入职工编号: " << std::endl;
		int id = -1;
		std::cin >> id;

		int index = isExist(id);
		if (index == -1) {
			std::cout << "该职工不存在! " << std::endl;
		}
		else {
			// 查找到该编号职工
			this->m_WorkArray[index]->showInfo();
			delete this->m_WorkArray[index];

			int newId = -1;
			std::string newName = "";
			int newDeptId = 0;
			std::cout << "查找到: " << id << " 号职工，请输入新职工号: " << std::endl;
			std::cin >> newId;
			while (isExist(newId) != -1) {
				std::cout << "此id已存在，请重新输入: " << std::endl;
				std::cin >> newId;
			}

			std::cout << "请输入新姓名： " << std::endl;
			std::cin >> newName;

			std::cout << "请选择该职工的岗位: " << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;

			std::cin >> newDeptId;
			while (newDeptId != 1 && newDeptId != 2 && newDeptId != 3) {
				std::cout << "岗位编号错误，请重新输入: " << std::endl;
				std::cin >> newDeptId;
			}

			Worker *worker = nullptr;
			switch (newDeptId) {
			case 1:    // 普通职工
				worker = new Employee(id, newName, 1);
				break;
			case 2:    // 经理
				worker = new Manager(id, newName, 2);
				break;
			case 3:      // 老板
				worker = new Boss(id, newName, 3);
				break;
			default: break;
			}

			// 更改数据到数组中
			this->m_WorkArray[index] = worker;

			std::cout << "修改成功! " << std::endl;
			this->m_WorkArray[index]->showInfo();

			// 保存到文件
			this->save();
		}
	}

	// 按任意键清屏
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

void WorkerManager::findWorker()
{
	if (this->m_FileIsEmpty) {
		std::cout << "文件不存在或记录为空！" << std::endl;
	}
	else {
		std::cout << "请输入查找方式: " << std::endl;
		std::cout << "1、按职工编号查找" << std::endl;
		std::cout << "2、按职工姓名查找" << std::endl;

		int select = 0;

		std::cin >> select;

		if (select == 1) {
			int id;

			std::cout << "请输入要查询的ID: " << std::endl;
			std::cin >> id;

			int index = isExist(id);

			if (index == -1) {
				std::cout << "此ID不存在! " << std::endl;
			}
			else {
				this->m_WorkArray[index]->showInfo();
			}
		}
		else if (select == 2) {
			std::string name;
			bool isExist = false;

			std::cout << "请输入要查询的姓名: " << std::endl;
			std::cin >> name;

			for (int i = 0; i < this->m_WorkNum; i++) {
				if (this->m_WorkArray[i]->m_Name == name) {

					isExist = true;
					std::cout << "查询成功!该职工信息如下: " << std::endl;
					this->m_WorkArray[i]->showInfo();
				}
			}
			if (!isExist) {
				// 查无此人
				std::cout << "查找失败，没有名叫 " << name << " 的职工" << std::endl;
			}

		}
		else {
			std::cout << "没有该选项! " << std::endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::bubbleSortA()
{
	if (this->m_FileIsEmpty) {
		std::cout << "文件不存在或记录为空！" << std::endl;
	}
	else {
		Worker *temp_worker = nullptr;
		bool is_sorted = true;
		for (int i = 0; i < this->m_WorkNum - 1; i++) {
			is_sorted = true;

			for (int j = 0; j < this->m_WorkNum - i - 1; j++) {
				if (this->m_WorkArray[j]->m_Id > this->m_WorkArray[j + 1]->m_Id) {
					is_sorted = false;
					temp_worker = this->m_WorkArray[j];
					this->m_WorkArray[j] = this->m_WorkArray[j + 1];
					this->m_WorkArray[j + 1] = temp_worker;
				}
			}

			if (is_sorted) break;
		}
		std::cout << "排序成功! " << std::endl;
	}
}

void WorkerManager::bubbleSortD()
{
	if (this->m_FileIsEmpty) {
		std::cout << "文件不存在或记录为空！" << std::endl;
	}
	else {
		Worker *temp_worker = nullptr;
		bool is_sorted = true;
		for (int i = 0; i < this->m_WorkNum - 1; i++) {
			is_sorted = true;

			for (int j = 0; j < this->m_WorkNum - i - 1; j++) {
				if (this->m_WorkArray[j]->m_Id < this->m_WorkArray[j + 1]->m_Id) {
					is_sorted = false;
					temp_worker = this->m_WorkArray[j];
					this->m_WorkArray[j] = this->m_WorkArray[j + 1];
					this->m_WorkArray[j + 1] = temp_worker;
				}
			}

			if (is_sorted) break;
		}
		std::cout << "排序成功! " << std::endl;
	}
}

void WorkerManager::sortWorker()
{
	if (this->m_FileIsEmpty) {
		std::cout << "文件不存在或记录为空！" << std::endl;
	}
	else {
		std::cout << "请选择排序方式: " << std::endl;
		std::cout << "1、按ID升序排列" << std::endl;
		std::cout << "2、按ID降序排列" << std::endl;

		int select = 0;
		std::cin >> select;

		if (select == 1) {
			this->bubbleSortA();    // 根据ID升序排列
		}
		else if (select == 2) {
			this->bubbleSortD();    // // 根据ID降序排列
		}
		else {
			std::cout << "没有该选项! " << std::endl;
		}

		std::cout << "排序结果为: " << std::endl;
		this->save();
		this->showWorker();

		system("cls");
	}
}

int WorkerManager::getWorkerNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME);
	int id;
	std::string name;
	int deptId;

	int num = 0;

	// 逻辑不够严谨
	while (ifs >> id && ifs >> name && ifs >> deptId) {
		num++;
	}

	ifs.close();
	return num;
}

int WorkerManager::getMaxId()
{
	int maxId = -1;
	if (this->m_FileIsEmpty) {
		std::cout << "文件不存在或记录为空！" << std::endl;
	}
	else {
		for (int i = 0; i < this->m_WorkNum; i++) {
			if (this->m_WorkArray[i]->m_Id > maxId) {
				maxId = this->m_WorkArray[i]->m_Id;
			}
		}
	}
	return maxId;
}

void WorkerManager::initWorker()
{
	std::ifstream ifs;
	ifs.open(FILENAME);
	int id;
	std::string name;
	int deptId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptId) {
		Worker *worker = nullptr;

		// 根据不同部门Id创建不同对象
		if (deptId == 1)    // 1普通员工
		{
			worker = new Employee(id, name, 1);
		}
		else if (deptId == 2)    // 2经理
		{
			worker = new Manager(id, name, 2);
		}
		else if (deptId == 3)    // 3老板
		{
			worker = new Boss(id, name, 3);
		}
		else {
			std::cout << "部门编号错误，添加失败! " << std::endl;
			break;
		}

		this->m_WorkArray[index] = worker;
		index++;
	}


	ifs.close();
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