cmake_minimum_required(VERSION 3.5)
project(packcpp)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(webots_ros2_driver REQUIRED)

add_executable(robot_cpp src/robot_cpp.cpp)
target_include_directories(robot_cpp PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  robot_cpp
  "rclcpp"
  "geometry_msgs"
  "webots_ros2_driver"
)

install(TARGETS robot_cpp
  DESTINATION lib/${PROJECT_NAME}
  )

install(DIRECTORY 
  launch 
  scripts 
  worlds
  DESTINATION share/${PROJECT_NAME}
  )

# install(PROGRAMS scripts/webots_launcher.py
#   DESTINATION lib/${PROJECT_NAME})

file(GLOB SCRIPT_FILES scripts/*)
install(PROGRAMS ${SCRIPT_FILES}
  DESTINATION lib/${PROJECT_NAME})

ament_package()
