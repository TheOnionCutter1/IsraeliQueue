add_library (IsraeliQueue IsraeliQueue.hpp)
set_target_properties(IsraeliQueue PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories (IsraeliQueue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
