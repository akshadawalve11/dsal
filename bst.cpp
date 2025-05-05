#include<iostream>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
};
class bst{
    public:
    node*root;
    void create();
    void insert(node*,node*);
    void display(node*);
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void minval(node*);
    void maxval(node*);
    int height(node*);
    void mirror(node*);
    bool search(node*);
    bst(){
        root==NULL;
    }
};
void bst::create(){
    char ch;
    do{
        node*nn=new node;
        cout<<"Enter data of node:";
        cin>>nn->data;
        nn->left=NULL;
        nn->right=NULL;
        if(root==NULL){
            root=nn;
        }else{
            insert(root,nn);
        }
        cout<<"Do you want to add more nodes(y/n):";
        cin>>ch;
    }while(ch=='y');
}
void bst::insert(node*root,node*nn){
    if(nn->data<root->data){
        if(root->left==NULL){
            root->left=nn;
        }else{
            insert(root->left,nn);
        }
    }else{
        if(root->right==NULL){
            root->right=nn;
        }else{
            insert(root->right,nn);
        }
    }
}
void bst::inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void bst::preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void bst:: postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void bst::display(node *root){
    cout<<"Inorder traversal:";
    inorder(root);
    cout<<"Preorder traversal:";
    preorder(root);
    cout<<"Postorder traversal:";
    postorder(root);
}
void bst::minval(node*root){
    node*temp=root;
    while(temp&&temp->left!=NULL){
        temp=temp->left;
    }
    if(temp){
        cout<<"Min value: "<<temp->data<<endl;
    }
}
void bst::maxval(node*root){
    node*temp=root;
    while(temp&&temp->right!=NULL){
        temp=temp->right;
    }
    if(temp){
        cout<<"Max value:"<<temp->data<<endl;
    }
}
int bst::height(node*root){
    if(root==NULL){
        return 0;
    }
    int hl=height(root->left);
    int hr=height(root->right);
    return(hr>hl?hr:hl)+1;
}
bool bst::search(node*root){
    int n;
    cout<<"Enter node to be searched:";
    cin>>n;
    node*temp=root;
    while(temp!=NULL){
        if(n==temp->data){
            return true;
        }else if(n<temp->data){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return false;
}
void bst:: mirror(node*root){
    if(root==NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    node*temp=root->left;
    root->left=root->right;
    root->right=temp;
}
int main(){
    bst b;
    int choice;
    char ans;
    do{
        cout<<"MENU:\n1.Create\n2.Insert\n3.display\n4.Minimum value\n5.Maximum value\n6.Height of tree \n7.Search\n8.Mirror\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
            b.create();
            break;

            case 2:
            b.create();
            break;

            case 3:
            b.display(b.root);
            break;

            case 4:
            b.minval(b.root);
            break;

            case 5:
            b.maxval(b.root);
            break;

            case 6:
            b.height(b.root);
            break;

            case 7:
            b.search(b.root);
            break;

            case 8:
            b.mirror(b.root);
            break;

            default:
            cout<<"Invalid choice!";
        }
        cout<<"Do you want to continue(y/n):";
        cin>>ans;
    }while(ans=='y');
    return 0;
}