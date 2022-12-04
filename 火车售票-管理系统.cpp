#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

//程序设计课程设计作业-计2204-张继尧//

//结构体声明区 
struct node//乘客信息 （在车次信息中被引用） 
{  
	char name[12];         //乘客姓名
    char IDcard[20];        //乘客身份证号码
    int TicketNum;         //订票数
    float FareSum;         //总票价
    struct node *next=NULL;      //指针成员
};

struct Dtime//日期信息 （在车次信息中被引用） 
{  
	short year;
    short month;
    short day;
    short hour;
    short minute;
};

struct train//车次信息 
{  
	char terminal[20];          //终点站
	char sequence[20];         //车次
	struct Dtime StartTime;     //发车时间
	float fare;                //票价
	int SpareTicketNum;       //余票数
	struct node *head;         //指针成员，指向该线路第一个订票乘客
}
	train_list[5][2];


void info()//车次信息赋值
{
	
//--青岛
//-Q101 
	strcpy(train_list[0][0].terminal,"青岛");
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
	strcpy(train_list[0][1].terminal,"青岛");
	strcpy(train_list[0][1].sequence,"Q102");
	train_list[0][1].fare=200; 
	train_list[0][1].SpareTicketNum=300;
	train_list[0][1].StartTime.year=2022;
	train_list[0][1].StartTime.month=12;
	train_list[0][1].StartTime.day=22;
	train_list[0][1].StartTime.hour=11;
	train_list[0][1].StartTime.minute=25;
	train_list[0][1].head=NULL;
//--临沂 
//-L101
	strcpy(train_list[1][0].terminal,"临沂");
	strcpy(train_list[1][0].sequence,"L101");
	train_list[1][0].fare=180; 
	train_list[1][0].SpareTicketNum=300;
	train_list[1][0].StartTime.year=2022;
	train_list[1][0].StartTime.month=12;
	train_list[1][0].StartTime.day=19;
	train_list[1][0].StartTime.hour=07;
	train_list[1][0].StartTime.minute=15;
	train_list[1][0].head=NULL;
//--淄博
//-Z101
	strcpy(train_list[2][0].terminal,"淄博");
	strcpy(train_list[2][0].sequence,"Z101");
	train_list[2][0].fare=210; 
	train_list[2][0].SpareTicketNum=300;
	train_list[2][0].StartTime.year=2022;
	train_list[2][0].StartTime.month=12;
	train_list[2][0].StartTime.day=18;
	train_list[2][0].StartTime.hour=06;
	train_list[2][0].StartTime.minute=30;
	train_list[2][0].head=NULL;
//--东营
//-D101
	strcpy(train_list[3][0].terminal,"东营");
	strcpy(train_list[3][0].sequence,"D101");
	train_list[3][0].fare=195; 
	train_list[3][0].SpareTicketNum=300;
	train_list[3][0].StartTime.year=2022;
	train_list[3][0].StartTime.month=12;
	train_list[3][0].StartTime.day=22;
	train_list[3][0].StartTime.hour=07;
	train_list[3][0].StartTime.minute=15;
	train_list[3][0].head=NULL;
//--聊城
//-L101
	strcpy(train_list[4][0].terminal,"聊城");
	strcpy(train_list[4][0].sequence,"L101");
	train_list[4][0].fare=220; 
	train_list[4][0].SpareTicketNum=300;
	train_list[4][0].StartTime.year=2022;
	train_list[4][0].StartTime.month=12;
	train_list[4][0].StartTime.day=18;
	train_list[4][0].StartTime.hour=06;
	train_list[4][0].StartTime.minute=30;
	train_list[4][0].head=NULL;	

//--聊城
//-L102
	strcpy(train_list[4][1].terminal,"聊城");
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

//函数声明 
int press_key();

//子函数区域
int input_guests_info()//1-4-3 导出乘客信息 Done
{
	system("cls");
	char temp[4];
	int place,code=0,flg=0; 
	printf("*--------------------*\n");
	printf("|请输入需要导出的车次|\n");
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
		printf("输入格式有误！请重新输入\n");
		system("pause");
		input_guests_info();
	}
	
	struct node *ptr;
	ptr=train_list[place][code].head;
	
	while(ptr!=NULL)
	{
		printf("乘客姓名 %s\n",ptr->name);
		printf("身份证号 %s\n",ptr->IDcard);
		printf("订购票数 %d\n",ptr->TicketNum);
		printf("订购总价 %.2lf\n",ptr->FareSum);
		printf("%#####################\n");
		ptr=ptr->next;
	}
	system("pause");
}
int sold_out_search()//1-4-2-查询告罄车次 Done
{
	int i,j,k;
	system("cls");
	printf("当前告罄的车票为：\n");
	printf("*#*#*#*#*#*#*#*#*#*#*#\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<2;j++)
		{
			if(train_list[i][j].SpareTicketNum==0&&(train_list[i][j].head!=NULL))
			{
				printf("%s站 %s车次\n",train_list[i][j].terminal,train_list[i][j].sequence);
			}
		}
	}
	printf("*#*#*#*#*#*#*#*#*#*#*#\n");
	system("pause");
	
}
 
