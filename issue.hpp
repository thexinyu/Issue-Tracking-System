#ifndef ISSUE_H
#define ISSUE_H
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <cstdlib>
#include <map>
#include "user.hpp"

using namespace std;

extern string types[];
extern string statuses[];
    
class Issue {
  public:
    int* values = nullptr;

  private: 
    int id;
    int priority;
    int date_created;
    int completion_time;
    string description;
    string comments;
    string type;
    string status;

  public:
    vector<User*> assignees;
    Issue(int prior, int date, int completion, string descript, int issue_type, int issue_status){
      this -> priority = prior;
      this -> date_created = date;
      this -> completion_time = completion;
      this -> description = descript;
      this -> type = types[issue_type];
      this -> status = statuses[issue_status];
    };
    // CONSTRUCTOR AND DESTRUCTOR
    Issue(){}
    ~Issue() {
      delete[] values;
    }
    
    // FUNCTION DECLARATIONS
    void display(){
      cout << "\tDESCRIPTION: " << description << endl;
      cout << "\tCOMPLETION TIME: " << completion_time << endl;
      cout << "\tPRIORITY: " << priority << endl; 
      cout << "\tTYPE: " << type << endl;
      cout << "\tSTATUS: " << status << endl;
    }

    // GETTERS AND SETTERS
    void set_priority(char);
    int get_priority();
    void set_date_created(int);
    int get_date_created() const;
    void set_completion_time(int);
    int get_completion_time();
    void set_description(string);
    string get_description();
    void set_comments(string);
    string get_comments();
    void set_type(int);
    string get_type();
    void set_status(int);
    string get_status();
    void add_user(User*);
    vector<User*> get_users();
    void remove_user(int);
    int get_status_num();
    int get_type_num();
};

#endif