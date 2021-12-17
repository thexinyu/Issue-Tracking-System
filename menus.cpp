#include "project.hpp"
#include "sprint.hpp"
#include "issue.hpp"
#include "user.hpp"
#include "initial.hpp"
#include "functions.hpp"
#include <iostream>

extern string line;
extern vector<User*> users;
extern Project* project;
extern string types[];
extern string statuses[];
extern User* currentuser;


// start screen
void start_menu(){
  int input;
  string userName;
  cout << endl << "ISSUE TRACKING APP" << endl << endl;
  cout << "[1] REGISTER/LOGIN USER" << endl;
  cout << "[2] QUIT" << endl;
  cin >> input;

  switch(input){
    case 1:
      {cout << "ENTER USERNAME: ";
      cin >> userName;
      // check to see if user exists
      auto it_users = find_if(users.begin(), users.end(), [&userName](User* &user) {return user->get_username() == userName;});

      if (it_users != users.end()){
        auto index = distance(users.begin(), it_users);
        currentuser = users.at(index);
      }
      
      else {
        string firstName, lastName;
        int type, userId;

        cout << "User role ([0]Lead, [1]Member): ";
        cin >> type;
        cout << "User not found" << endl << "Please enter the following to create a new user" << endl;
        cout << "First name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
        cout << "User ID (#): ";
        cin >> userId;
        currentuser = new User(type, userId, userName, firstName, lastName);
        // add user to vector of users
        users.push_back(currentuser);
      }
      break;
    }
    case 2:
      {exit(0);}
  }
  
}

// leader's main menu
void lead_main_menu(){
  // main menu 
  int input;
  cout << "OPTIONS MENU" << endl 
      << "[1] VIEW/EDIT PROJECT" << endl 
      << "[2] ADD TIME" << endl 
      << "[3] SWITCH USER" << endl
      << "[4] QUIT" << endl;
  cin >> input;
  cout << line << endl;

  switch(input){

    // view/edit project
    case 1:
    {
      edit_project();
      break;
    }
    // move forward in time
    case 2:
    {
      int time, sprint;
      cout << "NUMBER OF DAYS TO ADD: ";
      cin >> time;
      cout << "WHICH SPRINT TO WORK ON?" << endl;
      for (int i=1; i<project->get_sprint().size()+1; i++){
        cout << '[' << i << ']'<<  "ADD TIME: " << endl;
        project->get_sprint().at(i-1)->display();
      }
      cin >> sprint;
      add_time(time, sprint-1);
      break;
    }
    // switch users
    case 3:
    {
      start_menu();
      break;
    }
    // quit program
    case 4:
    {
      exit(0);
    }
  }
}

// member's main menu
void member_main_menu(){
  // main menu 
  int input;
  cout << "OPTIONS MENU" << endl 
      << "[1] VIEW/EDIT PROJECT" << endl 
      << "[2] ADD TIME" << endl 
      << "[3] SWITCH USER" << endl
      << "[4] QUIT" << endl;
  cin >> input;
  cout << line << endl;

  switch(input){
    case 1:
    {
      limited_edit_project();
      break;
    }
    case 2:
    {
      int time, sprint;
      cout << "NUMBER OF DAYS TO ADD: ";
      cin >> time;
      cout << "WHICH SPRINT TO WORK ON?" << endl;
      for (int i=1; i<project->get_sprint().size()+1; i++){
        cout << '[' << i << ']'<<  "ADD TIME: " << endl;
        project->get_sprint().at(i-1)->display();
      }
      cin >> sprint;
      add_time(time, sprint-1);
      break;
    }
    case 3:
    {
      start_menu();
      break;
    }
    case 4:
    {
      exit(0);
      break;
    }
  }
}

// run program and call main menu
void run_program(){
  while(1) {
    if (currentuser->get_type() == 0){
      lead_main_menu();
    }
    else {
      member_main_menu();
    }
  }
}