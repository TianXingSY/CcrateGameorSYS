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
        printf("内存申请失败\n");
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
    strcpy(teststu[0].name, "李华");

    teststu[1].stunum = 2;
    teststu[1].score = 66;
    strcpy(teststu[1].name, "张三");

    teststu[2].stunum = 3;
    teststu[2].score = 88;
    strcpy(teststu[2].name, "王五");

    teststu[3].stunum = 4;
    teststu[3].score = 77;
    strcpy(teststu[3].name, "赵六");

    teststu[4].stunum = 5;
    teststu[4].score = 55;
    strcpy(teststu[4].name, "钱七");

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
        printf("请输入名字：");
        scanf("%s", &c.name);
        printf("请输入学号：");
        scanf("%d", &c.stunum);
        printf("请输入成绩：");
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
        printf("输入非法\n");
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
    //printf("删除成功\n");
    return(1);
}

int InsertLL(LinkList L, int e, stu a) {
    if (e < 1) {
        printf("输入非法\n");
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
            //printf("插入位置不存在\n");
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
        printf("姓名：%s 学号：%d 成绩：%f\n", r->data.name, r->data.stunum, r->data.score);
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
    printf("数据不存在\n");
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
    printf("数据不存在\n");
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
    printf("数据不存在\n");
    return(0);
}



//依据成绩排序
int Sort(LinkList L, int re = 0) {
    LinkList f = L->next, b = L->next;
    int i, j, len, max = 0;
    len = linkLen(L);
    stu* linshi, temp;
    linshi = (stu*)malloc(sizeof(stu) * len);
    if (linshi == NULL) {
        printf("内存申请失败\n");
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



// 读取文件内容并打印到标准输出
int ReadListFromFile(LinkList* L, const char* filename) {

    // 打开文件
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("打开文件失败\n");
        return 0;
    }

    // 读取并解析文件内容
    LinkList current = *L;
    char buffer[100]; // 存储每行数据的缓冲区
    while (fgets(buffer, sizeof(buffer), fp)) {
        // 创建新节点
        LinkList newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("内存分配失败\n");
            fclose(fp);
            return 0;
        }

        // 解析数据
        sscanf(buffer, "%[^,],%d,%f", newNode->data.name, &newNode->data.stunum, &newNode->data.score);

        // 插入链表
        current->next = newNode;
        current = newNode;
    }
    current->next = NULL; // 设置尾节点的next指针为NULL

    // 关闭文件
    fclose(fp);
    return 1;
}

//把链表写入文件

int WriteListToFile(LinkList L, const char* filename) {
    // 打开文件
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("打开文件失败\n");
        return 0;
    }

    // 遍历链表并写入数据
    Node* current = L->next; // 跳过头节点
    while (current != NULL) {
        // 写入学生信息
        fprintf(fp, "%s,%d,%.1f\n", current->data.name, current->data.stunum, current->data.score);
        current = current->next; // 移动到下一个节点
    }

    // 关闭文件
    fclose(fp);
    return 1;
}


int main() {

    LinkList head;
    InitList(&head);
    if (ReadListFromFile(&head, "students.txt")!=1) {// 调用函数读取文件内容
        printf("读取文件失败,尝试创建新文件\n");
        if (WriteListToFile(head, "students.txt") != 1){
            printf("创建新文件失败\n");
            return 0;
        }
        printf("创建新文件成功\n");
    }
    int flag = 1;
    printf("欢迎使用学生成绩管理系统-ver 1.01\n");
    while (1) {
        int choice;
        printf("\n请选择操作：\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 修改学生信息（成绩）\n");
        printf("4. 查询学生成绩\n");
        printf("5. 显示所有学生成绩\n");
        printf("6. 排序所有学生信息\n");
        printf("7. 退出\n");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                stu newStu;
                printf("请输入学生姓名、学号和成绩(以空格space分割)：\n");
                scanf("%s %d %f", newStu.name, &newStu.stunum, &newStu.score);
                InsertLL(head, linkLen(head)+1, newStu);
                printf("学生信息已添加\n");
                if (WriteListToFile(head, "students.txt")) {
                    printf("\n");
                }
                break;
            }
            case 2: {
                int stunum, loca;
                printf("请输入要删除的学生学号：\n");
                scanf("%d", &stunum);
                stu deletedStu;
                loca = Findstunum(head, stunum);
                if (DelLL(head, loca, &deletedStu)) {
                    printf("学生信息已删除\n");
                }
                else {
                    printf("未找到该学生\n");
                }
                if (WriteListToFile(head, "students.txt")) {
                    printf("\n");
                }
                break;
            }
            case 3: {
                int stunum, loca;
                printf("请输入要修改的学生的学号：\n");
                scanf("%d", &stunum);
                stu modifiedStu;
                loca = Findstunum(head, stunum);
                if (DelLL(head, loca, &modifiedStu)) {
                    printf("请输入新成绩\n");
                    scanf("%f", &modifiedStu.score);
                    if (InsertLL(head, loca, modifiedStu)) {
                        printf("成绩修改成功\n");
                        if (WriteListToFile(head, "students.txt")) {
                            printf("\n");
                        }
                    }
                    else {
                        printf("成绩修改失败\n");
                    }
                }
                else {
                    printf("未找到该学生\n");
                }
                
                break;
            }
            case 4: {
                int stunum,choice;
                stu seestu;
                char name[30];
                printf("1: 姓名查询\n2: 学号查询\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("请输入要查询的学生姓名：\n");
                    scanf("%s", name);
                    if (Outname(head, name, &seestu)) {
                        printf("姓名：%s 学号：%d 成绩：%f\n", seestu.name, seestu.stunum, seestu.score);
                    }
                }
                else{
                    printf("请输入要查询的学生学号：\n");
                    scanf("%d", &stunum);
                    if (Outstunum(head, stunum, &seestu)) {
                        printf("姓名：%s 学号：%d 成绩：%f\n", seestu.name, seestu.stunum, seestu.score);
                    }
                }

                
                break;
                
            }
            case 5: {
                printf("所有学生成绩如下：\n");
                bianli(head);
                break;
            }
            case 6: {
                printf("0：升序\n1：降序\n");
                int choice;
                scanf("%d", &choice);
                if(choice != 1){
                    choice=0;
                }
                if (Sort(head, choice)) {
                    printf("成功");
                    bianli(head);
                }
                break;
            }
            case 7: {
                printf("感谢使用学生成绩管理系统-ver beta 0.1\n");
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            break;
        }

    }


    if (WriteListToFile(head, "students.txt")) {
        printf("链表数据已写入文件\n");
    }
    //释放内存
    int len = linkLen(head);
    stu temp;
    for (int i = 1; i <= len; i++) {
        DelLL(head, 1, &temp);
    }
    free(head);
    printf("内存已释放\n");
    
    return 0;
}