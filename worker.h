/**
  ******************************************************************************
  * @file           : worker.h
  * @author         : 25679
  * @date           : 2023/6/8
  ******************************************************************************
  */



#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include "workerManager.h"

using namespace std;


// 职工抽象基类
class Worker
{
	friend void WorkerManager::save();

public:
	int m_Id;        // 职工编号
	string m_Name;   // 职工姓名
	int m_DeptId;    // 职工所在部门名称编号


public:
	// 显示个人信息
	virtual void showInfo() = 0;

	// 获取岗位名称
	virtual string getDeptName() = 0;

};

#endif //WORKER_H
