cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(myNM VERSION 0.1.0) # update here

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/myNM_bits") # update here

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/standard.hpp
    ${PROJECT_INCLUDE_DIR}/globalConstants.hpp
    ${PROJECT_INCLUDE_DIR}/test.hpp
    ${PROJECT_INCLUDE_DIR}/LineChart.hpp
    ${PROJECT_INCLUDE_DIR}/Histogram.hpp
    ${PROJECT_INCLUDE_DIR}/testing.hpp
    ${PROJECT_INCLUDE_DIR}/textFunctions.hpp

    ${PROJECT_INCLUDE_DIR}/mathematics.hpp

    ${PROJECT_INCLUDE_DIR}/RealFunction.hpp
    ${PROJECT_INCLUDE_DIR}/RealFunction2D.hpp

    ${PROJECT_INCLUDE_DIR}/BissectionMethod.hpp
    ${PROJECT_INCLUDE_DIR}/RegulaFalsiMethod.hpp
    ${PROJECT_INCLUDE_DIR}/NewtonRaphsonMethod.hpp
    ${PROJECT_INCLUDE_DIR}/SecantMethod.hpp
    ${PROJECT_INCLUDE_DIR}/PointFixedMethod.hpp

    ${PROJECT_INCLUDE_DIR}/NumericalDifferentiation.hpp
    ${PROJECT_INCLUDE_DIR}/ForwardDifferentiation.hpp
    ${PROJECT_INCLUDE_DIR}/BackwardDifferentiation.hpp
    ${PROJECT_INCLUDE_DIR}/CentralDifferentiation.hpp

    ${PROJECT_INCLUDE_DIR}/EulerMethod.hpp
    ${PROJECT_INCLUDE_DIR}/RungeKutta4Method.hpp

    ${PROJECT_INCLUDE_DIR}/TrapezoidalMethod.hpp
    ${PROJECT_INCLUDE_DIR}/Simpson1_3Method.hpp
    ${PROJECT_INCLUDE_DIR}/Simpson3_8Method.hpp

    ${PROJECT_INCLUDE_DIR}/LinearInterpolationMethod.hpp
    ${PROJECT_INCLUDE_DIR}/LagrangeInterpolationMethod.hpp
    ${PROJECT_INCLUDE_DIR}/LinearRegressionMethod.hpp
    ${PROJECT_INCLUDE_DIR}/PolynomialFittingMethod.hpp
    ${PROJECT_INCLUDE_DIR}/ExponentialFittingMethod.hpp

    ${PROJECT_INCLUDE_DIR}/Vector.hpp

    ${PROJECT_SOURCE_DIR}/test.cpp
    ${PROJECT_SOURCE_DIR}/LineChart.cpp
    ${PROJECT_SOURCE_DIR}/Histogram.cpp
    ${PROJECT_SOURCE_DIR}/testing.cpp
    ${PROJECT_SOURCE_DIR}/textFunctions.cpp

    ${PROJECT_SOURCE_DIR}/mathematics.cpp

    ${PROJECT_SOURCE_DIR}/BissectionMethod.cpp
    ${PROJECT_SOURCE_DIR}/RegulaFalsiMethod.cpp
    ${PROJECT_SOURCE_DIR}/NewtonRaphsonMethod.cpp
    ${PROJECT_SOURCE_DIR}/SecantMethod.cpp
    ${PROJECT_SOURCE_DIR}/PointFixedMethod.cpp

    ${PROJECT_SOURCE_DIR}/ForwardDifferentiation.cpp
    ${PROJECT_SOURCE_DIR}/BackwardDifferentiation.cpp
    ${PROJECT_SOURCE_DIR}/CentralDifferentiation.cpp

    ${PROJECT_SOURCE_DIR}/EulerMethod.cpp
    ${PROJECT_SOURCE_DIR}/RungeKutta4Method.cpp

    ${PROJECT_SOURCE_DIR}/TrapezoidalMethod.cpp
    ${PROJECT_SOURCE_DIR}/Simpson1_3Method.cpp
    ${PROJECT_SOURCE_DIR}/Simpson3_8Method.cpp

    ${PROJECT_SOURCE_DIR}/LinearInterpolationMethod.cpp
    ${PROJECT_SOURCE_DIR}/LagrangeInterpolationMethod.cpp

    ${PROJECT_SOURCE_DIR}/LinearRegressionMethod.cpp
    ${PROJECT_SOURCE_DIR}/PolynomialFittingMethod.cpp
    ${PROJECT_SOURCE_DIR}/ExponentialFittingMethod.cpp

    ${PROJECT_SOURCE_DIR}/Vector.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(myNM SHARED ${SOURCE_FILES}) # update here

# Include directories
target_include_directories(myNM PRIVATE include/myNM_bits) # update here 2 times

# Install
install(TARGETS myNM DESTINATION lib) # update here

# Install the headers
install(FILES include/myNM DESTINATION include) # update here

# Create base directory
install(DIRECTORY include/myNM_bits DESTINATION include) # update here