int sequence_search_function()//1-4-1 车次查询 Done
{
	system("cls");
	char temp[4];
	int place,code=0,flg=0; 
	printf("#-----------------------------------#\n");
	printf("|          ***车次查询 ***          |\n");
	printf("|                                   |\n");
	printf("|     请在下方输入您要查询的车次    |\n");
	printf("|             输入T返回             |\n");
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
		printf("输入格式有误！请重新输入\n");
		system("pause");
		sequence_search_function();
	}
	
	system("cls");
	printf("#-----------------------------------#\n");
	printf("|          ***查询结果 ***          |\n");
	printf("|  你查询的车次为%s站%s班次列车 |\n",train_list[place][code].terminal,train_list[place][code].sequence);
	printf("|  发车时间%hd年%hd月%hd日%hd时%hd分   |\n",train_list[place][code].StartTime.year,train_list[place][code].StartTime.month,train_list[place][code].StartTime.day,train_list[place][code].StartTime.hour,train_list[place][code].StartTime.minute);
	printf("|  车票剩余量%3d                    |\n",train_list[place][code].SpareTicketNum);
	printf("|  票价%.2lf                       |\n",train_list[place][code].fare);
	printf("#-----------------------------------#\n");
	
	system("pause");
}
int book_ticket()//1-2-1订票界面（系统） Done
{
	system("cls");
	char temp[4];
	int place,code=0,flg=0; 
	printf("#-----------------------------------#\n");
	printf("|          ***订票界面 ***          |\n");
	printf("|                                   |\n");
	printf("|       请输入您要订购买的车次      |\n");
	printf("|             输入T返回             |\n");
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
		printf("输入格式有误！请重新输入\n");
		system("pause");
		book_ticket();
	}

	int tickets=0;


	loop:	
	if(flg==0)//2-2
	{
		system("cls");
		printf("#----------------------------------------#\n");
		printf("|            ***订票界面 ***             |\n");
		printf("| %s站 %s号班次 剩余%d %.2f元每张 |\n",train_list[place][code].terminal,train_list[place][code].sequence,train_list[place][code].SpareTicketNum,train_list[place][code].fare);
		printf("|         请输入您要订购买的数量         |\n");
		printf("#----------------------------------------#\n");

		scanf("%d",&tickets);
		if(tickets==0)
		{
			return 1;
		}
		if(tickets>train_list[place][code].SpareTicketNum)
		{
			printf("车票余量不足,请重新输入！\n");
			system("pause");
			goto loop;
		}
		
		else
		{
			system("cls");
			printf("#------------------------------------#\n");
			printf("|           ***订票界面 ***          |\n");
			printf("|          %s站 %s号班次         |\n",train_list[place][code].terminal,train_list[place][code].sequence);
			printf("|            订票数量%4d            |\n",tickets);
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
			printf("请输入姓名\n");				
			scanf("%s",ptr->name);
			printf("请输入身份证号\n");
			scanf("%s",ptr->IDcard);
		
		
			printf("成功订票,请支付%.2f元人民币\n",tickets*train_list[place][code].fare);
			ptr->TicketNum=tickets;
			ptr->FareSum=tickets*train_list[place][code].fare;
			ptr->next=NULL;
			system("pause");
			return 1; 
		}
		
	}
}

