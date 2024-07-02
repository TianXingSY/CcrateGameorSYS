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
        fprintf(fp, "%s,%d,%.2f\n", current->data.name, current->data.stunum, current->data.score);
        current = current->next; // 移动到下一个节点
    }

    // 关闭文件
    fclose(fp);
    return 1;
}
/*void writeFile(const char *filename, const char *content) {
    FILE *file;
    file = fopen(filename, "w"); // 打开文件用于写入

    if (file != NULL) {
        fprintf(file, "%s", content); // 将内容写入文件
        fclose(file); // 关闭文件
    } else {
        perror("Error opening file"); // 输出错误信息
    }
}*/



int main() {

    LinkList head;
    InitList(&head);
    ReadListFromFile(&head,"students.txt");// 调用函数读取文件内容
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
        printf("链表数据已写入文件\n");
    }
    
    return 0;
}