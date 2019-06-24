#最低版本要求
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

#工程名,类似workspace和workshop的概念
PROJECT(first_blood)
#C++特性,其实就是最终编译选项加上--std=c++11
SET(CMAKE_CXX_STANDARD 11)
#编译选项
ADD_DEFINITIONS(-pipe -g -Wall -fPIC -Wno-deprecated-declarations -Wl,--as-needed)
#结果可执行文件存放在工程根目录的releass下,默认在CMakeLists.txt同级目录,不要用相对目录,因为变量会被ADD_SUBDIRECTORY里的子目录继承
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release)
#结果库文件存放路径
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/release)

#工程依赖的第三方库
#cmake3内置了很多依赖cmake3 --help-module-list
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/extern_modules")
#会去CMAKE_MODULE_PATH路径下找Findjsoncpp.cmake文件拿到jsoncpp_FOUND,jsoncpp_INCLUDE_DIR,jsoncpp_LIBRARY三个变量
FIND_PACKAGE(jsoncpp REQUIRED)
#不用怕这三个变量膨胀,链接器会过滤掉不需要的
SET(COMM_INCS ${jsoncpp_INCLUDE_DIR})
SET(COMM_PATHS ${jsoncpp_LIBRARY})
SET(COMM_LIBS jsoncpp)

#编译子目录
ADD_SUBDIRECTORY(./src)

