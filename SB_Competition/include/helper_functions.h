#include "vex.h"
#include <string>
using namespace vex;

competition Competition;
motor_group Intake(IL, IR);
motor_group Tray(TL,TR);

std::string l =  "left";
std::string r =  "right";
std::string f = "fwd";
std::string b = "bwd";

void turn(std::string dir, int speed, int time) {
  if (dir == "right") {
    L.spin(reverse, speed, percent);
    R.spin(forward, speed, percent);
  }
  
  else if (dir == "lift") {
    L.spin(reverse, speed, percent);
    R.spin(forward, speed, percent);
  }

  wait(500, msec);
  return;
} 

void drive(std::string dir, int speed, int time) {
 
 if(dir == "fwd") {
  L.spin(forward, speed, percent);
  R.spin(forward, speed, percent); 
  }

 else if (dir == "bwd") {
  L.spin(reverse, speed, percent);
  R.spin(reverse, speed, percent); 
  }

  if (time != -1)
    wait(time, msec);

  return;
}

void stop() {
  L.stop(hold);
  R.stop(hold);
}

void setup() {
  L.spin(forward, 35, percent);
  R.spin(forward, 35, percent);
  wait(250, msec);

  L.spin(reverse, 75, percent);
  R.spin(reverse, 75, percent);
  wait(500, msec);


  Lift.spin(forward, 100, percent);
  wait(1000,msec);
  
  Lift.spin(reverse, 100, percent);
  wait(1000,msec);
  
  L.stop(hold);
  R.stop(hold);

  return;
}