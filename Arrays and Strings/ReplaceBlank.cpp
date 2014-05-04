#include<stdio.h>
#include<string.h>
#include<stdlib.h>;

char *ReplaceBlank(char *str)
{
	if(str == NULL)
		return NULL;
	int len = strlen(str);
	if(len == 0)
		return NULL;
	int i,count = 0;
	for(i=0;i<len;i++)
		if(str[i] == ' ')
			count++;
	//û�пո񣬾�ֱ�ӷ���str
	if(count == 0)
		return str;
	int new_len = 2*count+len+1;
	char *dest = (char *)malloc(new_len*sizeof(char));
	if(dest == NULL)
		exit(EXIT_FAILURE);
	int j = 0;
	for(i=0;i<len;i++)
	{
		if(str[i] != ' ')
		{
			dest[j++] = str[i];
		}
		else
		{
			dest[j] = '%';
			dest[j+1] = '2';
			dest[j+2] = '0';
			j += 3;
		}
	}
	dest[j] = '\0';
	return dest;
}

int main()
{
	//��ȻAC�ˣ���Ҫ�ŶȵĲ�������û�д��������Χ�ģ���������Ϊ������str�ĳ��Ȳ�������ѵķ�����
	//���ʹ��C++�е�string���java�е�String�࣬
	//��Ŀǰ��C�����У��һ���֪����ô���Բ��޶����ȵشӼ��̽���������ַ�����
	static char str[10000000];
	gets(str);
	char *dest = ReplaceBlank(str);
	if(dest != NULL)
		puts(dest);
	return 0;
}
