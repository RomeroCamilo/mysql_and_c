#include <mysql.h>
#include "sql_functions.h"
#include <iostream>
#include <string>

//test

int main() {

    // Initialize MySQL library
    if(init_sql_library_check() != 0){
        return -1;
    }else{
       std::cout<<"\nMySQL library initialization succeeded!\n";
    }

    // Connect to the MySQL server and initialize a new MYSQL object.
    MYSQL* conn;
    conn = mysql_init(nullptr);
    
    if(init_mysql_check(conn) != 0)
        return -1;
    else
        std::cout<<"MySQL initialization succeeded!\n";
    

    const char* host = "localhost"; // Replace with your MySQL server's hostname
    const char* user = "root"; // Replace with your MySQL username
    const char* password = "Champion2118!"; // Replace with your MySQL password
    const char* database = "login"; // Replace with the name of the database you want to connect to
    unsigned int port = 3306; // Replace with the port number of your MySQL server

    if (mysql_real_connect(conn, host, user, password, database, port, nullptr, 0) == nullptr) {
        std::cerr << "Connection to MySQL server failed: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        mysql_library_end();
        return 1;
    }
    else
        std::cout << "Connection to MySQL server succeeded!\n";

    // Connection successful, you can now execute queries on the MySQL server.

    const char* query = "SELECT * FROM login.users LIMIT 5;";

    // Execute the query
    if (mysql_query(conn, query) != 0) {
        std::cerr << "Query execution failed: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        mysql_library_end();
        return 1;
    }
    else
        std::cout << "Query execution succeeded!\n";
    
    // Get the result set
    MYSQL_RES* result = mysql_store_result(conn);

    if (result == nullptr) {
        std::cerr << "Failed to store result set: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        mysql_library_end();
        return 1;
    }
    else{
        std::cout<<"Result set stored successfully!\n";
    }

     // Process the result set and print the data
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        // row[n] returns n-th column in the current row. In this case, there are 2 columns: username and password.
        std::cout << "\nUsername: " << row[0] << " Password: " << row[1] << std::endl;
    }

    // Don't forget to close the connection when you're done.
    mysql_close(conn);

    // Shutdown MySQL library
    mysql_library_end();

    return 0;
}


