file(GLOB_RECURSE SOURCEFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
add_library(day_02_lib ${SOURCEFILES})
target_include_directories(day_02_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(day_02_lib PUBLIC ${CMAKE_SOURCE_DIR}/ext/strutils)

file(GLOB_RECURSE UNITTESTFILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/test/*)
add_executable(day_02_test ${UNITTESTFILES})

target_link_libraries(day_02_test gtest_main)
target_link_libraries(day_02_test gmock)
target_link_libraries(day_02_test day_02_lib)
