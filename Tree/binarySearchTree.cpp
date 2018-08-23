#include<stdio.h>
#include<iostream>
#include<queue>
#include <string.h>
using namespace std;

//pre or in or pos oder traversal
template < typename Key, typename Value>
class BST(){
private:
	struct Node
	{
		Key key;
		Value Value;
		Node *left;
		Node *right;

		Node (Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};
	Node *root;
	int count;
public:
	BST() {
		root = NULL;
		count = 0;
	}
	~BST() {
		destory(root);
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}
	void insert(Key key, Value value) {
		 root = insert(root, key, value);
	}
	//insert without recursion.
	void insert(Key key, Vlaue value) {
		root = insert(root, key, value);
	}
	bool contain(Key key) {
		return contain(root, key);
	}
	Value* search(Key key) {
		return search(root, key);

	}
	void preOder() {
		preOder(root);
		return;
	}

	void postOder(Node *node) {
		posOder(root);	
		return;
	}

	void inOder(Node *node) {
		inOder(root);
		return;
	}

	void levelOder() {
		queue<Node*> q;
		q.push(root);
		while( !q.empty()) {
			Node *node = q.front();
			q.pop();

			cout<<node.key<<endl;
			if (node.left != NULL) {
				q.push(node.left);	
			}
			if (node.right != NULL) {
				q.push(node.right);
			}
		}

	}
	Key minimum() {
		Node* minNode = minimum(root);
		return minNode.key; 
	}

	Key maxmum() {
		Node* maxNode = maxmum(root);
		return maxNode.key;
	}
	void removeMin() {
		if(root != NULL)
			root = removeMin(root);
		return;
	}

	void removeMax() {
		if ( root != NULL) 
			removeMax(root);
		return;
	}
private:
	void destory(Node *node) {

		if (node != NULL) {
			destory (node.left);
			destory (node.right);

			delete node;
			count--;
		}
		return ;
	}
	//another version....
	// void destory(Node *node) {
	// 	if (node == NULL)
	// 		return;
	// 	destory(node.left);
	// 	destory(node.right);

	// 	delete node;
	// 	count--;
	// }
	Node* insert(Node* node, Key key, Value value) {
		if(node == NULL) {
			count++;
			return new Node(key, value);
		}
		//this part is a function unit.
		if (node->key == key)
			node->value = value;
		else if (key < node->key) 
			node->left = insert(node->left, key, value);
		else
			node->right = insert(node->right, key, value);
		return node;
		//this part is a function unit.
	}
	bool contain(Node *node, Key key) {
		if(node == NULL)
			return false;

		if (key == node.key)
			return true;
		else if (key < node.key)
			return contain(node.left, key);
		else
			return contain(node.righ, key);
	}
	Value* search(Node *node, Key key) {
		if (node == NULL)
			return NULL

		if (node.key == key) {
			return &node.value;
		} else if ( key > node.key) {
			return search(node.right, key);
		} else {
			return search(node.left, key);
		}
	}
	void preOder(Node *node) {

		if (node == NULL)
			return;

		cout<<node.key<<endl;
		preOder(node.left);
		preOder(node.right);
		return;
	}

	void inOder(Node *node) {
		//TODO
		if (node == NULL)
			return;

		inOder(node.left);
		cout<<node.key<<endl;
		inOder(node.right);
	}

	void posOder(Node *node) {
		if (node == NULL)
			return;

		cout<<node.key<<endl;
		posOder(node.left);
		posOder(node.right);
	}
	Node* minimum(Node *node) {
		if (node.left == NULL)
			return node;

		return minimum(node.left);
	}

	Node* maxmum(Node *node) {
		if (node.right == NULL)
			return node;
		return maxmum(node.right);
	}

	Node* removeMin(Node *node) {
		if (node.left == NULL) {
			Node* rightNode = node.right;
			delete node;
			return rightNode;
		}

		node.left = removeMin(Node.left);

		return node;

	}
	Node* removeMax(Node *node) {

		if (node.right == NULL) {
			Node* leftNode = node.left;
			delete node;
			return leftNode;
		}

		node.right = removeMax(node.right);
		return node;
	}
};

//end

// This is the practice.
// void levelOder(){
// 	queue<Node*> q;
// 	q.push(root);
// 	while(!q.empty()) {
// 		Node node = q.front();
// 		q.pop();
// 		if(node.left != NULL)
// 			q.push(node.left);
// 		if(node.right != NULL)
// 			q.push(node.right);
// 	}
// 	return;
// }


// Value* search(Node* node, Key key) {
// 	if (node == NULL) return NULL;

// 	if (key == node.key) 
// 		return &node.value;	
// 	else if (key < node.key) 
// 		return search(node.left, key);
// 	else 
// 		return search(node.right, key);
// }