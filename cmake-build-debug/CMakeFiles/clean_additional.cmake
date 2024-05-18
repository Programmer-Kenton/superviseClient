# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\superviseClient_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\superviseClient_autogen.dir\\ParseCache.txt"
  "superviseClient_autogen"
  )
endif()
