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

class Employee;
class Employee: public Worker
{
public:
	// 构造函数
	Employee(int id, std::string name, int deptId);

	// 显示个人信息
	void showInfo();

	// 获取职工岗位名称
	std::string getDeptName();
};

#endif //EMPLOYEE_H
