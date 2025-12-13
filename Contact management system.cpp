#include<iostream>
#include<cstring>
#include<fstream>
#include<windows.h>
#include<conio.h>
using namespace std;
struct data
{
	string firstname;
	string surname;
	string email_id;
	long int phone_no;
};
data p[100];
int total=0;

void loginsystem(char[],char[]);
void contents();
void createcontacts();
void display_allcontacts();
void searchcontacts();
void editcontacts();
void deletecontacts();

int main()
{
	cout<<"    ____________________________________________________________________________________________________\n\n";
	cout<<"\t\t\t\t-----CONTACT MANAGEMENT SYSTEM-----"<<endl;
    cout<<"    ____________________________________________________________________________________________________\n\n";
	
	char name[50];
	char password[50];
	loginsystem(name,password);
	system("CLS");
	
    char choice;
   do
   {
	contents();

	cout<<"\n\tEnter your choice: ";
	cin>>choice;
	
	system("CLS");
	if(choice<1 && choice>6)
	{
		cout<<"\tPlease enter valid choice.";
		cin>>choice;
	}
	if(choice!=6)
	{
	   switch (choice)
	{
		case '1':
			createcontacts();
			break;
		case '2':
			display_allcontacts();
			break;
		case '3':
			searchcontacts();
			break;
		case '4':
			editcontacts();
			break;
		case '5':
			deletecontacts();
			break;
		case '6':
			exit(0);
			break;
	}
    }
	}while(choice!=6); 
getch();	
return 0;
}

void loginsystem(char username[50],char password[50] )
{
	
	cout<<"\t\t***SignUp***\n";
	cout<<"\t\tEnter New Username: ";
	cin.getline(username,50);
	cout<<"\t\tEnter New Password: ";
	cin.getline(password,50);
	cout<<"\n\t\tYour ID is Creating,Please wait.";
	for(int i=0;i<5;i++)
	{
		cout<<".";
		Sleep(500);
	}
	cout<<"\n\t\tYour ID is created successfully!";
	Sleep(2000);
    start:
	system("CLS");
	cout<<"    ____________________________________________________________________________________________________\n\n";
	cout<<"\t\t\t\t-----CONTACT MANAGEMENT SYSTEM-----"<<endl;
    cout<<"    ____________________________________________________________________________________________________\n\n";
	
	cout<<"\n\n\t\tEnter data to login:\n";
	char n[50]; //n for username.
	char p[50]; //p for password.
	int login_attempt;
	for( login_attempt=1;login_attempt<=5;login_attempt++)
{	
	cout<<"\t\tEnter Username: ";
	cin.getline(n,50);
	cout<<"\t\tEnter Password: ";
	cin.getline(p,50);
	int r,m;
	r=strcmp(username,n); // string name comparison
	m=strcmp(password,p); // string password comparison
	
	if(r==0&&m==0)
	{
		cout<<"\n\t\t\t****Welcome to Contact Management System (CMS)!****";
		Sleep(2000);
		break;
	}
	else
	{
		cout<<"\n\t\t\t***Please Enter Correct ID data...***\n";
		cout<<endl;
	}
    if(login_attempt==5)
    {
	cout<<"\t\t Sorry,You are no longer user."<<endl;
    }
    cout<<endl;
}
}
void contents()
{
	cout<<"\n\t\t-> 1. CREATE contact\n";
	cout<<"\t\t-> 2. DISPLAY the list of contacts\n";
	cout<<"\t\t-> 3. SEARCH the contact information\n";
	cout<<"\t\t-> 4. EDIT contacts\n";
	cout<<"\t\t-> 5. DELETE contact\n";
	cout<<"\t\t-> 6. EXIT\n";
	
}
void createcontacts()
{
	ofstream file("contactsdata.txt");
	int user;
	cout<<"\n\tHow many numbers of contacts you want save?";
	cin>>user;
	cout<<endl;
	int i;
	for(i=total;i<total+user;i++)
	{
	cout<<"\tEnter the information of "<<i+1<<" person\n";
	cout<<"\tEnter first Name:";
	cin>>p[i].firstname;
	cout<<"\tEnter Surname:";
	cin>>p[i].surname;
	cout<<"\tEnter Phone Number upto 10 digits:";
	cin>>p[i].phone_no;
	cout<<"\tEnter email ID:";
	cin>>p[i].email_id;
	
	file<<p[i].firstname<<endl;
	file<<p[i].surname<<endl;
	file<<p[i].phone_no<<endl;
	file<<p[i].email_id<<endl;
	file.close();
	cout<<"\n\n\t\t\t^^^^^^Contact saved successfully!^^^^^^\n\n";
}
total=total+user;
}

