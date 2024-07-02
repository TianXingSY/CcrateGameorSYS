//
// Created by l1460 on 24-7-2.
//
#include "LinkList.cpp"


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
    printf("欢迎使用学生成绩管理系统-ver beta 0.1\n");
    while (1) {
        int choice;
        printf("\n请选择操作：\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 修改学生信息（成绩）\n");
        printf("4. 查询学生成绩\n");
        printf("5. 显示所有学生成绩\n");
        printf("6. 退出\n");
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
                int stunum;
                stu seestu;
                printf("请输入要查询的学生学号：\n");
                scanf("%d", &stunum);
                if (Outstunum(head, stunum, &seestu)) {
                    printf("姓名：%s 学号：%d 成绩：%f\n", seestu.name, seestu.stunum, seestu.score);
                }
                
                break;
                
            }
            case 5: {
                printf("所有学生成绩如下：\n");
                bianli(head);
                break;
            }
            case 6: {
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