/**
  ******************************************************************************
  * @file           : manager.cpp
  * @author         : 25679
  * @date           : 2023/6/8
  ******************************************************************************
  */



#include "manager.h"

Manager::Manager(int id, std::string name, int deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

string Manager::getDeptName()
{
	string deptName = "经理";
	return deptName;
}

void Manager::showInfo()
{
	cout << "职工编号: " << this->m_Id
		 << "\t职工姓名: " << this->m_Name
		 << "\t职工岗位: " << this->getDeptName()
		 << "\t岗位职责: 完成老板交给的任务，并下发给员工" << endl;
}