project(accountsqt-testcase)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
enable_testing()

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

find_package(AccountsQt REQUIRED)
find_package(SignOnQt REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${ACCOUNTSQT_INCLUDE_DIRS} ${SIGNONQT_INCLUDE_DIRS})

set(accountsqt-testcase_SRCS accountsqt-testcase.cpp main.cpp)
qt4_automoc(${accountsqt-testcase_SRCS})
add_executable(accountsqt-testcase ${accountsqt-testcase_SRCS})
target_link_libraries(accountsqt-testcase ${QT_QTCORE_LIBRARY} ${ACCOUNTSQT_LIBRARIES} ${SIGNONQT_LIBRARIES})