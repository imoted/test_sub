#include <ros/ros.h>
#include <std_msgs/String.h>
#include <thread>

void chatterCallback1(const std_msgs::String::ConstPtr &msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void chatterCallback2(const std_msgs::String::ConstPtr &msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "test_sub_node");
  ros::NodeHandle nh;
  ros::Subscriber sub1 = nh.subscribe("/chatter1", 1000, chatterCallback1);
  ros::Subscriber sub2 = nh.subscribe("/chatter2", 1000, chatterCallback2);
  ros::spin();
  return 0;
}
