
# Build data static lib
add_library(data STATIC data.cpp reader.cpp)
set_target_properties(data PROPERTIES CLEAN_DIRECT_OUTPUT 1)
install(TARGETS data DESTINATION ${BUILD_RESULT_DIR}/libs)

# Build unit tests
add_executable(data_test data_test.cpp)
target_link_libraries(data_test gtest_main gtest data common)
install(TARGETS data_test DESTINATION ${BUILD_RESULT_DIR}/test)