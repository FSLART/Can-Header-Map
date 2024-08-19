/**
 * @file CAN_icupdb.h
 * @brief CAN database header file for the inter control unit line
 * @details This file contains the mapping used to encode and decode CAN messages
 * @note This is being developed as of right now
 * @author João Vieira
 * @version 0.0.1
 **/
#ifndef CAN_ICUPDB_H
#define CAN_ICUPDB_H

// #ifdef __LART_T24__
/**
 * @brief T24 uses a little endian architecture when it comes to CAN messages
 **/



#define GENERIC_MSG_CONVERSION_ENCODE_DATABUS(x) (x | 0x04000000)
#define GENERIC_MSG_CONVERSION_DECODE_DATABUS(x) (x & 0x1BFFFFFF)
#define GENERIC_MSG_CONVERSION_ENCODE_POWERTRAIN(x) (x | 0x08000000)
#define GENERIC_MSG_CONVERSION_DECODE_POWERTRAIN(x) (x & 0x17FFFFFF)
#define GENERIC_MSG_CONVERSION_ENCODE_AUTONOMOUSBUS(x) (x | 0x0C000000)
#define GENERIC_MSG_CONVERSION_DECODE_AUTONOMOUSBUS(x) (x & 0x13FFFFFF)

#endif  // CAN_DB_H
