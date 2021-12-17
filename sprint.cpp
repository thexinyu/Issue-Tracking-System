#include "sprint.hpp"
#include "issue.hpp"

using namespace std;

// GETTERS AND SETTERS
void Sprint::set_time(int time_input){
  time = time_input;
}
int Sprint::get_time(){
  return time;
}
void Sprint::set_timeframe(int sprint_timeframe){
  timeframe = sprint_timeframe;
}
int Sprint::get_timeframe(){
  return timeframe;
}
vector<Issue*> Sprint::get_issues(){
  return issues;
}

// FUNCTION DEFINITIONS
void Sprint::add_issue(Issue* sprint_issue){
  issues.push_back(sprint_issue);
}
void Sprint::add_time(int added_time){
  time+=added_time;
}
