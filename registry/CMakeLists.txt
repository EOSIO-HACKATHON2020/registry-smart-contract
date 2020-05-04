cmake_minimum_required( VERSION 3.5 )

project(registry)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

include_directories(
tables
)

add_contract(registry registry 
registry.cpp
${CMAKE_CURRENT_SOURCE_DIR}/tables/form.cpp
${CMAKE_CURRENT_SOURCE_DIR}/tables/response.cpp
)
