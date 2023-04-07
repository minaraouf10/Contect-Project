#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
struct Contect
{
    string fname, lname, mobile, email;
};
Contect contect;
vector<Contect>v;

bool cmp(const Contect& i, const Contect& j)
{
    if (i.fname == j.fname)
    {
        return i.lname < j.lname;
    }
    return i.fname < j.lname ;
}

bool check_name(string &s)
{

    if (s.size() > 20)
    {
        cout << " Name is very long " << endl;
        return  false;
    }
    for (int  i = 0; i < s.size(); i++)
    {
        if (!isalpha(s[i]))
        {
            cout << "Please Enter a Vailid Name  " << endl;
            return false;
        }
    }
    return true;
}

bool check_mobile(string &s)
{
    if (s.size() != 11)
    {
        cout << "Please Enter 11 Number " << endl;
        return false;
    }

    if (s[0] != '0' &&  s[1] != '1')
    {
        cout << "Number Should 01" << endl;
        return false;
    }
    if (s[2] != '0' && s[2] != '1' && s[2] != '2' && s[2] != '5')
    {
        cout << "Number Should 010 , 011 , 012 or 015 " << endl;
        return false;
    }

    for (int i = 3; i< s.size() ; i++)
    {
        if (!isdigit(s[i]))
        {
            cout << "Please Enter a Vailid Number  " << endl;
            return false;
        }
    }
    return true;
}

bool Check_Email(string s)
{
    int At = s.find('@');
    int com = s.find(".com");
    if (At < 1 || com <= At + 1)
    {
        cout << "\nEnter Valid Email\n";
        return false;
    }
    if (!isalpha(s[0]))
    {
        cout << "\nFirst Character must be from A to Z / a to z \n";
        return false;
    }

    for (int i = 1; i < At; i++)
    {
        if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_')
        {
            cout << "\nEnter Valid Email\n";
            return false;
        }
    }

    for (int i = At + 1; i < com; i++)
    {
        if (!isalpha(s[i]) && s[i] != '-' && s[i] != '.')
        {
            cout << "\nEnter Valid Email\n";
            return false;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].email == s)
        {
            cout << "this email found  " << endl;
            return false;
        }
    }
    return true;
}

void repair_name(string &s)
{
    s[0] = toupper (s[0]);
    for (int i = 1; i < s.size (); i++)
    {
        s[i] = tolower(s[i]);
    }
}

void COUT(int i,bool B)
{
    if(i==-1) return;
    cout << "\n First Name : " << v[i].fname << endl;
    cout << "\n Last Name : " << v[i].lname << endl;
    cout << "\n Number Of Mobile : " << v[i].mobile << endl;
    cout << "\n E_mail Address : " << v[i].email << endl;
    cout << "\n _________________________________________________________" <<endl<< endl;

    if(B)
    {

        char s2;
        do
        {
            cout<<"\nDo You Want Back to list? \n1) YES.\n2) NO."<<endl;
            cin>>s2;
        }
        while(s2!='1');
    }
}

void add(vector<Contect> & v, Contect & c)
{
    bool vailid = false;
    do
    {
        cout << "\n\t Enter First Name : " ;
        cin >> c.fname;
        if (check_name(c.fname))
        {
            vailid = check_name(c.fname);
        }
    }
    while (!vailid);
    repair_name(c.fname);


    do
    {
        vailid = false;
        cout << "\n\t Enter Last Name : " ;
        cin >> c.lname;
        if (check_name(c.lname))
        {
            vailid = check_name(c.lname);
        }
    }
    while (!vailid);
    repair_name(c.lname);


    do
    {
        vailid = false;
        cout << "\n\t Enter Mobile Number : " ;
        cin >> c.mobile;
        if (check_mobile(c.mobile))
        {
            vailid = check_mobile(c.mobile);
        }
    }
    while (!vailid);

    string c1;
    do
    {
        vailid = false;
        cout << "\n\t Enter E_mail : " ;
        cin >> c1;

        if (Check_Email(c1))
        {
            vailid = Check_Email(c1);
        }

        c.email = c1;
    }
    while (!vailid);

    v.push_back(c);
    sort(v.begin(), v.end(), cmp);
}

void deleted(int i)
{
    char s2;
    do
    {
        cout<<"Do you want delete "<<v[i].fname<<" "<<v[i].lname<<" from system \n1) YES.\n2) NO."<<endl;
        cin>>s2;
    }
    while(s2!='1'&&s2!='2');

    if(s2=='1')
    {
        v.erase(v.begin()+i,v.begin()+i+1);
    }

}

string center (string text,int i)
{
    i -= text.size();
    int l=i/2, r=i/2;
    if(i%2==1)
    {
        r++;
    }
    return string(l,' ')+text+ string(r,' ');
}

void table()
{
    cout<<(char)201<<string(5,(char)205)<<(char)203<<string(20,(char)205)<<(char)203<<string(13,(char)205)<<(char)203<<string(40,(char)205)<<(char)187<<endl;
    cout<<(char)186;
    cout<<center("ID",5)<<(char)186;
    cout<<center("Name",20)<<(char)186;
    cout<<center("Mobile",13)<<(char)186;
    cout<<center("E_mail",40)<<(char)186<<endl;

    cout<<(char)204<<string(5,(char)205)<<(char)206<<string(20,(char)205)<<(char)206<<string(13,(char)205)<<(char)206<<string(40,(char)205)<<(char)185<<endl;
    for (int i = 0; i < v.size() ; ++i)
    {

        cout<<(char)186;
        cout<<center(to_string(i+1),5)<<(char)186;
        cout<<center(v[i].fname+" "+v[i].lname,20)<<(char)186;
        cout<<center(v[i].mobile,13)<<(char)186;
        cout<<center(v[i].email,40)<<(char)186<<endl;
    }
    cout<<(char)200<<string(5,(char)205)<<(char)202<<string(20,(char)205)<<(char)202<<string(13,(char)205)<<(char)202<<string(40,(char)205)<<(char)188<<endl;

}

