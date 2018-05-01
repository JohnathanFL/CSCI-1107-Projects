cmake_minimum_required(VERSION 3.9)



project(CSCI-1107-Projects)
#set(CMAKE_CXX_STANDARD 11)

file(GLOB SUBDIRS "Source/*")
FOREACH(subdir ${SUBDIRS})
    file(GLOB CUR_SRCS "${subdir}/*.cpp" "${subdir}/*.h")
    get_filename_component(dirName ${subdir} NAME)
    add_executable(${dirName} ${CUR_SRCS})
ENDFOREACH()
