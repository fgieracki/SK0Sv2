//
// Created by Filip Gieracki
//

#ifndef SK0SV2_DATABASE_H
#define SK0SV2_DATABASE_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Row.h"

class Database {
private:
    std::vector <Row*> Data_;

public:
    std::vector <Row*> filter(Row *requirements_);

    void read_database();

    std::vector <Row*> search_records(std::string,
                        std::string,
                        std::string,
                        std::string,
                        std::string,
                        std::string,
                        std::string);

    static Database &instance(){
        static Database DB;
        return DB;
    }

    Database(){
        read_database();
    }
};


#endif //SK0SV2_DATABASE_H
