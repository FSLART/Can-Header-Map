/**
* @file CAN_db.h
* @brief CAN database header file
* @details This file contains the mapping used to extract to encode and decode CAN messages
* @author João Vieira
**/
#ifndef CAN_DB_H
#define CAN_DB_H

#ifdef __LART_T24__
	/**
	* @brief T24 uses a little endian architecture when it comes to CAN messages
	**/



	#define CAN_VCU_MODULUS_1 0x020
	/**======================================================================**/
	#define MAP_CONSUMED_POWER(x) (x[7] << 16 | x[6] << 8 | x[5])
	#define MAP_TARGET_POWER (x) (x[4] << 16 | x[3] << 8 | x[2])
	#define MAP_BRAKE_PRESSURE (x)(x[1])
	#define MAP_THROTTLE_POSITION (x) (x[0]) #define MAP_APPS (x) MAP_THROTTLE_POSITION(x)



	/**======================================================================**/
	#define CAN_VCU_MODULUS_2 0x021
	/**======================================================================**/
	#define MAP_RPM(x) ((x[7] << 8 | x[6])) 
	#define MAP_MOTOR_TEMPERATURE(x) ((x[5] << 8 | x[4]) +40)
	#define MAP_INVERTER_TEMPERATURE(x) ((x[3] << 8 | x[2]) +40)
	#define MAP_INVERTER_VOLTAGE(x) ((x[1] << 8 | x[0]))



	/**======================================================================**/
	#define CAN_TCU_MODULUS_1 0x60
	/**======================================================================**/
	#define MAP_FIRSTSEGMENT_TEMPERATURE(x) (x[7] << 8 | x[6])
	#define MAP_PACK_MEAN_TEMPERATURE(x) (x[5] << 8 | x[4])
	/**#define MAP_POWER_TO_BATTERY_FANS(x) (x[3])
	#define MAP_POWER_TO_BATTERY_FANS(x) (x[2])
	#define MAP_POWER_TO_BATTERY_FANS(x) (x[1])**/
	#define MAP_COLLING_BOARD_STATE(x) (x[0])



#endif

#endif // CAN_DB_H