#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

//������ƿγ������ҵ-��2204-�ż�Ң//

//�ṹ�������� 
struct node//�˿���Ϣ ���ڳ�����Ϣ�б����ã� 
{  
	char name[12];         //�˿�����
    char IDcard[20];        //�˿����֤����
    int TicketNum;         //��Ʊ��
    float FareSum;         //��Ʊ��
    struct node *next=NULL;      //ָ���Ա
};

struct Dtime//������Ϣ ���ڳ�����Ϣ�б����ã� 
{  
	short year;
    short month;
    short day;
    short hour;
    short minute;
};

struct train//������Ϣ 
{  
	char terminal[20];          //�յ�վ
	char sequence[20];         //����
	struct Dtime StartTime;     //����ʱ��
	float fare;                //Ʊ��
	int SpareTicketNum;       //��Ʊ��
	struct node *head;         //ָ���Ա��ָ�����·��һ����Ʊ�˿�
}
	train_list[5][2];


void info()//������Ϣ��ֵ
{
	
//--�ൺ
//-Q101 
	strcpy(train_list[0][0].terminal,"�ൺ");
	strcpy(train_list[0][0].sequence,"Q101");
	train_list[0][0].fare=200; 
	train_list[0][0].SpareTicketNum=300;
	train_list[0][0].StartTime.year=2022;
	train_list[0][0].StartTime.month=12;
	train_list[0][0].StartTime.day=20;
	train_list[0][0].StartTime.hour=10;
	train_list[0][0].StartTime.minute=30;
	train_list[0][0].head=NULL;
//-Q102
	strcpy(train_list[0][1].terminal,"�ൺ");
	strcpy(train_list[0][1].sequence,"Q102");
	train_list[0][1].fare=200; 
	train_list[0][1].SpareTicketNum=300;
	train_list[0][1].StartTime.year=2022;
	train_list[0][1].StartTime.month=12;
	train_list[0][1].StartTime.day=22;
	train_list[0][1].StartTime.hour=11;
	train_list[0][1].StartTime.minute=25;
	train_list[0][1].head=NULL;
//--���� 
//-L101
	strcpy(train_list[1][0].terminal,"����");
	strcpy(train_list[1][0].sequence,"L101");
	train_list[1][0].fare=180; 
	train_list[1][0].SpareTicketNum=300;
	train_list[1][0].StartTime.year=2022;
	train_list[1][0].StartTime.month=12;
	train_list[1][0].StartTime.day=19;
	train_list[1][0].StartTime.hour=07;
	train_list[1][0].StartTime.minute=15;
	train_list[1][0].head=NULL;
//--�Ͳ�
//-Z101
	strcpy(train_list[2][0].terminal,"�Ͳ�");
	strcpy(train_list[2][0].sequence,"Z101");
	train_list[2][0].fare=210; 
	train_list[2][0].SpareTicketNum=300;
	train_list[2][0].StartTime.year=2022;
	train_list[2][0].StartTime.month=12;
	train_list[2][0].StartTime.day=18;
	train_list[2][0].StartTime.hour=06;
	train_list[2][0].StartTime.minute=30;
	train_list[2][0].head=NULL;
//--��Ӫ
//-D101
	strcpy(train_list[3][0].terminal,"��Ӫ");
	strcpy(train_list[3][0].sequence,"D101");
	train_list[3][0].fare=195; 
	train_list[3][0].SpareTicketNum=300;
	train_list[3][0].StartTime.year=2022;
	train_list[3][0].StartTime.month=12;
	train_list[3][0].StartTime.day=22;
	train_list[3][0].StartTime.hour=07;
	train_list[3][0].StartTime.minute=15;
	train_list[3][0].head=NULL;
//--�ĳ�
//-L101
	strcpy(train_list[4][0].terminal,"�ĳ�");
	strcpy(train_list[4][0].sequence,"L101");
	train_list[4][0].fare=220; 
	train_list[4][0].SpareTicketNum=300;
	train_list[4][0].StartTime.year=2022;
	train_list[4][0].StartTime.month=12;
	train_list[4][0].StartTime.day=18;
	train_list[4][0].StartTime.hour=06;
	train_list[4][0].StartTime.minute=30;
	train_list[4][0].head=NULL;	

//--�ĳ�
//-L102
	strcpy(train_list[4][1].terminal,"�ĳ�");
	strcpy(train_list[4][1].sequence,"L102");
	train_list[4][1].fare=220; 
	train_list[4][1].SpareTicketNum=300;
	train_list[4][1].StartTime.year=2022;
	train_list[4][1].StartTime.month=12;
	train_list[4][1].StartTime.day=18;
	train_list[4][1].StartTime.hour=07;
	train_list[4][1].StartTime.minute=40;
	train_list[4][1].head=NULL;	
}

