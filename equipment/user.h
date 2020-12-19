void printUser(UNode *user)
{
    UNode *p;
    p = user->next;
    if(p == NULL)
    {
        printf("\n>>>>>>>>>>��ʾ:û�м�¼������ʾ!\n");
        return;
    }
    printf("\t\t\t\t��ʾ���\n\n");
    printf("�û�ID   �û���   ����   �û����   \n");
    while(p)
    {
        printf("\n%-9s%-11s%-10s%-15s\n",p->data.id,p->data.username,p->data.password,p->data.identity);
        p=p->next;
    }
}

void printUserInfo(UNode *user)
{
    printf("%s",user);
    UNode *p;
    p = user->next;
    printf("%s",p);
    if(p == NULL)
    {
        printf("\n>>>>>>>>>>��ʾ:û���û���Ϣ!\n");
        return;
    }
    printf("\t\t\t\t��ʾ���\n\n");
    printf("ID��   �û��ǳ�   �û�����   �û�Ȩ��\n");
    while(p)
    {
        printf("\n%-9s%-11s%-10s%-15s%\n",p->data.id,p->data.username,p->data.password,p->data.identity);
        p=p->next;
    }
}

void addUserInfo(UNode *user)          //����豸��¼
{
    UNode *p,*r;
    char id[10];            //�����û���ID
    r = user;
    while(r->next != NULL)
        r = r->next;
    while(1)
    {
        printf("\n�������û�ID(����0�򷵻����˵�):\n");
        scanf("%s",id);
        if(strcmp(id,"0") == 0)
            break;
        p=(UNode *)malloc(sizeof(UNode));
        strcpy(p->data.id,id);
        printf("\n�������û��ǳ�:");
        scanf("%s",p->data.username);
        printf("\n�������û�����:");
        scanf("%s",p->data.password);
        printf("\n�������û����:");
        scanf("%s",p->data.identity);
        p->next = NULL;
        r->next = p;
        r = p;
        write_user_toFile(user);
        printf("\n>>>>>>>>>>��ʾ:�ɹ����һ���û���¼\n\n");
    }
}

void updateUserInfo(UNode *user)       //�����豸��Ϣ
{
    UNode *p;
    char find[20];
    if(user->next == NULL)
    {
        printf("\n>>>>>>>>>>��ʾ:û�����Ͽ����޸�!\n");
        return ;
    }
    printf("\n������Ҫ�޸ĵ��û�ID��(����0�˳�):");
    scanf("%s",find);
    if(strcmp(find,"0") == 0)
        exit(0);
    p = user->next;
    while(p != NULL)
    {
        if(strcmp(p->data.id,find) == 0)
            break;
        p = p->next;
    }
    if(p)
    {
        while(1)
        {
            char x[10];
            printf("���������豸��(ԭ���� %s ):",p->data.id);
            scanf("%s",x);
            strcpy(p->data.id,x);
            printf("�������û��ǳ�(ԭ���� %s ):",p->data.username);
            scanf("%s",p->data.username);
            printf("���������û�����(ԭ���� %s ):",p->data.password);
            scanf("%s",p->data.password);
            write_user_toFile(user);
            break;
        }
    }
    else
    {
        printf("\n>>>>>>>>>>��ʾ:��Ҫ�޸ĵ���Ϣ������!\n");
    }
}


void updateUser_F(UNode *user)       //�����û���Ϣ
{
    UNode *p;
    p = user->next;
    printf(currentUser.data.username);
    while(p != NULL &&(strcmp(currentUser.data.username,p->data.username)!=0))
    {
        p = p->next;
    }

    if(p)
    {
        while(1)
        {
            char x[20];
            printf("���������û�����(ԭ���� %s ):",p->data.username);
            scanf("%s",p->data.username);
            printf("���������û�����(ԭ���� %s ):",p->data.password);
            scanf("%s",p->data.password);
            printf("\n>>>>>>>>>>��ʾ:�����¼�����Ѿ��ɹ��޸�!\n");
           // printUser(user);
            write_user_toFile(user);
            break;
        }
    }
    else
    {
        printf("\n>>>>>>>>>>��ʾ:��Ҫ�޸ĵ���Ϣ������!\n");
    }
}
