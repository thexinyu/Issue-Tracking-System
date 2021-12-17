#include "project.hpp"
#include "sprint.hpp"
#include "issue.hpp"
#include "user.hpp"
#include "initial.hpp"
#include <iostream>

extern string line;
extern vector<User*> users;
extern Project* project;
extern string types[];
extern string statuses[];
extern User* currentuser;

// move forward time
void add_time(int time, int sprint){
  project->get_sprint().at(sprint)->add_time(time);
  for (auto issue: project->get_sprint().at(sprint)->get_issues()){
    if (issue->get_completion_time() < (project->get_sprint().at(sprint)->get_time())){
      issue->set_status(2);
      cout << "ISSUE COMPLETED: " << endl;
      issue->display();
    }
    else {
      issue->set_status(1);
      cout << "ISSUE IN PROGRESS: " << endl;
      issue->display();
    }
  }
}

// view and edit current user
void edit_user(){
  currentuser->display();
  int edit_input;
  cout << "[1] EDIT USERNAME: " << currentuser->get_username() << endl;
  cout << "[2] EDIT FIRST NAME: " << currentuser->get_first_name() << endl;
  cout << "[3] EDIT LAST NAME: " << currentuser->get_last_name() << endl;
  cout << "[4] EDIT USER ID: " << currentuser->get_user_id() << endl;
  cout << "[5] EDIT USER TYPE: "  << currentuser->get_type() << endl;
  cout << "[6] QUIT: " << endl; 
  cin >> edit_input;
  cout << line << endl;
  switch(edit_input){
    case 1:
    { 
      string new_username;
      cout << "ENTER NEW USERNAME: ";
      cin >> new_username;
      currentuser->set_username(new_username);
      break;
    }
    case 2:
    {
      string new_firstname;
      cout << "ENTER NEW FIRST NAME: ";
      cin >> new_firstname;
      currentuser->set_first_name(new_firstname);
      break;
    }
    case 3:
    {
      string new_lastname;
      cout << "ENTER NEW LAST NAME: ";
      cin >> new_lastname;
      currentuser->set_last_name(new_lastname);
      break;
    }
    case 4:
    {
      int new_userid;
      cout << "ENTER NEW ID: ";
      cin >> new_userid;
      currentuser->set_user_id(new_userid);
      break;
    }
    case 5:
    {
      int new_usertype;
      cout << "ENTER TYPE ([0]LEAD, [1]MEMBER): ";
      cin >> new_usertype;
      currentuser->set_type(new_usertype);
      break;
    }
    case 6:
    {
      exit(0);
    }
  }

}

// view and edit current user
void limited_edit_user(){
  currentuser->display();
  int edit_input;
  cout << "[1] EDIT USERNAME: " << currentuser->get_username() << endl;
  cout << "[2] EDIT FIRST NAME: " << currentuser->get_first_name() << endl;
  cout << "[3] EDIT LAST NAME: " << currentuser->get_last_name() << endl;
  cout << "[4] EDIT USER ID: " << currentuser->get_user_id() << endl;
  cout << "[6] QUIT: " << endl; 

  cin >> edit_input;
  cout << line << endl;
  switch(edit_input){
    case 1:
    { 
      string new_username;
      cout << "ENTER NEW USERNAME: ";
      cin >> new_username;
      currentuser->set_username(new_username);
      break;
    }
    case 2:
    {
      string new_firstname;
      cout << "ENTER NEW FIRST NAME: ";
      cin >> new_firstname;
      currentuser->set_first_name(new_firstname);
      break;
    }
    case 3:
    {
      string new_lastname;
      cout << "ENTER NEW LAST NAME: ";
      cin >> new_lastname;
      currentuser->set_last_name(new_lastname);
      break;
    }
    case 4:
    {
      int new_userid;
      cout << "ENTER NEW ID: ";
      cin >> new_userid;
      currentuser->set_user_id(new_userid);
      break;
    }
    case 6:
    {
      exit(0);
    }
  }

}

// add user to system and assign role
void add_user(string userName){
  cout << "ADD/ASSIGN A NEW USER" << endl;
  string firstName, lastName;
  int type, userId;

  auto it_users = find_if(users.begin(), users.end(), [&userName](User* &user) {return user->get_username() == userName;});

  if (it_users == users.end()){
    cout << "User not found" << endl << "Please enter the following to create a new user" << endl;
    cout << "Type ([0]Lead, [1]Member): ";
    cin >> type;
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "User ID (#): ";
    cin >> userId;
    User* new_user = new User(type, userId, userName, firstName, lastName);
    project->add_user(new_user);
    users.push_back(new_user);
    delete new_user;
    cout << "User successfully added to project" << endl;
  }

  else{
    cout << "User already exists in project" << endl;
  }
}

