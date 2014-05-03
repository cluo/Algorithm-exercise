/****************************************************************************************************
��Ŀ������һ������ķǸ����������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֡�
Ҫ��ʱ�临�Ӷ���O(n)������ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
������������1��7��4��11��6��15������15������4+11=15��������4��11��
*****************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

/*
����������A���ҳ���Ϊsum����������Ԫ�أ�������a��b��
*/
bool FindTwoNumSum(int *A,int len,int sum,int *a,int *b)
{
	if(A==NULL || len<2)
		return false;
	//��Ԫ�ؾ�����ʼ��Ϊfalse��bool����
	bool *B = (bool*)calloc(sum,sizeof(bool));
	if(B == NULL)
		exit(EXIT_FAILURE);
	int i;
	for(i=0;i<len;i++)
	{
		if(A[i]>sum)
			break;
		if(B[A[i]] == false)
			B[sum-A[i]] = true;
		else
		{
			*a = A[i];
			*b = sum-A[i];
			free(B);
			B = NULL;
			return true;
		}
	}
	free(B);
	B = NULL;
	return false;
}

int main()
{
	int A[] = {19,3,9,7,12,20,17,18,1,16};
	int len = 10;
	int sum = 24;
	int a,b;
	if(FindTwoNumSum(A,len,sum,&a,&b))
		printf("Find two nums,they are:\n%d and %d\n",a,b);
	else
		printf("Not find\n");
	return 0;
}
