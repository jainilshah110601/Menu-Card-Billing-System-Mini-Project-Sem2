 
 table_creation(){
 
 
  string dummy7;

    MYSQL* conn7;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn7 = mysql_init(0);
    conn7 = mysql_real_connect(conn7, "192.168.56.1", "admin", "admin", "mini_project", 0, NULL, 0);





    stringstream ss7;
    ss7 << "CREATE TABLE  customer_details (billno VARCHAR(10),customer_name VARCHAR(30),mob_no(15))";

    string query7 = ss7.str();

    const char* q7= query7.c_str();




    if(conn7)
    {
        int qstate7 = mysql_query(conn7, q7);

       
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy7;
    }
    
}
