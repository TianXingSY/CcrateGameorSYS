//
// Created by l1460 on 24-7-2.
//
#include "LinkList.cpp"


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
    //readFile("sysconst.txt"); // ���ú�����ȡ�ļ�����

    LinkList head;
    InitList(&head);
    CreateFromTailWithoutInput(head);
    printf("%s %d %f",head->next->data.name,head->next->data.stunum,head->next->data.score);
    printf("\n");
    bianli(head);
    printf("%d\n", linkLen(head));

    printf("%d\n", sizeof(stu));

    stu see;
    DelLL(head, 5,&see);
    printf("%s\n",see.name);
    bianli(head);
    see.score+=5;
    InsertLL(head, 3, see);
    bianli(head);

    return 0;
}