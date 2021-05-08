#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char* argv[]){
	char filename[]="D:\\Desktop\\file.txt";
	FILE *fp;
	char buffer[1024];
	char c;
	int len;   //行字符个数 
	int lastBlank = 0; // 上个字符是否是空格(1表示是  0表示不是)
	int charCount=0; //统计字符数量 
	int wordCount=0; //统计单词数数量 
	int i;
 
	if((fp=fopen(filename,"rb"))==NULL){ 	//先写入后读出 
		printf("文件不能打开\n");
		exit(0);
	}
	while(fgets(buffer,1024,fp)!=NULL){
		len=strlen(buffer);
		for(i=0;i<len;i++){
			c=buffer[i];
			if(c==' ' || c=='\t'){	//判断空格 或者 tab 
				if(lastBlank==0){
					wordCount++;	//单词数统计 
				}
				lastBlank=1;
			}else if(c!='\n'&&c!='\r'){//判断换行 
				charCount++;//字符数统计 
				lastBlank=0;
			}
 
		}
		if(lastBlank==0)
			wordCount++;
		lastBlank=1;
	}
	fclose(fp);
	if(!strcmp(argv[1],"-w")){
		printf("单词数：%d\n",wordCount);
	} 
	if(!strcmp(argv[1],"-c")){
		printf("字符数：%d\n",charCount);
	}
	return 0;
}
