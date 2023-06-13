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

	// worker_file.txt 文件是否为空标志
	bool m_FileIsEmpty;

public:
	// 构造函数
	WorkerManager();

	// 展示菜单
	void showMenu();

	// 增加职工
	void addWorker();

	// 显示职工
	void showWorker();

	// 删除职工
	void deleteWorker();

	// 修改职工信息
	void modifyWorker();

	// 判断职工是否存在
	int isExist(int id);

	// 查找职工
	void findWorker();

	// 统计人数
	int getWorkerNum();

	// 找到最大ID
	int getMaxId();

	// 初始化职工
	void initWorker();

	// 保存职工信息
	void save();

	// 职工排序
	void sortWorker();
	void bubbleSortA();        // 冒泡升序
	void bubbleSortD();        // 冒泡降序

	// 退出程序
	void exitSystem();

	// 析构函数
	~WorkerManager();
};

#endif //EMPLOYEE_SYSTEM__WORKERMANAGER_H
