PROJECT(WC)

SET(CMAKE_C_COMPILER g++)
if(CMAKE_COMPILER_IS_GNUCXX)
	add_compile_options(-std=c++11)
endif(CMAKE_COMPILER_IS_GNUCXX)

SET(SRC_LIST  Link.h Stack.h functions.h exp.cpp)
ADD_EXECUTABLE(worldcup ${SRC_LIST})