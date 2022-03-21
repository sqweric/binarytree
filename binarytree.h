#pragma once
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * left; //左右子树
    Node * right;
};

class BTree
{
public:
    Node * root;
public:
    BTree();
    ~BTree();
    void showroot(Node * p);  //中序
    void showhead(Node * p);  //先序
    void showtail(Node * p);  //后序
    void create(Node * &p,Node * &temp); //创建二叉树
    void insert(int value,Node * &p,Node * last); //插入元素
    Node * search(int value,Node * &p);//二分查找
    void insertRoot(Node * &p ,Node * &temp); //当做根节点插入
    Node * deleteNode(int value,Node * &p ); //删除一个节点
    int getlength(Node * p); //获取二叉树的节点数
    int getdepth(Node * p ,int depth);//求二叉树的深度
    void destory(Node * &p);  //销毁二叉树
    void menu();
};


