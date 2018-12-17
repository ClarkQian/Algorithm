#include <iostream>
using namespace std;

void inthreading(Node*now , Node**pre){
	if(now){
		inthreading(now-> left, pre);

		if(now -> left == NULL){
			now -> tag = 1;
			now -> left = *pre;
		}

		// the first line that the pre is NULL so you need to escape this situation
		if (pre != NULL && pre -> right == NULL)
		{
			pre -> tag =1 ;
			pre -> right = now;
		}

		pre = now ;
		inthreading(now -> right, pre);

	}

}



void inthreading(){
	Node* p, *q = NULL;
	p = Head;
	inthreading(p, &q);

}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
