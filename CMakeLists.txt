cmake_minimum_required(VERSION 3.16)
project(mantid-framework-test)


find_package(MantidFramework)

add_executable(main main.cpp)

# expecing the following targets to be set:
    # Types
    # Json
    # Kernel
    # Parallel
    # HistogramData
    # Indexing
    # Beamline
    # Geometry
    # API
    # NexusGeometry
    # DataObjects
    # Catalog
    # Nexus
    # PythonInterfaceCore


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
    Mantid::NexusGeometry
    Mantid::DataObjects
    Mantid::Catalog
    Mantid::Nexus
    Mantid::PythonInterfaceCore
)