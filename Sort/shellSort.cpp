template<typename T>
void shellSort(T arr[], int n){

    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int h = 1;
    while( h < n/3 )
        h = 3 * h + 1;

    while( h >= 1 ){

        // h-sort the array
        for( int i = h ; i < n ; i ++ ){

            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;

            //!!!!here is  j= i !!!!!!!!
            //h is the interval???
            // j - h >= 0;
            //when h = 1, it is the same as the insertion sort.
            for( j = i ; j >= h && e < arr[j-h] ; j -= h )
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        //about above thing. when the i is near to h the child loop is only swap at most 1 time
        //but when the size is long enough... i is much bigger than h. 
        //at that time the child loop will have  arr[i],arr[i - h], arr[i - 2*h].....
        
        //one more thing; h is initialized as 1 so 3*h + 1 will not be so big.
        //for instance, the size of arrary is 27, the h is 13.
        //so when the i=26; we will compare arr[26],arr[13],arr[0].
        //if the list is long, I think maybe it will work more efficiently
        h /= 3;
    }
}
