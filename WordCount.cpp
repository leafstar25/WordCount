#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char* argv[]){
	char filename[]="D:\\Desktop\\file.txt";
	FILE *fp;
	char buffer[1024];
	char c;
	int len;   //���ַ����� 
	int lastBlank = 0; // �ϸ��ַ��Ƿ��ǿո�(1��ʾ��  0��ʾ����)
	int charCount=0; //ͳ���ַ����� 
	int wordCount=0; //ͳ�Ƶ��������� 
	int i;
 
	if((fp=fopen(filename,"rb"))==NULL){ 	//��д������ 
		printf("�ļ����ܴ�\n");
		exit(0);
	}
	while(fgets(buffer,1024,fp)!=NULL){
		len=strlen(buffer);
		for(i=0;i<len;i++){
			c=buffer[i];
			if(c==' ' || c=='\t'){	//�жϿո� ���� tab 
				if(lastBlank==0){
					wordCount++;	//������ͳ�� 
				}
				lastBlank=1;
			}else if(c!='\n'&&c!='\r'){//�жϻ��� 
				charCount++;//�ַ���ͳ�� 
				lastBlank=0;
			}
 
		}
		if(lastBlank==0)
			wordCount++;
		lastBlank=1;
	}
	fclose(fp);
	if(!strcmp(argv[1],"-w")){
		printf("��������%d\n",wordCount);
	} 
	if(!strcmp(argv[1],"-c")){
		printf("�ַ�����%d\n",charCount);
	}
	return 0;
}
