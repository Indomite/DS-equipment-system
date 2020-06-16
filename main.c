#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct equipment
{
    char ID[10];            //�豸ID
    char name[20];      //�豸����
    char kind[20];          //�豸����
    char over[50];          //�豸��������
    char scrap[10];         //�豸�Ƿ񱨷�
    char date[50];          //�豸����ʱ��
    char price[10];         //�豸�۸�
};

typedef struct node
{
    struct equipment data;
    struct node *next;
}Node;

void fscanfEquipment(Node *equip)      //���豸��Ϣ�����ļ�
{
    FILE *fp = fopen("equipment.txt","w");
    Node *current = equip->next;
    while(current){
        fprintf(fp,"%s\t",current->data.ID);
        fprintf(fp,"%s\t",current->data.name);
        fprintf(fp,"%s\t",current->data.kind);
        fprintf(fp,"%s\t",current->data.over);
        fprintf(fp,"%s\t",current->data.scrap);
        fprintf(fp,"%s\t",current->data.date);
        if(!current->next)          //�ж��Ƿ�Ϊ���һ�У���->������
            fprintf(fp,"%s",current->data.price);
        else
            fprintf(fp,"%s\t\n",current->data.price);
        current = current->next;
    }
    fclose(fp);
}

Node *fprintfEquipment()            //���豸��Ϣ���ļ������
{
    FILE* fp;
    fp = fopen("equipment.txt","r");
    Node *head = (Node *)malloc(sizeof(Node));
    Node* pre = head;
    while(!feof(fp)){
        Node *newnode = (Node*)malloc(sizeof(Node));
        fscanf(fp,"%s",newnode->data.ID);
        fscanf(fp,"%s",newnode->data.name);
        fscanf(fp,"%s",newnode->data.kind);
        fscanf(fp,"%s",newnode->data.over);
        fscanf(fp,"%s",newnode->data.scrap);
        fscanf(fp,"%s",newnode->data.date);
        fscanf(fp,"%s",newnode->data.price);
        pre->next = newnode;
        pre = newnode;
    }
    pre->next = NULL;
    fclose(fp);
    return head;
}

void addEquipment(Node *equip)          //����豸��¼
{
    Node *p,*r;
    char id[10];            //�����豸��ID
    r = equip;
    while(r->next != NULL)
        r = r->next;
    while(1){
        printf("\n���������豸ID��(����0�򷵻����˵�):\n");
        scanf("%s",id);
        if(strcmp(id,"0") == 0)
            break;
        if(checkID(equip,id)){
            printf("\n>>>>>>>>>>��ʾ:����ı���Ѿ�����,����ʧ��\n\n");
            return;
        }
        p=(Node *)malloc(sizeof(Node));
        strcpy(p->data.ID,id);
        printf("\n�������豸����:");
        scanf("%s",p->data.kind);
        printf("\n�������豸����:");
        scanf("%s",p->data.name);
        printf("\n�������豸�۸�:");
        scanf("%s",p->data.price);
        printf("\n�������豸��������:");
        scanf("%s",&p->data.date);
        printf("\n�豸�Ƿ񱨷�(1=>��;0=>��):");
        scanf("%s",&p->data.scrap);
        printf("\n�豸��������:");
        scanf("%s",&p->data.over);
        p->next = NULL;
        r->next = p;
        r = p;
        fscanfEquipment(equip);
        printf("\n>>>>>>>>>>��ʾ:�ɹ����һ����¼\n\n");
    }
}