void display_allcontacts()
{

	if(total!=0)
   {	
	for(int i=0;i<total;i++)
	{   
	    ifstream file("contactsdata.txt");
	    file>>p[i].firstname>>p[i].surname>>p[i].email_id>>p[i].phone_no;
	    cout<<endl;
		cout<<"\tData of "<<i+1<<"person:\n"<<endl;
		cout<<"\tName:  "<<p[i].firstname<<endl;
		cout<<"\tsurname: "<<p[i].surname<<endl;
		cout<<"\tPhone Number: "<<p[i].phone_no<<endl;
		cout<<"\tEmail_ID: "<<p[i].email_id<<endl;
		cout<<endl;
    }
   }
    else
	{
	cout<<"\t\tYou have entered no data.";
    }
}
void searchcontacts()
{
	string name;	
	if(total!=0)
	{
		cout<<"\t\tEnter the name of contact you want to search: ";
	    cin>>name;
	    
	    for(int i=0;i<total;i++)
	  {
	   if(p[i].firstname==name)
	   {
	   	cout<<"\t\tName: "<<p[i].firstname<<endl;
		cout<<"\tsurname: "<<p[i].surname<<endl;   	
		cout<<"\t\tPhone Number: "<<p[i].phone_no<<endl;
		cout<<"\t\tEmail_ID: "<<p[i].email_id<<endl;
		cout<<endl;
		break;
	   }
	   if(i==total-1)	
	   {
	   	cout<<"\t\tNo results found for "<<" \" "<<name<<" \" "<<endl;
	   }
       }
   }
    else
    {
    	cout<<"\n\t\tYou have entered no data."<<endl;
	}
	cout<<endl;
}

void editcontacts()
{
	
	string n;
	
	if(total!=0)
	{
		cout<<"\t\tEnter the name of contact you want to edit: ";
	    cin>>n;
		for(int i=0;i<total;i++)
		{
			if(p[i].firstname==n)
			{
				cout<<"\n\t\tOld data of this contact is:\n";
				cout<<"\t\tName: "<<p[i].firstname<<endl;
				cout<<"\tsurname: "<<p[i].surname<<endl;   	
	        	cout<<"\t\tPhone Number: "<<p[i].phone_no<<endl;
		        cout<<"\t\tEmail_ID: "<<p[i].email_id<<endl;
	        	cout<<endl;
	        	cout<<"\n\t\tNow edit this contact:\n";
	        	cout<<"\t\tEnter  First  Name: ";
            	cin>>p[i].firstname;
	            cout<<"\t\tEnter  Surname: ";
	            cin>>p[i].surname;
	            cout<<"\t\tEnter  Phone  Number  upto  10  digits: ";
	            cin>>p[i].phone_no;
	            cout<<"\t\tEnter  email  ID: ";
            	cin>>p[i].email_id;
             	cout<<"\n\n\t\t\t^^^^^^ NEW Contact saved successfully!^^^^^^\n";
             	break;
			}
			else if(p[i].firstname!=n)
			{
				cout<<"\t\tNo result found of this contact "<<n<<endl;
				break;
			}
		}
	}
	else
	{
		cout<<"\t\t You have entered no data!";
	}
}


void deletecontacts()
{	
	string nme;
	int press;
	if(total!=0)
	{
		cout<<"Press 1 to delete any contact!\n";
		cout<<"Press 2 to delete all the contacts!\n";
		cin>>press;
		if(press==1)
		{
			cout<<"Enter the name of contact you want to delete:";
			cin>>nme;
			for(int i=0;i<total;i++)
			{
			   if(p[i].firstname==nme)
			   {
				p[i].firstname=p[i+1].firstname;
				p[i].phone_no=p[i+1].phone_no;
				p[i].surname=p[i+1].surname;
				p[i].email_id = p[i+1].email_id;
				total--;
				
				cout<<"\t\tYour contact is deleted succesfully!";
				break;
		    	}
		    	
		    	else if(p[total].firstname!=nme)
			   {
				cout<<"\t\tNo result found for \""<<nme<<"\"";
			   }
		    }
	    }
		else if (press==2)
		{
			total=0;
			cout<<"\t\tAll contacts deleted successfully!";
		}
	}
	else 
	{
		cout<<"\t\tYou have entered no data!";
	}
	cout<<endl;
}

