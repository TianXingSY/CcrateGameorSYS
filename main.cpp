//
// Created by l1460 on 24-7-2.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[20];
    int stunum;
    float score;
}stu;
typedef stu Elemtype;


typedef struct node {
    Elemtype data;
    struct node* next;
}Node, * LinkList;



int InitList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(Node));
    if (L == NULL) {
        printf("�ڴ�����ʧ��\n");
        return(0);
    }
    else {
        (*L)->next = NULL;
        return(1);
    }
}

int CreateFromTailWithoutInput(LinkList L) {
    Node* r, * s;
    int flag = 1;
    r = L;
    Elemtype c;
    stu teststu[50];
    teststu[0].stunum = 1;
    teststu[0].score = 99;
    strcpy(teststu[0].name, "�");

    teststu[1].stunum = 2;
    teststu[1].score = 66;
    strcpy(teststu[1].name, "����");

    teststu[2].stunum = 3;
    teststu[2].score = 88;
    strcpy(teststu[2].name, "����");

    teststu[3].stunum = 4;
    teststu[3].score = 77;
    strcpy(teststu[3].name, "����");

    teststu[4].stunum = 5;
    teststu[4].score = 55;
    strcpy(teststu[4].name, "Ǯ��");

    teststu[5].stunum = 0;

    int k = 0;
    while (flag) {
        memmove(&c, &teststu[k], sizeof(Elemtype));
        if (c.stunum != 0 && c.score != -1 && strcmp(c.name, "") != 0) {
            s = (Node*)malloc(sizeof(Node));
            s->data.stunum = c.stunum;
            s->data.score = c.score;
            strcpy(s->data.name, c.name);
            r->next = s;
            r = s;
        }
        else {
            flag = 0;
            r->next = NULL;
        }
        k++;
    }
    return(0);
}
int CreateFromTail(LinkList L) {
    Node* r, * s;
    int flag = 1;
    r = L;
    Elemtype c;
    while (flag) {
        printf("���������֣�");
        scanf("%s", &c.name);
        printf("������ѧ�ţ�");
        scanf("%d", &c.stunum);
        printf("������ɼ���");
        scanf("%f", &c.score);
        if (c.stunum != 0 && c.score != -1 && strcmp(c.name, "") != 0) {
            s = (Node*)malloc(sizeof(Node));
            s->data.stunum = c.stunum;
            s->data.score = c.score;
            strcpy(s->data.name, c.name);
            r->next = s;
            r = s;
        }
        else {
            flag = 0;
            r->next = NULL;
        }
    }
    return(0);
}

int linkLen(LinkList L) {
    LinkList r;
    int i = 0;
    r = L->next;
    while (r != NULL) {
        i++;
        r = r->next;
    }
    return(i);
}


int DelLL(LinkList L, int e, stu* a) {
    if (e<1 || e>linkLen(L)) {
        printf("����Ƿ�\n");
        return(0);
    }
    LinkList r, s;
    if (e == 1) {
        s = L->next;
        L->next = L->next->next;
        free(s);
        return(1);
    }
    int i;
    s = L;
    r = L->next;
    for (i = 1; i < e; i++) {
        s = r;
        r = r->next;
        memmove(a, &r->data, sizeof(stu));

    }
    s->next = r->next;
    free(r);
    //printf("ɾ���ɹ�\n");
    return(1);
}

int InsertLL(LinkList L, int e, stu a) {
    if (e < 1) {
        printf("����Ƿ�\n");
        return(0);
    }

    int i;
    LinkList r = L->next, s, In;
    In = (Node*)malloc(sizeof(Node));

    memmove(&In->data, &a, sizeof(stu));
    for (i = 0; i < e; i++) {
        if (e == 1) {
            In->next = L->next;
            L->next = In;
            return(1);
        }
        if (i == e - 2) {
            s = r;
        }
        else if (i == e - 1) {
            s->next = In;
            In->next = r;
            return(1);
        }
        if (r == NULL) {
            //printf("����λ�ò�����\n");
            return(0);
        }
        else if (r->next == NULL && i == e - 2) {
            r->next = In;
            In->next = NULL;
            return(0);
        }
        r = r->next;
    }
}