//�������� 
int press_key();

//�Ӻ�������
int input_guests_info()//1-4-3 �����˿���Ϣ Done
{
	system("cls");
	char temp[4];
	int place,code=0,flg=0; 
	printf("*--------------------*\n");
	printf("|��������Ҫ�����ĳ���|\n");
	printf("*--------------------*\n");	
	scanf("%s",temp);
	if(temp[0]=='Q') 
	{
		place=0;
		code=(int)(temp[3]-'1');
	}
	
	else if(temp[0]=='L'&&temp[1]=='1')
	{
		place=1;
	}
	
	else if(temp[0]=='Z')
	{
		place=2;
	}
	
	else if(temp[0]=='D')
	{
		place=3;
	}
	
	else if(temp[0]=='L'&&temp[1]=='2')
	{
		place=4;
		code=(int)(temp[3]-'1');
	}
	else if(temp[0]=='T')
	{
		return 1; 
	}
	else
	{
		flg=1;
		printf("�����ʽ��������������\n");
		system("pause");
		input_guests_info();
	}
	
	struct node *ptr;
	ptr=train_list[place][code].head;
	
	while(ptr!=NULL)
	{
		printf("�˿����� %s\n",ptr->name);
		printf("���֤�� %s\n",ptr->IDcard);
		printf("����Ʊ�� %d\n",ptr->TicketNum);
		printf("�����ܼ� %.2lf\n",ptr->FareSum);
		printf("%#####################\n");
		ptr=ptr->next;
	}
	system("pause");
}
int sold_out_search()//1-4-2-��ѯ�������� Done
{
	int i,j,k;
	system("cls");
	printf("��ǰ�����ĳ�ƱΪ��\n");
	printf("*#*#*#*#*#*#*#*#*#*#*#\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<2;j++)
		{
			if(train_list[i][j].SpareTicketNum==0&&(train_list[i][j].head!=NULL))
			{
				printf("%sվ %s����\n",train_list[i][j].terminal,train_list[i][j].sequence);
			}
		}
	}
	printf("*#*#*#*#*#*#*#*#*#*#*#\n");
	system("pause");
	
}
 
