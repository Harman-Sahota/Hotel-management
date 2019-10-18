#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

class hotel
{
public:
    int room_no;
    char name[30];
    char address[50];
    char phone[10];
    char *feedbck;


    void main_menu();    //to dispay the main menu
    void add();        //to book a room
    void display();    //to display the customer record
    void rooms();    //to display alloted rooms
    void edit();    //to edit the customer record
    int check(int);    //to check room status
    void modify(int);    //to modify the record
    void delete_rec(int);    //to delete the record
}h;

void hotel::main_menu()
{
    int choice;

    while(choice!=5)
    {
	clrscr();
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\t\t\t\t* MAIN MENU *";
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\n\n\t\t\t1.Book A Room";
	cout<<"\n\t\t\t2.Customer Record";
	cout<<"\n\t\t\t3.feedback";
	cout<<"\n\t\t\t4.Edit Record";
	cout<<"\n\t\t\t5.Exit";
	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>choice;

	switch(choice)
	{
	    case 1: add();
		    break;
	    case 2: display();
		    break;
	    case 3: rooms();
		    break;
	    case 4: edit();
		    break;
	    case 5: break;
	    default:
		    {
			cout<<"\n\n\t\t\tWrong choice!!!";
			exit(0);
		    }
	}
    }
}

void hotel::add()
{
    clrscr();
    int r,flag;
    ofstream fout("Records.dat",ios::app);

    cout<<"\n Enter Customer Detalis";
    cout<<"\n **********************";
    cout<<"\n\n Room no: ";
    cin>>room_no;
    if(room_no!=check(r))
    {
	cout<<" Name: ";
	gets(name);
	cout<<" Address: ";
	gets(address);
	cout<<" Phone No: ";
	gets(phone);
	fout.write((char*)&h,sizeof(h));
	cout<<"\n Room is booked!!!";
	}
	 else
	 cout<<"room is booked !!!";

    cout<<"\n Press any key to continue!!";
    getch();
    fout.close();
}

void hotel::display()
{
    clrscr();
    ifstream fin("Records.dat",ios::in);
    int r,flag;
    cout<<"\n Enter room no: ";
    cin>>r;

    while(!fin.eof())
    {
	fin.read((char*)&h,sizeof(h));
	if(room_no==r)
	{
	    clrscr();
	    cout<<"\n Customer Details";
	    cout<<"\n ****************";
	    cout<<"\n\n Room no: "<<room_no;
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<" \n Phone no: "<<phone;
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";

    cout<<"\n\n Press any key to continue!!";
    getch();
    fin.close();
}

void hotel::rooms()
{
    clrscr();
    ofstream fin("feedbck.txt",ios::app);
    cout<<"\n\t\t\tFeedback";
    cout<<"\n\t\t\t*********";
    cout<<"\n\n please enter your feedback !!"<<endl<<endl;
     cin>>h.feedbck;
	fin.write((char*)&h,sizeof(h));



    cout<<"\n\n\n\t\t\tPress any key to continue!!";
    getch();
    fin.close();
}

void hotel::edit()
{
    clrscr();
    int choice,r;

    cout<<"\n EDIT MENU";
    cout<<"\n *********";
    cout<<"\n\n 1.Modify Customer Record";
    cout<<"\n 2.Delete Customer Record";

    cout<<"\n Enter your choice: ";
    cin>>choice;

    clrscr();
    cout<<"\n Enter room no: ";
    cin>>r;

    switch(choice)
    {
	case 1: modify(r);
		break;
	case 2: delete_rec(r);
		break;
	default: cout<<"\n Wrong Choice!!";
    }

    cout<<"\n Press any key to continue!!!";
    getch();
}

int hotel::check(int r)
{
    int flag=0;
    ifstream fin("Records.dat",ios::in);
    while(!fin.eof())
    {
	fin.read((char*)&h,sizeof(h));
	if(room_no==r)
	{
	    flag=1;
		break;
	}
    }

    fin.close();
    return(flag);
}

void hotel::modify(int r)
{
    long pos,flag=0;
    fstream file("Records.dat",ios::in|ios::out|ios::binary);

    while(!file.eof())
    {
	pos=file.tellg();
	file.read((char*)&h,sizeof(h));
	if(room_no==r)
	{
	    cout<<"\n Enter New Details";
	    cout<<"\n *****************";
	    cout<<"\n Name: ";
	    gets(name);
	    cout<<" Address: ";
	    gets(address);
	    cout<<" Phone no: ";
	    gets(phone);

	    file.seekg(pos);
	    file.write((char*)&h,sizeof(h));
	    cout<<"\n Record is modified!!";
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant!!";

    file.close();
}

void hotel::delete_rec(int r)
{
    int flag=0;
    char ch;
    ifstream fin("Records.dat",ios::in);
    ofstream fout("tempo.dat",ios::out);

    while(!fin.eof())
    {
	fin.read((char*)&h,sizeof(h));
	if(room_no==r)
	{
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone No.: "<<phone;
	    cout<<"\n\n Do you want to delete this record(y/n): ";
	    cin>>ch;

	    if(ch=='n')
	    fout.write((char*)&h,sizeof(h));

	    flag=1;
	}
	else
	    fout.write((char*)&h,sizeof(h));
    }

    fin.close();
    fout.close();

    if(flag==0)
	cout<<"\n Sorry room no. not found or vacant!!";
    else
    {
	remove("Records.dat");
	rename("tempo.dat","Record.dat");
    }
}

void main()
{
    hotel h;
    char *c;
    char *name;
    clrscr();
    cout<<"\n\t\t\t****************************";
    cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
    cout<<"\n\t\t\t****************************";


    cout<<endl;
    cout<<"\tenter your user name :  ";
    cin>>name;
    cout<<"\tenter your password :  ";
    for(int i=0;i<3;i++)
    {
	c[i]=getch();
	cout<<"*";
    }
    if(strcmp(c,"c++")==0)
    {
    h.main_menu();
    }
    else
    cout<<"\t\tinvalid option" ;
    exit(0);
}