// delete member from assigned project
void delete_user(string userName){
  auto it_users = find_if(users.begin(), users.end(), [&userName](User* &user) {return user->get_username() == userName;});
  auto index = distance(users.begin(), it_users);
  project->delete_user(index);
  cout << "User successfully deleted from project" << endl;
}

// function to add/delete collaborators from project
void edit_collaborators(int input){
  int total = project->get_users().size();
  if (input-1 < total){
    project->get_users().at(input-1)->change_role();
    cout << "Changed user's role" << endl;
  }
  else if (input == total+1){
    string username_input;
    cout << "USERNAME: " << endl;
    cin >> username_input;
    cout << line << endl;
    add_user(username_input);
  }
  else if (input == total+2){
    string username_input;
    cout << "USERNAME: " << endl;
    cin >> username_input;
    cout << line << endl;
    delete_user(username_input);
  }
  else{
    exit(0);
  }
}

// edit in progress issues in a sprint
void edit_sprint_issue(int sprint, int issue){
  int edit_input;
  project->get_sprint().at(sprint-1)->get_issues().at(issue-1)->display();
  cout << "[1] EDIT DESCRIPTION: " << project->get_sprint().at(sprint-1)->get_issues().at(issue-1)->get_description() << endl;
  cout << "[2] EDIT PRIORITY: " << project->get_sprint().at(sprint-1)->get_issues().at(issue-1)->get_priority() << endl;
  cout << "[3] EDIT COMPLETION TIME: " << project->get_sprint().at(sprint-1)->get_issues().at(issue-1)->get_completion_time() << endl;
  cin >> edit_input;
  switch(edit_input){
    case 1:
    { 
      string new_description;
      cout << "ENTER NEW DESCRIPTION: ";
      cin >> new_description;
      project->get_sprint().at(sprint-1)->get_issues().at(issue-1)->set_description(new_description);
      break;
    }
    case 2:
    {
      int new_priority;
      cout << "ENTER NEW PRIORITY (1,2,3): ";
      cin >> new_priority;
      project->get_sprint().at(sprint-1)->get_issues().at(issue-1)->set_priority(new_priority);
      break;
    }
    case 3:
    {
      int new_completion_time;
      cout << "ENTER NEW COMPLETION TIME: ";
      cin >> new_completion_time;
      project->get_sprint().at(sprint-1)->get_issues().at(issue-1)->set_completion_time(new_completion_time);
      break;
    }
  }

}

// add new issue to a sprint
void add_issue(int input){
  int priority, date, completion, issue_type, issue_status;
  char description[100];

  cout << "TO ADD AN ISSUE, PLEASE ENTER: " << endl;
  cout << "DESCRIPTION: ";
  cin.ignore();
  cin.getline(description, 100);
  cout << endl << "PRIORITY (1, 2, 3): ";
  cin >> priority;
  cout << endl << "DATE (i.e. 021221): ";
  cin >> date;
  cout << endl << "COMPLETION TIME (i.e. 10): ";
  cin >> completion;
  cout << endl << "ISSUE TYPE (0:BUILD, 1:TEST, 2:DEBUG): ";
  cin >> issue_type;
  cout << endl << "STATUS (0:OPEN, 1:IN PROGRESS, 2:DONE): ";
  cin >> issue_status;

  Issue *issue = new Issue(priority, date, completion, description, issue_type, issue_status);
  project->get_sprint().at(input)->add_issue(issue);
  delete issue;
  cout << "ISSUE SUCCESSFULLY ADDED TO SPRINT" << endl;
}

// function to change sprint
void edit_sprint(int input){
  int edit_issue_input;
  int num_issues = project->get_sprint().at(input-1)->get_issues().size();
  for (int j=0; j<num_issues; j++){
    cout << '[' << j+1 << ']'<<  "EDIT ISSUE: ";
    cout << project->get_sprint().at(input-1)->get_issues().at(j)->get_description() << endl;
  }
  cout << '[' << num_issues+1 << ']' << "ADD ISSUE" << endl;
  cout << '[' << num_issues+2 << ']' << "QUIT" << endl;

  cin >> edit_issue_input;
  cout << line << endl;
  if (edit_issue_input < num_issues){
    edit_sprint_issue(input, edit_issue_input);
  }
  else if (edit_issue_input < num_issues+1) {
    add_issue(input);
  }
  else{
    exit(0);
  }
}

