  /*
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Copyright (c) 2015 - 2016 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/**
 * @file
 * @ingroup grove 
 * @brief Analog Input
 * 
 * Demonstrate how to read an analog voltage value from an input pin using the
 * MRAA library, any sensor that outputs a variable voltage can be used with
 * this example code.
 * Suitable ones in the Grove Starter Kit are the Rotary Angle Sensor, Light
 * Sensor, Sound Sensor, Temperature Sensor.
 *
 * @hardware Analog sensor connected to pin A0 (Grove Base Shield Port A0)
 *
 * @date 13/06/2015
 */
#include "mraa.hpp"
#include "mraa.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
int main()
{
 // check that we are running on Galileo or Edison
 mraa_platform_t platform = mraa_get_platform_type();
 if ((platform != MRAA_INTEL_GALILEO_GEN1) &&
   (platform != MRAA_INTEL_GALILEO_GEN2) &&
   (platform != MRAA_INTEL_EDISON_FAB_C)) {
  std::cerr << "Unsupported platform, exiting" << std::endl;
  return MRAA_ERROR_INVALID_PLATFORM;
 }
 mraa_gpio_context d_pin_button_1 = NULL;
  mraa_gpio_context d_pin_button_2 = NULL;
  mraa_gpio_context d_pin_button_3 = NULL;
  mraa_gpio_context d_pin_1 = NULL;
  mraa_gpio_context d_pin_2 = NULL;
  mraa_gpio_context d_pin_3 = NULL;
  mraa_gpio_context d_pin_4 = NULL;
 // create an analog input object from MRAA using pin A0
 mraa::Aio* a_pin_1 = new mraa::Aio(0);
 mraa::Aio* a_pin_2 = new mraa::Aio(1);
 mraa::Aio* a_pin_3 = new mraa::Aio(2);
 d_pin_1 = mraa_gpio_init(5);
    d_pin_2 = mraa_gpio_init(6);
    d_pin_3 = mraa_gpio_init(7);
    d_pin_4 = mraa_gpio_init(8);
    uint16_t pin_value_1, pin_value_2, pin_value_3;
     int i;
 if (a_pin_1 == NULL) {
  std::cerr << "Can't create mraa::Aio object, exiting" << std::endl;
  return MRAA_ERROR_UNSPECIFIED;
 }
 // set the pin as output
  if (mraa_gpio_dir(d_pin_1, MRAA_GPIO_OUT) != MRAA_SUCCESS &&
    mraa_gpio_dir(d_pin_2, MRAA_GPIO_OUT) != MRAA_SUCCESS &&
    mraa_gpio_dir(d_pin_3, MRAA_GPIO_OUT) != MRAA_SUCCESS &&
    mraa_gpio_dir(d_pin_4, MRAA_GPIO_OUT) != MRAA_SUCCESS ) {
   fprintf(stderr, "Can't set digital pin as output, exiting");
   return MRAA_ERROR_UNSPECIFIED;
  };
  char *value_wlan_p;
  char value_wlan = 0;
  //FILE *fp = fopen("/water.txt", "r");
  //for(;;) {
  //FILE *fp = fopen("/water.txt", "r");
  //while(!feof(fp)){
   //fgets(value_wlan_p, 1, fp);
   //printf("value_wlan:%c\n", *value_wlan_p);
  //}
  ////value_wlan = *value_wlan_p;
  //fclose(fp);
  //printf("value_wlan_int:%d\n", value_wlan);
 // loop forever printing the input value every second
 if(value_wlan == 1) {
  for(i=0;i<10;i++) {
        mraa_gpio_write(d_pin_4, 0);
        sleep(1);
        mraa_gpio_write(d_pin_4, 1);
        sleep(1);
       }
 }
 for (;;) {
  pin_value_1 = a_pin_1->read();
  std::cout << "analog input value1 " << pin_value_1 << std::endl;
  sleep(0.2);
  pin_value_2 = a_pin_2->read();
  std::cout << "analog input value2 " << pin_value_2 << std::endl;
  sleep(0.2);
  pin_value_3 = a_pin_3->read();
  std::cout << "analog input value3 " << pin_value_3 << std::endl;
  sleep(0.2);
  if (pin_value_1 >=100) {
     for(i=0;i<10;i++) {
      mraa_gpio_write(d_pin_4, 0);
      sleep(1);
      mraa_gpio_write(d_pin_4, 1);
      sleep(1);
     }
  } else if (pin_value_2 >=100){
     mraa_gpio_write(d_pin_1, 0);
     sleep(1);
     mraa_gpio_write(d_pin_1, 1);
     sleep(1);
     mraa_gpio_write(d_pin_2, 0);
     sleep(1);
     mraa_gpio_write(d_pin_2, 1);
     sleep(1);
  } else if(pin_value_3 >=100) {
     mraa_gpio_write(d_pin_3, 0);
     sleep(1);
     mraa_gpio_write(d_pin_3, 1);
     sleep(1);
  } else {
     // do noting!
    }
  }
 //}
  //fclose(fp);
 return MRAA_SUCCESS;
}