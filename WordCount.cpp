#include<bits/stdc++.h>
//ͳ���ַ��� 
int charCount(char *file);
//ͳ�Ƶ����� 
int wordCount(char *file);

int main()
{
	FILE *fp;
	//ͳ���ַ�����ͳ�Ƶ��� 
	char order[10];
	int chCount,woCount;
	//�����ļ��� 
	char file[101];
	scanf("%s %s",order,file);
	
	if(order[1] == 'c')
	{
		chCount=charCount(file);
		printf("\n�ַ���:%d\n",chCount);
	}
	else if(order[1] == 'w')
	{
		woCount=wordCount(file);
		printf("\n������:%d\n",woCount);
	}

}
int charCount(char *file) 
{
	FILE *fp = NULL;
	int ans = 0;
	if ((fp=fopen(file,"r"))== NULL) 
	{
		printf("û���ҵ���Ӧ�ļ���\n");
		exit(-1);
	}
	char ch;
	ch = fgetc(fp);
	while (!feof(fp)) 
	{
		ans++;
		ch = fgetc(fp);
	}
	fclose(fp);
	return ans;
}



int wordCount(char *file) 
{
	FILE *fp = NULL;
	int wordcount = 0;
	if ((fp = fopen(file,"r")) == NULL) 
	{
		printf("û���ҵ���Ӧ�ļ���\n");
		exit(-1);
	}
	char ch;
	ch = fgetc(fp);
	int word;
	while(!feof(fp)) 
	{
		//ͳ�Ƶ��ʼ��������һ��Ϊ������ 
		if(ch==' '||ch == ',')
		wordcount++;
		ch = fgetc(fp);
	}
	wordcount++;
	return wordcount;
}

