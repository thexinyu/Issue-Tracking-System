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
#include "issue.hpp"
#include "sprint.hpp"
#include "project.hpp"
#include "functions.hpp"

extern string line;
extern Project* project;
extern vector<User*> users;
extern User* currentuser;

string filename;

using namespace std;

void write_file(string filename){
  ofstream outfile;
  outfile.open(filename);
      
  if(!outfile) {
    cout << "can't open file " << filename << endl;
  }

  else {
    string output, output2; 
    vector<User*> users = project->get_users();
    vector<Issue*> not_done = project->get_todo();
    vector<Sprint*> sprints = project->get_sprint();
    vector<Issue*> finished = project->get_work_done();
    outfile << "PROJECT NAME: " << endl << project->get_name() << endl;
    outfile << "PROJECT DESCRIPTION: " << endl << project->get_description() << endl;
    for (auto user: users) {
      outfile << "USER: " << endl;
      outfile << "User First Name: " << endl << user->get_first_name() << endl << "User Last Name: " << endl << user->get_last_name() << endl << "Username: " << endl << user->get_username() << endl << "User Type" << endl << user->get_type() << endl << "User ID: " << endl << user->get_user_id() << endl;
    };
    for (auto issue: not_done) {
      outfile << "ISSUE: " << endl;
      outfile << "Issue priority: " << endl << issue->get_priority() << endl << "Date created: " << endl << issue->get_date_created() << endl << "Completion time: " << endl << issue->get_completion_time() << endl << "Issue Description: " << endl << issue->get_description() << endl << "Issue Type: " << endl << issue->get_type() << endl << "Issue Status: " << endl << issue->get_status() << endl;
    };

    for (auto sprint: sprints) {
      outfile << "SPRINT: " << endl;
      outfile << "Sprint Time: " << endl << sprint->get_time() << endl << "Sprint Timeframe: " << endl << sprint->get_timeframe() << endl;
      vector<Issue*> sprint_issues = sprint->get_issues();

      for (auto issue : sprint_issues) {
        outfile << "Sprint Issue priority: " << endl << issue->get_priority() << endl << "Sprint Issue Date created: " << endl << issue->get_date_created() << endl << "Sprint Issue Completion time: " << endl << issue->get_completion_time() << endl << "Sprint Issue Description: " << endl << issue->get_description() << endl << "Sprint Issue Type: " << endl << issue->get_type() << endl << "Sprint Issue Status: " << endl << issue->get_status() << endl;
      }
    };
    for (auto issue: finished) {
      outfile << "COMPLETED ISSUE: " << endl;
      outfile << "Completed Issue priority: " << endl << issue->get_priority() << endl << "Completed Date created: " << endl << issue->get_date_created() << endl << "Completed Completion time: " << endl << issue->get_completion_time() << endl << "Completed Issue Description: " << endl << issue->get_description() << endl << "Completed Issue Type: " << endl << issue->get_type() << endl << "Completed Issue Status: " << endl << issue->get_status() << endl;
    };

  }

}


void save_file(string filename){
  // Opens and reads text file
  fstream fs;
  fs.open(filename, fstream::in);
           
  ifstream infile(filename);
  if(!infile) {
    cout << "can't open file " << filename << endl;
  }

  else {
    string line;
    vector <Issue*> todo_vec;
    vector <Issue*> finished_vec;

    while(getline(infile, line)) {
      if (line == "PROJECT NAME: "){
        getline(infile, line);
        project->set_name(line);
      }
      else if (line == "PROJECT DESCRIPTION: ") {
        getline(infile, line);
        project->set_description(line);
      }
      else if (line == "USER: "){
        getline(infile, line);
        getline(infile, line);
        string fname = line;
        getline(infile, line);
        getline(infile, line);
        string lname = line;
        getline(infile, line);
        getline(infile, line);
        string uname = line;
        getline(infile, line);
        getline(infile, line);
        int user_type = stoi(line);
        getline(infile, line);
        getline(infile, line);
        int user_id = stoi(line);
        User *new_user = new User(user_type, user_id, uname, fname, lname);
        project->add_user(new_user);
        // delete new_user;
      }
      else if (line == "ISSUE: "){
        getline(infile, line);
        getline(infile, line);
        int priority = stoi(line);
        getline(infile, line);
        getline(infile, line);
        int date = stoi(line);
        getline(infile, line);
        getline(infile, line);
        int complete = stoi(line);
        getline(infile, line);
        getline(infile, line);
        string descript = line;
        getline(infile, line);
        getline(infile, line);
        string issue_type = line;
        int type = get_type_num(line);
        getline(infile, line);
        getline(infile, line);
        string issue_status = line;
        int status = get_status_num(line);
        Issue *new_issue = new Issue(priority, date, complete, descript, type, status);
        todo_vec.push_back(new_issue);
        // delete new_issue;
      }
      else if (line == "SPRINT: "){
        vector<Issue*> issues = {};
        getline(infile, line);
        getline(infile, line);
        int sprint_time = stoi(line);
        getline(infile, line);
        getline(infile, line);
        int sprint_timeframe = stoi(line);
        while (getline(infile, line)){
          if (line == "Sprint Issue priority: ") {
            getline(infile, line);
            int sprint_priority = stoi(line);
            getline(infile, line);
            getline(infile, line);
            int sprint_date = stoi(line);
            getline(infile, line);
            getline(infile, line);
            int sprint_complete_time = stoi(line);
            getline(infile, line);
            getline(infile, line);
            string sprint_descr = line;
            getline(infile, line);
            getline(infile, line);
            int spr_type = get_type_num(line);
            getline(infile, line);
            getline(infile, line);
            int spr_status = get_status_num(line);
            Issue *sprint_issue = new Issue(sprint_priority, sprint_date, sprint_complete_time, sprint_descr, spr_type, spr_status);
            issues.push_back(sprint_issue);
            // delete sprint_issue;
          }
          else{
            Sprint *new_sprint = new Sprint(sprint_time, sprint_timeframe, issues);
            project->add_sprint(new_sprint); 
            break;
          }
        }
      }
      else if(line == "COMPLETED ISSUE: "){
        getline(infile, line);
        getline(infile, line);
        int prior = stoi(line);
        getline(infile, line);
        getline(infile, line);
        int cdate = stoi(line);
        getline(infile, line);
        getline(infile, line);
        int complete_t = stoi(line);
        getline(infile, line);
        getline(infile, line);
        string desc = line;
        getline(infile, line);
        getline(infile, line);
        int itype = get_type_num(line);
        getline(infile, line);
        getline(infile, line);
        int istatus = get_status_num(line);
        Issue *new_issue = new Issue(prior, cdate, complete_t, desc, itype, istatus);
        finished_vec.push_back(new_issue);
        // delete new_issue;
      }
      project->add_issues(todo_vec); 
      project->add_work_done(finished_vec); 
    }
      
  }
  
};
