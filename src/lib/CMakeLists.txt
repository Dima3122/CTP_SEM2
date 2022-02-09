project(Library)

add_library(time STATIC time/Time.cpp time/TimeSpan.cpp time/CustomLiterals.hpp)
add_library(smartptr STATIC smartptr/SharedPtr.cpp smartptr/UniquePtr.cpp)
add_library(soundex STATIC soundex/soundex.cpp)
set_compile_options(time)
set_compile_options(smartptr)
set_compile_options(soundex)