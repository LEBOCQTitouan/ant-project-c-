# MIT License 
# Copyright (c) 2022-Today Titouan Lebocq <lebocq.titouan@gmail.com>
#
# Dependencies

# Required for Testing
if(BUILD_TESTING)
  find_package(doctest REQUIRED)
endif()

# Optional Dependency, doesn't trigger error if missing
find_package(OpenSSL)
