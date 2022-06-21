cmake_minimum_required(VERSION 3.10)

set(This Test)

include_directories(This ../BinaryTree)

set(Sources
    ExampleTest.cpp
    ../src/AppInit.cpp
    ../src/Factory.cpp
    ../src/IBinaryTree.cpp
    ../src/Item.cpp
    ../src/Vyvazeny.cpp
    ../src/Nevyvazeny.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This}
)