#include <iostream>
#include "binarytree.h"
using namespace std;


int main(){
    int choice;
    BTree tree;
    while(1){
        tree.menu();
        int value = 0;
        cin>>choice;
        switch (choice){
            case 0:
                return 0;
            case 1:{
                cout<<"enter the root's value"<<endl;
                tree.root = new Node;
                cin>>tree.root->data;
                while(1){
                    cout<<"enter the value or -999 to exit"<<endl;
                    cin>>value;
                    if(value == -999){
                        break;
                    }
                    Node * p =new Node;
                    //
                    p->data = value;
                    p->left = nullptr;
                    p->right = nullptr;
                    tree.create(p,tree.root);
                }
                cout<<"the binary tree has been created"<<endl;
                break;
            }
            case 2:{
                cout<<endl;
                tree.showroot(tree.root);
                break;
            }
            case 3:{
                cout<<endl;
                tree.showhead(tree.root);
                break;
            }
            case 4:{
                cout<<endl;
                tree.showtail(tree.root);
                break;
            }
            case 5:{
                Node * p =tree.root;
                cout<<"the tree's length is "<<tree.getlength(p)<<endl;
                break;
            }
            case 6:{
                Node * p = tree.root;
                cout<<"enter the value"<<endl;
                cin>>value;

                tree.insert(value,p,p);
                break;
            }
            case 7:{
                Node * p =new Node;
                cout<<"enter the value and insert as root"<<endl;
                cin>>p->data;
                tree.insertRoot(p,tree.root);
                break;
            }
            case 8:{
                cout<<"enter the value to find"<<endl;
                cin>>value;
                Node * address = tree.search(value,tree.root);
                cout<<"address is "<<address<<endl;
                break;
            }
            case 9:{
                cout<<"enter the value to delete"<<endl;
                cin>>value;
                tree.deleteNode(value,tree.root);
                break;

            }
            case 10:{
                Node * p = tree.root;
                int depth = 0;
                cout<<"the tree's depth is "<<tree.getdepth(p,depth);
                break;
            }
            case 11:{
                tree.destory(tree.root);
                break;
            }
            default:
                break;
        }
    }
}
