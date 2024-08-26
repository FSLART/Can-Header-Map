/**
 * @file CAN_datadb.h
 * @brief CAN database header file for the data line
 * @details This file contains the mapping used to encode and decode CAN messages
 * @note This is being developed as of right now
 * @author João Vieira
 * @author Pedro Ferreira
 * @author Guilherme Candido
 * @version 0.0.1
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
#define MAP_DECODE_HV_VOLTAGE(x) (x[6] << 8 | x[5])
#define MAP_DECODE_HV_SOC(x) (x[7])

#define MAP_ENCODE_MOTOR_TEMPERATURE(pnt, x) (pnt[3] = (x - 40) >> 8, pnt[2] = (x - 40) & 0xFF)
#define MAP_ENCODE_INVERTER_TEMPERATURE(pnt, x) (pnt[1] = (x - 40) >> 8, pnt[0] = (x - 40) & 0xFF)
#define MAP_ENCODE_HV_VOLTAGE(pnt, x) (pnt[6] = (x >> 8) & 0xFF, pnt[5] = x & 0xFF)
#define MAP_ENCODE_HV_SOC(pnt, x) (pnt[7] = x)

/**======================================================================**/
#define CAN_VCU_ID_3 0x022
/**======================================================================**/
#define MAP_DECODE_VCU_STATE(x) (x[4])
#define MAP_DECODE_LMT2(x) (x[3])
#define MAP_DECODE_LMT1(x) (x[2])
#define MAP_DECODE_INVERTER_ERROR(x) (x[1] << 8 | x[0])
#define MAP_DECODE_APPS_ERROR(x) (x[5])
#define MAP_DECODE_POWER_PLAN(x) (x[6])


#define MAP_ENCODE_VCU_STATE(pnt, x) (pnt[4] = x)
#define MAP_ENCODE_LMT2(pnt, x) (pnt[3] = x)
#define MAP_ENCODE_LMT1(pnt, x) (pnt[2] = x)
#define MAP_ENCODE_INVERTER_ERROR(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = x & 0xFF)
#define MAP_ENCODE_APPS_ERROR(pnt, x) (pnt[5] = x)
#define MAP_ENCODE_POWER_PLAN(pnt, x) (pnt[6] = x)

/**======================================================================**/
#define CAN_VCU_ID_4 0x023
/**======================================================================**/

#define MAP_DECODE_RPM(x) (x[3] << 8 | x[2])
#define MAP_DECODE_INVERTER_VOLTAGE(x) (x[1] << 8 | x[0])
#define MAP_DECODE_IGNITION_STATE(x) (x[4])
#define MAP_DECODE_Ready2Drive_STATE(x) (x[5])

#define MAP_ENCODE_RPM(pnt, x) (pnt[3] = (x >> 8) & 0xFF, pnt[2] = x & 0xFF)
#define MAP_ENCODE_INVERTER_VOLTAGE(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = x & 0xFF)
#define MAP_ENCODE_IGNITION_STATE(pnt, x) (pnt[4] = x)
#define MAP_ENCODE_Ready2Drive_STATE(pnt, x) (pnt[5] = x)

/**======================================================================**/
#define CAN_VCU_ID_5 0x024

#define MAP_DECODE_VCU_TCU_STATE(x) (x[0])
#define MAP_DECODE_VCU_ACU_STATE(x) (x[1])
#define MAP_DECODE_VCU_ALC_STATE(x) (x[2])
#define MAP_DECODE_LV_SOC(x) ((x[3] << 8 | x[4]) /10)
#define MAP_DECODE_LV_VOLTAGE(x) (x[5] << 8 | x[6])

#define MAP_ENCODE_VCU_TCU_STATE(pnt, x) (pnt[0] = x)  
#define MAP_ENCODE_VCU_ACU_STATE(pnt, x) (pnt[1] = x)
#define MAP_ENCODE_VCU_ALC_STATE(pnt, x) (pnt[2] = x)
#define MAP_ENCODE_LV_SOC(pnt, x) (pnt[3] = (x >> 8) & 0xFF, pnt[4] = x & 0xFF) // 0-1000
#define MAP_ENCODE_LV_VOLTAGE(pnt, x) (pnt[5] = (x >> 8) & 0xFF, pnt[6] = x & 0xFF)

