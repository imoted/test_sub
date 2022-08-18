#include <ros/ros.h>
#include <std_msgs/String.h>
#include <thread>

int main(int argc, char **argv) {
  ros::init(argc, argv, "test_pub_node");
  ros::NodeHandle nh;
  ros::Publisher pub1 = nh.advertise<std_msgs::String>("/chatter1", 1000);
  ros::Publisher pub2 = nh.advertise<std_msgs::String>("/chatter2", 1000);

  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  std_msgs::String msg1;
  msg1.data = "hello1";
  std_msgs::String msg2;
  msg2.data = "hello2";

  pub1.publish(msg1);
  pub2.publish(msg2);

  ros::spin();
  return 0;
}
