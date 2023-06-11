/**
  ******************************************************************************
  * @file           : employee.h
  * @author         : 25679
  * @date           : 2023/6/8
  ******************************************************************************
  */



#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include "worker.h"
using namespace std;

class Employee: public Worker
{
public:
	// 构造函数
	Employee(int id, string name, int deptId);

	// 显示个人信息
	void showInfo();

	// 获取职工岗位名称
	string getDeptName();
};

#endif //EMPLOYEE_H
