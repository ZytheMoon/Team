#include<iostream>
using namespace std;
template<class T>
struct TreeNode {
	T data;
	TreeNode<T>*left, *right;
	TreeNode() :left(NULL), right(NULL) {}
	TreeNode(T x) :data(x),left(NULL),right(NULL){}
};
template<class T>
class Tree {
public:
	Tree(){}
	void preorder(TreeNode<T> *b);//ǰ������ݹ��㷨
	void inorder(TreeNode<T>*b);//��������ݹ��㷨
	void postorder(TreeNode<T>*b);//��������ݹ��㷨
    TreeNode<T> * createTree(TreeNode<T>*&b);//����һ��������
	
};
template<class T>
TreeNode<T>*Tree<T>::createTree(TreeNode<T>*&b) {
	T Data;
	cin >> Data;
	if (Data == 0)
		return NULL;
	else {
		
			b = new TreeNode<T>(Data);
			if (b == NULL) { cerr << "�洢�������\n"; }
			createTree(b->left);
			createTree(b->right);
			return ( b);
		
	}
}
template<class T>
void Tree<T>::preorder(TreeNode<T> *b) {
	if(b!=NULL){
		cout << b->data<<' ';
		preorder(b->left);
		preorder(b->right);
	}
}
template<class T>
void Tree<T>::inorder(TreeNode<T>*b) {
	if (b != NULL) {
		inorder(b->left);
		cout << b->data<<' ';
		inorder(b->right);
	}
}
template<class T>
void Tree<T>::postorder(TreeNode<T>*b) {
	if (b != NULL) {
		postorder(b->left);
		postorder(b->right);
		cout << b->data<<' ';
	}
};
int main(){
	TreeNode<int> *p=new TreeNode<int>;
	Tree<int>*q=new Tree<int>;
	cout << "�밴��ǰ��ķ�ʽ����������Ľڵ�Ԫ��" << endl;
	 q->createTree(p);
	cout << "ǰ�����" << endl;
	q->preorder(p);
	cout << "\n�������" << endl;
	 q->inorder(p);
	 cout << "\n�������" << endl;
	 q->postorder(p);
	 system("pause");





	

}