// edit issue in to-do
void edit_todo(int input){
  int edit_input;
  project->get_todo().at(input-1)->display();
  cout << "[1] EDIT DESCRIPTION: " << project->get_todo().at(input-1)->get_description() << endl;
  cout << "[2] EDIT PRIORITY: " << project->get_todo().at(input-1)->get_priority() << endl;
  cout << "[3] EDIT COMPLETION TIME: " << project->get_todo().at(input-1)->get_completion_time() << endl;
  cout << "[4] EDIT USERS: " << endl;
  cin >> edit_input;
  switch(edit_input){
    case 1:
    { 
      char new_description[100];
      cout << "ENTER NEW DESCRIPTION: ";
      cin.ignore();
      cin.getline(new_description, 100);
      project->get_todo().at(input-1)->set_description(new_description);
      break;
    }
    case 2:
    {
      int new_priority;
      cout << "ENTER NEW PRIORITY (1,2,3): ";
      cin >> new_priority;
      project->get_todo().at(input-1)->set_priority(new_priority);
      break;
    }
    case 3:
    {
      int new_completion_time;
      cout << "ENTER NEW COMPLETION TIME: ";
      cin >> new_completion_time;
      project->get_todo().at(input-1)->set_completion_time(new_completion_time);
      break;
    }
    case 4:
    {
      for (auto user:project->get_todo().at(input-1)->get_users()){
        user->display();
      }
      int todo_user_input;
      cout << "[1] ADD USER" << endl;
      cout << "[2] REMOVE USER" << endl;
      cin >> todo_user_input;
      switch(todo_user_input){
        case 1:
        { 
          string username;
          cout << "ENTER USERNAME: " << endl;
          cin >> username;
          auto it_users = find_if(project->get_todo().at(input-1)->get_users().begin(), project->get_todo().at(input-1)->get_users().end(), [&username](User* &user) {return user->get_username() == username;});
          auto index = distance(users.begin(), it_users);
          project->get_todo().at(input-1)->add_user(users.at(index));
        }
        case 2:
        {
          string username;
          cout << "ENTER USERNAME: " << endl;
          cin >> username;
          auto it_users = find_if(project->get_todo().at(input-1)->get_users().begin(), project->get_todo().at(input-1)->get_users().end(), [&username](User* &user) {return user->get_username() == username;});
          auto index = distance(users.begin(), it_users);
          project->get_todo().at(input-1)->remove_user(index);
        }
      }
    }
  }
}

// add new issue to to-do
void add_todo(){
  int priority, date, completion, issue_type, issue_status, issue_user;
  char description[100];

  cout << "TO ADD AN ISSUE, PLEASE ENTER: " << endl;
  cout << "DESCRIPTION: ";
  cin.ignore();
  cin.getline(description, 100);
  cout << endl << "PRIORITY (1, 2, 3): ";
  cin >> priority;
  cout << endl << "DATE (i.e. 021221): ";
  cin >> date;
  cout << endl << "COMPLETION TIME (i.e. 10): ";
  cin >> completion;
  cout << endl << "ISSUE TYPE (0:BUILD, 1:TEST, 2:DEBUG): ";
  cin >> issue_type;
  cout << endl << "STATUS (0:OPEN, 1:IN PROGRESS, 2:DONE): ";
  cin >> issue_status;
  // cout << endl << "ASSIGNED USER (USERNAME): ";
  // cin >> issue_user;

  Issue *issue = new Issue(priority, date, completion, description, issue_type, issue_status);
  vector<Issue*>add = {issue};
  project->add_issues(add);
  delete issue;
  cout << "ISSUE SUCCESSFULLY ADDED" << endl;
}

