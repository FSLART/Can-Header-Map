/**
 * @file CAN_pwtdb.h
 * @brief CAN database header file for the powertrain bus line
 * @details This file contains the mapping used to encode and decode CAN messages
 * @author João Vieira
 * @author Pedro Ferreira
 * @version 0.0.1
 **/
#ifndef CAN_PWTDB_H
#define CAN_PWTDB_H

// #ifdef __LART_T24__
/**
 * @brief T24 uses a little endian architecture when it comes to CAN messages
 **/

/**======================================================================**/
#define CAN_HV500_ERPM_DUTY_VOLTAGE_ID 0x14
/**======================================================================**/

#define MAP_DECODE_Actual_ERPM(x) (x[3] << 24 | x[2] << 16 | x[1] << 8 | x[0])
#define MAP_DECODE_Actual_Duty(x) (x[5] << 8 | x[4])
#define MAP_DECODE_Actual_InputVoltage(x) (x[7] << 8 | x[6])

/**======================================================================**/
#define CAN_HV500_AC_DC_current_ID 0x34
/**======================================================================**/
#define MAP_DECODE_Actual_ACCurrent(x) (x[1] << 8 | x[0])
#define MAP_DECODE_Actual_DCCurrent(x) (x[3] << 8 | x[2])

/**======================================================================**/
#define CAN_HV500_Temperatures_ID 0x54
/**======================================================================**/
#define MAP_DECODE_Actual_TempController(x) (x[1] << 8 | x[0])
#define MAP_DECODE_Actual_TempMotor(x) (x[3] << 8 | x[2])
#define MAP_DECODE_Actual_FaultCode(x) (x[4])

/**======================================================================**/
#define CAN_HV500_FOC_ID 0x74
/**======================================================================**/
#define MAP_DECODE_Actual_FOC_id(x) (x[3] << 24 | x[2] << 16 | x[1] << 8 | x[0])
#define MAP_DECODE_Actual_FOC_iq(x) (x[7] << 24 | x[6] << 16 | x[5] << 8 | x[4])

/**======================================================================**/
#define CAN_HV500_MISC_ID 0x94
/**======================================================================**/
#define MAP_DECODE_Actual_Throttle(x) (x[0])
#define MAP_DECODE_Actual_Brake(x) (x[1])
#define MAP_DECODE_Digital_input_1(x) (x[2] & 0x01)
#define MAP_DECODE_Digital_input_2(x) (x[2] & 0x02)
#define MAP_DECODE_Digital_input_3(x) (x[2] & 0x04)
#define MAP_DECODE_Digital_input_4(x) (x[2] & 0x08)
#define MAP_DECODE_Digital_output_1(x) (x[2] & 0x10)
#define MAP_DECODE_Digital_output_2(x) (x[2] & 0x20)
#define MAP_DECODE_Digital_output_3(x) (x[2] & 0x40)
#define MAP_DECODE_Digital_output_4(x) (x[2] & 0x80)
#define MAP_DECODE_Drive_enable(x) (x[3])
#define MAP_DECODE_Capacitor_temp_limit(x) (x[4] & 0x01)
#define MAP_DECODE_DC_current_limit(x) (x[4] & 0x02)
#define MAP_DECODE_Drive_enable_limit(x) (x[4] & 0x04)
#define MAP_DECODE_IGBT_accel_limit(x) (x[4] & 0x08)
#define MAP_DECODE_IGBT_temp_limit(x) (x[4] & 0x10)
#define MAP_DECODE_Input_voltage_limit(x) (x[4] & 0x20)
#define MAP_DECODE_Motor_accel_limit(x) (x[4] & 0x40)
#define MAP_DECODE_Motor_temp_limit(x) (x[4] & 0x80)
#define MAP_DECODE_RPM_min_limit(x) (x[5] & 0x01)
#define MAP_DECODE_RPM_max_limit(x) (x[5] & 0x02)
#define MAP_DECODE_Power_limit(x) (x[5] & 0x04)
//wtf is in [6]???
#define MAP_DECODE_CAN_map_version(x) (x[7])

/**======================================================================**/
#define CAN_HV500_SetAcCurrent_ID 0x354
/**======================================================================**/
#define MAP_ENCODE_CMD_AcCurrent(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = x * 10 & 0xFF)

/**======================================================================**/
#define CAN_HV500_SetBrakeCurrent_ID 0x374
/**======================================================================**/
#define MAP_ENCODE_CMD_BrakeCurrent(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = x * 10 & 0xFF)

/**======================================================================**/
#define CAN_HV500_SetERPM_ID 0x394
/**======================================================================**/
#define MAP_ENCODE_CMD_ERPM(pnt, x) (pnt[2] = (x >> 16) & 0xFF, pnt[1] = (x >> 8) & 0xFF, pnt[0] = x & 0xFF)

/**======================================================================**/
#define CAN_HV500_SetPosition_ID 0x3b4
/**======================================================================**/
//TODO: This might result in noise due to * 10 operation BEFORE the cutting shift
#define MAP_ENCODE_CMD_Position(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = ((x * 10) & 0xFF))

/**======================================================================**/
#define CAN_HV500_SetRelCurrent_ID 0x3d4
/**======================================================================**/

#define MAP_ENCODE_CMD_RelCurrent(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = ((x * 10) & 0xFF))

/**======================================================================**/
#define CAN_HV500_SetRelBrakeCurrent_ID 0x3F4
/**======================================================================**/
#define MAP_ENCODE_CMD_RelBrakeCurrent(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = ((x * 10) & 0xFF))

/**======================================================================**/
#define CAN_HV500_SetMaxAcCurrent_ID 0x414
/**======================================================================**/
#define MAP_ENCODE_CMD_MaxAcCurrent(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = ((x * 10) & 0xFF))

/**======================================================================**/
#define CAN_HV500_SetMaxAcBrakeCurrent_ID 0x434
/**======================================================================**/
#define MAP_ENCODE_CMD_MaxAcBrakeCurrent(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = ((x * 10) & 0xFF))

/**======================================================================**/
#define CAN_HV500_SetMaxDcCurrent_ID 0x454
/**======================================================================**/
#define MAP_ENCODE_CMD_MaxDcCurrent(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = ((x * 10) & 0xFF))

/**======================================================================**/
#define CAN_HV500_SetMaxDcBrakeCurrent_ID 0x474
/**======================================================================**/
#define MAP_ENCODE_CMD_MaxDcBrakeCurrent(pnt, x) (pnt[1] = (x >> 8) & 0xFF, pnt[0] = ((x * 10) & 0xFF))

/**======================================================================**/
#define CAN_HV500_SetDriveEnable_ID 0x494
/**======================================================================**/
#define MAP_ENCODE_CMD_DriveEnable(pnt, x) (pnt[0] = x)

// #endif

#endif  // CAN_PWTDB_H