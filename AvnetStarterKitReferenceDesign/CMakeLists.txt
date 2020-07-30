#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

cmake_minimum_required(VERSION 3.10)
project(AvnetStarterKitReferenceDesign C) 

azsphere_configure_tools(TOOLS_REVISION "20.04")
azsphere_configure_api(TARGET_API_SET "6+Beta2007")

# Create executable
add_executable(${PROJECT_NAME} main.c epoll_timerfd_utilities.c oled.c parson.c azure_iot_utilities.c device_twin.c i2c.c lps22hh_reg.c lsm6dso_reg.c sd1306.c)
target_link_libraries(${PROJECT_NAME} m azureiot applibs pthread gcc_s c)
target_include_directories(${PROJECT_NAME} PUBLIC ${AZURE_SPHERE_API_SET_DIR}/usr/include/azureiot)
#target_compile_definitions(${PROJECT_NAME} PUBLIC AZURE_IOT_HUB_CONFIGURED)

azsphere_target_hardware_definition(${PROJECT_NAME} TARGET_DIRECTORY "${projectDir}../Hardware/avnet_mt3620_sk" TARGET_DEFINITION "avnet_mt3620_sk.json")

azsphere_target_add_image_package(${PROJECT_NAME}) 