#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test1()
{
	Worker *worker = NULL;

	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}

int main()
{
	system("chcp 65001");
	WorkerManager wm;

	int choice = 0;

	while (true) {
		// 展示菜单
		wm.showMenu();
		std::cout << "请输入您的选择: " << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 0:    // 退出系统
			wm.exitSystem();
			break;
		case 1:    // 添加职工
			wm.addWorker();
			break;
		case 2:    // 显示职工
			wm.showWorker();
			break;
		case 3:    // 删除职工
			wm.deleteWorker();
			break;
		case 4:    // 修改职工
			wm.modifyWorker();
			break;
		case 5:    // 查找职工
			wm.findWorker();
			break;
		case 6:    // 排序职工
			wm.sortWorker();
			break;
		case 7:    // 清空文件
			break;
		default: system("cls");
			break;
		}
	}

	test1();

	system("pause");

	return 0;
}
