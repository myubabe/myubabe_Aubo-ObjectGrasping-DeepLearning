cmake_minimum_required(VERSION 2.8.3)
project(my_aubo_i5_robot_config)
add_compile_options(-std=c++11)

find_package(Eigen3 REQUIRED)

# Eigen 3.2 (Wily) only provides EIGEN3_