int bianli(LinkList L) {
    LinkList r;
    r = L->next;
    printf("\n");
    while (r != NULL) {
        printf("������%s ѧ�ţ�%d �ɼ���%f\n", r->data.name, r->data.stunum, r->data.score);
        r = r->next;
    }
    printf("\n");
    return(0);
}

int Findstunum(LinkList L, int x) {
    LinkList r;
    int i = 0;
    r = L->next;
    while (r != NULL) {
        if (r->data.stunum == x) {
            return(i + 1);
        }
        r = r->next;
        i++;
    }
    printf("���ݲ�����\n");
    return(0);
}
int Outstunum(LinkList L, int x, stu* a) {
    LinkList r;
    int i = 0;
    r = L->next;
    while (r != NULL) {
        if (r->data.stunum == x) {
            memmove(a, &r->data, sizeof(stu));
            return(i + 1);
        }
        r = r->next;
        i++;
    }
    printf("���ݲ�����\n");
    return(0);
}
int Outname(LinkList L, char* x, stu* a) {
    LinkList r;
    int i = 0;
    r = L->next;
    while (r != NULL) {
        if (strcmp(r->data.name, x) == 0) {
            memmove(a, &r->data, sizeof(stu));
            return(i + 1);
        }
        r = r->next;
        i++;
    }
    printf("���ݲ�����\n");
    return(0);
}



//���ݳɼ�����
int Sort(LinkList L, int re = 0) {
    LinkList f = L->next, b = L->next;
    int i, j, len, max = 0;
    len = linkLen(L);
    stu* linshi, temp;
    linshi = (stu*)malloc(sizeof(stu) * len);
    if (linshi == NULL) {
        printf("�ڴ�����ʧ��\n");
        return(0);
    }
    for (i = 0; i < len; i++) {
        memmove(&linshi[i], &b->data, sizeof(stu));
        b = b->next;
    }
    for (i = 0; i < len - 1; i++) {
        max = 0;
        for (j = 0; j < len - i; j++) {
            if (linshi[j].score > linshi[max].score) {
                max = j;
            }
        }
        memmove(&temp, &linshi[max], sizeof(stu));
        memmove(&linshi[max], &linshi[len - i - 1], sizeof(stu));
        memmove(&linshi[len - i - 1], &temp, sizeof(stu));
    }

    if (re == 1) {
        for (i = len - 1; i > -1; i--) {
            memmove(&f->data, &linshi[i], sizeof(stu));
            f = f->next;
        }
    }
    else {
        for (i = 0; i < len; i++) {
            memmove(&f->data, &linshi[i], sizeof(stu));
            f = f->next;
        }
    }

    free(linshi);
    return 1;
}



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
    printf("��ӭʹ��ѧ���ɼ�����ϵͳ-ver 1.01\n");
    while (1) {
        int choice;
        printf("\n��ѡ�������\n");
        printf("1. ���ѧ��\n");
        printf("2. ɾ��ѧ��\n");
        printf("3. �޸�ѧ����Ϣ���ɼ���\n");
        printf("4. ��ѯѧ���ɼ�\n");
        printf("5. ��ʾ����ѧ���ɼ�\n");
        printf("6. ��������ѧ����Ϣ\n");
        printf("7. �˳�\n");
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
                int stunum,choice;
                stu seestu;
                char name[30];
                printf("1: ������ѯ\n2: ѧ�Ų�ѯ\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("������Ҫ��ѯ��ѧ��������\n");
                    scanf("%s", name);
                    if (Outname(head, name, &seestu)) {
                        printf("������%s ѧ�ţ�%d �ɼ���%f\n", seestu.name, seestu.stunum, seestu.score);
                    }
                }
                else{
                    printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
                    scanf("%d", &stunum);
                    if (Outstunum(head, stunum, &seestu)) {
                        printf("������%s ѧ�ţ�%d �ɼ���%f\n", seestu.name, seestu.stunum, seestu.score);
                    }
                }

                
                break;
                
            }
            case 5: {
                printf("����ѧ���ɼ����£�\n");
                bianli(head);
                break;
            }
            case 6: {
                printf("0������\n1������\n");
                int choice;
                scanf("%d", &choice);
                if(choice != 1){
                    choice=0;
                }
                if (Sort(head, choice)) {
                    printf("�ɹ�");
                    bianli(head);
                }
                break;
            }
            case 7: {
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