void printBlank(int n)          //��ӡָ�������Ŀո�
{
    int i;
    for(i=0; i<=n; i++)
        putchar(' ');
}

void printLine(char c, int n)       //��ӡһ��ָ�����ַ�
{
    int i;
    for(i=0; i<=n; i++)
        putchar(c);
    printf("\n");
}

void title()        //ϵͳ����ҳ��
{
    printBlank(20);
    printLine('=', 60);
    printBlank(20);
    printf("��");
    printBlank(17);
    printBlank(38);
    printf("��\n");
    printBlank(20);
    printf("��");
    printBlank(20);
      printf("**ʵ���豸����ϵͳ**");
    printBlank(15);
    printf("��\n");
    printBlank(20);
    printf("��");
    printBlank(56);
    printf("��\n");
    printBlank(20);
    printLine('=', 60);
}

void work_meau()
{
    if(strcmp(currentUser.data.identity,"user")==0)
    {
        user_work_station();
    }
    else if(strcmp(currentUser.data.identity,"admin")==0)
    {
        admin_work_station();
    }
}

void  user_work_meau()        //�û����˵�
{
    printBlank(20);
    printf("1->�豸����ͳ��");
    printBlank(20);
    printf("2->�豸��ѯ��ʾ");
    printf("\n");
    printBlank(20);
    printf("3->������Ϣ����");
    printBlank(20);
    printf("0->�˳�");
    printf("\n");
    printf("\n");
}

void  admin_work_meau()        //����Ա���˵�
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
   // printf("\n");
    printBlank(20);
    printf("6->��ʾ�û���Ϣ");
    printBlank(24);
     printf("\n");
     printBlank(20);
    printf("7->�����û���Ϣ");
   // printf("\n");
    printBlank(24);
    printf("8->�޸��û���Ϣ");
    printf("\n");
    printBlank(20);
    printf("0->�˳�");
    printf("\n");
    printf("\n");
}
