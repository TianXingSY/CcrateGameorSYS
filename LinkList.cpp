//
// Created by l1460 on 2024/3/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[20];
    int stunum;
    float score;
}stu;
typedef stu Elemtype;


typedef struct node{
    Elemtype data;
    struct node *next;
}Node,*LinkList;



int InitList(LinkList *L){
    *L=(LinkList)malloc(sizeof(Node));
    if(L==NULL){
        printf("内存申请失败\n");
        return(0);
    }
    else{
        (*L)->next=NULL;
        return(1);
    }
}

int CreateFromTailWithoutInput(LinkList L){
    Node *r,*s;
    int flag=1;
    r=L;
    Elemtype c;
    stu teststu[50];
    teststu[0].stunum=1;
    teststu[0].score=99;
    strcpy(teststu[0].name,"李华");

    teststu[1].stunum=2;
    teststu[1].score=66;
    strcpy(teststu[1].name,"张三");

    teststu[2].stunum=3;
    teststu[2].score=88;
    strcpy(teststu[2].name,"王五");

    teststu[3].stunum=4;
    teststu[3].score=77;
    strcpy(teststu[3].name,"赵六");

    teststu[4].stunum=5;
    teststu[4].score=55;
    strcpy(teststu[4].name,"钱七");

    teststu[5].stunum=0;

    int k=0;
    while(flag){
        memmove(&c,&teststu[k],sizeof(Elemtype));
        if(c.stunum != 0 && c.score != -1 && strcmp(c.name, "") !=  0){
            s=(Node*)malloc(sizeof(Node));
            s->data.stunum=c.stunum;
            s->data.score=c.score;
            strcpy(s->data.name,c.name);
            r->next=s;
            r=s;
        }
        else{
            flag=0;
            r->next=NULL;
        }
        k++;
    }
    return(0);
}
int CreateFromTail(LinkList L){
    Node *r,*s;
    int flag=1;
    r=L;
    Elemtype c;
    while(flag){
        printf("请输入名字：");
        scanf("%s",&c.name);
        printf("请输入学号：");
        scanf("%d",&c.stunum);
        printf("请输入成绩：");
        scanf("%f",&c.score);
        if(c.stunum!=0 && c.score!=-1 && strcmp(c.name, "") != 0){
            s=(Node*)malloc(sizeof(Node));
            s->data.stunum=c.stunum;
            s->data.score=c.score;
            strcpy(s->data.name,c.name);
            r->next=s;
            r=s;
        }
        else{
            flag=0;
            r->next=NULL;
        }
    }
    return(0);
}

int linkLen(LinkList L){
    LinkList r;
    int i=0;
    r=L->next;
    while(r!=NULL){
        i++;
        r=r->next;
    }
    return(i);
}


int DelLL(LinkList L,int e,stu *a){
    if(e<1|| e>linkLen(L)){
        printf("输入非法\n");
    }

    int i;
    LinkList r,s;
    r=L->next;
    for(i=1;i<e+1;i++){
        printf("%d ",i);
        if(e==1){
            s=L->next;
            L->next=L->next->next;
            free(s);
            return(1);
        }
        if(i==e-1){
            s=r;
        }
        else if(i==e){
            s->next=r->next;
            printf("%d. ",i);
            printf("%s %d %.1f\n",r->data.name,r->data.stunum,r->data.score);
            //memmove(a, &r->data, sizeof(stu));
            a->stunum=r->data.stunum;
            a->score=r->data.score;
            strcpy(a->name,r->data.name);
            printf("%d。 ",i);
            free(r);

            printf("删除成功\n");
            return(1);
        }

        r=r->next;
    }
}

int InsertLL(LinkList L,int e,stu a){
    if(e<1){
        printf("输入非法\n");
    }

    int i;
    LinkList r=L->next,s,In;
    In=(Node*)malloc(sizeof(Node));

    memmove(&In->data, &a, sizeof(stu));
    for(i=0;i<e;i++){
        if(e==1){
            In->next=L->next;
            L->next=In;
            return(1);
        }
        if(i==e-2){
            s=r;
        }
        else if(i==e-1){
            s->next=In;
            In->next=r;
            return(1);
        }
        if(r==NULL){
            printf("插入位置不存在\n");
            return(0);
        }
        else if(r->next==NULL && i==e-2){
            r->next=In;
            In->next=NULL;
            return(0);
        }
        r=r->next;
    }
}

int bianli(LinkList L){
    LinkList r;
    r=L->next;
    printf("\n");
    while(r!=NULL){
        printf("%s %d:%f \n",r->data.name,r->data.stunum,r->data.score);
        r=r->next;
    }
    printf("\n");
    return(0);
}

int Findstunum(LinkList L,int x){
    LinkList r;
    int i=0;
    r=L->next;
    while(r!=NULL){
        if(r->data.stunum==x){
            return(i+1);
        }
        r=r->next;
        i++;
    }
    printf("数据不存在\n");
    return(0);
}
