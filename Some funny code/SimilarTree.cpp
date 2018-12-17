#include <iostream>
using namespace std;
int judgement = 1;

template <class T>
struct Node
{
	char data;
	Node<T>* left = NULL;
	Node<T>* right = NULL;
};

template <class T>
class BinaryTree
{
private:
	Node<T>* __Create(T endflag);
	void __prePrintTree(Node<T>* p);
	void compare(Node<T>* p1, Node<T>* p2);
public:
	Node<T>* Head;
	BinaryTree(T endflag){

		Create(endflag);
	}
	void prePrintTree();
	void Create(T endflag);
	void Like(BinaryTree& b);
	
};




//below is the recursion part of the function -> Create
//Maybe we can make them in a function, but this will be more clear;
template <class T>
Node<T>* BinaryTree<T>:: __Create(T endflag){
	Node<T>* s;
	//cin from user.
	T ain;
	cin>>ain;

	if(ain == endflag){
		s = NULL;
	} else {
		s = new Node<T>;
		s -> data = ain;
		s -> left = __Create(endflag);
		s -> right = __Create(endflag);
	}
	return s;
}
template <class T>
void BinaryTree<T>:: __prePrintTree(Node<T>* p){
	if (!p){
		return;
	}
	cout << p -> data << ' ';
	__prePrintTree(p -> left);
	__prePrintTree(p -> right);
	return;
}

template <class T>
void BinaryTree<T>::compare(Node<T>* p1, Node<T>* p2){
	if((!p1&&p2)||(p1&&!p2)){
		judgement = 0;
		return;
	}
	if(!p1 && !p2)
		return;

	compare(p1 -> left, p2 -> left);
	compare(p1 -> right, p2 -> right);

	return;
}

template <class T>
void BinaryTree<T>:: Create(T endflag){
	T ain;
	cin>>ain;
	if (ain == endflag ){
		Head = NULL;
		return;
	}
	Head = new Node<T>;
	Head -> data = ain;

	Head -> left = __Create(endflag);
	Head -> right = __Create(endflag); 
	return;
}

template <class T>
void BinaryTree<T>:: prePrintTree(){
	Node<T>* p;
	p = Head;
	__prePrintTree(p);
	cout<<endl;
	return;
}

template <class T>
void BinaryTree<T>:: Like(BinaryTree<T>& b){

	compare(this -> Head, b.Head);
	return;
}



int main(int argc, char const *argv[])
{
	BinaryTree<char> aTree('#');
	BinaryTree<char> bTree('#');
	aTree.Like(bTree);
	if(judgement){
		cout<<"The two trees are similar!"<<endl;
	} else {
		cout<<"The two trees are not similar!"<<endl;
	}
	return 0;
}
