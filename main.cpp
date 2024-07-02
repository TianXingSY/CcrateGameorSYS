//
// Created by l1460 on 24-7-2.
//
#include <stdio.h>

// 读取文件内容并打印到标准输出
void readFile(const char *filename) {
    FILE *file;
    char line[100];

    file = fopen(filename, "r"); // 打开文件用于读取

    if (file != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) { // 读取文件的每一行
            printf("%s", line); // 输出读取的内容
        }
        fclose(file); // 关闭文件
    } else {
        perror("Error opening file"); // 输出错误信息
    }
}

int main() {
    readFile("sysconst.txt");
    return 0;
}