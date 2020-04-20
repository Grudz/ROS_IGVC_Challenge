// ----------------- IGVC COURSE PROJECT -----------------
//
// Due Date: Wednesday, April 22nd 2020
// Professor: Wing-Yue Geoffrey Louie
// Course: Introduction to Autonomous Vehicle Systems
// Authors: Benjamin Grudzien and Sam Tkac
//
// **********************************************************
//
// Notes: This code differs from the examples in class. 
//        Basically, we are using the action library
//        to send move_base goals to the robot. This 
//        was reccomended by the ROS Wiki. For this advanced
//        course, several waypoints were added for the
//        sole purpose of helping the robot navigate out
//        of tough situations.
//        Link: http://wiki.ros.org/navigation/Tutorials/SendingSimpleGoals

#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

int current_waypoint = 0;
move_base_msgs::MoveBaseGoal goal;

int main(int argc, char** argv){

ros::init(argc, argv, "simple_navigation_goals");
ROS_INFO("Start move base");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

//tell the action client that we want to spin a thread by default
MoveBaseClient ac("move_base", true);

//wait for the action server to come up
while(!ac.waitForServer(ros::Duration(5.0))){
ROS_INFO("Waiting for the move_base action server to come up");
}
 
if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ++current_waypoint; 
}

ROS_INFO("check waypoint");
 
// Checks waypoint status and action clients status to make decsion
switch(current_waypoint){

 case 0 :
     
ROS_INFO("current_waypoint check 1: (%d)", current_waypoint);

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

// Sends the goal in the map frame with a position and orientation
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = 21.92;
goal.target_pose.pose.position.y = 15.65;
goal.target_pose.pose.orientation.w = 1.0;
 
ROS_INFO("Sending goal");
ac.sendGoal(goal);

ac.waitForResult();
ROS_INFO("Waiting for result");

if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ++current_waypoint; 
    ROS_INFO("Hooray, the base moved");
}
else
     ROS_INFO("The base failed to move for some reason");

ROS_INFO("current_waypoint check 2: (%d)", current_waypoint);

ROS_INFO("end case 0");

 case 1 : 
     
ROS_INFO("start case 1: North 3");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = 16.43;
goal.target_pose.pose.position.y = 7.41;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 2 : 
     
ROS_INFO("start case 2: North 3 exit aid");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = 15.31017;
goal.target_pose.pose.position.y = 6.4467;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 3 : 
     
ROS_INFO("start case 3: North 2");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -2.42;
goal.target_pose.pose.position.y = 7.62;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 4 : 
     
ROS_INFO("start case 4: North 1");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -18.05;
goal.target_pose.pose.position.y = 7.00;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 5 : 
     
ROS_INFO("start case 5: North 1 exit help");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -11.5264;
goal.target_pose.pose.position.y = 6.467;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 6 : 
     
ROS_INFO("start case 6: South 1");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -16.92;
goal.target_pose.pose.position.y = -5.04;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 7 : 
     
ROS_INFO("start case 7: South 1 exit aid");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -18.2185;
goal.target_pose.pose.position.y = -4.0423;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 8 : 
     
ROS_INFO("start case 8: South 2");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -1.37;
goal.target_pose.pose.position.y = -4.78;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 9 : 
     
ROS_INFO("start case 9: South 3");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = 16.81;
goal.target_pose.pose.position.y = -8.64;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 10 : 
     
ROS_INFO("start case 10: South Opening");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = 22.02;
goal.target_pose.pose.position.y = -15.23;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 11 : 
     
ROS_INFO("start case 11: South Gauntlet Help");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -2.5766;
goal.target_pose.pose.position.y = -17.48622;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 12 : 
     
ROS_INFO("start case 11: South Gauntlet Help 2");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -5.3379;
goal.target_pose.pose.position.y = -20.505;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 case 13 : 
     
ROS_INFO("start case 13: Finish");

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
     
goal.target_pose.header.frame_id = "map";
goal.target_pose.header.stamp = ros::Time::now();
goal.target_pose.pose.position.x = -25;
goal.target_pose.pose.position.y = 0.0;
goal.target_pose.pose.orientation.w = 1.0;

ROS_INFO("Sending goal");
ac.sendGoal(goal);
 
ac.waitForResult();

 }

ros::spin();
}

