/**
* @file CAN_datadb.h
* @brief CAN database header file for the data line
* @details This file contains the mapping used to encode and decode CAN messages
* @note This is being developed as of right now
* @author João Vieira
* @version 0.0.0
**/
#ifndef CAN_DATADB_H
#define CAN_DATADB_H

// #ifdef __LART_T24__
/**
 * @brief T24 uses a little endian architecture when it comes to CAN messages
 **/

#define CAN_VCU_ID_1 0x020
/**======================================================================**/
#define MAP_DECODE_CONSUMED_POWER(x) (x[7] << 16 | x[6] << 8 | x[5])
#define MAP_DECODE_TARGET_POWER (x)(x[4] << 16 | x[3] << 8 | x[2])
#define MAP_DECODE_BRAKE_PRESSURE (x)(x[1])
#define MAP_DECODE_THROTTLE_POSITION (x)(x[0])

#define MAP_DECODE_APPS (x) MAP_DECODE_THROTTLE_POSITION(x)

#define MAP_ENCODE_CONSUMED_POWER(pnt, x) (pnt[7] = (x >> 16) & 0xFF, pnt[6] = (x >> 8) & 0xFF, pnt[5] = x & 0xFF)
#define MAP_ENCODE_TARGET_POWER(pnt, x) (pnt[4] = (x >> 16) & 0xFF, pnt[3] = (x >> 8) & 0xFF, pnt[2] = x & 0xFF)
#define MAP_ENCODE_BRAKE_PRESSURE(pnt, x) (pnt[1] = x)
#define MAP_ENCODE_THROTTLE_POSITION(pnt, x) (pnt[0] = x)

#define MAP_ENCODE_APPS(pnt, x) MAP_ENCODE_THROTTLE_POSITION(pnt, x)

/**======================================================================**/
#define CAN_VCU_ID_2 0x021
/**======================================================================**/

#define MAP_DECODE_MOTOR_TEMPERATURE(x) ((x[3] << 8 | x[2]) + 40)
#define MAP_DECODE_INVERTER_TEMPERATURE(x) ((x[1] << 8 | x[0]) + 40)

#define MAP_ENCODE_MOTOR_TEMPERATURE(pnt, x) (pnt[3] = (x - 40) >> 8, pnt[2] = (x - 40) & 0xFF)
#define MAP_ENCODE_INVERTER_TEMPERATURE(pnt, x) (pnt[1] = (x - 40) >> 8, pnt[0] = (x - 40) & 0xFF)

/**======================================================================**/
#define CAN_VCU_ID_3 0x022
/**======================================================================**/
#define MAP_DECODE_VCU_STATE(x) (x[4])
#define MAP_DECODE_LMT2(x) (x[3])
#define MAP_DECODE_LMT1(x) (x[2])
#define MAP_DECODE_INVERTER_ERROR(x) (x[1] << 8 | x[0])

#define MAP_ENCODE_VCU_STATE(pnt, x) (pnt[4] = x)
#define MAP_ENCODE_LMT2(pnt, x) (pnt[3] = x)
#define MAP_ENCODE_LMT1(pnt, x) (pnt[2] = x)
#define MAP_ENCODE_INVERTER_ERROR(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = x & 0xFF)

/**======================================================================**/
#define CAN_VCU_ID_4 0x023
/**======================================================================**/

#define MAP_DECODE_RPM(x) (x[3] << 8 | x[2])
#define MAP_DECODE_INVERTER_VOLTAGE(x) (x[1] << 8 | x[0])

#define MAP_ENCODE_RPM(pnt, x) (pnt[3] = (x >> 8) & 0xFF, pnt[2] = x & 0xFF)
#define MAP_ENCODE_INVERTER_VOLTAGE(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = x & 0xFF)

/**======================================================================**/
#define CAN_PDM_ID_1 0x40
/**======================================================================**/

/**======================================================================**/
#define CAN_PDM_ID_2 0x41
/**======================================================================**/

/**======================================================================**/
#define CAN_PDM_ID_3 0x42
/**======================================================================**/

/**======================================================================**/
#define CAN_PDM_ID_4 0x43
/**======================================================================**/

/**======================================================================**/
#define CAN_IMU_ID_1 0x60
/**======================================================================**/
/**======================================================================**/
#define CAN_IMU_ID_2 0x61
/**======================================================================**/

/**======================================================================**/
#define CAN_DYNAMICS_REAR_ID_1 0x80
/**======================================================================**/
/**======================================================================**/
#define CAN_DYNAMICS_REAR_ID_2 0xA0
/**======================================================================**/
/**======================================================================**/
// #define CAN_DYNAMICS_FRONT_ID_1 0x80 //definir id
/**======================================================================**/
/**======================================================================**/
// #define CAN_DYNAMICS_FRONT_ID_2 0xA0 //definir id
/**======================================================================**/

// #endif

#endif  // CAN_DB_H