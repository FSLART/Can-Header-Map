/**
* @file CAN_asdb.h
* @brief CAN database for autonomous driving header file
* @details This file contains the mapping used to encode and decode CAN messages
* @author João Vieira
* @author Pedro Ferreira
* @version 0.0.1
**/
#ifndef CAN_ASDB_H
#define CAN_ASDB_H
	//#ifdef __LART_T24__
		/**
		* @brief T24 uses a little endian architecture when it comes to CAN messages
		**/

        #define CAN_AS_DATALOGGER 0x199
        /**======================================================================**/

		#define CAN_AS_DYNAMICS_ONE 0x500
		/**======================================================================**/
        #define MAP_DECODE_AS_SPEED_ACTUAL(x) (x[0]) // KM per hour
        #define MAP_DECODE_AS_SPEED_TARGET(x) (x[1]) // KM per hour
        //TODO bellow must be 0.5x and encode should 2x?
        #define MAP_DECODE_AS_STEERING_ANGLE_ACTUAL(x) (x[2]) // Signed degrees, 0.5 resolution
        #define MAP_DECODE_AS_STEERING_ANGLE_TARGET(x) (x[3]) // Signed degrees, 0.5 resolution
        #define MAP_DECODE_AS_BRAKE_HYDR_ACTUAL(x) (x[4]) // %
        #define MAP_DECODE_AS_BRAKE_HYDR_TARGET(x) (x[5]) // %
        #define MAP_DECODE_AS_MOTOR_MOMENT_ACTUAL(x) (x[6]) // SIGNED %
        #define MAP_DECODE_AS_MOTOR_MOMENT_TARGET(x) (x[7])  // SIGNED %

        #define MAP_ENCODE_AS_SPEED_ACTUAL(pnt, x) (pnt[0] = x)
        #define MAP_ENCODE_AS_SPEED_TARGET(pnt, x) (pnt[1] = x)
        #define MAP_ENCODE_AS_STEERING_ANGLE_ACTUAL(pnt, x) (pnt[2] = x)
        #define MAP_ENCODE_AS_STEERING_ANGLE_TARGET(pnt, x) (pnt[3] = x)
        #define MAP_ENCODE_AS_BRAKE_HYDR_ACTUAL(pnt, x) (pnt[4] = x)
        #define MAP_ENCODE_AS_BRAKE_HYDR_TARGET(pnt, x) (pnt[5] = x)
        #define MAP_ENCODE_AS_MOTOR_MOMENT_ACTUAL(pnt, x) (pnt[6] = x)
        #define MAP_ENCODE_AS_MOTOR_MOMENT_TARGET(pnt, x) (pnt[7] = x)


		#define CAN_AS_DYNAMICS_TWO 0x501
		/**======================================================================**/
        #define MAP_DECODE_AS_ACCELERATION_LONGITUDINAL (x) (x[1] << 8 | x[0]) // m/s^2 1/512 resolution
        #define MAP_DECODE_AS_ACCELERATION_LATERAL (x) (x[3] << 8 | x[2]) // m/s^2 1/512 resolution
        #define MAP_DECODE_AS_YAW_RATE (x) (x[5] << 8 | x[4]) //degrees per second 1/128 resolution

		#define CAN_AS_STATUS 0x502
		/**======================================================================**/
		#define MAP_DECODE_AS_MISSION(x) (x[0]&0xE0)
		#define MAP_DECODE_AS_EBS(x) (x[0]&0x18)
		#define MAP_DECODE_AS_STATE(x) (x[0]&0x07)
		
		#define MAP_ENCODE_AS_MISSION(pnt, x)(pnt[0]=(pnt[0]&0x1F) | (x&0xE0) )
		#define MAP_ENCODE_AS_EBS(pnt, x)(pnt[0]=(pnt[0]&0xE7) | (x&0x18) )
		#define MAP_ENCODE_AS_STATE(pnt, x)(pnt[0]=(pnt[0]&0xF8)| (x&0x07) )
		

	//#endif
#endif // CAN_ASDB_H
