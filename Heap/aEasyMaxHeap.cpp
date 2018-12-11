#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include <typeinfo>
using namespace std;

class MaxHeap{
private:
	int *data;
	int count;
	int capacity;

	void shiftUp(int index){
		while (data[index/2] < data[index] && index > 1){
			swap(data[index], data[index/2]);
			index /= 2;
		}
		return;
	}

	void shiftDown(int index){
		while(2*index <= count){
			int i = 2*index;
			if(i+1 <= count && data[i] < data[i+1])
				i = i+1;
			//correct code here!
			if(data[index] > data[i])
				break;
			swap(data[i],data[index]);
			index = i;
		}
		return;
	}

public:
	MaxHeap(int capacity){
		data = new int[capacity];
		count = 0;
		this -> capacity = capacity;
	}

	~MaxHeap(){
		delete[] data;	
	}

	int size(){
		return count;
	}

	int isEmpty(){
		return !count;
	}

	void insert(int e){
		assert( count + 1 < capacity);
		data[count+1] = e;
		count++;
		shiftUp(count);
	}
	int extractMax(){
		int res = data[1];
		swap(data[1],data[count]);
		shiftDown(1);
		count--;
		return res;

	}

	int getMax(){
		return data[1];
	}

	public:
    // below is used to print the tree
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }


        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

};



int main(){

	MaxHeap maxheap(100);
	srand(time(NULL));
	for(int i = 0; i < 50; i++){
		maxheap.insert(rand()%100);
	}
	for(int i = 0; i < 3; i++){
		maxheap.extractMax();
	}
	maxheap.testPrint();

	return 0;
}
