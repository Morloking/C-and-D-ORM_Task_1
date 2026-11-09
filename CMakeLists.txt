cmake_minimum_required (VERSION 3.22)

project(homework_orm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(homework_orm
main.cpp
consts.h
)

set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/orm/WT 4.15.0 msvs2022 x64")
find_package(Wt REQUIRED)


set(PostgreSQL_ROOT "C:/Program Files/PostgreSQL/18")

target_link_libraries(homework_orm PRIVATE
Wt::Wt
Wt::Dbo
Wt::DboPostgres
)