//
// Created by afy on 3/3/21.
//

#ifndef TELEMETRIX4RPIPICO_TELEMETRIX4RPIPICO_H
#define TELEMETRIX4RPIPICO_TELEMETRIX4RPIPICO_H
/************************** FORWARD REFERENCES ***********************
We define all functions here as extern to provide allow
forward referencing.
**********************************************************************/

extern void serial_loopback();

extern void set_pin_mode();

extern void digital_write();

extern void pwm_write();

extern void modify_reporting();

extern void get_firmware_version();

extern void get_pico_unique_id();

extern void servo_attach();

extern void servo_write();

extern void servo_detach();

extern void i2c_begin();

extern void i2c_read();

extern void i2c_write();

extern void sonar_new();

extern void serial_write(int *buffer, int num_of_bytes_to_send);

extern void led_debug(int blinks, uint delay);

extern void send_debug_info(uint id, uint value);

extern void dht_new();

extern void stop_all_reports();

extern void enable_all_reports();

extern void reset_data();

extern void reset_board();

extern void scan_digital_inputs();

extern void scan_analog_inputs();



/*********************************************************
 *                       COMMAND DEFINES
 ********************************************************/

// Commands -received by this sketch
// Add commands retaining the sequential numbering.
// The order of commands here must be maintained in the command_table below.
#define SERIAL_LOOP_BACK 0
#define SET_PIN_MODE 1
#define DIGITAL_WRITE 2
#define PWM_WRITE 3
#define MODIFY_REPORTING 4 // mode(all, analog, or digital), pin, enable or disable
#define GET_FIRMWARE_VERSION 5
#define GET_PICO_UNIQUE_ID  6
#define SERVO_ATTACH 7
#define SERVO_WRITE 8
#define SERVO_DETACH 9
#define I2C_BEGIN 10
#define I2C_READ 11
#define I2C_WRITE 12
#define SONAR_NEW 13
#define DHT_NEW 14
#define STOP_ALL_REPORTS 15
#define ENABLE_ALL_REPORTS 16
#define RESET_DATA 17
#define RESET_BOARD 18

/*****************************************************
 *                  MESSAGE OFFSETS
 ***************************************************/
// i2c_common
#define I2C_PORT 1
#define I2C_DEVICE_ADDRESS 2 // read and write

// i2c_init
#define I2C_SDA_GPIO_PIN 2
#define I2C_SCL_GPIO_PIN 3

// i2c_read
#define I2C_READ_REGISTER 3
#define I2C_READ_LENGTH 4
#define I2C_READ_NO_STOP_FLAG 5

// I2c_write
#define I2C_WRITE_NUMBER_OF_BYTES 3
#define I2C_WRITE_NO_STOP_FLAG 4
#define I2C_WRITE_BYTES_TO_WRITE 5

// This defines how many bytes there are
// that precede the first byte read position
// in the i2c report message buffer.
#define I2C_READ_DATA_BASE_BYTES 5

// Start of i2c data read within the message buffer
#define I2C_READ_START_OF_DATA 6

// Indicator that no i2c register is being specified in the command
#define I2C_NO_REGISTER 254

/******************************* COMMAND BUFFER OFFSETS ************/
// loop back command buffer offsets
#define DATA_TO_LOOP_BACK 1

// set pin mode command buffer offsets
#define SET_PIN_MODE_GPIO_PIN 1
#define SET_PIN_MODE_MODE_TYPE 2

// set pin mode digital input command offsets
#define SET_PIN_MODE_DIGITAL_IN_REPORTING_STATE 3

// set pin mode PWM output input command offsets
#define SET_PIN_MODE_PWM_HIGH_VALUE 3
#define SET_PIN_MODE_PWM_LOW_VALUE 4

// ADC number for temperature sensor
#define ADC_TEMPERATURE_REGISTER 4

// set pin mode analog input command offsets
#define SET_PIN_MODE_ANALOG_IN_REPORTING_STATE 5
#define SET_PIN_MODE_ANALOG_DIFF_HIGH 3
#define SET_PIN_MODE_ANALOG_DIFF_LOW 4

// digital_write
#define DIGITAL_WRITE_GPIO_PIN 1
#define DIGITAL_WRITE_VALUE 2

