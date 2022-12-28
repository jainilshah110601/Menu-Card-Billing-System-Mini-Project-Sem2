#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;



bool dbconn();

void addrec();
void modifyrec();
void editrec();
void findmed();
void removerec();
void view();
void selected();
void takeorder();
void loginnew();
void menu();
void privilegescheck(string p);

string cuisine_list()
{

    string item;
    int no;
    cout<<"\nSelect the type of cuisine-"<<endl<<"Enter 1 for CHINESE"<<endl<<"Enter 2 for GUJARATI"<<endl<<"Enter 3 for SOUTHINDIAN"<<endl<<"Enter 4 for ITALIAN"<<endl<<"Enter 5 for PUNJABI"<<endl<<"Enter 6 for DESERTS"<<endl<<endl;
    cout<<"enter-";
    cin>>no;

    switch(no)
    {
    case 1:
        item="chinese";
        break;
    case 2:
        item="gujarati";
        break;
    case 3:
        item="southindian";
        break;
    case 4:
        item="italian";
        break;
    case 5:
        item="punjabi";
    case 6:
        item="deserts";
        break;

    }
    return item;
};
void admins_page()
{

    int runforever = 1;
    int ans;

    while(runforever == 1)
    {

        cout << endl << endl << "---------------" << endl << endl << "1. Add new food item " << endl << "2. display MENU" << endl << "3. modify food item"<< endl<<"4. remove item"<<endl<<"5. take order"<<endl<<endl<<"--------";

        cout << endl << "Your Answer : ";

        cin >> ans;

        switch(ans)
        {
        case 1:
            addrec();
            break;
        case 2:
            view();
            break;
        case 3:
            editrec();
            break;
        case 4:
            removerec();
        case 5:
            takeorder();
            //  case 6:
            //  selected();

        }
    }



};
void managers_page() {};
void waiters_page() {};


void login(int id)
{

    if(id==1)
    {
        cout<<"\nwelcome ADMIN";
        admins_page();
    }
    else if(id==2)
    {
        cout<<"\nwelcome MANAGER";
        managers_page();
    }
    else if(id==3)
    {
        cout<<"\nwelcome WAITER";
        waiters_page();
    }

};

void testt()
{
    string dummy;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);
    if(conn)
    {
        int qstate = 0;
        int id,price;
        string name;

        cout << "Enter id : ";
        cin >> id;

        cout << "Enter name : ";
        cin >> name;

        cout << "Enter price : ";
        cin >> price;

        stringstream ss;
        ss << "INSERT INTO testt(id, name, price) VALUES('" << id << "','" << name << "'," << price <<")";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
        {
            cout << "Record Inserted..." << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }

    system("pause");
    system("cls");




}

void create_table()
{
    string dummy7;

    MYSQL* conn7;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn7 = mysql_init(0);
    conn7 = mysql_real_connect(conn7, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);


    cout<<"name ----";


    stringstream ss7;
    ss7 << "CREATE TABLE   sanika1  (cuisine_id  INT(10) ,item_id INT(10),item_name VARCHAR(30),price INT(10),quantity INT(5),amount INT(10))";

    string query7 = ss7.str();

    const char* q7= query7.c_str();



//11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111


    if(conn7)
    {
        int qstate7 = mysql_query(conn7, q7);

        /* if(!qstate)
         {
             res = mysql_store_result(conn);

             while(row = mysql_fetch_row(res))
             {
                 cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << endl << endl;
             }
         }*/
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy7;
    }

    cout << "Press B to go back";
    cin >> dummy7;

    system("pause");
    system("cls");
}