int sequence_search_function()//1-4-1 ���β�ѯ Done
{
	system("cls");
	char temp[4];
	int place,code=0,flg=0; 
	printf("#-----------------------------------#\n");
	printf("|          ***���β�ѯ ***          |\n");
	printf("|                                   |\n");
	printf("|     �����·�������Ҫ��ѯ�ĳ���    |\n");
	printf("|             ����T����             |\n");
	printf("#-----------------------------------#\n");
	scanf("%s",temp);
	if(temp[0]=='Q')
	{
		place=0;
		code=(int)(temp[3]-'1');
	}
	
	else if(temp[0]=='L'&&temp[1]=='1')
	{
		place=1;
	}
	
	else if(temp[0]=='Z')
	{
		place=2;
	}
	
	else if(temp[0]=='D')
	{
		place=3;
	}
	
	else if(temp[0]=='L'&&temp[1]=='2')
	{
		place=4;
		code=(int)(temp[3]-'1');
	}
	else if(temp[0]=='T')
	{
		return 1; 
	}
	else
	{
		flg=1;
		printf("�����ʽ��������������\n");
		system("pause");
		sequence_search_function();
	}
	
	system("cls");
	printf("#-----------------------------------#\n");
	printf("|          ***��ѯ��� ***          |\n");
	printf("|  ���ѯ�ĳ���Ϊ%sվ%s����г� |\n",train_list[place][code].terminal,train_list[place][code].sequence);
	printf("|  ����ʱ��%hd��%hd��%hd��%hdʱ%hd��   |\n",train_list[place][code].StartTime.year,train_list[place][code].StartTime.month,train_list[place][code].StartTime.day,train_list[place][code].StartTime.hour,train_list[place][code].StartTime.minute);
	printf("|  ��Ʊʣ����%3d                    |\n",train_list[place][code].SpareTicketNum);
	printf("|  Ʊ��%.2lf                       |\n",train_list[place][code].fare);
	printf("#-----------------------------------#\n");
	
	system("pause");
}
int book_ticket()//1-2-1��Ʊ���棨ϵͳ�� Done
{
	system("cls");
	char temp[4];
	int place,code=0,flg=0; 
	printf("#-----------------------------------#\n");
	printf("|          ***��Ʊ���� ***          |\n");
	printf("|                                   |\n");
	printf("|       ��������Ҫ������ĳ���      |\n");
	printf("|             ����T����             |\n");
	printf("#-----------------------------------#\n");
	scanf("%s",temp);
	if(temp[0]=='Q')
	{
		place=0;
		code=(int)(temp[3]-'1');
	}
	
	else if(temp[0]=='L'&&temp[1]=='1')
	{
		place=1;
	}
	
	else if(temp[0]=='Z')
	{
		place=2;
	}
	
	else if(temp[0]=='D')
	{
		place=3;
	}
	
	else if(temp[0]=='L'&&temp[1]=='2')
	{
		place=4;
		code=(int)(temp[3]-'1');
	}
	else if(temp[0]=='T')
	{
		return 1; 
	}
	else
	{
		flg=1;
		printf("�����ʽ��������������\n");
		system("pause");
		book_ticket();
	}

	int tickets=0;


	loop:	
	if(flg==0)//2-2
	{
		system("cls");
		printf("#----------------------------------------#\n");
		printf("|            ***��Ʊ���� ***             |\n");
		printf("| %sվ %s�Ű�� ʣ��%d %.2fԪÿ�� |\n",train_list[place][code].terminal,train_list[place][code].sequence,train_list[place][code].SpareTicketNum,train_list[place][code].fare);
		printf("|         ��������Ҫ�����������         |\n");
		printf("#----------------------------------------#\n");

		scanf("%d",&tickets);
		if(tickets==0)
		{
			return 1;
		}
		if(tickets>train_list[place][code].SpareTicketNum)
		{
			printf("��Ʊ��������,���������룡\n");
			system("pause");
			goto loop;
		}
		
		else
		{
			system("cls");
			printf("#------------------------------------#\n");
			printf("|           ***��Ʊ���� ***          |\n");
			printf("|          %sվ %s�Ű��         |\n",train_list[place][code].terminal,train_list[place][code].sequence);
			printf("|            ��Ʊ����%4d            |\n",tickets);
			printf("#------------------------------------#\n");
			
			struct node *ptr,*p_r1,*p_r2;
			ptr=(struct node*)malloc(sizeof(struct node));
			
			if(train_list[place][code].head==NULL)
			{
				train_list[place][code].head=ptr;
			}
			else
			{
				p_r1=train_list[place][code].head;
				while(p_r1->next!=NULL)
				{
					p_r1=p_r1->next;				
				}
				p_r1->next=ptr;
			}
			
			train_list[place][code].SpareTicketNum-=tickets;
			printf("����������\n");				
			scanf("%s",ptr->name);
			printf("���������֤��\n");
			scanf("%s",ptr->IDcard);
		
		
			printf("�ɹ���Ʊ,��֧��%.2fԪ�����\n",tickets*train_list[place][code].fare);
			ptr->TicketNum=tickets;
			ptr->FareSum=tickets*train_list[place][code].fare;
			ptr->next=NULL;
			system("pause");
			return 1; 
		}
		
	}
}

