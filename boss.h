/**
  ******************************************************************************
  * @file           : boss.h
  * @author         : 25679
  * @date           : 2023/6/8
  ******************************************************************************
  */



#ifndef BOSS_H
#define BOSS_H
#include <iostream>
#include "worker.h"
using namespace std;

class Boss: public Worker
{
public:
	Boss(int id,string name,int deptId);

	// 获取职工岗位信息
	string getDeptName();

	// 显示个人信息
	void showInfo();
};

#endif //BOSS_H
