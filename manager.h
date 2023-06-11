/**
  ******************************************************************************
  * @file           : manager.h
  * @author         : 25679
  * @date           : 2023/6/8
  ******************************************************************************
  */


#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "worker.h"
using namespace std;

class Manager: public Worker
{
public:
	// 构造函数
	Manager(int id, string name, int deptId);

	// 显示个人信息
	void showInfo();

	// 获取职工岗位信息
	string getDeptName();

};


#endif //MANAGER_H
