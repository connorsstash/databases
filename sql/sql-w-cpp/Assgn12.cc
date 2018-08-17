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
 * Description: We connect to the database, make out query, then output the answer using
 *			the printf() function so it looks more like a table that I'm
 *			used to seeing.
 *
 * unix usage:  1.  g++ -o Assgn12.exe Assgn12.cc -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql
 *              2.  ./Assgn12
 *
 * FileName:    Assgn12.cc
 *
 ***********************************************************************/

#include <mysql.h>
#include <iostream>

using namespace std;

/* User information for database connection.*/
#define SERVER "students"
#define USER "z1761994"
#define PASSWORD "1996Dec04"
#define DATABASE "z1761994"


int main()

{
 cout << endl;  //Title for program.
 cout << "------------ Alexamara in C++ ----------------- " << endl;
 cout << endl;

  MYSQL *connect, mysql;

  connect = mysql_init(&mysql); // Used to initalize the connection object.

  // Database connection being made.
  connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);

    // Making sure connection is valid before we run querys.
    if(connect)
    {

      MYSQL_RES *res_set; // pointer to receive the return value.
      MYSQL_ROW row; 	  // variable for rows.

      //First query --> title.
      cout << "--- Table Displating all the Marinas---" << endl;

      // The Query.
      mysql_query(connect,"select * from Marina;");

      // A cursor.
      res_set = mysql_store_result(connect);

      //  While the cursor fetching the row is now null...
      while ((row = mysql_fetch_row(res_set)) != NULL)
      {
	        //Table style output.
	        printf("|%3s|%19s|%17s|%10s|%4s|%6s|", row[0], row[1], row[2], row[3], row[4], row[5]);
	        cout << endl;
      }
      //Free the result set.
      mysql_free_result(res_set);

      cout << endl;



    //Next query. --> Title
	   cout << "--- Table displaying the first name, last name, then city. ---" << endl;

     mysql_query(connect,"select LastName, FirstName, City from Owner;"); //The Query.

     res_set = mysql_store_result(connect); /* a cursor*/

      //While the cursor fetching the row is now null...
      while ((row = mysql_fetch_row(res_set)) != NULL) /*not end of cursor */
      {
	       //Table style output.
	        printf("|%9s|%15s|%12s|", row[0], row[1], row[2]);

	         cout << endl;
      }
	  cout << " End of Table;. " << endl;
    //Free the result set.
    mysql_free_result(res_set);// free the result set.

    cout << endl;


    // Next query ---> Title.
    cout << "---------------- Table displating all the boat's in the Marina. --------------------" << endl;

    //The Query.
    mysql_query(connect,"select Owner.LastName, Owner.FirstName, Owner.City, MarinaSlip.BoatName, MarinaSlip.BoatType from Owner, MarinaSlip where Owner.OwnerNum = MarinaSlip.OwnerNum;");

    //A cursor.
    res_set = mysql_store_result(connect);

    //While the cursor fetching the row is now null...
    while ((row = mysql_fetch_row(res_set)) != NULL)
     {
          //Table style output.
          printf("|%10s|%20s|%12s|%15s|%15s|", row[0], row[1], row[2], row[3], row[4]);

      cout << endl;
     }

   cout << " End of Record. " << endl;
   //Free the result set.
   mysql_free_result(res_set);

   cout << endl;



   //Next query --> Title.
   cout << "---Listing each boats Service Request description and status.---" << endl;

   //The Query.
   mysql_query(connect,"select MarinaSlip.BoatName, ServiceRequest.Status, ServiceRequest.Description from MarinaSlip, ServiceRequest where MarinaSlip.SlipID = ServiceRequest.SlipID;");

   //A cursor.
   res_set = mysql_store_result(connect); /* a cursor*/

   //While the cursor fetching the row is now null...
   while ((row = mysql_fetch_row(res_set)) != NULL) /*not end of cursor */
   {
	/*  I didn't output in table format becuase row[2] could be up to 250
	characters and it's more readable this way in Unix. */
      cout << endl << endl;
      cout << "- Latest boat service request record for the " << row[0] << ". -" << endl;
      cout << "   Boat Name: " << row[0] << endl;
      cout << "   Boat Status: " << row[1] << endl;
      cout << "   Description: " << row[2] << endl;
      cout << "- End of " << row[0] << "service request table. ";
      cout << endl;
   }
   cout << " End of Record. " << endl;

   mysql_free_result(res_set);// free the result set.

   mysql_close(connect);  // Close connection.

   cout << endl;

    }
}

//  ##
