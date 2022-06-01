//
// Created by Filip Gieracki
//

#include <iostream>
#include <utility>
#include "Row.h"

void Row::split_data(std::string data_){
    std::string delimiter = ";";
    size_t pos = 0;
    pos = data_.find(delimiter);
    if(pos != std::string::npos) {
        surname_ = data_.substr(1, pos-2);
        data_.erase(0, pos+delimiter.length());
    }
    pos = data_.find(delimiter);
    if(pos != std::string::npos) {
        name_ = data_.substr(1, pos-2);
        data_.erase(0, pos+delimiter.length());
    }
    pos = data_.find(delimiter);
    if(pos != std::string::npos) {
        name2_ = data_.substr(1, pos-2);
        data_.erase(0, pos+delimiter.length());
    }
    pos = data_.find(delimiter);
    if(pos != std::string::npos) {
        crossed_out_ = (data_.substr(1, pos-2) == "1");
        data_.erase(0, pos+delimiter.length());
    }
    pos = data_.find(delimiter);
    if(pos != std::string::npos) {
        resignation_ = (data_.substr(1, pos-2) == "1");
        data_.erase(0, pos+delimiter.length());
    }
    email_ = data_.substr(1, data_.size()-2);
    pos = email_.find("@");
    index_ = email_.substr(0, pos);
}


void Row::clear_data(){
    surname_ = "";
    name_ = "";
    name2_ = "";
    crossed_out_ = 0;
    resignation_ = 0;
    email_ = "";
    index_ = "";
}

Row::Row():surname_(""), name_(""), name2_(""), crossed_out_(0), resignation_(0), email_(""), index_(""){}

Row::Row(std::string surname_, std::string name_, std::string name2_, bool crossed_out_, bool resignation_, std::string email_, std::string index_):
        surname_(std::move(surname_)),
        name_(std::move(name_)),
        name2_(std::move(name2_)),
        crossed_out_(crossed_out_),
        resignation_(resignation_),
        email_(std::move(email_)),
        index_(std::move(index_)){}

Row::Row(std::string data_){
clear_data();
split_data(data_);
}

bool find_substring(std::string a, std::string b){
    std::transform(a.begin(), a.end(), a.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    std::transform(b.begin(), b.end(), b.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return (a.find(b) != std::string::npos);
}

bool Row::validate_row(Row *requirements_){
    return (find_substring(surname_, requirements_->surname_)
            && (find_substring(name_, requirements_->name_))
               && (find_substring(name2_, requirements_->name2_))
                  && (find_substring(email_, requirements_->email_))
                     && (find_substring(index_, requirements_->index_))
                        && (crossed_out_ == requirements_->crossed_out_)
                            && (resignation_ == requirements_->resignation_)
                            );
}

void Row::print() {
    std::cout<<get_row()<<'\n';
}

std::string Row::get_row(){
    return std::string(surname() + " "
        + name() + " "
        + name2() + " "
        + crossed_out() + " "
        + resignation() + " "
        + email() + " "
        + index());
}