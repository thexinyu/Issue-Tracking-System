#include "issue.hpp"
#include "user.hpp"

using namespace std;

extern string types[];
extern string statuses[];

// GETTERS AND SETTERS
void Issue::set_priority(char issue_priority){
  priority = issue_priority;
}
int Issue::get_priority(){
  return priority;
}
void Issue::set_date_created(int creation_date){
  date_created = creation_date;
}
int Issue::get_date_created()const{
  return date_created;
}
void Issue::set_completion_time(int time_complete){
  completion_time = time_complete;
}
int Issue::get_completion_time(){
  return completion_time;
}
void Issue::set_description(string issue_description){
  description = issue_description;
}
string Issue::get_description(){
  return description;
}
void Issue::set_comments(string issue_comments){
  comments = issue_comments;
}
string Issue::get_comments(){
  return comments;
}
void Issue::set_type(int issue_type){
  type = types[issue_type];
}
string Issue::get_type() {
  return type;
}
void Issue::set_status(int issue_status){
  status = statuses[issue_status];
}
string Issue::get_status(){
  return status;
}
void Issue::add_user(User* user){
  assignees.push_back(user);
}
vector<User*> Issue::get_users(){
  return assignees;
}
void Issue::remove_user(int user_ind){
  assignees.erase(assignees.begin()+user_ind);
}
