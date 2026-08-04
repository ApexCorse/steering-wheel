#include "vera_stm32hal.h"
#include <string.h>

static void insert_data_in_payload(uint8_t* payload, uint64_t data, uint8_t start, uint8_t length)
{
	for (uint8_t i = start; i < start + length; i++) {
		uint8_t payload_index = i / 8;
		uint8_t shift_right = start + length - i - 1;
		uint8_t shift_left = 7 - (i % 8);

		payload[payload_index] |= ((data >> shift_right) & 1) << shift_left;
	}
}

#define _insert_data_in_payload insert_data_in_payload

static void init_standard_tx_header(CAN_TxHeaderTypeDef* frame, uint32_t id, uint32_t dlc)
{
	frame->StdId = id;
	frame->ExtId = 0;
	frame->IDE = CAN_ID_STD;
	frame->RTR = CAN_RTR_DATA;
	frame->DLC = dlc;
	frame->TransmitGlobalTime = DISABLE;
}

vera_err_t vera_decode_stm32hal_rx_frame(
	CAN_RxHeaderTypeDef*    frame,
	uint8_t*                data,
	vera_decoding_result_t* result
) {
	vera_can_rx_frame_t vera_frame = {
		.id             = frame->IDE == CAN_ID_EXT ? frame->ExtId : frame->StdId,
		.dlc            = frame->DLC,
		.is_extended_id = frame->IDE == CAN_ID_EXT ? true : false,
		.timestamp      = frame->Timestamp
	};
	memcpy(vera_frame.data, data, frame->DLC);

	return vera_decode_can_frame(&vera_frame, result);
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x1, 7);
	
	_insert_data_in_payload(data, Voltage_S1_C1, 0, 8);
	_insert_data_in_payload(data, Voltage_S1_C2, 8, 8);
	_insert_data_in_payload(data, Voltage_S1_C3, 16, 8);
	_insert_data_in_payload(data, Voltage_S1_C4, 24, 8);
	_insert_data_in_payload(data, Voltage_S1_C5, 32, 8);
	_insert_data_in_payload(data, Voltage_S1_C6, 40, 8);
	_insert_data_in_payload(data, Voltage_S1_C7, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x2, 7);
	
	_insert_data_in_payload(data, Voltage_S1_C8, 0, 8);
	_insert_data_in_payload(data, Voltage_S1_C9, 8, 8);
	_insert_data_in_payload(data, Voltage_S1_C10, 16, 8);
	_insert_data_in_payload(data, Voltage_S1_C11, 24, 8);
	_insert_data_in_payload(data, Voltage_S1_C12, 32, 8);
	_insert_data_in_payload(data, Voltage_S1_C13, 40, 8);
	_insert_data_in_payload(data, Voltage_S1_C14, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x3, 7);
	
	_insert_data_in_payload(data, Voltage_S2_C1, 0, 8);
	_insert_data_in_payload(data, Voltage_S2_C2, 8, 8);
	_insert_data_in_payload(data, Voltage_S2_C3, 16, 8);
	_insert_data_in_payload(data, Voltage_S2_C4, 24, 8);
	_insert_data_in_payload(data, Voltage_S2_C5, 32, 8);
	_insert_data_in_payload(data, Voltage_S2_C6, 40, 8);
	_insert_data_in_payload(data, Voltage_S2_C7, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x4, 7);
	
	_insert_data_in_payload(data, Voltage_S2_C8, 0, 8);
	_insert_data_in_payload(data, Voltage_S2_C9, 8, 8);
	_insert_data_in_payload(data, Voltage_S2_C10, 16, 8);
	_insert_data_in_payload(data, Voltage_S2_C11, 24, 8);
	_insert_data_in_payload(data, Voltage_S2_C12, 32, 8);
	_insert_data_in_payload(data, Voltage_S2_C13, 40, 8);
	_insert_data_in_payload(data, Voltage_S2_C14, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x5, 7);
	
	_insert_data_in_payload(data, Voltage_S3_C1, 0, 8);
	_insert_data_in_payload(data, Voltage_S3_C2, 8, 8);
	_insert_data_in_payload(data, Voltage_S3_C3, 16, 8);
	_insert_data_in_payload(data, Voltage_S3_C4, 24, 8);
	_insert_data_in_payload(data, Voltage_S3_C5, 32, 8);
	_insert_data_in_payload(data, Voltage_S3_C6, 40, 8);
	_insert_data_in_payload(data, Voltage_S3_C7, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x6, 7);
	
	_insert_data_in_payload(data, Voltage_S3_C8, 0, 8);
	_insert_data_in_payload(data, Voltage_S3_C9, 8, 8);
	_insert_data_in_payload(data, Voltage_S3_C10, 16, 8);
	_insert_data_in_payload(data, Voltage_S3_C11, 24, 8);
	_insert_data_in_payload(data, Voltage_S3_C12, 32, 8);
	_insert_data_in_payload(data, Voltage_S3_C13, 40, 8);
	_insert_data_in_payload(data, Voltage_S3_C14, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x7, 7);
	
	_insert_data_in_payload(data, Voltage_S4_C1, 0, 8);
	_insert_data_in_payload(data, Voltage_S4_C2, 8, 8);
	_insert_data_in_payload(data, Voltage_S4_C3, 16, 8);
	_insert_data_in_payload(data, Voltage_S4_C4, 24, 8);
	_insert_data_in_payload(data, Voltage_S4_C5, 32, 8);
	_insert_data_in_payload(data, Voltage_S4_C6, 40, 8);
	_insert_data_in_payload(data, Voltage_S4_C7, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x8, 7);
	
	_insert_data_in_payload(data, Voltage_S4_C8, 0, 8);
	_insert_data_in_payload(data, Voltage_S4_C9, 8, 8);
	_insert_data_in_payload(data, Voltage_S4_C10, 16, 8);
	_insert_data_in_payload(data, Voltage_S4_C11, 24, 8);
	_insert_data_in_payload(data, Voltage_S4_C12, 32, 8);
	_insert_data_in_payload(data, Voltage_S4_C13, 40, 8);
	_insert_data_in_payload(data, Voltage_S4_C14, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x9, 7);
	
	_insert_data_in_payload(data, Voltage_S5_C1, 0, 8);
	_insert_data_in_payload(data, Voltage_S5_C2, 8, 8);
	_insert_data_in_payload(data, Voltage_S5_C3, 16, 8);
	_insert_data_in_payload(data, Voltage_S5_C4, 24, 8);
	_insert_data_in_payload(data, Voltage_S5_C5, 32, 8);
	_insert_data_in_payload(data, Voltage_S5_C6, 40, 8);
	_insert_data_in_payload(data, Voltage_S5_C7, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0xa, 7);
	
	_insert_data_in_payload(data, Voltage_S5_C8, 0, 8);
	_insert_data_in_payload(data, Voltage_S5_C9, 8, 8);
	_insert_data_in_payload(data, Voltage_S5_C10, 16, 8);
	_insert_data_in_payload(data, Voltage_S5_C11, 24, 8);
	_insert_data_in_payload(data, Voltage_S5_C12, 32, 8);
	_insert_data_in_payload(data, Voltage_S5_C13, 40, 8);
	_insert_data_in_payload(data, Voltage_S5_C14, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0xb, 7);
	
	_insert_data_in_payload(data, Voltage_S6_C1, 0, 8);
	_insert_data_in_payload(data, Voltage_S6_C2, 8, 8);
	_insert_data_in_payload(data, Voltage_S6_C3, 16, 8);
	_insert_data_in_payload(data, Voltage_S6_C4, 24, 8);
	_insert_data_in_payload(data, Voltage_S6_C5, 32, 8);
	_insert_data_in_payload(data, Voltage_S6_C6, 40, 8);
	_insert_data_in_payload(data, Voltage_S6_C7, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0xc, 7);
	
	_insert_data_in_payload(data, Voltage_S6_C8, 0, 8);
	_insert_data_in_payload(data, Voltage_S6_C9, 8, 8);
	_insert_data_in_payload(data, Voltage_S6_C10, 16, 8);
	_insert_data_in_payload(data, Voltage_S6_C11, 24, 8);
	_insert_data_in_payload(data, Voltage_S6_C12, 32, 8);
	_insert_data_in_payload(data, Voltage_S6_C13, 40, 8);
	_insert_data_in_payload(data, Voltage_S6_C14, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0xd, 7);
	
	_insert_data_in_payload(data, Voltage_S7_C1, 0, 8);
	_insert_data_in_payload(data, Voltage_S7_C2, 8, 8);
	_insert_data_in_payload(data, Voltage_S7_C3, 16, 8);
	_insert_data_in_payload(data, Voltage_S7_C4, 24, 8);
	_insert_data_in_payload(data, Voltage_S7_C5, 32, 8);
	_insert_data_in_payload(data, Voltage_S7_C6, 40, 8);
	_insert_data_in_payload(data, Voltage_S7_C7, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0xe, 7);
	
	_insert_data_in_payload(data, Voltage_S7_C8, 0, 8);
	_insert_data_in_payload(data, Voltage_S7_C9, 8, 8);
	_insert_data_in_payload(data, Voltage_S7_C10, 16, 8);
	_insert_data_in_payload(data, Voltage_S7_C11, 24, 8);
	_insert_data_in_payload(data, Voltage_S7_C12, 32, 8);
	_insert_data_in_payload(data, Voltage_S7_C13, 40, 8);
	_insert_data_in_payload(data, Voltage_S7_C14, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0xf, 7);
	
	_insert_data_in_payload(data, Voltage_S8_C1, 0, 8);
	_insert_data_in_payload(data, Voltage_S8_C2, 8, 8);
	_insert_data_in_payload(data, Voltage_S8_C3, 16, 8);
	_insert_data_in_payload(data, Voltage_S8_C4, 24, 8);
	_insert_data_in_payload(data, Voltage_S8_C5, 32, 8);
	_insert_data_in_payload(data, Voltage_S8_C6, 40, 8);
	_insert_data_in_payload(data, Voltage_S8_C7, 48, 8);
	return vera_err_ok;
}

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
) {
	if (!frame)	return vera_err_null_arg;

	memset(data, 0, sizeof(uint8_t)*8);
	init_standard_tx_header(frame, 0x10, 7);
	
	_insert_data_in_payload(data, Voltage_S8_C8, 0, 8);
	_insert_data_in_payload(data, Voltage_S8_C9, 8, 8);
	_insert_data_in_payload(data, Voltage_S8_C10, 16, 8);
	_insert_data_in_payload(data, Voltage_S8_C11, 24, 8);
	_insert_data_in_payload(data, Voltage_S8_C12, 32, 8);
	_insert_data_in_payload(data, Voltage_S8_C13, 40, 8);
	_insert_data_in_payload(data, Voltage_S8_C14, 48, 8);
	return vera_err_ok;
}
