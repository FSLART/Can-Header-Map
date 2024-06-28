/*
 * CANOPEN_maxondb.h
 *
 *  Created on: 26/06/2024
 *      Author: micron
 */

#ifndef CANOPEN_MAXONDB_H
#define CANOPEN_MAXONDB_H

#define NMT_ADDRESS_COBID() (0x000)

#define BOOTUP_ADDRESS_COBID() (0x700+REMOTE_NODE_ID)
//Maxon SDOs
#define SDO_REQUEST_ADDRESS_COBID() (0x600+REMOTE_NODE_ID)
#define SDO_RESPONSE_ADDRESS_COBID() (0x580+REMOTE_NODE_ID)
/**======================================================================**/

/**================== Maxon Receive from World ==========================**/
#define PDO_RXONE_MAXON() (0x200+REMOTE_NODE_ID)
/**======================================================================**/
#define MAP_DECODE_PDO_RXONE_CONTROL_WORD(x) (x[1] << 8 | x[0])
/**======================================================================**/
#define PDO_RXTWO_MAXON() (0x300+REMOTE_NODE_ID)
/**======================================================================**/
#define MAP_DECODE_PDO_RXONE_CONTROL_WORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_RXONE_MODES_OF_OPERATION(x) (x[2])
/**======================================================================**/
#define PDO_RXTHREE_MAXON() (0x400+REMOTE_NODE_ID)
/**======================================================================**/
#define MAP_DECODE_PDO_RXTHREE_CONTROL_WORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_RXTHREE_TARGET_POSITION(x) (x[5] << 24 | x[4] << 16 | x[3] << 8 | x[2])
/**======================================================================**/
#define PDO_RXFOUR_MAXON() (0x500+REMOTE_NODE_ID)
/**======================================================================**/
#define MAP_DECODE_PDO_RXFOUR_CONTROL_WORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_RXFOUR_TARGET_SPEED(x) (x[5] << 24 | x[4] << 16 | x[3] << 8 | x[2])

/**=================== Maxon Transmit to World ==========================**/
#define PDO_TXONE_MAXON() (0x180+REMOTE_NODE_ID)
/**======================================================================**/
#define MAP_DECODE_PDO_TXONE_STATUSWORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_TXONE_MODES_OF_OPERATION(x) (x[2])
#define MAP_DECODE_PDO_TXONE_ERROR_CODE(x) (x[4] << 8 | x[3])

/**======================================================================**/
#define PDO_TXTWO_MAXON() (0x280+REMOTE_NODE_ID)
/**======================================================================**/
#define MAP_DECODE_PDO_TXTWO_TARGET_POSITION(x) (x[3] << 24 | x[2]  << 16 | x[1] << 8 | x[0])
#define MAP_DECODE_PDO_TXTWO_TARGET_SPEED(x) (x[7] << 24 | x[6]  << 16 | x[5] << 8 | x[4])

/**======================================================================**/
#define PDO_TXTHREE_MAXON() (0x380+REMOTE_NODE_ID)
/**======================================================================**/
#define MAP_DECODE_PDO_TXTHREE_STATUSWORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_TXTHREE_ACTUAL_POSITION(x) (x[5] << 24 | x[4] << 16 | x[3] << 8 | x[2])
#define MAP_DECODE_PDO_TXTHREE_ACTUAL_MOMENT(x)(x[7] <<8 | x[6])
/**======================================================================**/
#define PDO_TXFOUR_MAXON() (0x480+REMOTE_NODE_ID)
/**======================================================================**/
#define MAP_DECODE_PDO_TXFOUR_STATUSWORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_TXFOUR_ACTUAL_SPEED(x) (x[5] << 24 | x[4] << 16 | x[3] << 8 | x[2])
#define MAP_DECODE_PDO_TXFOUR_ACTUAL_PWM_DUTY(x) (x[7] << 8 | x[6])







#endif /* CANOPEN_MAXONDB_H */
