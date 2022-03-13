#include "binarytree.h"

BTree::BTree(){
    root = nullptr;
}

BTree::~BTree(){
    Node * p = root;
    destory(p);
}


//创建二叉树 递归
void BTree::create(Node * &p,Node * &temp) {
    //保证二叉树满足 左子树小于根节点，右子树大于根节点
    //p是新的节点，temp是从root开始遍历的节点
    if (temp == nullptr) {
        temp = p;
    } else {
        //根节点有值了，判断大小
        if (temp->data == p->data) {
            cout << "the same value is not allowed" << endl;
        } else if (p->data < temp->data) { //新节点比根节点小，就去左边递归
            create(p, temp->left);
        } else {
            create(p, temp->right);//p->data > root->data //反之去右边递归{
        }
    }
}

//中序遍历
void BTree::showroot(Node * p){
    if(p!=nullptr){
        showroot(p->left);
        cout<<p->data<<endl;
        showroot(p->right);
    }
}

//先序遍历
void BTree::showhead(Node *p){
    if(p!=nullptr){
        cout<<p->data<<endl;
        showhead(p->left);
        showhead(p->right);

    }
}

//后序遍历
void BTree::showtail(Node *p){
    if(p!=nullptr){

        showhead(p->left);
        showhead(p->right);
        cout<<p->data<<endl;
    }
}

void BTree::insert(int value,Node * &p,Node * last){
    if(p == nullptr&&p==root){ //如果根节点为空，表示这是一个空链表，需要new根节点了
        root = new Node;
        root->data = value;
        return;
    }
    if(p!=nullptr) { //当前位置无法提供插入
        cout<<"当前的值为"<<p->data<<endl;
        if(p->data > value){ //当前节点比要插入的值大 往左边寻找空节点
            insert(value,p->left,p);
        }
        else if(p->data < value){ //反之去右边寻找
            insert(value,p->right,p);
        }
        else{ //重复的元素暂不支持
            cout<<"the same value is not be allowed"<<endl;
            return ;
        }
    }
    else if(p==nullptr){
        p = new Node;
        p->data = value;
        if(p->data>last->data){
            last->right = p;//左边比右边小
        }
        else{
            last ->left = p;
        }
        return ;
    }
}

Node * BTree::search(int value, Node * &p){
    if(p == nullptr){
        cout<<"value not found"<<endl;
        return nullptr;
    }
    else if(p->data == value){
        cout<<"value has been found "<<endl;
        cout<< p<<endl;
        return p;
    }
    else if(p->data<value){
        return search(value,p->right);
    }
    else{
        return search(value,p->left);
    }
}

void BTree::insertRoot(Node *&p, Node *&temp){
    //p是新的节点，temp是之前的head
    if(temp == nullptr){
        root = p; //空树
    }
    else{
        if(search(p->data,temp))
        {
            cout<<"the same value is not allowed"<<endl;
            return;
        }
        if(p->data == temp->data){
            cout<<"the same value is not allowed"<<endl;
        }
        else if(p->data>temp->data){//新的根节点比之前的大
            p->left = temp;
            root = p;
        }
        else{ //新的根节点比之前的小，那么右子树就是原先的根节点了
            p->right = temp;
            root = p;
        }
    }

}

int BTree::getlength(Node *p){
    if(p == nullptr){
        return 0;
    }
    else{
        return getlength(p->left)+1+getlength(p->right);
    }
}

int BTree::getdepth(Node *p,int depth){
    if(p==nullptr){
        return depth;
    }
    return max(getdepth(p->left,depth+1),getdepth(p->right,depth+1));
}

Node * BTree::deleteNode(int value, Node * &p){
    if(p == nullptr)
    {
        cout<<"data not found"<<endl;
        return p;//空节点不能删除
    }
    else if (value < p->data){
        p->left = deleteNode(value,p->left); //删除后的值改对应链接
    }
    else if(value > p->data)
    {
        p->right = deleteNode(value,p->right);
    }
    else //查找到元素 value == p->data
    {
        cout<<"found"<<endl;
        if(p->left == nullptr && p->right == nullptr) //删除的节点是叶子
        {
            delete p;
            p = nullptr;
        }
        else if (root->data == value) //当为根节点时候
        {
            //也可以不让删除
            Node * tempR = root->right; //为了遍历出右子树的最大值
            Node * tempL = root->left;
            Node * temp = root->right;  //记录当前的右节点的指针
            if(tempR == nullptr && tempL != nullptr ){
                root  = tempL;
            }
            else if (tempR != nullptr && tempL == nullptr){
                root  = temp;
            }
            else {  //都有数据
                while(tempR->left != nullptr)  //找到右子树最大的值
                {
                    tempR = tempR->left;
                }
                tempR->left = tempL; //让右子树最大值的的左节点拼接最初的左节点
                root = temp;
            }
            return root;
        }
        else if(p->left == nullptr && p->right != nullptr) {//当节点左空 右有 时
            Node * temp = p->right; //把右边节点记录下来
            delete p;
            return  temp; //返回上个节点的指向
        }
        else if(p->right == nullptr && p->left != nullptr) {//当节点右空 左有 时
            Node *temp = p->left;
            delete p;
            return temp; //返回上个节点的指向
        }
        else {  //当两边都有节点时
            Node * tempR = p->right; //为了遍历出右子树的最大值
            Node * tempL = p->left;
            Node * temp = p->right;  //记录当前的右节点的指针
            delete p;
            while(tempR->left != nullptr){  //找到右子树最大的值
                tempR = tempR->left;
            }
            tempR->left = tempL; //让右子树最大值的的右节点拼接最初的左节点
            return temp;
        }

    }
    return p;
}

void BTree::destory(Node * &p){
    if(p != nullptr){
        destory(p->left);
        destory(p->right);
        delete p;
        p = nullptr;
    }
}