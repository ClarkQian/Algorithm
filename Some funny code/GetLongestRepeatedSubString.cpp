#include<iostream>
#define MAX 100
using namespace std;
char l[MAX]; //the string needed to be read;
char temp[MAX];
int n1;
char res[MAX];
int n2;


class Discovery{
private:
	int length;
	int* T; //the table of possiblity
	int* index; //different char's index; //be used with length
	int* rev;
public:
	Discovery(){
		length = 0;
		index = new int[MAX];
		rev = new int[MAX];
	}

	//push the position char into the class
	void push(int pos){
		index[length++] = pos;
		rev[pos] = length - 1;
		return;
	}

	//initialize T
	void setT(){
		T = new int[length*length];
		for (int i = 0; i < length*length; i++)
			T[i] = 1;
		return;
	}


	//change the table 1 -> 0
	void pop(int index_a, int index_b){
		T[index_a*length + index_b] = 0;
		return;
	}

	//show index list;
	void showIndex(){
		for (int i = 0; i < length; i++){
			cout << index[i] << endl;
		}
		return;
	}
	//show rev list;
	void showRev(){
		for (int i = 0; i < length; i++){
			cout << rev[i] << endl;
		}
		return;
	}


	int getLength(){
		return length;
	}

	int getRev(int pos){
		return rev[pos];
	}
	//check the character of string to find the longest substring.
	void check(Discovery chr[]){
		for (int i = 0; i < length; i++){
			for (int j = i + 1; j < length; j++){
				if (T[i*length + j]){
					T[i*length + j] = 0;
					//add to temp list
					temp[n1++] = l[index[i]];
					//the number of adder
					int a1 = 1;
					//check whether out of the valid range -> add latter
					while ((l[index[i] + a1] == l[index[j] + a1])){
						char u = l[index[i] + a1];
						int rev1 = chr[u].getRev(index[i] + a1);
						int rev2 = chr[u].getRev(index[j] + a1);
						chr[u].pop(rev1, rev2);
						temp[n1++] = u;
						a1++;
					}

					temp[n1] = '\0';

					if (n1 > n2){
						for (int i = 0; i <= n1; i++){
							res[i] = temp[i];
						}
						n2 = n1;
					}
					//notice that!
					n1 = 0;
				}
			}
		}
		return;
	}
};




int main(){
	//crosstab
	Discovery chr[129];
	cin >> l;
	for (int i = 0; l[i] != '\0'; i++){
		chr[l[i]].push(i);
	}

	for (int i = 0; i < 129; i++){
		chr[i].setT();
	}

	for (int i = 0; i < 129; i++){
		if (chr[i].getLength() >= 2){
			chr[i].check(chr);
		}
	}
	cout << "The string entered by you is:" << l << endl;
	cout <<"The longest repeated substring is:"<< res << endl;
	return 0;
}
