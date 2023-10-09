#include<iostream>
#include <mysql.h>

/* init mysql library */
int init_sql_library_check(){
    int passed = 0;

    // Initialize MySQL library
    if (mysql_library_init(0, nullptr, nullptr) != 0) {
        std::cerr << "MySQL library initialization failed.\n";
        passed = 1; /* error occurred */
    }

    return passed;
};

/* this functions check if a new MySQL object was successfully made */
int init_mysql_check(MYSQL* conn){
    int passed = 0;

    if(conn == nullptr){
        std::cerr<<"MySQL initialization failed.\n";
        passed = 1;
    }

    return passed;
}