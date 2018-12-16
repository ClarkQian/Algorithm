//This is a code to extract biggest 100 elements.

//Biggest elements -> minHeap
//Smallest elements -> maxHeap

//Reason:
//To maxHeap, only I know is the biggest element, so when I need add a new element, if I want to get the biggest 100 elements
//I do not know whether this element is in the rank 100. However, I use minHeap


const int N = 1000;
const int K = 100;

void AdjustDown(int topK[],int parent) //建小堆
{
	// parent is the index of the parent node.
	int child = 2*parent+1;
	while(child < K) //k is the max rank number
	{
		if(child+1 < K && topK[child+1] < topK[child])
		{
			++child;
		}
		if(topK[child] < topK[parent])
		{
			swap(topK[child],topK[parent]);
			parent = child;
			child = 2*parent+1;
		}
		else
		{
			break;
		}
	}
}
void GetTopK(int a[],int topK[])
{
	assert(a);
	int i = 0;
	for(i=0;i<K;++i) //将a的前K个元素放入数组中
	{
		topK[i] = a[i];
	}
	for(i=(K-2)/2;i>=0;--i)//对前K个元素建小堆
	{
		AdjustDown(topK,i);
	}
	for(i=K;i<N;++i)
	{
		if(a[i] > topK[0]) //将K个元素之后的每个元素和堆的第一个元素(最小元素)比较
		{
			swap(a[i],topK[0]);//若比第一个元素大，则交换
			AdjustDown(topK,0);//对新堆重新建小堆
		}
	}
}
