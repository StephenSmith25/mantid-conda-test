cmake_minimum_required(VERSION 3.16)
project(mantid-framework-test)


find_package(MantidFramework)

add_executable(main main.cpp)


target_link_libraries(main PRIVATE 
    Mantid::Kernel
    Mantid::Types
    Mantid::Json
    Mantid::Parallel
    Mantid::HistogramData
    Mantid::Indexing
    Mantid::Geometry
    Mantid::Beamline
    Mantid::API
)