#include<bits/stdc++.h>
//统计字符数 
int charCount(char *file);
//统计单词数 
int wordCount(char *file);

int main()
{
	FILE *fp;
	//统计字符还是统计单词 
	char order[10];
	int chCount,woCount;
	//保存文件名 
	char file[101];
	scanf("%s %s",order,file);
	
	if(order[1] == 'c')
	{
		chCount=charCount(file);
		printf("\n字符数:%d\n",chCount);
	}
	else if(order[1] == 'w')
	{
		woCount=wordCount(file);
		printf("\n单词数:%d\n",woCount);
	}

}
int charCount(char *file) 
{
	FILE *fp = NULL;
	int ans = 0;
	if ((fp=fopen(file,"r"))== NULL) 
	{
		printf("没有找到对应文件！\n");
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
		printf("没有找到对应文件！\n");
		exit(-1);
	}
	char ch;
	ch = fgetc(fp);
	int word;
	while(!feof(fp)) 
	{
		//统计单词间隔数，加一即为单词数 
		if(ch==' '||ch == ',')
		wordcount++;
		ch = fgetc(fp);
	}
	wordcount++;
	return wordcount;
}