// function for project lead to edit project
void edit_project(){
  int edit_input;
  cout << "[1] VIEW/EDIT COLLABORATORS" << endl
    << "[2] VIEW/EDIT ISSUES" << endl
    << "[3] VIEW/EDIT SPRINT" << endl
    << "[4] VIEW/EDIT PROJECT NAME" << endl
    << "[5] VIEW/EDIT PROJECT DESCRIPTION" << endl
    << "[6] VIEW/EDIT USER" << endl
    << "[7] QUIT" << endl;
  cin >> edit_input;
  cout << line << endl;
  switch(edit_input){

    // CHANGE COLLABORATORS
    case 1:
    {
      int change_collaboraters_input;
      int total = project->get_users().size();
      for (int i=1; i<project->get_users().size()+1; i++){
        if (project->get_users().at(i-1)->get_type() == 0){
          cout << '[' << i << ']'<<  "EDIT LEADER ROLE: " << project->get_users().at(i-1)->get_username() << endl;
        }
        else{
          cout << '[' << i << ']'<<  "EDIT MEMBER ROLE: " << project->get_users().at(i-1)->get_username() << endl;
        }
      }
      cout << '[' << total+1 << ']' << "ADD USER" << endl;
      cout << '[' << total+2 << ']' << "REMOVE USER" << endl;
      cout << '[' << total+3 << ']' << "QUIT" << endl;
      cin >> change_collaboraters_input;
      edit_collaborators(change_collaboraters_input);
      break;
    }
    
    // UPDATE TO DO ISSUES
    case 2:
    {
      int change_issues_input;
      for (int i=1; i<project->get_todo().size()+1; i++){
        cout << '[' << i << ']'<<  "EDIT ISSUE: " << project->get_todo().at(i-1)->get_description() << endl;
      }
      cout << '[' << project->get_todo().size()+1 << ']' << "ADD ISSUE" << endl;
      cin >> change_issues_input;
      cout << line << endl;
      if (change_issues_input == project->get_todo().size()+1){
        add_todo();
      }
      else {
        edit_todo(change_issues_input);
      }
      break;
    }

    //. UPDATE SPRINT
    case 3:
    {
      int change_sprint_input;
      for (int i=1; i<project->get_sprint().size()+1; i++){
        cout << '[' << i << ']'<<  "EDIT SPRINT ISSUE: " << endl;
        project->get_sprint().at(i-1)->display();
      }
      cin >> change_sprint_input;
      cout << line << endl;
      edit_sprint(change_sprint_input);
      break;
    }
    
    // UPDATE PROJECT NAME
    case 4:
    {
      char project_name_input[100];
      cout << "PROJECT NAME: " << project->get_name() << endl << "NEW NAME: ";
      cin.ignore();
      cin.getline(project_name_input, 100);
      project->set_name(project_name_input);
      break;
    }

    // UPDATE PROJECT DESCRIPTION
    case 5:
    {
      char description_input[100];
      cout << "EDIT PROJECT DESCRIPTION: " << project->get_description() << endl << "NEW DESCRIPTION: ";
      cin.ignore();
      cin.getline(description_input, 100);
      project->set_description(description_input);
      break;
    }
    
    // UPDATE USER INFORMATION
    case 6:
    {
      edit_user();
      break;
    }
    
    case 7:
    {
      exit(0);
    }

  }
  
}

// edit project function for team member
// function for project lead to edit project
void limited_edit_project(){
  int edit_input;
  cout << "[1] VIEW/EDIT ISSUES" << endl
    << "[2] VIEW/EDIT SPRINT" << endl
    << "[3] VIEW/EDIT USER" << endl
    << "[4] QUIT" <<endl;
  cin >> edit_input;
  cout << line << endl;
  switch(edit_input){
    
    // UPDATE TO DO ISSUES
    case 1:
    {
      int change_issues_input;
      for (int i=1; i<project->get_todo().size()+1; i++){
        cout << '[' << i << ']'<<  "EDIT ISSUE: " << project->get_todo().at(i-1)->get_description() << endl;
      }
      cout << '[' << project->get_todo().size()+1 << ']' << "ADD ISSUE" << endl;
      cin >> change_issues_input;
      cout << line << endl;
      if (change_issues_input == project->get_todo().size()+2){
        add_todo();
      }
      else {
        edit_todo(change_issues_input);
      }
      break;
    }

    //. UPDATE SPRINT
    case 2:
    {
      int change_sprint_input;
      for (int i=1; i<project->get_sprint().size()+1; i++){
        cout << '[' << i << ']'<<  "EDIT SPRINT ISSUE: " << endl;
        project->get_sprint().at(i-1)->display();
      }
      cin >> change_sprint_input;
      cout << line << endl;
      edit_sprint(change_sprint_input);
      break;
    }
    
    // UPDATE USER INFORMATION
    case 3:
    {
      limited_edit_user();
      break;
    }

    // exit program
    case 4:
    {
      exit(0);
    }
  }
  
}

int get_type_num(string type){
  if (type == "BUILD"){
    return 0;
  }
  else if (type == "TEST"){
    return 1;
  }
  else {
    return 2;
  }
}

int get_status_num(string status){
  if (status == "OPEN"){
    return 0;
  }
  else if (status == "IN_PROGRESS"){
    return 1;
  }
  else if (status == "DONE"){
    return 2;
  }
  else {
    return 3;
  }
}

