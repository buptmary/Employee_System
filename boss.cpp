/**
  ******************************************************************************
  * @file           : boss.cpp
  * @author         : 25679
  * @date           : 2023/6/8
  ******************************************************************************
  */



#include "boss.h"

Boss::Boss(int id, std::string name, int deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

std::string Boss::getDeptName()
{
	std::string deptName = "老板";
	return deptName;
}

void Boss::showInfo()
{
	std::cout << "职工编号: " << this->m_Id
			  << "\t职工姓名: " << this->m_Name
			  << "\t职工岗位: " << this->getDeptName()
			  << "\t岗位职责: 管理公司所有事务" << std::endl;
}