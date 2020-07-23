#include "feature.h"
#include "data_st.h"
void systemMenu(void)
{
	//几个菜单通常情况下就是几个函数
	//菜单--功能
	//隐藏功能：同步文件
	printf("----------------------[学生管理系统]-----------------------\n");
	printf("\t\t\t0.[退出系统]\n");
	printf("\t\t\t1.[插入信息]\n");
	printf("\t\t\t2.[浏览信息]\n");
	printf("\t\t\t3.[删除信息]\n");
	printf("\t\t\t4.[修改信息]\n");
	printf("\t\t\t5.[查找信息]\n");
	// printf("\t\t6.保存到文件"); 默认所有操作都是保存到文件中
	printf("-----------------------------------------------------------\n");
	printf("请输入相关功能序号(0-5):");
	/* 需要给出交互的提示 */
}
void keyDown(struct Node *list)
/* 用户输入交互 */
{
	int userKey;
	struct student tempData;
	struct Node *currenNode;
	scanf("%d", &userKey);
	currenNode = searchNodeByAppoinNum(list, tempData.number);
	switch (userKey)
	{
	case 0:
		printf("\t\t\t0.[退出系统]\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("\t\t\t1.[插入信息]\n");
		printf("请输入姓名，学号，年龄，电话，住址：");
		scanf("%s%s%d%s%s", tempData.name, tempData.number, &tempData.age, tempData.tel, tempData.addr);
		insertNodeByHead(list, tempData);
		saveInfoToFile("student.txt", list);
		break;
	case 2:
		printf("\t\t\t2.[浏览信息]\n");
		printList(list);
		break;
	case 3:
		printf("\t\t\t3.[删除信息]\n");
		printf("请输入要删除的学生姓名：");
		scanf("%s", tempData.name);
		deleteNodeByAppoinName(list, tempData.name);
		saveInfoToFile("student.txt", list);
		break;
	case 4:
		printf("\t\t\t4.[修改信息]\n");
		printf("请输入需要修改的学生的学号：");
		scanf("%s", tempData.number);
		if (currenNode == NULL)
		{
			printf("未找到相关信息！");
		}
		else
		{
			printf("请输入新的学生信息:\n");
			printf("请输入姓名，学号，年龄，电话，住址：");
			scanf("%s%s%d%s%s", currenNode->data.name, currenNode->data.number, &currenNode->data.age, currenNode->data.tel, currenNode->data.addr);
			saveInfoToFile("student.txt", list);
		}
		break;
	case 5:
		printf("\t\t\t5.[查找信息]\n");
		printf("请输入查找的学号：");
		scanf("%s", tempData.number);
		if (searchNodeByAppoinNum(list, tempData.number) == NULL)
		{
			printf("未找到相关信息！");
		}
		else
		{
			printNode(searchNodeByAppoinNum(list, tempData.number));
		}
		break;
	default:
		printf("\t\t\t[输入错误，请重新输入！]\n");
		break;
	}
}
