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


class WorkerManager; // 添加前向声明

// 职工抽象基类
class Worker
{
protected:
	int m_Id;        // 职工编号
	std::string m_Name;   // 职工姓名
	int m_DeptId;    // 职工所在部门名称编号

public:
	// 显示个人信息
	virtual void showInfo() = 0;

	// 获取岗位名称
	virtual std::string getDeptName() = 0;

	// 声明 WorkerManager 类为友元
	friend class WorkerManager;

	// 添加虚析构函数
	virtual ~Worker() = default;
};

#endif //WORKER_H
