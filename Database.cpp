//
// Created by Filip Gieracki
//

#include "Database.h"

std::vector <Row*> Database::filter(Row *requirements_){
    std::vector <Row*> res;
    for(auto Record : Data_){
        if(Record->validate_row(requirements_)) res.push_back(Record);
    }
    return res;
}

void Database::read_database(){
    std::string filename, line;
    filename = "data.csv" ;
    std::ifstream file(filename);
    bool flag = false;
    if(file.is_open()){
        while(getline(file, line)){
            Row *tmp = new Row(line);
            if(flag)
                Data_.push_back(tmp);
            else flag = true;
        }
        file.close();
        return;
    }
    else {
        throw std::logic_error("DATASET_ERROR");
    }
}

std::vector <Row*> Database::search_records(std::string surname_="",
                    std::string name_="",
                    std::string name2_="",
                    std::string crossed_out_="",
                    std::string resignation_="",
                    std::string email_="",
                    std::string index_=""){
    Row *requirements = new Row(std::move(surname_),
                                std::move(name_),
                                std::move(name2_),
                                crossed_out_.find('1')!=std::string::npos,
                                resignation_.find('1')!=std::string::npos,
                                std::move(email_),
                                std::move(index_));
    std::vector <Row*> res = filter(requirements);



    return res;
}