void Edit_name(int i)
{
    system("CLS");
    cout<< "your name is: "<<v[i].fname<<" "<<v[i].lname<<"."<<endl;
    Contect c=v[i];
    bool vailid = false;
    do
    {
        cout << "\n\t Enter First Name : " ;
        cin >> c.fname;
        if (check_name(c.fname))
        {
            vailid = check_name(c.fname);
        }
    }
    while (!vailid);
    repair_name(c.fname);


    do
    {
        vailid = false;
        cout << "\n\t Enter Last Name : " << endl;
        cin >> c.lname;
        if (check_name(c.lname))
        {
            vailid = check_name(c.lname);
        }
    }
    while (!vailid);
    repair_name(c.lname);
    v[i]=c;
}

void Edit_mobile(int i)
{
    system("CLS");
    cout<< "your mobile is: "<<v[i].mobile<<endl;
    Contect c=v[i];
    bool vailid = false ;
    do
    {
        vailid = false;
        cout << "\n\t Enter Mobile Number : " ;
        cin >> c.mobile;
        if (check_mobile(c.mobile))
        {
            vailid = check_mobile(c.mobile);
        }
    }
    while (!vailid);
    v[i]= c;
}

void Edit_email(int i)
{
    system("CLS");
    cout<< "your email is: "<<v[i].email<<endl;
    Contect c=v[i];
    bool vailid = false ;
    string c1;
    do
    {
        vailid = false;
        cout << "\n\t Enter E_mail : " ;
        cin >> c1;

        if (Check_Email(c1))
        {
            vailid = Check_Email(c1);
        }

        c.email = c1;
    }
    while (!vailid);
    v[i]=c;
}

void updata(int i)
{
    do
    {
        system("CLS");
        cout<<"Your data is:"<<endl;

        COUT(i,false);

        cout<<"Do You Want From Options:"<<endl<<endl;

        cout<<"1) Name."<<endl;
        cout<<"2) Mobile."<<endl;
        cout<<"3) Email."<<endl;
        cout<<"4) Save And Back."<<endl<<endl;

        cout<<"please select: ";

        int Ask;
        cin>>Ask;

        switch(Ask)
        {
        case 1:
            Edit_name(i);
            break;
        case 2:
            Edit_mobile(i);
            break;
        case 3:
            Edit_email(i);
            break;
        case 4:
            return;
            break;
        default :
            cout<<"Sorry,please enter a vailed option"<<endl;
        }
    }
    while(1);
}

void Print(vector<Contect>v)
{
    if(v.size()==0)
        cout<<"Sorry, not find data in your system"<<endl;
    else
        table();
    char s;
    do
    {
        cout<<"\nDo You Want Back to list? \n1) YES.\n2) NO."<<endl;
        cin>>s;
    }
    while(s!='1');


}

int serch(vector<Contect>& v)
{
    string s;
    bool vailid = false;
    do
    {
        cout << "\n\t Enter data your name to search : ";
        cin >> s;
        if (check_name(s))
        {
            vailid = check_name(s);
        }
    }
    while (!vailid);
    repair_name(s);
    for (int i = 0; i < v.size(); i++)
    {
        if (s == v[i].fname)
        {
            return i;
            break;
        }
    }
    return -1;
}

void get_data(string link)
{
    ifstream CIN(link);
    if(CIN.is_open())
    {
        Contect C;
        while(CIN>>C.fname>>C.lname>>C.mobile>>C.email)
        {
            repair_name(C.fname);
            repair_name(C.lname);
            v.push_back(C);
        }
        sort(v.begin(),v.end(),cmp);
    }
}

void set_data(string link)
{
    ofstream Cout(link);
    if(Cout.is_open())
    {
        for(int i=0; i<v.size(); i++)
        {
            Cout<<v[i].fname<<" "<<v[i].lname<<" "<<v[i].mobile<<" "<<v[i].email<<endl;
        }
        Cout.close();
    }
}

int main()
{
    string link = "data.txt";
    get_data(link);
    char op;
    do
    {
        system("CLS");
        cout << "\n\t A)  Add contect "
             << "\n\t B)  Print contect "
             << "\n\t C) Serceh "
             << "\n\t D) Delete "
             << "\n\t E) Updata "
             << "\n\t F) Quit \n";
        cin >> op;
        system("CLS");
        switch (op)
        {
        case 'A':
        case  'a':
            add(v,contect);
            break;
        case 'B':
        case 'b' :
            Print(v);
            break;
        case 'C':
        case 'c' :
            COUT(serch(v),true);
            break;
        case 'D':
        case 'd' :
            deleted(serch(v));

            break;
        case 'E':
        case 'e' :
            updata(serch(v));
            break;
        case 'F':
        case 'f' :
            cout << "System Ended \n";
            return 0;
            break;
        default:
            cout << "Error : wrong " << endl;
            break;
        }
    set_data(link);
    }
    while ( op != 'f' && op !='F' );

}


