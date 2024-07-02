//
// Created by l1460 on 24-7-2.
//
#include "LinkList.cpp"


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
    //readFile("sysconst.txt"); // 调用函数读取文件内容

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