#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[20];
    char number[15];
    int age;
    char tel[20];
    char addr[20];
};
struct Node
{
    struct student data;
    struct Node* next;
};

struct Node *createList();
struct Node *createNode(struct student data);
void insertNodeByHead(struct Node *listHeadNode, struct student data);
void printList(struct Node *listHeadNode);
void deleteNodeByAppoinName(struct Node *listHeadNode, char *name);
struct Node *searchNodeByAppoinNum(struct Node *listHeadNode, char *num);
void printNode(struct Node *currenNode);
void readInfoFromFile(char *fileName, struct Node *listHeadNode);
void saveInfoToFile(char *fileName, struct Node *listHeadNode);
