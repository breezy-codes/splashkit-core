# Install script for directory: /home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/breezy/Documents/Thoth-Tech/splashkit-core/out/lib/libSplashKitBackend.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/CMakeFiles/SplashKitBackend.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SplashKitBackend" TYPE FILE FILES
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/animations.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/audio.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/basics.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/bundles.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/camera.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/circle_drawing.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/circle_geometry.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/clipping.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/collisions.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/color.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/drawing_options.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/ellipse_drawing.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/geometry.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/graphics.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/images.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/input.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/interface.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/json.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/keyboard_input.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/line_drawing.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/line_geometry.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/logging.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/matrix_2d.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/mouse_input.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/music.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/networking.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/physics.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/point_drawing.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/point_geometry.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/quad_geometry.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/random.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/raspi_gpio.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/rectangle_drawing.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/rectangle_geometry.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/resources.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/sound.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/sprites.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/terminal.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/text.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/text_input.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/timers.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/triangle_drawing.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/triangle_geometry.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/types.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/utils.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/vector_2d.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/web_client.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/web_server.h"
    "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/../../coresdk/src/coresdk/window_manager.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/breezy/Documents/Thoth-Tech/splashkit-core/projects/cmake/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
