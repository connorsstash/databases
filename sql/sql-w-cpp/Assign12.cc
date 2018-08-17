/*
 *
 * Programmer:  Connor Pekovic - Northern Illinois University
 * Z-ID:        z1761994
 * TA:          Shivasupraj Pasham.
 * Section:     2
 * Date Due:    May 1st, 2018
 *
 * Purpose:     This is a C++ program that's an exercise in using MySQL by using the
 *		#include <MySQL.h> predefined function to acess a database.
 *
 * Description: We connect to the database, make out query, then output the answer.
 *
 * unix usage:  1.  g++ -o Assign12.exe Assign12.cc -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql
 *              2.  ./Assign12
 *
 * FileName:    Assgn12.cc
 *
 ***********************************************************************/
#include<mysql.h>
#include<iostream>
#include<string>
using namespace std;

/*header files for database connnection*/
#define SERVER "students"
#define USER "z1761994"
#define PASSWORD "1996Dec04"
#define DATABASE "z1761994"


int main()
{
  int i;
  MYSQL *connect,mysql;       //Create a pointer to the MySQL instance
  connect = mysql_init(&mysql); // Initialize the instance.
  connect = mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);

        /* Connect to the specific database.*/
        if(connect)
        {
        /*Create a pointer to receive the return values for all 4 querys that
          we're about to do.*/
        MYSQL_RES *res_set;
        MYSQL_RES *res1_set;
        MYSQL_RES *res2_set;
        MYSQL_RES *res3_set;

        // Assign variable for akk 4 row's we'er about to return.
        MYSQL_ROW res_row;
        MYSQL_ROW res3_row;
        MYSQL_ROW res1_row;
        MYSQL_ROW res2_row;

        /* Send a query to the database. */
        string sql = "select * from Marina";
        mysql_query(connect,sql.c_str());//converting to c++ style string

        /* Receive the result and store it in res_set */
        res_set=mysql_store_result(connect);
        while((res_row=mysql_fetch_row(res_set))!=NULL)
        {
          cout<<"Marina Name: "<<res_row[1]<<" Address: "<<res_row[2]<<" City: "<<res_row[3]<<" State: "<<res_row[4]<<" Zip: "<<res_row[5]<<endl;

          string val=(const char *)(res_row[0]);

          string sql="select * from Owner,MarinaSlip where MarinaSlip.OwnerNum=Owner.OwnerNum AND MarinaSlip.MarinaNum= ";
          sql+=val;
          mysql_query(connect,sql.c_str());//converting to c++ style string

          /* Receive the result and store it in res_set */
        res1_set=mysql_store_result(connect);
        while((res_row=mysql_fetch_row(res1_set))!=NULL)
        {
          cout<< "  Owner LastName: "<<res_row[1]<<" FirstName: "<<res_row[2]<<" City: "<<res_row[4]<<" "<<endl << endl;
          string val=(const char *)(res_row[0]);
          string sql="select * from MarinaSlip where OwnerNum=";
          sql+=val;
          mysql_query(connect,sql.c_str());
          res2_set=mysql_store_result(connect);
          while((res1_row=mysql_fetch_row(res2_set))!=NULL)
          /* to move through each row in the cursor. mysql_fetch_row gets a
            single row from the cursor.*/
            {
              cout<<"  BoatName: "<<res1_row[5]<<" BoatType: "<<res1_row[6]<<endl;
              cout<<endl;
            }

        string val1=(const char *)(res_row[0]);
        string sql1="select * from ServiceRequest where SlipID=";
        sql1+=val1;
        mysql_query(connect,sql1.c_str());
        res3_set=mysql_store_result(connect);
        while((res3_row=mysql_fetch_row(res3_set))!=NULL)
        {
            cout<<"  Description: "<<res3_row[3]<<" Status: "<<res3_row[4]<<endl;
            cout<<endl;
        }
      cout<<"============== New Entery =============="<<endl;
    }
  }
/*mysql_free_result(res1_set);   //Frees up the cursor pointer of res1_set
mysql_free_result(res2_set);
mysql_free_result(res2_set);
mysql_free_result(res_set);
mysql_close(connect);*/
}

} // end of main.
