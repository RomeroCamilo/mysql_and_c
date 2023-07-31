#include<iostream>
#include <mysql.h>

void print(){
    std::cout<<"MySQL library initialization succeeded!\n";
}

int init_sql_library(){
    int passed = 0;
    // Initialize MySQL library
    if (mysql_library_init(0, nullptr, nullptr) != 0) {
        std::cerr << "MySQL library initialization failed.\n";
        passed = 1; /* error occurred */
    }
    return passed;
}