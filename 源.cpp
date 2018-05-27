#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include"string"
#include"iostream"
using namespace std;

void hangshu(char ss[]) //行数
{
	FILE *fp;

	if ((fp = fopen(ss, "r")) == NULL)
	{
		printf("file read failure.");
	}
	int l = 1;
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '\n')
		{
			l++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	printf("行数：%d.\n", l);
	fclose(fp);
}
void zifushu(char ss[]) //字符数
{
	FILE *fp;	
	if ((fp = fopen(ss, "r")) == NULL)
	{
		printf("文件打开失败");
	}
	int c = 0;
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		c++;
		ch = fgetc(fp);
	}
	printf("字符数 ：%d.\n", c);
	fclose(fp);
}

void dancishu(char ss[]) //单词数
{
	FILE *fp;
	if ((fp = fopen(ss, "r")) == NULL)
	{
		printf("file read failure.");
	}
	int w = 0;
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
		{
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9') || ch == '_')
			{
				ch = fgetc(fp);
			}
			w++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	printf("单词数：%d.\n", w);
	fclose(fp);
}

void zuihou(char ss[])  //传入路径显示代码行，空行，注释行
{
	FILE *fp;
	if ((fp = fopen(ss, "r")) == NULL)
	{
		printf("文件打开失败");
	}
	char ch;
	int danci = 0, konghang = 0, zushihang = 0;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '{' || ch == '}')
		{
			konghang++;
			ch = fgetc(fp);
		}
		else if (ch == '\n')
		{
			ch = fgetc(fp);
			while (ch == '\n')
			{
				konghang++;
				ch = fgetc(fp);
			}
		}
		else if (ch == '/')
		{
			ch = fgetc(fp);
			if (ch == '/')
				while (ch != '\n')
				{
					ch = fgetc(fp);
				}
			zushihang++;
			ch = fgetc(fp);
		}
		else
		{
			danci++;
			while (ch != '{'&&ch != '}'&&ch != '\n'&&ch != '/'&&ch != EOF)
			{
				ch = fgetc(fp);
			}
		}

	}
	printf("单词行：%d.\n",danci );
	printf("空行：%d.\n", konghang);
	printf("注释行 ：%d.\n", zushihang);
	fclose(fp);
}
int main(int argc, char *argv[])
{
	

	if ((strcmp(argv[1], "-c") == 0) )
	{
		zifushu(argv[2]);
	}

	if ((strcmp(argv[1], "-w") == 0) ) {

		dancishu(argv[2]);
	}
	if ((strcmp(argv[1], "-l") == 0) )
	{
		hangshu(argv[2]);
	}
	if((strcmp(argv[1], "-a") == 0))
	{
		zuihou(argv[2]);
	}
	return 0;
}