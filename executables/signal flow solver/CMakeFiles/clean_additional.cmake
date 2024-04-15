# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Signal_flow_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Signal_flow_autogen.dir\\ParseCache.txt"
  "Signal_flow_autogen"
  )
endif()
