/****************************************************************************************************
��Ŀ������һ���Ѿ�������������������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֡�
Ҫ��ʱ�临�Ӷ���O(n)������ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
������������1��2��4��7��11��15������15������4+11=15��������4��11��
*****************************************************************************************************/
#include<stdio.h>

/*
����������A���ҳ���Ϊsum����������Ԫ�أ�������a��b��
*/
bool FindTwoNumSum(int *A,int len,int sum,int *a,int *b)
{
	if(A==NULL || len<2)
		return false;
	int low = 0;
	int high = len-1;
	while(low<high)
	{
		if(A[low]+A[high] == sum)
		{
			*a = A[low];
			*b = A[high];
			return true;
		}
		else if(A[low]+A[high] < sum)
			low++;
		else
			high--;
	}
	return false;
}

int main()
{
	int A[] = {1,3,7,9,12,15,17,18,19,20};
	int len = 10;
	int sum = 24;
	int a,b;
	if(FindTwoNumSum(A,len,sum,&a,&b))
		printf("Find two nums,they are:\n%d and %d\n",a,b);
	else
		printf("Not find\n");
	return 0;
}