int return_ticket()//1-3-1��Ʊ���� Done
{
	system("cls");
	char temp[4];
	int place,code=0,flg=0; 
	printf("#-----------------------------------#\n");
	printf("|         +++ ��Ʊ���� +++          |\n");
	printf("|                                   |\n");
	printf("|       ����������Ҫ��Ʊ�ĳ���      |\n");
	printf("|             ����T����             |\n");
	printf("#-----------------------------------#\n");
	scanf("%s",temp);
	if(temp[0]=='Q')
	{
		place=0;
		code=(int)(temp[3]-'1');
	}
	
	else if(temp[0]=='L'&&temp[1]=='1')
	{
		place=1;
	}
	
	else if(temp[0]=='Z')
	{
		place=2;
	}
	
	else if(temp[0]=='D')
	{
		place=3;
	}
	
	else if(temp[0]=='L'&&temp[1]=='2')
	{
		place=4;
		code=(int)(temp[3]-'1');
	}
	else if(temp[0]=='T')
	{
		return 1; 
	}
	
	else
	{
		flg=1;
		printf("�����ʽ��������������\n");
		system("pause");
		return_ticket();
	}
	
	bool flg_srhID=0;
	int tempTicksts;
	char tempID[20];
	struct node *ptr,*p1,*p2;
	
	mark:

	if(flg==0)//1-3-2
	{
		system("cls");
		printf("#-----------------------------------#\n");
		printf("|          ***��Ʊ���� ***          |\n");
		printf("|   %sվ %s���� ʣ��Ʊ��%4d    |\n",train_list[place][code].sequence,train_list[place][code].terminal,train_list[place][code].SpareTicketNum);
		printf("#-----------------------------------#\n");
		
		printf("�������������֤���루����0�˳���\n");
		scanf("%s",tempID);
		if(tempID==0)
		{
			return 1;	
		} 
		p1=train_list[place][code].head;
		
		if(train_list[place][code].head==NULL)//�ճ� 
		{
			system("cls");
			printf("���г���ǰ���˶�Ʊ,���������ĳ����Ƿ���ȷ��");
			system("pause");
			return 1;
		}
		else if(strcmp(tempID,p1->IDcard)==0)//��Ʊ���ǵ�һ����Ʊ�ĳ˿� 
		{
			 flg_srhID=1; 
			
			printf("����������Ҫ�˶���Ʊ��\n");
			scanf("%d",&tempTicksts);
			if(tempTicksts==0)
			{
				return 1;	
			} 
			else if(tempTicksts==(p1->TicketNum))//ȫ�˵� 
			{
				system("cls");
				printf("��Ʊ�ɹ������ѳɹ�ȫ����Ʊ%d�ţ��˷�%.2fԪ\n",tempTicksts,train_list[place][code].fare*tempTicksts);
				train_list[place][code].head=p1->next;
				free(p1);
				train_list[place][code].SpareTicketNum+=tempTicksts;
				system("pause");
				return 1;
				
			}
			else if(tempTicksts>p1->TicketNum)//û�� 
			{
				system("cls");
				printf("������Ʊ�����������Ķ�Ʊ����������������\n");
				system("pause");
				goto mark;		
			}
			else if(tempTicksts<p1->TicketNum)//������ 
			{
				system("cls");
				p1->TicketNum-=tempTicksts;
				train_list[place][code].SpareTicketNum+=tempTicksts;
				printf("��Ʊ�ɹ������ѳɹ���Ʊ%d�ţ��˷�%.2fԪ\n",tempTicksts,train_list[place][code].fare*tempTicksts);
				system("pause");
				return 1;
			}
		}

		else if(strcmp(tempID,p1->IDcard)!=0)//���ǵ�һ���˿�
		{
			
			p2=p1;
			while(strcmp(tempID,p2->IDcard)!=0)
			{
				p1=p2;
				p2=p1->next;
				if(p2==NULL)
				{
					goto mark2;
				}
			}
			flg_srhID=1;
			printf("����������Ҫ�˶���Ʊ��\n");
			scanf("%d",&tempTicksts);
			if(tempTicksts==0)
			{
				return 1;	
			} 
			else if(tempTicksts==(p2->TicketNum))//ȫ 
			{
				system("cls");
				printf("��Ʊ�ɹ������ѳɹ�ȫ����Ʊ%d�ţ��˷�%.2fԪ\n",tempTicksts,train_list[place][code].fare*tempTicksts);
				p1->next=p2->next;
				free(p2);
				train_list[place][code].SpareTicketNum+=tempTicksts;
				system("pause");
				return 1;
				
			}
			else if(tempTicksts>p2->TicketNum)//���� 
			{
				system("cls");
				printf("������Ʊ�����������Ķ�Ʊ����������������\n");
				system("pause");
				goto mark;		
			}
			else if(tempTicksts<p2->TicketNum)//���� 
			{	
				system("cls");
				p2->TicketNum-=tempTicksts;
				train_list[place][code].SpareTicketNum+=tempTicksts;
				printf("��Ʊ�ɹ������ѳɹ���Ʊ%d�ţ��˷�%.2fԪ\n",tempTicksts,train_list[place][code].fare*tempTicksts);
				system("pause");
				return 1;
			}
		}
		
		mark2:
		if(flg_srhID==0)//���޴��� 
		{
			system("cls");
			printf("���޴��ˣ�����������������֤��");
			system("pause");
			goto mark;
		}	
	}
}
int other_search_function()//1-4�ڶ����˵�-������ѯ���� Done
{
	int key;
	system("cls");

	printf("#-----------------------------------#\n");
	printf("| * ���� 1 ���������ѯ             |\n");
	printf("| * ���� 2 ��ѯ�Ѹ���Ʊ             |\n");
	printf("| * ���� 3 �����˿���Ϣ             |\n");
	printf("| * ���� 4 �����ϼ��˵�             |\n");
	printf("#-----------------------------------#\n");

	key=press_key();

	switch(key)
	{
		case 1:
			while(sequence_search_function()==1)
			{
				break;
			}
			break;
		case 2:
			sold_out_search();
			break;
		case 3:
			input_guests_info();
			break;
		case 4:
			return 1;
			break;
	}
	
}

