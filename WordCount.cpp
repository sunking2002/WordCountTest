
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)��
int main(int argc,char* argv[])
{

    FILE* fp;  // ָ���ļ���ָ��
    char buffer[1003];  //���������洢��ȡ����ÿ�е�����
    int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char c;  // ��ȡ�����ַ�
    int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    int charNum = 0;  // ��ǰ�е��ַ���
    int wordNum = 0; // ��ǰ�еĵ�����
    int totalWord = 0;//���ַ���
    int totalSign = 0;//�ܵ�����
    if ((fp = fopen(argv[2], "rb")) == NULL) {
        perror(argv[2]);
        return NULL;
    }
    // ÿ�ζ�ȡһ�����ݣ����浽buffer��ÿ�����ֻ����1000���ַ�
    while (fgets(buffer, 1003, fp) != NULL) {
        bufferLen = strlen(buffer);
        // ����������������
        for (i = 0; i < bufferLen; i++) {
            c = buffer[i];
            if (c == ' ' || c == '\t') {  // �����ո�
                !isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
                isLastBlank = 1;
            }
            else if (c != '\n' && c != '\r') {  // ���Ի��з�
                charNum++;  // ����Ȳ��ǻ��з�Ҳ���ǿո��ַ�����1
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
        isLastBlank = 1;  // ÿ�λ�������Ϊ1
        // һ�н������������ַ������ܵ�������������
        totalSign++;  // ������
        totalSign+= charNum;  // ���ַ���
        totalWord += wordNum;  // �ܵ�����
        // ���㣬����ͳ����һ��
        charNum = 0;
        wordNum = 0;
    }
   if (!strcmp(argv[1],"-w")) {
        printf("�ַ�����%d", totalSign);
   }
   else {
        printf("��������%d", totalWord);
   }
}