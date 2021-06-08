//
// Created by eddis on 6/8/2021.
//

#ifndef HELLOWORLD_REPOSITORY_H
#define HELLOWORLD_REPOSITORY_H
#include "../domain/User.h"
using namespace std;
class repository {
private:
    std::vector<User> array;
public:

    void add_user(User u);

    vector<User> get_array();

    void load_data();
};


#endif //HELLOWORLD_REPOSITORY_H
