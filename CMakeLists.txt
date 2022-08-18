cmake_minimum_required(VERSION 3.0.2)
project(test_sub)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
 roscpp
 std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_sub
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

include_directories(
include
${catkin_INCLUDE_DIRS}
)

add_executable(test_sub_node src/test_sub_node.cpp)
add_executable(test_pub_node src/test_pub_node.cpp)


target_link_libraries(test_sub_node
  ${catkin_LIBRARIES}
)

target_link_libraries(test_pub_node
  ${catkin_LIBRARIES}
)
