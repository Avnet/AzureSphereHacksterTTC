#pragma once

// If your application is going to connect to an IoT Central Application, then enable this define.  When
// enabled Device Twin JSON updates will conform to what IoT Central expects to confirm Device Twin settings
//#define IOT_CENTRAL_APPLICATION

// If your application is going to connect straight to a IoT Hub, then enable this define.
//#define IOT_HUB_APPLICATION

#if (defined(IOT_CENTRAL_APPLICATION) && defined(IOT_HUB_APPLICATION))
#error "Can not define both IoT Central and IoT Hub Applications at the same time only define one."
#endif 

#if (!defined(IOT_CENTRAL_APPLICATION) && !defined(IOT_HUB_APPLICATION))
#warning "Building application for no cloud connectivity"
#endif 

#ifdef IOT_CENTRAL_APPLICATION
#warning "Building for IoT Central Application"
#endif 

#ifdef IOT_HUB_APPLICATION
#warning "Building for IoT Hub Application"
#endif 

// Include SD1306 OLED code
// To use the OLED 
// Install a 128x64 OLED display onto the unpopulated J7 Display connector
// https://www.amazon.com/gp/product/B06XRCQZRX/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1
// Enable the OLED_SD1306 #define below
//#define OLED_SD1306

// Include Intercore Communication code
// This will enable reading the ALST19 light sensor data from the M0 application
// To exercise the inter-core communication code run the M0 application first
// Enable the M0_INTERCORE_COMMS #define below
//#define M0_INTERCORE_COMMS

// Defines how quickly the accelerator data is read and reported
#define ACCEL_READ_PERIOD_SECONDS 1
#define ACCEL_READ_PERIOD_NANO_SECONDS 0

// Enables I2C read/write debug
//#define ENABLE_READ_WRITE_DEBUG