void deleteEquipment(Node *equip)       //ɾ���豸��Ϣ
{
    Node *r,*s;
    char id[10];
    r = equip;
    s = r->next;
    if(equip->next == NULL){
        printf("\n>>>>>>>>>>��ʾ:û�����Ͽ���ɾ��\n\n");
        return ;
    }
    printf("\n��������Ҫɾ�����豸ID��(����0�˳�):");
    scanf("%s",id);
    if(strcmp(id,"0") == 0){
        return;
    }
    if(!checkID(equip,id)){
        printf("\n>>>>>>>>>>��ʾ:IDΪ%s���豸������\n\n",id);
        return;
    }
    while(s->next != NULL){
        if(strcmp(s->data.ID,id) == 0){
//                printf("%s",s->data.ID);
            r->next = s->next;
            free(s);
//                printf("%s",r->data.ID);
//                printf("%s",s->data.ID);
                fscanfEquipment(equip);
            printf("\n>>>>>>>>>>��ʾ:�ɹ�ɾ��һ����¼\n");
            return ;
        }
        r = s;
        s = s->next;
    }
}

void updateEquipment(Node *equip)       //�����豸��Ϣ
{
    Node *p;
    char find[20];
    if(equip->next == NULL){
        printf("\n>>>>>>>>>>��ʾ:û�����Ͽ����޸�!\n");
        return ;
    }
    printf("\n������Ҫ�޸ĵ��豸ID��(����0�˳�):");
    scanf("%s",find);
    if(strcmp(find,"0") == 0)
        exit(0);
    p = equip->next;
    while(p != NULL){
        if(strcmp(p->data.ID,find) == 0)
            break;
        p = p->next;
    }
    if(p){
        while(1){
            char x[10];
            printf("���������豸��(ԭ���� %s ):",p->data.ID);
            scanf("%s",x);
            if(checkID(equip,x) && (strcmp(p->data.ID,x))){             //���豸����Ϣ�޸�ʱ������ID��������
                printf("����ı���Ѿ����ڣ�����ʧ��\n");
                return;
            }
            strcpy(p->data.ID,x);
           printf("���������豸����(ԭ���� %s ):",p->data.name);
           scanf("%s",p->data.name);
           printf("���������豸�豸��������(ԭ���� %s ):",p->data.kind);
           scanf("%s",p->data.kind);
           printf("���������豸������������(ԭ���� %s ):",p->data.over);
           scanf("%s",p->data.over);
           printf("���������豸�Ƿ񱨷�(ԭ���� %s ):",p->data.scrap);
           scanf("%s",p->data.scrap);
           printf("���������豸����ʱ��(ԭ���� %s ):",p->data.date);
           scanf("%s",p->data.date);
           printf("���������豸�۸�(ԭ���� %s ):",p->data.price);
           scanf("%s",p->data.price);
           printf("\n>>>>>>>>>>��ʾ:�����¼�����Ѿ��ɹ��޸�!\n");
           fscanfEquipment(equip);
           break;
        }
    }else{
        printf("\n>>>>>>>>>>��ʾ:��Ҫ�޸ĵ���Ϣ������!\n");
    }
}

void printEquipment(Node *equip)
{
    Node *p;
    p = equip->next;
    if(p == NULL){
        printf("\n>>>>>>>>>>��ʾ:û�м�¼������ʾ!\n");
        return;
    }
    printf("\t\t\t\t��ʾ���\n\n");
    printf("�豸��   �豸����   �豸����   ��������   �Ƿ񱨷�   ����ʱ��   �۸�\n");
    while(p){
        printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
    p=p->next;
    }
}

