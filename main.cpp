//
// Created by l1460 on 24-7-2.
//
#include <stdio.h>

// ��ȡ�ļ����ݲ���ӡ����׼���
void readFile(const char *filename) {
    FILE *file;
    char line[100];

    file = fopen(filename, "r"); // ���ļ����ڶ�ȡ

    if (file != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) { // ��ȡ�ļ���ÿһ��
            printf("%s", line); // �����ȡ������
        }
        fclose(file); // �ر��ļ�
    } else {
        perror("Error opening file"); // ���������Ϣ
    }
}

int main() {
    readFile("sysconst.txt");
    return 0;
}