#include "project.hpp"
#include "sprint.hpp"
#include "issue.hpp"
#include "user.hpp"
#include "menus.hpp"
#include "data_persistence.hpp"

extern string line;
extern Project* project;
extern vector<User*> users;

void initialize(){
  // create members
  User *user_1 = new User(0, 100, "em", "Emily", "Wang");
  User *user_2 = new User(0, 200, "xi", "Xinyu", "Wu");
  User *user_3 = new User(1, 300, "ni", "Nicole", "Al");
  User *user_4 = new User(1, 400, "an", "Angel", "Lu");
  User *user_5 = new User(1, 500, "to", "Tommy", "Be");

  // add users to data storage vectors
  users.push_back(user_1);
  users.push_back(user_2);
  users.push_back(user_3);
  users.push_back(user_4);
  users.push_back(user_5);

  // assign users to project
  for (int i=0; i<users.size(); i++){
    project->add_user(users.at(i));
  }

  // create issues
  Issue *issue_1 = new Issue(3, 122021, 8, "complete task1", 0, 1);
  Issue *issue_2 = new Issue(2, 102021, 4, "complete task2", 0, 2);
  Issue *issue_3 = new Issue(3, 012021, 4, "complete task3", 1, 0);
  Issue *issue_4 = new Issue(3, 022021, 9, "task 4", 2, 0);
  Issue *issue_5 = new Issue(3, 012221, 10, "comment code", 1, 2);
  Issue *issue_6 = new Issue(3, 122021, 5, "finish project", 2, 1);

  issue_1->add_user(user_1);
  issue_1->add_user(user_3);
  issue_1->add_user(user_5);
  issue_2->add_user(user_1);
  issue_2->add_user(user_2);
  issue_3->add_user(user_2);
  issue_4->add_user(user_2);
  issue_4->add_user(user_5);
  issue_4->add_user(user_4);
  issue_5->add_user(user_1);
  issue_6->add_user(user_1);
  issue_6->add_user(user_2);
  issue_6->add_user(user_4);

  vector<Issue*> issues = {issue_1, issue_2, issue_3, issue_4, issue_5, issue_6};
  vector<Issue*> issues1 = {issue_1, issue_6};
  vector<Issue*> issues2 = {issue_3, issue_2, issue_4, issue_5};

  Sprint *sprint_1 = new Sprint(3, 5, issues1);
  Sprint *sprint_2 = new Sprint(4, 9, issues2);


  project->add_issues(issues);
  project->add_sprint(sprint_1);
  project->add_sprint(sprint_2);

  write_file("saved.txt");
  
  // deallocate memory
  delete issue_1;
  delete issue_2;
  delete issue_3;
  delete issue_4;
  delete issue_5;
  delete issue_6;
  delete sprint_1;
  delete sprint_2;

}