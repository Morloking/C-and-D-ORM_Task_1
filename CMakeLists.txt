cmake_minimum_required (VERSION 3.22)

project(homework_orm)

set(WT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/orm/WT 4.15.0 msvs2022 x64")
set(PG_DIR "C:/Program Files/PostgreSQL/18")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "${WT_DIR}")
find_package(Wt REQUIRED)

add_executable(homework_orm
main.cpp
consts.h
models/publisher.h
models/book.h
models/shop.h
models/stock.h
models/sale.h
models/general_models.h
)

target_link_libraries(homework_orm PRIVATE
"${WT_DIR}/lib/wt.lib"
"${WT_DIR}/lib/wtdbo.lib"
"${WT_DIR}/lib/wtdbopostgres.lib"
)

target_include_directories(homework_orm PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}/models
"${WT_DIR}/include"
)

file(GLOB PG_DLLS "${PG_DIR}/bin/*.dll")
file(GLOB ALL_WT_DLLS "${WT_DIR}/bin/*.dll")
set(WT_RELEASE_DLLS ${ALL_WT_DLLS})
list(FILTER WT_RELEASE_DLLS EXCLUDE REGEX ".*d\\.dll$")


add_custom_command(TARGET homework_orm POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_if_different
${WT_RELEASE_DLLS}
${PG_DLLS}
"$<TARGET_FILE_DIR:homework_orm>"
)