/**======================================================================**/
#define CAN_IMU_ID_1 0x60
/**======================================================================**/

/**======================================================================**/
#define CAN_IMU_ID_2 0x61
/**======================================================================**/

/**======================================================================**/
#define CAN_DYNAMICS_REAR_ID_1 0x80
/**======================================================================**/

#define MAP_DECODE_WHEEL_SPEED_RL(x) (x[7])
#define MAP_DECODE_WHEEL_SPEED_RR(x) (x[6])
#define MAP_DECODE_SUSPOS_RL(x) (x[5])
#define MAP_DECODE_SUSPOS_RR(x) (x[4])
#define MAP_DECODE_BRK_STATE(x) (x[3])
#define MAP_DECODE_DY_REAR_STATE(x) (x[2])

#define MAP_ENCODE_WHEEL_SPEED_RL(pnt, x) (pnt[7] = x)
#define MAP_ENCODE_WHEEL_SPEED_RR(pnt, x) (pnt[6] = x)
#define MAP_ENCODE_SUSPOS_RL(pnt, x) (pnt[5] = x)
#define MAP_ENCODE_SUSPOS_RR(pnt, x) (pnt[4] = x)
#define MAP_ENCODE_BRK_STATE(pnt, x) (pnt[3] = x)
#define MAP_ENCODE_DY_REAR_STATE(pnt, x) (pnt[2] = x)

/**======================================================================**/
#define CAN_DYNAMICS_REAR_ID_2 0x81
/**======================================================================**/

/**======================================================================**/
#define CAN_DYNAMICS_FRONT_ID_1 0xA0  // definir id
/**======================================================================**/

#define MAP_DECODE_WHEEL_SPEED_FL(x) (x[7])
#define MAP_DECODE_WHEEL_SPEED_FR(x) (x[6])
#define MAP_DECODE_SUSPOS_FL(x) (x[5])
#define MAP_DECODE_SUSPOS_FR(x) (x[4])
#define MAP_DECODE_DY_FRONT_STATE(x) (x[2])

#define MAP_ENCODE_WHEEL_SPEED_FL(pnt, x) (pnt[7] = x)
#define MAP_ENCODE_WHEEL_SPEED_FR(pnt, x) (pnt[6] = x)
#define MAP_ENCODE_SUSPOS_FL(pnt, x) (pnt[5] = x)
#define MAP_ENCODE_SUSPOS_FR(pnt, x) (pnt[4] = x)
#define MAP_ENCODE_DY_FRONT_STATE(pnt, x) (pnt[2] = x)

/**======================================================================**/
#define CAN_DYNAMICS_FRONT_ID_2 0xA1  // definir id
/**======================================================================**/

/**======================================================================**/
#define CAN_DATA_LOGGER_ID 0x180

#define MAP_DECODE_DATA_LOGGER_STATE(x) (x[0])
#define MAP_DECODE_DATA_LOGGER_RECORD_STATE(x) (x[1])

#define MAP_ENCODE_DATA_LOGGER_STATE(pnt, x) (pnt[0] = x)
#define MAP_ENCODE_DATA_LOGGER_RECORD_STATE(pnt, x) (pnt[1] = x)


/**======================================================================**/
#define CAN_BRAKE_LIGHT 0x253  // definir id
/**======================================================================**/


/**======================================================================**/
#define CAN_STEERING_WHEEL 0x254  // definir id
/**======================================================================**/

#define MAP_DECODE_VCU_POWER_LIMIT(x) (x[0])

#define MAP_ENCODE_VCU_POWER_LIMIT(pnt, x) (pnt[0] = x)

// #endif

#endif  // CAN_DB_H
