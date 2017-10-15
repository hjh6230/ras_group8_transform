cmake_minimum_required(VERSION 2.8.3)
project(ras_group8_transform)

find_package(catkin REQUIRED
  COMPONENTS
  roscpp
  phidgets
  tf
  sensor_msgs
  message_filters
  laser_geometry
)

catkin_package(
  INCLUDE_DIRS
    include

  CATKIN_DEPENDS
    roscpp
    phidgets
    tf
    sensor_msgs
    message_filters
    laser_geometry

# DEPENDS
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(lidartrans
  src/lidar_transform_node.cpp
  src/LidarTransform.cpp
)

add_dependencies(lidartrans
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(lidartrans
  ${catkin_LIBRARIES}
)

#catkin_add_gtest(transform_tests test/test_transform.cpp src/Transform.cpp)

# Make main executable
install(
  TARGETS lidartrans
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Install headers
install(
  DIRECTORY include/lidartrans/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
)


add_executable(scan2cloud src/ScantoCloud.cpp)
target_link_libraries(scan2cloud ${catkin_LIBRARIES})

add_executable(Obj2Arm src/obj2Arm.cpp)
target_link_libraries(Obj2Arm ${catkin_LIBRARIES})

add_executable(cameratrans
  src/camera_transform_node.cpp
  src/LidarTransform.cpp
  )

add_dependencies(cameratrans
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(cameratrans
  ${catkin_LIBRARIES}
)
# Make main executable
install(
  TARGETS cameratrans
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Install headers
install(
  DIRECTORY include/cameratrans/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
)


add_executable(armtrans
  src/arm_transform_node.cpp
  src/LidarTransform.cpp
)

add_dependencies(armtrans
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(armtrans
  ${catkin_LIBRARIES}
)
# Make main executable
install(
  TARGETS armtrans
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Install headers
install(
  DIRECTORY include/armtrans/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
)