int return_ticket()//1-3-1退票界面 Done
{
	system("cls");
	char temp[4];
	int place,code=0,flg=0; 
	printf("#-----------------------------------#\n");
	printf("|         +++ 退票界面 +++          |\n");
	printf("|                                   |\n");
	printf("|       请输入您需要退票的车次      |\n");
	printf("|             输入T返回             |\n");
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
		printf("输入格式有误！请重新输入\n");
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
		printf("|          ***退票界面 ***          |\n");
		printf("|   %s站 %s车次 剩余票数%4d    |\n",train_list[place][code].sequence,train_list[place][code].terminal,train_list[place][code].SpareTicketNum);
		printf("#-----------------------------------#\n");
		
		printf("请输入您的身份证号码（输入0退出）\n");
		scanf("%s",tempID);
		if(tempID==0)
		{
			return 1;	
		} 
		p1=train_list[place][code].head;
		
		if(train_list[place][code].head==NULL)//空车 
		{
			system("cls");
			printf("该列车当前无人订票,检查你输入的车次是否正确！");
			system("pause");
			return 1;
		}
		else if(strcmp(tempID,p1->IDcard)==0)//退票的是第一个订票的乘客 
		{
			 flg_srhID=1; 
			
			printf("请输入您的要退订的票数\n");
			scanf("%d",&tempTicksts);
			if(tempTicksts==0)
			{
				return 1;	
			} 
			else if(tempTicksts==(p1->TicketNum))//全退掉 
			{
				system("cls");
				printf("退票成功！您已成功全部退票%d张，退费%.2f元\n",tempTicksts,train_list[place][code].fare*tempTicksts);
				train_list[place][code].head=p1->next;
				free(p1);
				train_list[place][code].SpareTicketNum+=tempTicksts;
				system("pause");
				return 1;
				
			}
			else if(tempTicksts>p1->TicketNum)//没买够 
			{
				system("cls");
				printf("您的退票数量大于您的订票数量！请重新输入\n");
				system("pause");
				goto mark;		
			}
			else if(tempTicksts<p1->TicketNum)//部分退 
			{
				system("cls");
				p1->TicketNum-=tempTicksts;
				train_list[place][code].SpareTicketNum+=tempTicksts;
				printf("退票成功！您已成功退票%d张，退费%.2f元\n",tempTicksts,train_list[place][code].fare*tempTicksts);
				system("pause");
				return 1;
			}
		}

		else if(strcmp(tempID,p1->IDcard)!=0)//不是第一个乘客
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
			printf("请输入您的要退订的票数\n");
			scanf("%d",&tempTicksts);
			if(tempTicksts==0)
			{
				return 1;	
			} 
			else if(tempTicksts==(p2->TicketNum))//全 
			{
				system("cls");
				printf("退票成功！您已成功全部退票%d张，退费%.2f元\n",tempTicksts,train_list[place][code].fare*tempTicksts);
				p1->next=p2->next;
				free(p2);
				train_list[place][code].SpareTicketNum+=tempTicksts;
				system("pause");
				return 1;
				
			}
			else if(tempTicksts>p2->TicketNum)//不够 
			{
				system("cls");
				printf("您的退票数量大于您的订票数量！请重新输入\n");
				system("pause");
				goto mark;		
			}
			else if(tempTicksts<p2->TicketNum)//部分 
			{	
				system("cls");
				p2->TicketNum-=tempTicksts;
				train_list[place][code].SpareTicketNum+=tempTicksts;
				printf("退票成功！您已成功退票%d张，退费%.2f元\n",tempTicksts,train_list[place][code].fare*tempTicksts);
				system("pause");
				return 1;
			}
		}
		
		mark2:
		if(flg_srhID==0)//查无此人 
		{
			system("cls");
			printf("查无此人，请重新输入你的身份证号");
			system("pause");
			goto mark;
		}	
	}
}
int other_search_function()//1-4第二级菜单-其他查询功能 Done
{
	int key;
	system("cls");

	printf("#-----------------------------------#\n");
	printf("| * 输入 1 车次输入查询             |\n");
	printf("| * 输入 2 查询已告罄票             |\n");
	printf("| * 输入 3 导出乘客信息             |\n");
	printf("| * 输入 4 返回上级菜单             |\n");
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

int press_key()//0检测按键并返回数字 Done
{
	char n;
	n=getchar();
	n=n-'0';
	return n;
} 
 
void search_system()//1-1查询界面 Done
{
	char temp;
	system("cls");
	printf("#-----------------------------------#\n");
	printf("|   ##      车次查询界面      ##    |\n");
	printf("|        当前车次有：               |\n");
	printf("| # 青岛站 #  Q101 Q102             |\n");
	printf("| # 临沂站 #  L101                  |\n");
	printf("| # 淄博站 #  Z101                  |\n");
	printf("| # 东营站 #  D101                  |\n");
	printf("| # 聊城站 #  L201 L202             |\n");
	printf("#-----------------------------------#\n");
	system("pause"); 
 
}

int menu_page()//1第一级菜单 Done 
{
	int key;
	printf("#-----------------------------------#\n");
	printf("| * 输入 1 查询当前火车线路         |\n");
	printf("| * 输入 2 打开订票功能             |\n");
	printf("| * 输入 3 打开退票功能             |\n");
	printf("| * 输入 4 打开其他查询功能         |\n");
	printf("| * 输入 5 退出订票系统             |\n");
	printf("#-----------------------------------#\n");
//DONE: 订票 
//DONE: 退票 
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
			printf("感谢您的使用");
			exit(0);	
			break;
			
		return 0;
	}
	
}

//主函数区域 
int main()//主函数，调用菜单 Done
{
	info();
	while(1)
	{
		system("cls");
		menu_page();
	}
	return 0;
} 