int press_key()//0��ⰴ������������ Done
{
	char n;
	n=getchar();
	n=n-'0';
	return n;
} 
 
void search_system()//1-1��ѯ���� Done
{
	char temp;
	system("cls");
	printf("#-----------------------------------#\n");
	printf("|   ##      ���β�ѯ����      ##    |\n");
	printf("|        ��ǰ�����У�               |\n");
	printf("| # �ൺվ #  Q101 Q102             |\n");
	printf("| # ����վ #  L101                  |\n");
	printf("| # �Ͳ�վ #  Z101                  |\n");
	printf("| # ��Ӫվ #  D101                  |\n");
	printf("| # �ĳ�վ #  L201 L202             |\n");
	printf("#-----------------------------------#\n");
	system("pause"); 
 
}

int menu_page()//1��һ���˵� Done 
{
	int key;
	printf("#-----------------------------------#\n");
	printf("| * ���� 1 ��ѯ��ǰ����·         |\n");
	printf("| * ���� 2 �򿪶�Ʊ����             |\n");
	printf("| * ���� 3 ����Ʊ����             |\n");
	printf("| * ���� 4 ��������ѯ����         |\n");
	printf("| * ���� 5 �˳���Ʊϵͳ             |\n");
	printf("#-----------------------------------#\n");
//DONE: ��Ʊ 
//DONE: ��Ʊ 
	key=press_key();
	
	switch(key)
	{
		case 1:
			search_system();
			break;
			
		case 2:
			while(1)
			{
				if(book_ticket()==1)
				{
					break;
				}
			}
			break;
			
		case 3:
			while(1)
			{
				if(return_ticket()==1)
				{
					break;
				}
			}
			break;
			
		case 4:
			while(1)
			{
				if(other_search_function()==1)
				{
					break;	
				} 
			}
			break;
			
		case 5:
			printf("��л����ʹ��");
			exit(0);	
			break;
			
		return 0;
	}
	
}

//���������� 
int main()//�����������ò˵� Done
{
	info();
	while(1)
	{
		system("cls");
		menu_page();
	}
	return 0;
} 
