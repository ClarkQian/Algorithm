

//pretraverse without recursion

void PreTraverse(){
	Node* stack[MAX];
	Node* p = Head;
	int top = -1;
	while (p!= NULL || top != -1){
		if (p != NULL){
			cout<< p -> data;
			top++;
			stack[top] = p;
			p = p -> left;
		}

		if (top != -1){
			p = stack[top--];
			p = p -> right;
		}
	}
}


void inTraverse(){
	Node* stack[MAX];
	Node* p = Head;
	int top = -1;
	while (p != NULL || top != -1){
		if (p != NULL){
			stack[++top] = p;
			p = p -> left;
		}

		if (top != -1){
			p = stack[top--];
			cout<<p -> data;
			p = p -> right;
		}
	}
}


Node{
	node* link;
	int flag;
}
//two in and two out!
void postTraverse(){
	Node * stack[MAX];
	Node* p = Head;
	int top = -1;
	while( p != NULL || top != -1 ){
		if ( p != NULL){
			stack[++top] -> link = p;
			Stack[top].flag = 1;
			p = p -> left;
		}

		if ( top != -1){
			p = stack[top--];
			int flag2 = p -> flag;
			if(flag2 == 1){
				stack[++top] = p;
				p -> flag = 2;
				p = p -> right;
			} else {
				cout<<p -> link -> data;
				//!!!!!!
				p = NULL;
			}
		}
	}

}
