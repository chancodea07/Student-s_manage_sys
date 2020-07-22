#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//写数据结构
//死方法
//1.抽象单一个体 切分
//2.描述最初状态：初始化变量
//3.插入、修改、删除
//4.打印遍历（查找）
struct Node
{
    int data;
    struct Node *next;
};
/*
    - 明确链表的含义：结构体变量和结构体变量连接在一起
    - 指针变成变量的常用方式：动态内存申请
    - 用第一个节点（头节点）表示整个链表
 */
struct Node *createList()
{
    //有表头的链表：头节点不存储数据
    //无标头的链表：头节点存储数据
    //产生一个结构体变量 -> 初始化一个变量
    struct Node *listHeadNode = (struct Node *)malloc(sizeof(struct Node));
    listHeadNode->next = NULL;
    return listHeadNode;
}
//创建一个新的节点
struct Node *createNode(int data)
{
    //产生一个结构体变量 -> 初始化一个变量
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//插入节点并指定插入位置和值
void insertNodeByHead(struct Node *listHeadNode, int data)
{
    struct Node *newNode =createNode(data);
    newNode->next = listHeadNode->next;
    listHeadNode->next = newNode;
}
//打印链表
void printList(struct Node *listHeadNode)
{
    struct Node *pMove = listHeadNode->next;
    while (pMove != NULL)
    {
        printf("%d ", pMove->data);
        pMove = pMove->next;
    }
    printf("\n");
}
