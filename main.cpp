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
    while (1) {
        int choice;
        printf("\n��ѡ�������\n");
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
                stu seestu;
                printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
                scanf("%d", &stunum);
                if (Outstunum(head, stunum, &seestu)) {
                    printf("������%s ѧ�ţ�%d �ɼ���%f\n", seestu.name, seestu.stunum, seestu.score);
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
        if (flag == 0) {
            break;
        }

    }


    if (WriteListToFile(head, "students.txt")) {
        printf("����������д���ļ�\n");
    }
    //�ͷ��ڴ�
    int len = linkLen(head);
    stu temp;
    for (int i = 1; i <= len; i++) {
        DelLL(head, 1, &temp);
    }
    free(head);
    printf("�ڴ����ͷ�\n");
    
    return 0;
}