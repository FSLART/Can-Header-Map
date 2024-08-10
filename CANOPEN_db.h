/*
 * CANOPEN_maxondb.h
 *
 *  Created on: 26/06/2024
 *      Author: micron
 */

#ifndef CANOPEN_MAXONDB_H
#define CANOPEN_MAXONDB_H

/**================== Node IDS ==========================**/
#define NODE_ID_ACU 0x03
#define NODE_ID_STEERING 0x05
#define NODE_ID_BRAKE 0x06 //RESERVED DONT USE
#define NODE_ID_RES 0x11 // DO NOT CHANGE!! ENFORCED BY RULES!!!
/**======================================================================**/


#define NMT_ADDRESS_COBID() (0x000)

#define BOOTUP_ADDRESS_COBID(node_id) (node_id + 0x700)
//Maxon SDOs
#define SDO_REQUEST_ADDRESS_COBID(node_id) (node_id+0x600)
#define SDO_RESPONSE_ADDRESS_COBID(node_id) (node_id+0x580)


/**======================================================================**/

/**================== Receive from World ==========================**/
#define PDO_RXONE(node_id) (node_id+0x200)
/**======================================================================**/
#define MAP_DECODE_PDO_RXONE_CONTROL_WORD(x) (x[1] << 8 | x[0])
/**======================================================================**/
#define PDO_RXTWO(node_id) (node_id+0x300)
/**======================================================================**/
#define MAP_DECODE_PDO_RXTWO_MAXON_CONTROL_WORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_RXTWO_MAXON_MODES_OF_OPERATION(x) (x[2])
/**======================================================================**/
#define PDO_RXTHREE(node_id) (node_id+0x400)
/**======================================================================**/
#define MAP_DECODE_PDO_RXTHREE_MAXON_CONTROL_WORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_RXTHREE_MAXON_TARGET_POSITION(x) (x[5] << 24 | x[4] << 16 | x[3] << 8 | x[2])
/**======================================================================**/
#define PDO_RXFOUR(node_id) (node_id+0x500)
/**======================================================================**/
#define MAP_DECODE_PDO_RXFOUR_MAXON_CONTROL_WORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_RXFOUR_MAXON_TARGET_SPEED(x) (x[5] << 24 | x[4] << 16 | x[3] << 8 | x[2])

/**=================== Transmit to World ==========================**/
#define PDO_TXONE(node_id) (node_id+0x180)
/**======================================================================**/
#define MAP_DECODE_PDO_TXONE_MAXON_STATUSWORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_TXONE_MAXON_MODES_OF_OPERATION(x) (x[2])
#define MAP_DECODE_PDO_TXONE_MAXON_ERROR_CODE(x) (x[4] << 8 | x[3])

#define MAP_DECODE_PDO_TXONE_RES_STATUS(x) (x[0])


/**======================================================================**/
#define PDO_TXTWO(node_id) (node_id+0x280)
/**======================================================================**/
#define MAP_DECODE_PDO_TXTWO_MAXON_TARGET_POSITION(x) (x[3] << 24 | x[2]  << 16 | x[1] << 8 | x[0])
#define MAP_DECODE_PDO_TXTWO_MAXON_TARGET_SPEED(x) (x[7] << 24 | x[6]  << 16 | x[5] << 8 | x[4])

/**======================================================================**/
#define PDO_TXTHREE(node_id) (node_id+0x380)
/**======================================================================**/
#define MAP_DECODE_PDO_TXTHREE_MAXON_STATUSWORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_TXTHREE_MAXON_ACTUAL_POSITION(x) (x[5] << 24 | x[4] << 16 | x[3] << 8 | x[2])
#define MAP_DECODE_PDO_TXTHREE_MAXON_ACTUAL_MOMENT(x)(x[7] <<8 | x[6])
/**======================================================================**/
#define PDO_TXFOUR(node_id) (node_id+0x480)
/**======================================================================**/
#define MAP_DECODE_PDO_TXFOUR_MAXON_STATUSWORD(x) (x[1] << 8 | x[0])
#define MAP_DECODE_PDO_TXFOUR_MAXON_ACTUAL_SPEED(x) (x[5] << 24 | x[4] << 16 | x[3] << 8 | x[2])
#define MAP_DECODE_PDO_TXFOUR_MAXON_ACTUAL_PWM_DUTY(x) (x[7] << 8 | x[6])







#endif /* CANOPEN_MAXONDB_H */