// pwm write
#define PWM_WRITE_GPIO_PIN 1
#define PWM_WRITE_HIGH_VALUE 2
#define PWM_WRITE_LOW_VALUE 3

// modify reporting
// This can be a gpio pin or adc channel
#define MODIFY_REPORTING_PIN 2
#define MODIFY_REPORTING_TYPE 1

// i2c report buffer offsets
#define I2C_PACKET_LENGTH 0
#define I2C_REPORT_ID 1
#define I2C_REPORT_PORT 2
#define I2C_REPORT_DEVICE_ADDRESS 3
#define I2C_REPORT_READ_REGISTER 4
#define I2C_REPORT_READ_NUMBER_DATA_BYTES 5


#define I2C_ERROR_REPORT_LENGTH 4
#define I2C_ERROR_REPORT_NUM_OF_BYTE_TO_SEND 5



/*********************** REPORTING BUFFER OFFSETS ******************/
// loopback buffer offset for data being looped back
#define LOOP_BACK_DATA 2

// send_debug message buffer offsets
#define DEBUG_ID 2
#define DEBUG_VALUE_HIGH_BYTE 3
#define DEBUG_VALUE_LOW_BYTE 4

// digital input report buffer offsets
#define DIGITAL_INPUT_GPIO_PIN 2
#define DIGITAL_INPUT_GPIO_VALUE 3


// analog input report buffer offsets
#define ANALOG_INPUT_GPIO_PIN 2
#define ANALOG_VALUE_HIGH_BYTE 3
#define ANALOG_VALUE_LOW_BYTE 4
/******************************************************
 *                 PIN MODE DEFINITIONS
 *****************************************************/
#define DIGITAL_INPUT 0
#define DIGITAL_OUTPUT 1
#define PWM_OUTPUT 2
#define DIGITAL_INPUT_PULL_UP 3
#define DIGITAL_INPUT_PULL_DOWN 4
#define ANALOG_INPUT 5

#define PIN_MODE_NOT_SET 255

/**************************************************
 *               REPORT DEFINITIONS
 **************************************************/
#define SERIAL_LOOP_BACK_REPORT 0
#define DIGITAL_REPORT 2
#define ANALOG_REPORT 3
#define FIRMWARE_REPORT 5
#define REPORT_PICO_UNIQUE_ID 6
#define SERVO_UNAVAILABLE 7 // for the future
#define I2C_WRITE_FAILED 8
#define I2C_READ_FAILED 9
#define I2C_READ_REPORT 10
#define SONAR_DISTANCE 11 // for the future
#define DEBUG_PRINT 99

/***************************************************************
 *          INPUT PIN REPORTING CONTROL SUB COMMANDS
 ***************************************************************/
#define REPORTING_DISABLE_ALL 0
#define REPORTING_ANALOG_ENABLE 1
#define REPORTING_DIGITAL_ENABLE 2
#define REPORTING_ANALOG_DISABLE 3
#define REPORTING_DIGITAL_DISABLE 4

/* Maximum Supported pins */
#define MAX_DIGITAL_PINS_SUPPORTED 30
#define MAX_ANALOG_PINS_SUPPORTED 5

/* Firmware Version Values */
#define FIRMWARE_MAJOR 0
#define FIRMWARE_MINOR 2

// maximum length of a command packet in bytes
#define MAX_COMMAND_LENGTH 30


// Indicator that no i2c register is being specified in the command
#define I2C_NO_REGISTER_SPECIFIED 254

// a descriptor for digital pins
typedef struct {
    uint pin_number;
    uint pin_mode;
    uint reporting_enabled; // If true, then send reports if an input pin
    int last_value;        // Last value read for input mode
} pin_descriptor;

// a descriptor for analog pins
typedef struct analog_pin_descriptor {
    uint reporting_enabled; // If true, then send reports if an input pin
    int last_value;         // Last value read for input mode
    int differential;       // difference between current and last value needed
} analog_pin_descriptor;


typedef struct {
    // a pointer to the command processing function
    void (*command_func)(void);
} command_descriptor;
#endif //TELEMETRIX4RPIPICO_TELEMETRIX4RPIPICO_H