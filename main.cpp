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
#include "menus.hpp"
#include "initial.hpp"
#include "data_persistence.hpp"

using namespace std;

// UI
string line = "------------------------------------------------------";

// Initialize
User * currentuser;
vector<User*> users;
Project *project = new Project("Project 1104", "The poggest project out there", users);



// Initialize issue types and statuses
string types[] = {
  "BUILD",
  "TEST",
  "DEBUG"
};
string statuses[] = {
  "OPEN",
  "IN_PROGRESS",
  "DONE",
  "OVERDUE"
};
string usertypes[] = {
  "LEAD",
  "MEMBER"
};


int main() {
  initialize();
  start_menu();
  run_program();
  save_file("saved.txt");
  return (0);
} 