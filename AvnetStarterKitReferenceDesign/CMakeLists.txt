#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

cmake_minimum_required(VERSION 3.10)

project(AvnetStarterKitReferenceDesign C) 

azsphere_configure_tools(TOOLS_REVISION "20.10")
azsphere_configure_api(TARGET_API_SET "7")
 
set_source_files_properties(lsm6dso_reg.c PROPERTIES COMPILE_FLAGS -Wno-conversion)
set_source_files_properties(lps22hh_reg.c PROPERTIES COMPILE_FLAGS -Wno-conversion)
set_source_files_properties(oled.c PROPERTIES COMPILE_FLAGS -Wno-conversion)
set_source_files_properties(sd1306.c PROPERTIES COMPILE_FLAGS -Wno-conversion)
set_source_files_properties(i2c.c PROPERTIES COMPILE_FLAGS -Wno-conversion)

# Create executable
add_executable(${PROJECT_NAME} main.c epoll_timerfd_utilities.c oled.c parson.c azure_iot_utilities.c device_twin.c i2c.c lps22hh_reg.c lsm6dso_reg.c sd1306.c)
target_link_libraries(${PROJECT_NAME} m azureiot applibs pthread gcc_s c)
target_include_directories(${PROJECT_NAME} PUBLIC ${AZURE_SPHERE_API_SET_DIR}/usr/include/azureiot ${AZURE_SPHERE_API_SET_DIR}/usr/include/azure_prov_client)
target_compile_definitions(${PROJECT_NAME} PUBLIC AZURE_IOT_HUB_CONFIGURED)

azsphere_target_hardware_definition(${PROJECT_NAME} TARGET_DIRECTORY "${projectDir}../Hardware/avnet_mt3620_sk_rev2" TARGET_DEFINITION "avnet_mt3620_sk.json")
azsphere_target_add_image_package(${PROJECT_NAME}) 