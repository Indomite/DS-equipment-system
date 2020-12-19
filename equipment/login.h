/* ����һ��Ԫ�� */
UNode *Logincheck(UNode *user,char* userName, char* passWord)
{
    UNode *ptr;
    ptr = user->next;
    if (ptr == NULL)
    {
        printf("�û�����Ϊ�գ�\n");
        return NULL;
    }

    while (ptr != NULL && (strcmp(userName,ptr->data.username)!=0))
    {
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        if(strcmp(passWord,ptr->data.password)==0)
        {
            printf("                     ��¼�ɹ�����ӭ����\n\n");
            strcpy(currentUser.data.id,ptr->data.id);
            strcpy(currentUser.data.username,ptr->data.username);
            strcpy(currentUser.data.password,ptr->data.password);
            strcpy(currentUser.data.identity,ptr->data.identity);
            currentUserP = ptr;
            return ptr;
        }
        else
        {
            printf("                     �������\n");
            return NULL;
        }
    }
    else
    {
        printf("�û��������ڣ�\n");
    }
    return ptr;
}

int Login()
{
    UNode *userlist;
    userlist = read_user_fromFile();
    char userName[20];/*�û���*/
    char userPassword[20];/*����*/
    int i,sum;
    system("color 0B");//���ڵ�������̨��ɫ
    for(i=0; i<5; i++)
    {
        printf("\n                     �����������û���:");
        gets(userName);
        printf("\n                     ��������������:");
        gets(userPassword);
        UNode *current_User = Logincheck(userlist,userName, userPassword);
        if(current_User)
        {
            strcpy(currentUser.data.identity, current_User->data.identity);
            return 0;
        }
        else
        {
            if (i < 2)
            {
                printf("                     ����������!");//��ʾ�û���������
            }
            else
            {
                printf("��������3�����Ͻ��û������������ϵͳ���˳�!");//����3����������û��������룬�˳�ϵͳ��
                exit(1);
            }
        }
    }
}

void user_work_station()
{
    UNode *user;
    user = read_user_fromFile();
    ENode *equip;
    equip = fprintfEquipment();
    int flag;
    while(1)
    {
        user_work_meau();
        printf("��������Ҫ���������:");
        scanf("%d",&flag);
        switch(flag)
        {
        case 0:
            printf("\n>>>>>>>>>>��ʾ:�Ѿ��˳�ϵͳ,ByeBye!\n");
            exit(0);
        case 1:
            classifyEquipment(equip);
            break; //���Ӽ�¼
        case 2:
            printEquipment(equip);
            break;//ɾ����¼
        case 3:
            updateUser_F(user);
            break;//�޸ļ�¼
        default:
            printf("\n>>>>>>>>>>��ʾ:�������!\n");
            break;
        }
    }
}

void admin_work_station()
{
    UNode *user;
    user = read_user_fromFile();
    ENode *equip;
    equip = fprintfEquipment();
    int flag;
    while(1)
    {
        admin_work_meau();
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
        case 6:
            printUserInfo(user);
            break;//ͳ�Ƽ�¼
        case 7:
            addUserInfo(user);
            break;//ͳ�Ƽ�¼
        case 8:
            updateUserInfo(user);
            break;//ͳ�Ƽ�¼
        case 9:
            classifyEquipment(equip);
            break;//ͳ�Ƽ�¼
        default:
            printf("\n>>>>>>>>>>��ʾ:�������!\n");
            break;
        }
    }
}