void selected()
{

    string billno="mompop";

    string dummy;

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);

    stringstream ss;
    ss << "SELECT * FROM " << billno << "";

    string query = ss.str();

    const char* q = query.c_str();



    if(conn)
    {
        int qstate = mysql_query(conn, q);

        if(!qstate)
        {
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
            {
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t"<<row[4] <<"\t | \t" <<row[5]  << endl << endl;
            }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void addrec()
{

    string cuisine;

    cuisine=cuisine_list();

    cout<<"\ncuisine--"<<cuisine<<"\n";

    string dummy;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);
    if(conn)
    {
        int qstate = 0;
        int id,price;
        string name;
        cout << "Enter id : ";
        cin >> id;

        cout << "Enter name : ";
        cin >> name;

        cout << "Enter price : ";
        cin >> price;

        stringstream ss;
        ss << "INSERT INTO " << cuisine << "(id, item, price) VALUES('" << id << "','" << name << "'," << price <<")";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
        {
            cout << "Record Inserted..." << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }

    system("pause");
    system("cls");

}

void view()
{

    string cuisine;

    cuisine=cuisine_list();

    cout<<"\ncuisine--"<<cuisine<<"\n";



    string dummy;

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);

    stringstream ss;
    ss << "SELECT * FROM " << cuisine << "";

    string query = ss.str();

    const char* q = query.c_str();



    if(conn)
    {
        int qstate = mysql_query(conn, q);

        if(!qstate)
        {
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
            {
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << endl << endl;
            }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void editrec()
{

    string cuisine;

    cuisine=cuisine_list();

    cout<<"\ncuisine--"<<cuisine<<"\n";


    string dummy;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);
    if(conn)
    {
        int qstate = 0;
        string name,price;

        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter price : ";
        cin >> price;

        stringstream ss;
        ss << "UPDATE " << cuisine << " SET price = " << price << " WHERE item = '" << name << "'";

        string query = ss.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
        {
            cout << "Record Updated..." << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }

    system("pause");
    system("cls");

}
void removerec()
{
    string cuisine;

    cuisine=cuisine_list();

    cout<<"\ncuisine--"<<cuisine<<"\n";

    string dummy;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);
    if(conn)
    {
        int qstate = 0;
        string name,price;

        cout << "Enter Name : ";
        cin >> name;

        stringstream ss;
        ss << "DELETE FROM " << cuisine << " WHERE item = '" << name << "'";

        string query = ss.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
        {
            cout << "Record Removed..." << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }

    system("pause");
    system("cls");

};


struct retri
{

    int p3;
    string n3;
};
typedef struct retri Struct;

Struct retrieve_data(int c,int i)
{


    Struct d;

    string n;


// step 1 -finding the name from code;


    switch(c)
    {
    case 1:
        n="chinese";
        break;
    case 2:
        n="gujarati";
        break;
    case 3:
        n="southindian";
        break;
    case 4:
        n="italian";
        break;
    case 5:
        n="punjabi";
    case 6:
        n="deserts";
        break;

    }

    string dummy;

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);


    stringstream ss;
    ss << "SELECT item,price FROM "<< n << " WHERE id = '" << i << "'";

    string query = ss.str();

    const char* q = query.c_str();


    if(conn)
    {
        int qstate = mysql_query(conn, q);

        if(!qstate)
        {
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
            {
                d.n3=row[0];
               // cout<<"\n"<<d.n3;


                // object from the class stringstream
                stringstream geek(row[1]);

                // The object has the value  and stream
                // it to the integer x

                geek >> d.p3;

               // cout<<"\n"<<d.p3;



                //cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << endl << endl;

            }
        }
    }

    //cout << "Press B to go back";
    //cin >> dummy;

   // system("pause");
  //  system("cls");

    return d;

};



void takeorder()
{

// step 1 -display menu;
    menu();

// step 2 -getting customer information;

    string name,billno;
    int mob_no;
    int quantity,cu_id,item_id;


// step 3 -storing customer data in the database;
    string dummy;
    MYSQL* conn3;
    conn3 = mysql_init(0);
    conn3 = mysql_real_connect(conn3, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);
    if(conn3)
    {
        int qstate3 = 0;
        //step2



        cout<<"ENTER THE BILLNO:";
        cin>>billno;
        cout<<"\n ENTER THE CUSTOMER NAME:";
        cin>>name;
        cout<<"\nENTER THE MOBILE NUMBER:";
        cin>>mob_no;

        stringstream ss3;
        ss3 << "INSERT INTO customer_details(billno, customer_name, mob_no) VALUES('" << billno << "','" << name << "'," << mob_no <<")";

        string query3 = ss3.str();
        const char* q3 = query3.c_str();
        qstate3 = mysql_query(conn3, q3);
        if(qstate3 == 0)
        {
            cout << "\nbill generation started...." << endl;
            // cout << "Press B to go back";
            // cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn3) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }

    // system("pause");
    // system("cls");




///////////////////////////////
    int ans=1;







//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    string dummy7;

    MYSQL* conn7;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn7 = mysql_init(0);
    conn7 = mysql_real_connect(conn7, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);





    stringstream ss7;
    ss7 << "CREATE TABLE  "<< billno << " (cuisine_id  INT(10) ,item_id INT(10),item_name VARCHAR(30),price INT(10),quantity INT(5),amount INT(10))";

    string query7 = ss7.str();

    const char* q7= query7.c_str();




    if(conn7)
    {
        int qstate7 = mysql_query(conn7, q7);

        /* if(!qstate)
         {
             res = mysql_store_result(conn);

             while(row = mysql_fetch_row(res))
             {
                 cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << endl << endl;
             }
         }*/
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy7;
    }
    /*
        cout << "Press B to go back";
        cin >> dummy7;

        system("pause");
        system("cls");
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*MYSQL* conn5;
    conn5 = mysql_init(0);
    conn5 = mysql_real_connect(conn5, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);
    if(conn5)
    {
        int qstate5 = 0,qstate2 = 0;
        string id,name;


        stringstream ss5;
        ss5 << "CREATE TABLE "<< billno <<" (cuisine_id  INT(10) ,item_id INT(10),item_name VARCHAR(30),price INT(10),quantity INT(5),amount INT(10))";

        string query5 = ss5.str();

        const char* q5 = query5.c_str();
        qstate5 = mysql_query(conn5, q5);
        if(qstate5 == 0)
        {
            cout << "process started..." << endl;
            // cout << "Press B to go back";
            // cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn5) << endl;
            // cout << "Press B to go back";
            //cin >> dummy;
        }

    }*/
//step 4 -start taking orders;




    while(ans==1)
    {
        cout << "\nEnter cuisine id : ";
        cin >> cu_id;

        cout << "\nEnter item id : ";
        cin >> item_id;

        cout << "\nEnter quantity : ";
        cin >> quantity;



        Struct result;
        result=retrieve_data(cu_id,item_id);
        int amount;

        // cout<<"\n\nname: "<<result.n3;
        // cout<<"\nprice: "<<result.p3;
        amount=result.p3*quantity;



        MYSQL* conn6;
        conn6 = mysql_init(0);
        conn6 = mysql_real_connect(conn6, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);
        if(conn6)
        {
            int qstate6 = 0;
            string id,name;



            stringstream ss6;
            ss6 << "INSERT INTO "<< billno << " VALUES(" << cu_id << "," << item_id << ",'" << result.n3 << "'," << result.p3 << "," << quantity <<"," << amount << ") ";
//(cuisine_id,item_id,item,price,quantity,amount)
            string query6 = ss6.str();

            const char* q6 = query6.c_str();
            qstate6 = mysql_query(conn6, q6);
            if(qstate6 == 0)
            {
                cout << "added !" << endl;
                cout<<"add more? press 1 else 0";
                cin>>ans;


            }
            else
            {
                cout << "Insert Error" << mysql_error(conn6) << endl;
                cout << "Press B to go back";
                cin >> dummy;
            }

        }

        else
        {
            cout << "Connection Error" << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }

        //  cout << "Press B to go back";
        // cin >> dummy;

        //system("pause");
        // system("cls");

    }
    cout<<"\nBILL GENERATED\n";


    //display bill
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

    MYSQL* conn;
    // MYSQL_ROW row;
    // MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);

    stringstream ss;
    ss << "SELECT * FROM " << billno << "";

    string query = ss.str();

    const char* q = query.c_str();



    if(conn)
    {
        int qstate = mysql_query(conn, q);

        if(!qstate)
        {
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
            {

                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t"<<row[4] <<"\t | \t" <<row[5]  << endl << endl;
            }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");

    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

}
//LOGIN SYSTEM





void loginnew()
{
    string name,pass,db_pass,privi;



u:
    cout<<endl<<"\n\n\n\n\n\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<endl<<"\n\t\t\t\t  ENTER USER-ID: ";
    cin>>name;


z:


    pass="";
    char cha;
    cout<<endl<<"\n\t\t\t\t  ENTER PASSWORD:";

pp:
    cha=getch();

    if(cha!=13)
    {
        if(cha==8)
        {
            goto pp;
        }
        cout<<"*";
        pass=pass+cha;
        goto pp;
    }
//CONNECTING TO LOGIN_SYS AND VERIFYING



    string dummy;

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);


    stringstream ss;
    ss << "SELECT password FROM login_sys WHERE name = '" << name << "'";

    string query = ss.str();

    const char* q = query.c_str();



//11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111


    if(conn)
    {
        int qstate = mysql_query(conn, q);

        if(!qstate)
        {
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
            {
                db_pass=row[0];
            }
        }
    }



    //  system("pause");
    // system("cls");




    if(pass==db_pass)
    {
        cout<<endl<<"\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<endl<<"\n\t\t\t\t\t     ACCSESS GRANTED "<<name;
        cout<<endl<<"\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<endl<<"\n\t\t\t\t         WELCOME TO REGERA RESTAURANTS  "<<endl;
        system("PAUSE");
        system("CLS");

    }
    else
    {
        cout<<endl<<"\n\n\t\t\t\t\t\t\t\t WRONG PASSWORD";
        cout<<endl<<"\n\t\t\t\t\t\t\t\t DON'T BE SO SMART";
        goto z;
    }

//privileges check


    MYSQL* conn1;
    MYSQL_ROW row1;
    MYSQL_RES* res1;
    conn1 = mysql_init(0);
    conn1 = mysql_real_connect(conn1, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);


    stringstream ss1;
    ss1 << "SELECT privileges FROM login_sys WHERE name = '" << name << "'";

    string query1 = ss1.str();

    const char* q1 = query1.c_str();





    if(conn1)
    {
        int qstate1 = mysql_query(conn, q1);

        if(!qstate1)
        {
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
            {
                privi=row[0];
            }
        }
    }

    //cout<<"\n\n"<<privi;
    privilegescheck(privi);

}
void privilegescheck(string p)
{

    if(p=="5")
    {
        cout<<"\nwelcome ADMIN";
        admins_page();
    }
    else if(p=="3")
    {
        cout<<"\nwelcome MANAGER";
        managers_page();
    }
    else if(p=="1")
    {
        cout<<"\nwelcome WAITER";
        waiters_page();
    }

};

void menu()
{
    string cuisine;


    for(int i=1; i<=6; i++)
    {

        switch(i)
        {
        case 1:
            cuisine="chinese";
            break;
        case 2:
            cuisine="gujarati";
            break;
        case 3:
            cuisine="southindian";
            break;
        case 4:
            cuisine="italian";
            break;
        case 5:
            cuisine="punjabi";
        case 6:
            cuisine="deserts";
            break;

        }


        cout<<endl<<"-------------"<<cuisine<<"------------------"<<endl;

        string dummy;

        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);

        stringstream ss;
        ss << "SELECT * FROM " << cuisine << "";

        string query = ss.str();

        const char* q = query.c_str();



        if(conn)
        {
            int qstate = mysql_query(conn, q);

            if(!qstate)
            {
                res = mysql_store_result(conn);

                while(row = mysql_fetch_row(res))
                {
                    cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << endl << endl;
                }
            }
        }

    }
}





int main()
{



    //login page

    loginnew();

    //  login(id);

    return 0;


}
