cmake_minimum_required(VERSION 3.8)
project(hello_world)

set(CMAKE_CXX_STANDARD 11)

set(wxWidgets_ROOT_DIR C:/Users/Public/cpp/wxWidgets-3.0.4)
set(wxWidgets_LIB_DIR C:/Users/Public/cpp/wxWidgets-3.0.4/lib/vc_x64_lib)
set(wxWidgets_CONFIGURATION msw)

find_package(wxWidgets REQUIRED net gl core base)

if(wxWidgets_FOUND)
	include(${wxWidgets_USE_FILE})

	set(SOURCE_FILES main.cpp app.h app.cpp frame.h frame.cpp 
	                 panel.h panel.cpp menu_bar.h menu_bar.cpp)

	add_executable(hello_gui_exe WIN32 ${SOURCE_FILES})
	target_link_libraries(hello_gui_exe ${wxWidgets_LIBRARIES})
endif()