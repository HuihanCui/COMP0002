#include <stdio.h>
#include <math.h>

int nums[9], now_num = 1;
int a = 0;
int flags[9];//保存符号
// 递归计算选出的n个数的 + - 排列组合求和结果
int calulate(int i,int sum)
{
	if (i == a+1) {
		if (sum == 100) {
			for (int j = 0; j <= a; j++) {
				printf("%d", nums[j]);
				if (j != a)
					if (flags[j+1]) printf("-");
					else printf("+");
			}
			printf("=%d\n", sum);
		}
 		return 0;
	}
	if (i == 0) {
		calulate(i + 1, nums[i]);
		return 0;
	}
	flags[i] = 0;//0是+
	calulate(i + 1, sum + nums[i]);
	flags[i] = 1;//1是-
	calulate(i + 1, sum - nums[i]);
	
	return 0;
}
// n是总共要分成n个数字  r是剩余的数字
int generate_num(int n,int r)
{
	//结束递归  n=1时 剩下的所有数字组成一个
	if (n == 1)
	{
		for (int i = 0; i <= r - n; i++) {
			nums[a] = nums[a] * 10 + now_num++;
		}
		calulate(0, 0);
		nums[a] = 0;
		now_num -= r - n + 1;
		return 0;
	}
	//至多可以与其后面R-N个数字结合
	for (int i = 0; i <= r-n; i++)
	{	
		//计算结合后的数字
		for (int j = 0; j < i + 1; j++) {
			nums[a] = nums[a]*10+ now_num++;
		}
		a++;//数字个数加一
		generate_num(n - 1, r - i - 1);
		//回溯
		a--;
		nums[a] = 0;
		now_num -= i + 1;

	}
	return 0;
}
int main()
{
	for (int i = 9; i >= 2; i--) {
		generate_num(i, 9);
	}
	return 0;
}
