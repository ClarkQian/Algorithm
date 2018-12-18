#include<iostream>
#include<string>
#include<limits>
#include<sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;
using std::numeric_limits;
using std::streamsize;

//计算当前输出的应该是哪个数字的函数
//第 i 行 ，j 列 ；n 表示方阵的维数
int calculateNumber(int i,int j,int n)
{
	int n_j=n-j;
	int n_i=n-i;
	//正在打印的数在上环时
	if(i<=j&&i<=n_i&&i<=n_j)
	{
		i--;//换成直观数据，即外面有i层。
		n_i++;
		return(4*i*n_i+j-i);
	}
	//正在打印的数据在左环的时候
	 if(j<=i&&j<=n_i&&j<=n_j)
	{
		//此处与上面的情况不同，此处先算满整第 j 环（最外面为第一环） ,然后再从中减掉多余的
		return(4*j*n_j-i+j+1);
	}
	//正在打印的数据在下环的时候
	if(n_i<=i&&n_i<=j&&n_i<=n_j)
	{//这种情况下n_i就代表外面的层数
		return(4*i*n_i+4*i-2*n-1+i-j);
	}
	//正在打印的数据在右环的时候
	if(n_j<=i&&n_j<=j&&n_j<=n_j)
	{//这种情况下n_j就代表外面的层数
		return(4*j*n_j+2*j-n-1+j+i-n);
	}
	return 0;
}

//此问题的核心函数，打印函数
void matrixPrint(int n)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			//此处由于用到格式化输出，printf格式控制输出方式
			//printf("%4d",calculateNumber(i,j,n));
			cout.width(5);
			cout<<calculateNumber(i,j,n);
			if(j==n)
				cout<<endl;
		}
}

int main(int argc, char const *argv[])
{
	matrixPrint(4);
	return 0;
}
