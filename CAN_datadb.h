/**
* @file CAN_datadb.h
* @brief CAN database header file for the data line
* @details This file contains the mapping used to encode and decode CAN messages
* @note THIS IS OBSOLETE/NEEDS TO BE UPDATED
* @author João Vieira
**/
#ifndef CAN_DATADB_H
#define CAN_DATADB_H

//#ifdef __LART_T24__
	/**
	* @brief T24 uses a little endian architecture when it comes to CAN messages
	**/



	#define CAN_VCU_MODULUS_1 0x020
	/**======================================================================**/
	#define MAP_DECODE_CONSUMED_POWER(x) (x[7] << 16 | x[6] << 8 | x[5])
	#define MAP_DECODE_TARGET_POWER (x) (x[4] << 16 | x[3] << 8 | x[2])
	#define MAP_DECODE_BRAKE_PRESSURE (x)(x[1])
	#define MAP_DECODE_THROTTLE_POSITION (x) (x[0]) 
	
	#define MAP_DECODE_APPS (x) MAP_DECODE_THROTTLE_POSITION(x)
	
	#define MAP_ENCODE_CONSUMED_POWER(pnt, x) (pnt[7] = (x >> 16) & 0xFF, pnt[6] = (x >> 8) & 0xFF, pnt[5] = x & 0xFF)
	#define MAP_ENCODE_TARGET_POWER(pnt, x) (pnt[4] = (x >> 16) & 0xFF, pnt[3] = (x >> 8) & 0xFF, pnt[2] = x & 0xFF)
	#define MAP_ENCODE_BRAKE_PRESSURE(pnt, x) (pnt[1] = x)
	#define MAP_ENCODE_THROTTLE_POSITION(pnt, x) (pnt[0] = x)

	#define MAP_ENCODE_APPS(pnt, x) MAP_ENCODE_THROTTLE_POSITION(pnt, x)

	/**======================================================================**/
	#define CAN_VCU_MODULUS_2 0x021
	/**======================================================================**/
	#define MAP_DECODE_RPM(x) ((x[7] << 8 | x[6])) 
	#define MAP_DECODE_MOTOR_TEMPERATURE(x) ((x[5] << 8 | x[4]) +40)
	#define MAP_DECODE_INVERTER_TEMPERATURE(x) ((x[3] << 8 | x[2]) +40)
	#define MAP_DECODE_INVERTER_VOLTAGE(x) ((x[1] << 8 | x[0]))



	/**======================================================================**/
	#define CAN_TCU_MODULUS_1 0x60
	/**======================================================================**/
	#define MAP_DECODE_FIRSTSEGMENT_TEMPERATURE(x) (x[7] << 8 | x[6])
	#define MAP_DECODE_PACK_MEAN_TEMPERATURE(x) (x[5] << 8 | x[4])
	/**#define MAP_DECODE_POWER_TO_BATTERY_FANS(x) (x[3])
	#define MAP_DECODE_POWER_TO_BATTERY_FANS(x) (x[2])
	#define MAP_DECODE_POWER_TO_BATTERY_FANS(x) (x[1])**/
	#define MAP_DECODE_COLLING_BOARD_STATE(x) (x[0])



//#endif

#endif // CAN_DB_H