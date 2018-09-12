cmake_minimum_required(VERSION 3.9)
project(Backend)

set(CMAKE_CXX_STANDARD 11)

add_executable(Backend main.cpp include/Tree.h include/matrix.h include/team.h include/Group.h include/Team.h include/Match.h include/Date.h)