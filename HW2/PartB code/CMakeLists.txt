cmake_minimum_required(VERSION 2.8.9)
project (median)
set(SOURCES median.c img_pro.c)
add_executable(median ${SOURCES} )
