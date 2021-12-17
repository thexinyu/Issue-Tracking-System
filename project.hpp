#ifndef PROJECT_H
#define PROJECT_H
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
#include "sprint.hpp"
#include "issue.hpp"

using namespace std;

class Project {
  private:
    string name;
    string description;

  public:
    int* values = nullptr;
    vector<User*> users;
    vector<Issue*> to_do;
    vector<Sprint*> in_progress;
    vector<Issue*> work_done;

    // CONSTRUCTOR AND DESTRUCTOR
    Project(string nm, string des, vector<User*> use){
      this -> name = nm;
      this -> description = des;
      this -> users = use;
    }
    Project(){}
    ~Project() {
      delete[] values;
    }

    // FUNCTION DECLARATIONS
    // getters and setters
    void set_name(string);
    string get_name();
    void set_description(string);
    string get_description();

    // team users
    void add_user(User *user);
    vector<User*> get_users();
    void delete_user(int);

    // add issues and sprints
    void add_issues(vector<Issue*>);
    vector<Issue*> get_todo();
    void add_sprint(Sprint*);
    vector<Sprint*> get_sprint();
    void add_work_done(vector<Issue*>);
    vector<Issue*> get_work_done();

    // display project summary function
    void display(void){
      cout << endl << "NAME: " << name << endl;
      cout << endl << "DESCRIPTION: " << description << endl;
      cout << endl << "USERS: " << endl;
      for (int i=0; i<users.size(); i++){
        cout << users.at(i)->get_first_name() << " " << users.at(i)->get_last_name() << endl;
      }
    };

    // display to do issues
    void display_todo(void){
      cout << endl << "TO DO: " << endl;
      for (int i=0; i<to_do.size(); i++){
        to_do.at(i)->display();
        cout << endl;
      }
    };

    // display in progress sprints and functions
    void display_inprogress(void){
      cout << endl << "TO DO: " << endl;
      for (int i=0; i<in_progress.size(); i++){
        in_progress[i]->display();
        cout << endl;
      }
    };

    // display completed issues 
    void display_workdone(void){
      cout << endl << "COMPLETED: " << endl;
      for (int i=0; i<work_done.size(); i++){
        work_done.at(i)->display();
        cout << endl;
      }
    };


};

#endif
