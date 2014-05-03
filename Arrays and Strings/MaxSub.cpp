#include<stdio.h>

/*
���淽��,ʱ�临�Ӷ�O��n*n��
�ȴӵ�һ��Ԫ�ؿ�ʼ����ۼӣ�
ÿ���ۼӺ���֮ǰ�ĺͱȽϣ��������ֵ��
�ٴӵڶ���Ԫ�ؿ�ʼ����ۼӣ��Դ����ơ�
*/
int MaxSubSum1(int *arr,int len)
{
	int i,j;
	int MaxSum = 0;
	//ÿ�ο�ʼ�ۼӵ���ʼλ�õ�ѭ��
	for(i=0;i<len;i++)
	{
		int CurSum = 0;
		//����ۼӵ�ѭ��
		for(j=i;j<len;j++)
		{
			CurSum += arr[j];
			if(CurSum > MaxSum)
				MaxSum = CurSum;
		}
	}
	return MaxSum;
}

/*
���������е����ֵ
*/
int Max3(int a,int b,int c)
{
	int Max = a;
	if(b > Max)
		Max = b;
	if(c > Max)
		Max = c;
	return Max;
}

/*
�����㷨�����÷��β���
*/
int MaxSubSum2(int *arr,int left,int right)
{
	int MaxLeftSum,MaxRightSum;	//���ұߵ�����
	int MaxLeftBorderSum,MaxRightBorderSum;	//���м�߽�����Ҳ�������
	int LeftBorderSum,RightBorderSum;	//���м�߽�����Ҳ��ֵ�ǰ��
	int i,center;

	//�ݹ鵽���Ļ������
	if(left == right)
		if(arr[left]>0)
			return arr[left];
		else
			return 0;

	//���м�߽�����Ҳ��ֵ����ֵ
	center = (left + right)/2;
	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for(i=center;i>=left;i--)
	{
		LeftBorderSum += arr[i];
		if(LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for(i=center+1;i<=right;i++)
	{
		RightBorderSum += arr[i];
		if(RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	//�ݹ������Ҳ������ֵ
	MaxLeftSum = MaxSubSum2(arr,left,center);
	MaxRightSum = MaxSubSum2(arr,center+1,right);

	//���������е����ֵ
	return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);
}

/*
����֧����ʵ�ֵ��㷨��װ����
*/
int MaxSubSum2_1(int *arr,int len)
{
	return MaxSubSum2(arr,0,len-1);
}

/*
���ŷ�����ʱ�临�Ӷ�O��n��
�����������еĵ�һ��Ԫ�ؿ϶�������
��ΪԪ�������и�����������е�����һ������0
*/
int MaxSubSum3(int *arr,int len)
{
	int i;
	int MaxSum = 0;
	int CurSum = 0;
	for(i=0;i<len;i++)
	{
		CurSum += arr[i];
		if(CurSum > MaxSum)
			MaxSum = CurSum;
		//����ۼӺͳ���С��0�������
		//������������п϶������ܰ���ǰ���Ԫ�أ�
		//��ʱ���ۼӺ���0�����¸�Ԫ�����¿�ʼ�ۼ�
		if(CurSum < 0)
			CurSum = 0;
	}
	return MaxSum;
}


int main()
{
	int arr[] = {2,4,-7,5,2,-1,2,-4,3};
	printf("�����е�����Ϊ��%d\n",MaxSubSum2_1(arr,9));
	return 0;
}