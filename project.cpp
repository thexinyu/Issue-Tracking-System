#include "project.hpp"
#include "sprint.hpp"
#include "issue.hpp"
#include "user.hpp"

using namespace std;

// GETTERS AND SETTERS
void Project::set_name(string project_name){
  name = project_name;
}
string Project::get_name(){
  return name;
}
void Project::set_description(string project_description){
  description = project_description;
}
string Project::get_description(){
  return description;
}

// add and delete team members and leaders
// team leaders
void Project::add_user(User *project_user){
  users.push_back(project_user);
}
vector<User*> Project::get_users(){
  return users;
}
void Project::delete_user(int index){
  users.erase(users.begin() + index);
}

// add issues and sprints 
void Project::add_issues(vector<Issue*> issues){
  for (int i=0; i<issues.size(); i++)
    to_do.push_back(issues.at(i));
}
vector<Issue*> Project::get_todo(){
  return to_do;
}
void Project::add_sprint(Sprint* sprint){
  in_progress.push_back(sprint);
}
vector<Sprint*> Project::get_sprint(){
  return in_progress;
}
void Project::add_work_done(vector<Issue*> issues){
  for (int i=0; i<issues.size(); i++)
    work_done.push_back(issues.at(i));
}
vector<Issue*> Project::get_work_done(){
  return work_done;
}

