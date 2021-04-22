/*
 * sram.h
 *
 *  Created on: 13 Apr 2021
 *      Author: SECWK0
 */

#ifndef INC_SRAM_H_
#define INC_SRAM_H_

#define CONFIG_SET_ADDR					0x01	//uint8_t
#define GO_GOME_DIRECTION_ADDR			0x02	//uint8_t
#define BOUNDARY_TIMEOUT_ADDR			0x03	//uint8_t
#define WORKINGHOURSTART_ADDR			0x04	//uint8_t
#define WORKINGHOUREND_ADDR				0x05	//uint8_t
#define OVERTURN_LIMIT_ADDR				0x06	//uint8_t
#define MOTORSPEEDUPDATEFREQ_ADDR		0x07	//uint8_t
#define OUTSIDE_THRESHOLD_ADDR			0x08	//uint8_t

#define HOLDCHARGEDETECTION_ADDR		0x32	//uint16_t 0x09

#define BATTERY_LOW_LIMIT_ADDR			0x64	//uint32_t 0x0A
#define BATTERY_HIGH_LIMIT_ADDR			0x68	//uint32_t 0x0E
#define SIGNAL_INTEGRITY_IN_ADDR		0x6C	//uint32_t 0x12
#define SIGNAL_INTEGRITY_OUT_ADDR		0x70	//uint32_t 0x16
#define MOTOR_LIMIT_ADDR				0x74	//uint32_t 0x1A
#define CUTTER_LIMIT_ADDR				0x78	//uint32_t 0x1E
#define KP_ADDR							0x7C	//uint32_t 0x22
#define KI_ADDR							0x80	//uint32_t 0x26
#define KD_ADDR							0x84	//uint32_t 0x2A


typedef struct SRAM {

	uint8_t Config_Set;
	uint8_t Go_Home_Direction;
	uint8_t Boundary_Timeout;
	uint8_t WorkingHourStart;
	uint8_t WorkingHourEnd;
	uint8_t Overturn_Limit;
	uint8_t MotorSpeedUpdateFreq;
	uint8_t Outside_Threshold;
	uint16_t HoldChargeDetection;
	float Battery_Low_Limit;
	float Battery_High_Limit;
	float Signal_Integrity_IN;
	float Signal_Integrity_OUT;
	float Motor_Limit;
	float Cutter_Limit;
	float kp;
	float ki;
	float kd;

} sram_settings;

extern void enable_backup_sram(void);

extern void write_sram_uint8(uint8_t l_data, uint8_t addr);
extern uint8_t read_sram_uint8(uint8_t);
extern void write_sram_uint16(uint16_t l_data, uint8_t addr);
extern uint16_t read_sram_uint16(uint8_t);
extern void write_sram_uint32(uint32_t l_data, uint8_t addr);
extern uint32_t read_sram_uint32(uint8_t);
extern void write_sram_float(float l_data, uint8_t);
extern float read_sram_float(uint8_t);
extern sram_settings read_all_settings(void);
extern void write_all_settings(sram_settings w_settings);
extern void save_default_settings(void);


#endif /* INC_SRAM_H_ */