project(Library)

add_library(time STATIC time/Time.cpp time/TimeSpan.cpp time/CustomLiterals.hpp)
add_library(smartptr STATIC smartptr/SharedPtr.cpp smartptr/UniquePtr.cpp)