#ifndef SPRINT_H
#define SPRINT_H
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
// #include "project.hpp"
#include "issue.hpp"
// #include "user.hpp"

using namespace std;

class Sprint {   
  private: 
    vector<Issue*> issues;
  public:
    int* values = nullptr;
    // CONSTRUCTOR AND DESTRUCTOR
    int time = 0;
    int timeframe;
    Sprint(int t, int tf, vector<Issue*> issues_vec){
      this -> time = t;
      this -> timeframe = tf;
      this -> issues = issues_vec;
    }
    Sprint(){}
    ~Sprint() {
      delete[] values;
    }

    // SETTERS AND GETTERS
    void set_time(int);
    int get_time();
    void set_timeframe(int);
    int get_timeframe();
    vector<Issue*> get_issues();

    // FUNCTION DECLARATIONS
    void add_issue(Issue*);
    void display(void){
      for(int i=0; i<issues.size(); i++){
        issues[i]->display();
      }
    }
    void add_time(int);

};


#endif