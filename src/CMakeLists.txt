set(polyran_SRC fit.cpp logging.cpp)
set(polyran_LIBS m)

include_directories(${EIGEN3_INCLUDE_DIR})
add_executable(fit ${polyran_SRC})
target_link_libraries(fit ${polyran_LIBS})
