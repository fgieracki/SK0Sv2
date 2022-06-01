//
// Created by Filip Gieracki
//

#ifndef SK0SV2_ROW_H
#define SK0SV2_ROW_H

#include <string>
#include <algorithm>
#include <vector>

class Row {
private:
    std::string surname_;
    std::string name_;
    std::string name2_;
    bool crossed_out_;
    bool resignation_;
    std::string email_;
    std::string index_;

protected:
    void split_data(std::string data_); //extract data from string to variables
    void clear_data(); //clear row variables
public:
    Row(); //default constructor
    Row(std::string, std::string, std::string, bool, bool, std::string, std::string); //constructor with string parameter
    Row(std::string data_);
    void print();
    bool validate_row(Row *requirements_); //check if the row meets the requirements
    std::string surname(){return surname_;}
    std::string name(){return name_;}
    std::string name2(){return name2_;}
    std::string crossed_out(){return crossed_out_==1? "1": "0";}
    std::string resignation(){return resignation_==1? "1": "0";}
    std::string email(){return email_;}
    std::string index(){return index_;}
    std::string get_row();
//    friend std::vector<Row*> filter(Row *requirements_); //simple search engine function

};


#endif //SK0SV2_ROW_H
