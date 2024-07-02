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
        fprintf(fp, "%s,%d,%.1f\n", current->data.name, current->data.stunum, current->data.score);
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
    if (ReadListFromFile(&head, "students.txt")!=1) {// ���ú�����ȡ�ļ�����
        printf("��ȡ�ļ�ʧ��,���Դ������ļ�\n");
        if (WriteListToFile(head, "students.txt") != 1){
            printf("�������ļ�ʧ��\n");
            return 0;
        }
        printf("�������ļ��ɹ�\n");
    }
    int flag = 1;
    printf("��ӭʹ��ѧ���ɼ�����ϵͳ-ver beta 0.1\n");
    while (flag) {
        int choice;
        printf("��ѡ�������\n");
        printf("1. ���ѧ��\n");
        printf("2. ɾ��ѧ��\n");
        printf("3. �޸�ѧ����Ϣ���ɼ���\n");
        printf("4. ��ѯѧ���ɼ�\n");
        printf("5. ��ʾ����ѧ���ɼ�\n");
        printf("6. �˳�\n");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                stu newStu;
                printf("������ѧ��������ѧ�źͳɼ�(�Կո�space�ָ�)��\n");
                scanf("%s %d %f", newStu.name, &newStu.stunum, &newStu.score);
                InsertLL(head, linkLen(head)+1, newStu);
                printf("ѧ����Ϣ�����\n");
                if (WriteListToFile(head, "students.txt")) {
                    printf("\n");
                }
                break;
            }
            case 2: {
                int stunum, loca;
                printf("������Ҫɾ����ѧ��ѧ�ţ�\n");
                scanf("%d", &stunum);
                stu deletedStu;
                loca = Findstunum(head, stunum);
                if (DelLL(head, loca, &deletedStu)) {
                    printf("ѧ����Ϣ��ɾ��\n");
                }
                else {
                    printf("δ�ҵ���ѧ��\n");
                }
                if (WriteListToFile(head, "students.txt")) {
                    printf("\n");
                }
                break;
            }
            case 3: {
                int stunum, loca;
                printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
                scanf("%d", &stunum);
                stu modifiedStu;
                loca = Findstunum(head, stunum);
                if (DelLL(head, loca, &modifiedStu)) {
                    printf("�������³ɼ�\n");
                    scanf("%f", &modifiedStu.score);
                    if (InsertLL(head, loca, modifiedStu)) {
                        printf("�ɼ��޸ĳɹ�\n");
                        if (WriteListToFile(head, "students.txt")) {
                            printf("\n");
                        }
                    }
                    else {
                        printf("�ɼ��޸�ʧ��\n");
                    }
                }
                else {
                    printf("δ�ҵ���ѧ��\n");
                }
                
                break;
            }
            case 4: {
                int stunum;
                printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
                scanf("%d", &stunum);
                stu searchedStu;
                if (Findstunum(head, stunum) != -1) {
                    printf("ѧ����Ϣ���£�\n");
                    printf("%s %d %f\n", searchedStu.name, searchedStu.stunum, searchedStu.score);
                }
                else {
                    printf("δ�ҵ���ѧ��\n");
                }
                break;
            }
            case 5: {
                printf("����ѧ���ɼ����£�\n");
                bianli(head);
                break;
            }
            case 6: {
                printf("��лʹ��ѧ���ɼ�����ϵͳ-ver beta 0.1\n");
                flag = 0;
                break;
            }
        }

    }
    /*CreateFromTailWithoutInput(head);
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
    bianli(head);*/

    if (WriteListToFile(head, "students.txt")) {
        printf("����������д���ļ�\n");
    }
    
    return 0;
}