/**
  ******************************************************************************
  * @file           : employee.cpp
  * @author         : 25679
  * @date           : 2023/6/8
  ******************************************************************************
  */


#include "employee.h"

Employee::Employee(int id, std::string name, int deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

void Employee::showInfo()
{
	std::cout << "职工编号: " << this->m_Id
			  << "\t职工姓名: " << this->m_Name
			  << "\t职工岗位: " << this->getDeptName()
			  << "\t岗位职责: 完成经理交给的任务" << std::endl;
}

std::string Employee::getDeptName()
{
	std::string deptName = "员工";
	return deptName;
}

