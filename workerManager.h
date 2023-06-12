//
// Created by 25679 on 2023/6/8.
//

#ifndef EMPLOYEE_SYSTEM__WORKERMANAGER_H
#define EMPLOYEE_SYSTEM__WORKERMANAGER_H

#include <iostream>
#include <fstream>

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "../worker_file.txt"

class WorkerManager
{
public:
	// 记录文件中的人数个数
	int m_WorkNum;

	// 员工数组的指针
	Worker **m_WorkArray;

public:
	// 构造函数
	WorkerManager();

	// 展示菜单
	void showMenu();

	// 增加职工
	void addWorker();

	// 保存职工信息
	void save();

	// 退出程序
	void exitSystem();

	// 析构函数
	~WorkerManager();
};

#endif //EMPLOYEE_SYSTEM__WORKERMANAGER_H
