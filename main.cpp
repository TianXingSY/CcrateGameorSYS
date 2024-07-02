//
// Created by l1460 on 24-7-2.
//
#include "LinkList.cpp"


// ��ȡ�ļ����ݲ���ӡ����׼���
int ReadListFromFile(LinkList* L, const char* filename) {

    // ���ļ�
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("���ļ�ʧ��\n");
        return 0;
    }

    // ��ȡ�������ļ�����
    LinkList current = *L;
    char buffer[100]; // �洢ÿ�����ݵĻ�����
    while (fgets(buffer, sizeof(buffer), fp)) {
        // �����½ڵ�
        LinkList newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("�ڴ����ʧ��\n");
            fclose(fp);
            return 0;
        }

        // ��������
        sscanf(buffer, "%[^,],%d,%f", newNode->data.name, &newNode->data.stunum, &newNode->data.score);

        // ��������
        current->next = newNode;
        current = newNode;
    }
    current->next = NULL; // ����β�ڵ��nextָ��ΪNULL

    // �ر��ļ�
    fclose(fp);
    return 1;
}

//������д���ļ�

int WriteListToFile(LinkList L, const char* filename) {
    // ���ļ�
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("���ļ�ʧ��\n");
        return 0;
    }

    // ��������д������
    Node* current = L->next; // ����ͷ�ڵ�
    while (current != NULL) {
        // д��ѧ����Ϣ
        fprintf(fp, "%s,%d,%.2f\n", current->data.name, current->data.stunum, current->data.score);
        current = current->next; // �ƶ�����һ���ڵ�
    }

    // �ر��ļ�
    fclose(fp);
    return 1;
}
/*void writeFile(const char *filename, const char *content) {
    FILE *file;
    file = fopen(filename, "w"); // ���ļ�����д��

    if (file != NULL) {
        fprintf(file, "%s", content); // ������д���ļ�
        fclose(file); // �ر��ļ�
    } else {
        perror("Error opening file"); // ���������Ϣ
    }
}*/



int main() {

    LinkList head;
    InitList(&head);
    ReadListFromFile(&head,"students.txt");// ���ú�����ȡ�ļ�����
    //CreateFromTailWithoutInput(head);
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

    if (WriteListToFile(head, "students.txt")) {
        printf("����������д���ļ�\n");
    }
    
    return 0;
}