
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)；
int main(int argc,char* argv[])
{

    FILE* fp;  // 指向文件的指针
    char buffer[1003];  //缓冲区，存储读取到的每行的内容
    int bufferLen;  // 缓冲区中实际存储的内容的长度
    int i;  // 当前读到缓冲区的第i个字符
    char c;  // 读取到的字符
    int isLastBlank = 0;  // 上个字符是否是空格
    int charNum = 0;  // 当前行的字符数
    int wordNum = 0; // 当前行的单词数
    int totalWord = 0;//总字符数
    int totalSign = 0;//总单词数
    if ((fp = fopen(argv[2], "rb")) == NULL) {
        perror(argv[2]);
        return NULL;
    }
    // 每次读取一行数据，保存到buffer，每行最多只能有1000个字符
    while (fgets(buffer, 1003, fp) != NULL) {
        bufferLen = strlen(buffer);
        // 遍历缓冲区的内容
        for (i = 0; i < bufferLen; i++) {
            c = buffer[i];
            if (c == ' ' || c == '\t') {  // 遇到空格
                !isLastBlank && wordNum++;  // 如果上个字符不是空格，那么单词数加1
                isLastBlank = 1;
            }
            else if (c != '\n' && c != '\r') {  // 忽略换行符
                charNum++;  // 如果既不是换行符也不是空格，字符数加1
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++;  // 如果最后一个字符不是空格，那么单词数加1
        isLastBlank = 1;  // 每次换行重置为1
        // 一行结束，计算总字符数、总单词数、总行数
        totalSign++;  // 总行数
        totalSign+= charNum;  // 总字符数
        totalWord += wordNum;  // 总单词数
        // 置零，重新统计下一行
        charNum = 0;
        wordNum = 0;
    }
   if (!strcmp(argv[1],"-w")) {
        printf("字符数：%d", totalSign);
   }
   else {
        printf("单词数：%d", totalWord);
   }
}