cmake_minimum_required(VERSION 3.12)
aux_source_directory(src DIR_LIB_SRCS)
add_library (facex ${DIR_LIB_SRCS})