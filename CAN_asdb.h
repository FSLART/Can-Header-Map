/**
* @file CAN_asdb.h
* @brief CAN database for autonomous driving header file
* @details This file contains the mapping used to encode and decode CAN messages
* @author João Vieira
**/
#ifndef CAN_ASDB_H
#define CAN_ASDB_H
	//#ifdef __LART_T24__
		/**
		* @brief T24 uses a little endian architecture when it comes to CAN messages
		**/
		#define CAN_AS_STATUS 0x502
		/**======================================================================**/
		#define MAP_DECODE_AS_EBS(x) (x[0]&0x18)
		#define MAP_DECODE_AS_STATE(x) (x[0]&0x07)
		
		#define MAP_ENCODE_AS_EBS(pnt, x)(pnt[0]=(pnt[0]&0xE7) | (x&0x18) )
		#define MAP_ENCODE_AS_STATE(pnt, x)(pnt[0]=(pnt[0]&0xF8)| (x&0x07) )
		
	//#endif
#endif // CAN_ASDB_H
