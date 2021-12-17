#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <memory>
#include <cstdlib>
#include <map>
// #include "issue.hpp"

using namespace std;

extern string usertypes[];

class User {
  public:
    int* values = nullptr;
    
  protected:
    int user_id;
    string username;
    string first_name;
    string last_name;
    string type;

  public:
  // CONSTRUCTOR AND DESTRUCTOR
    User(int user_type, int id, string user_name, string first, string last){
      this -> type = usertypes[user_type];
      this -> user_id = id;
      this -> username = user_name;
      this -> first_name = first;
      this -> last_name = last;
    }
    User(){}
    ~User() {
      delete[] values;
    }
    // vector <Issue*> tasks;
    
    // FUNCTION DECLARATIONS
    // getters and setters
    void set_user_id(int);
    int get_user_id();
    void set_username(string);
    string get_username();
    void set_first_name(string);
    string get_first_name();
    void set_last_name(string);
    string get_last_name();
    void set_type(int);
    int get_type();
    void change_role();

    void display(){
      cout << "USERNAME: " << username << endl;
      cout << "FIRST NAME: " << first_name << endl;
      cout << "LAST NAME: " << last_name << endl;
      cout << "ASSIGNED TASKS: " << endl;
    }
};

#endif