void classifyEquipment(Node *equip)
{
    Node *p;
    int sel;
    int flag2 = 0,ha = 0;
    p = equip->next;
    char find[20];
    if(equip->next == NULL)
    {
        printf("\n>>>>>>>>>>��ʾ:û�����Ͽ���ͳ�Ʒ���!\n");
        return ;
    }
    printf(">>>>>>>>>>��ʾ:\n0=>�˳�\n1=>���豸����ͳ��\n2=>���豸����ͳ��\n");
    scanf("%d",&sel);
    if(sel == 1){
        printf("\n������Ҫͳ�Ʒ�����豸����:");
        scanf("%s",find);
        while(p){
            if(strcmp(p->data.name,find)==0){
                flag2++;
            }
            //�ҵ�������������Ϣ
            if(flag2 == 1 && ha!=flag2){
                printf("�豸��   �豸����   �豸����   ��������   �Ƿ񱨷�   ����ʱ��   �۸�\n");
                printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
                ha = flag2;
            }else if(flag2 > ha){
                printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
                ha = flag2;
            }
            p = p->next;
        }
        if(flag2){
            printf("\n*************************���豸����%sͳ�Ʒ������%d����¼:*************************\n\n",find,flag2);
        }else{
            printf("\n���豸����%sͳ�ƵĽ��Ϊ0��\n\n",find);
        }
    }else if(sel == 2){
        printf("\n������Ҫͳ�Ʒ�����豸����:");
        scanf("%s",find);
        while(p){
            if(strcmp(p->data.kind,find)==0){
                flag2++;
            }
            if(flag2 == 1 && ha!=flag2){
                printf("�豸��   �豸����   �豸����   ��������   �Ƿ񱨷�   ����ʱ��   �۸�\n");
                printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
                ha = flag2;
            }else if(flag2 > ha){
                printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
                ha = flag2;
            }
            p = p->next;
        }
        if(flag2){
            printf("\n*************************���豸����%sͳ�Ʒ������%d����¼:*************************\n\n",find,flag2);
        }else{
            printf("\n���豸����%sͳ�ƵĽ��Ϊ0��\n\n",find);
        }
    }else
        return;
}

int checkID(Node *equip,char* num)         //��ѯID�Ƿ��Ѿ�����
{
    Node *current = equip->next;
    while(current){
        if(strcmp(current->data.ID,num)==0){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void printBlank(int n)          //��ӡָ�������Ŀո�
{
    int i;
    for(i=0;i<=n;i++)
        putchar(' ');
}

void printLine(char c, int n)       //��ӡһ��ָ�����ַ�
{
    int i;
    for(i=0;i<=n;i++)
        putchar(c);
        printf("\n");
}

void title()        //ϵͳ����ҳ��
{
    printBlank(20);printLine('=', 60);printBlank(20);
    printf("��");
    printBlank(17);printf("**ʵ���豸����ϵͳ**");printBlank(18);printf("��\n");
    printBlank(20);printf("��");printBlank(56);printf("��\n");
    printBlank(20);printf("��");printBlank(56);printf("��\n");
    printBlank(20);printf("��");printBlank(31);printf("Author:����  Version:v1.0");printf("��\n");
    printBlank(20);printLine('=', 60);
}

void  meau()        //���˵�
{
    printBlank(20);
    printf("1->���ʵ���豸��Ϣ");
    printBlank(20);
    printf("2->ɾ��ʵ���豸��Ϣ");
    printf("\n");
    printBlank(20);
    printf("3->�޸�ʵ���豸��Ϣ");
    printBlank(20);
    printf("4->��ʾʵ���豸��Ϣ");
    printf("\n");
    printBlank(20);
    printf("5->�豸��Ϣͳ�Ʒ���");
    printBlank(20);
    printf("0->������Ŀ¼");
    printf("\n");
    printf("\n");
}

void main()
{
    Node *equip;
    equip = fprintfEquipment();
    int flag;
    title();
    while(1){
        meau();
        printf("��������Ҫ���������:");
        scanf("%d",&flag);
        switch(flag)
        {
        case 0:
            printf("\n>>>>>>>>>>��ʾ:�Ѿ��˳�ϵͳ,ByeBye!\n");
            exit(0);
        case 1:
            addEquipment(equip);
            break; //���Ӽ�¼
        case 2:
            deleteEquipment(equip);
            break;//ɾ����¼
        case 3:
            updateEquipment(equip);
            break;//�޸ļ�¼
        case 4:
            printEquipment(equip);
            break;//��ʾ��¼��Ϣ
        case 5:
          classifyEquipment(equip);
            break;//ͳ�Ƽ�¼
        default:
            printf("\n>>>>>>>>>>��ʾ:�������!\n");
            break;
        }
    }
}
