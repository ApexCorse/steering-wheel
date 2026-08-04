#ifndef VERA_STM32HAL_H
#define VERA_STM32HAL_H

#include "vera.h"
#include "stm32f4xx_hal.h"

vera_err_t vera_decode_stm32hal_rx_frame(
	CAN_RxHeaderTypeDef*    frame,
	uint8_t*                data,
	vera_decoding_result_t* result
);

vera_err_t vera_encode_autodevkit_Battery_S1_1(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S1_C1,
	uint64_t Voltage_S1_C2,
	uint64_t Voltage_S1_C3,
	uint64_t Voltage_S1_C4,
	uint64_t Voltage_S1_C5,
	uint64_t Voltage_S1_C6,
	uint64_t Voltage_S1_C7
);

vera_err_t vera_encode_autodevkit_Battery_S1_2(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S1_C8,
	uint64_t Voltage_S1_C9,
	uint64_t Voltage_S1_C10,
	uint64_t Voltage_S1_C11,
	uint64_t Voltage_S1_C12,
	uint64_t Voltage_S1_C13,
	uint64_t Voltage_S1_C14
);

vera_err_t vera_encode_autodevkit_Battery_S2_1(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S2_C1,
	uint64_t Voltage_S2_C2,
	uint64_t Voltage_S2_C3,
	uint64_t Voltage_S2_C4,
	uint64_t Voltage_S2_C5,
	uint64_t Voltage_S2_C6,
	uint64_t Voltage_S2_C7
);

vera_err_t vera_encode_autodevkit_Battery_S2_2(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S2_C8,
	uint64_t Voltage_S2_C9,
	uint64_t Voltage_S2_C10,
	uint64_t Voltage_S2_C11,
	uint64_t Voltage_S2_C12,
	uint64_t Voltage_S2_C13,
	uint64_t Voltage_S2_C14
);

vera_err_t vera_encode_autodevkit_Battery_S3_1(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S3_C1,
	uint64_t Voltage_S3_C2,
	uint64_t Voltage_S3_C3,
	uint64_t Voltage_S3_C4,
	uint64_t Voltage_S3_C5,
	uint64_t Voltage_S3_C6,
	uint64_t Voltage_S3_C7
);

vera_err_t vera_encode_autodevkit_Battery_S3_2(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S3_C8,
	uint64_t Voltage_S3_C9,
	uint64_t Voltage_S3_C10,
	uint64_t Voltage_S3_C11,
	uint64_t Voltage_S3_C12,
	uint64_t Voltage_S3_C13,
	uint64_t Voltage_S3_C14
);

vera_err_t vera_encode_autodevkit_Battery_S4_1(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S4_C1,
	uint64_t Voltage_S4_C2,
	uint64_t Voltage_S4_C3,
	uint64_t Voltage_S4_C4,
	uint64_t Voltage_S4_C5,
	uint64_t Voltage_S4_C6,
	uint64_t Voltage_S4_C7
);

vera_err_t vera_encode_autodevkit_Battery_S4_2(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S4_C8,
	uint64_t Voltage_S4_C9,
	uint64_t Voltage_S4_C10,
	uint64_t Voltage_S4_C11,
	uint64_t Voltage_S4_C12,
	uint64_t Voltage_S4_C13,
	uint64_t Voltage_S4_C14
);

vera_err_t vera_encode_autodevkit_Battery_S5_1(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S5_C1,
	uint64_t Voltage_S5_C2,
	uint64_t Voltage_S5_C3,
	uint64_t Voltage_S5_C4,
	uint64_t Voltage_S5_C5,
	uint64_t Voltage_S5_C6,
	uint64_t Voltage_S5_C7
);

vera_err_t vera_encode_autodevkit_Battery_S5_2(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S5_C8,
	uint64_t Voltage_S5_C9,
	uint64_t Voltage_S5_C10,
	uint64_t Voltage_S5_C11,
	uint64_t Voltage_S5_C12,
	uint64_t Voltage_S5_C13,
	uint64_t Voltage_S5_C14
);

vera_err_t vera_encode_autodevkit_Battery_S6_1(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S6_C1,
	uint64_t Voltage_S6_C2,
	uint64_t Voltage_S6_C3,
	uint64_t Voltage_S6_C4,
	uint64_t Voltage_S6_C5,
	uint64_t Voltage_S6_C6,
	uint64_t Voltage_S6_C7
);

vera_err_t vera_encode_autodevkit_Battery_S6_2(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S6_C8,
	uint64_t Voltage_S6_C9,
	uint64_t Voltage_S6_C10,
	uint64_t Voltage_S6_C11,
	uint64_t Voltage_S6_C12,
	uint64_t Voltage_S6_C13,
	uint64_t Voltage_S6_C14
);

vera_err_t vera_encode_autodevkit_Battery_S7_1(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S7_C1,
	uint64_t Voltage_S7_C2,
	uint64_t Voltage_S7_C3,
	uint64_t Voltage_S7_C4,
	uint64_t Voltage_S7_C5,
	uint64_t Voltage_S7_C6,
	uint64_t Voltage_S7_C7
);

vera_err_t vera_encode_autodevkit_Battery_S7_2(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S7_C8,
	uint64_t Voltage_S7_C9,
	uint64_t Voltage_S7_C10,
	uint64_t Voltage_S7_C11,
	uint64_t Voltage_S7_C12,
	uint64_t Voltage_S7_C13,
	uint64_t Voltage_S7_C14
);

vera_err_t vera_encode_autodevkit_Battery_S8_1(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S8_C1,
	uint64_t Voltage_S8_C2,
	uint64_t Voltage_S8_C3,
	uint64_t Voltage_S8_C4,
	uint64_t Voltage_S8_C5,
	uint64_t Voltage_S8_C6,
	uint64_t Voltage_S8_C7
);

vera_err_t vera_encode_autodevkit_Battery_S8_2(
	CAN_TxHeaderTypeDef* frame,
	uint8_t*             data,
	uint64_t Voltage_S8_C8,
	uint64_t Voltage_S8_C9,
	uint64_t Voltage_S8_C10,
	uint64_t Voltage_S8_C11,
	uint64_t Voltage_S8_C12,
	uint64_t Voltage_S8_C13,
	uint64_t Voltage_S8_C14
);

#endif // VERA_STM32HAL_H
