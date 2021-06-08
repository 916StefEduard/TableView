
#include "repository.h"
#include <fstream>
#include <sstream>

void repository::add_user(User u){
    array.push_back(u);
}


vector<User> repository::get_array(){
    return array;
}

std::vector<string> split_string(const std::string &s, char delimitator) {
    std::vector<string> elements;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delimitator)) {
        elements.push_back(number);
    }
    return elements;
}

void repository::load_data(){
    fstream new_file;
    User u;
    int i;
    new_file.open("../data/data.txt");
    if (new_file.is_open()) {
        string line;
        while (getline(new_file, line)) {
            std::vector<string> strings = split_string(line, ';');
            i=0;
            while (i < strings.size()) {
                u.m_name=strings[0];
                u.m_skill=strings[1];
                i++;
            }
            repository::add_user(u);
        }
        new_file.close();
    }
}

