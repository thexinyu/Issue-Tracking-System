#include "user.hpp"

using namespace std;

// GETTERS AND SETTERS
void User::set_user_id(int id_input){
  user_id = id_input;
}
int User::get_user_id(){
  return user_id;
}
void User::set_username(string user_name){
  user_name = username;
}
string User::get_username(){
  return username;
}
void User::set_first_name(string fname){
  first_name = fname;
}
string User::get_first_name(){
  return first_name;
}
void User::set_last_name(string lname){
  last_name = lname;
}
string User::get_last_name(){
  return last_name;
}
void User::set_type(int user_type){
  type = usertypes[user_type];
}
int User::get_type(){
  if (type == "LEAD"){
    return 0;
  }
  else{
    return 1;
  }
}
void User::change_role(){
  if (type == "LEAD"){
    type = usertypes[1];
  }
  else{
    type = usertypes[0];
  }
}

