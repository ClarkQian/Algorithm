

//Create a tree with preOrder list and InOrder list
void PreInOd(char pre[], int i, int j, char in[], int m, int n, Node**t){
	*t = new Node;
	*t -> data = pre[i];
	int k = m;
	while(in[k] != pre[i])
		k++;
	if (k == m)
		*t -> left = NULL;
	else 
		PreInOd(pre, i, i + k -m, in, m, k-1, *t -> left);
	if (k == n)
		*t -> right = NULL;
	else 
		PreInOd(pre, i+k -m + 1, j, in, k + 1, n, *t -> right);

}


void PreInOd(char pre[], char in[], int n, Node* root){
	PreInOd(pre, 0, n - 1, in, 0, n - 1, &root);
}
