#include "vera.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

uint64_t _get_payload_by_start_and_length(uint8_t* payload, uint8_t start, uint8_t length) {
	uint64_t res = 0ULL;

	for (uint8_t i = 0; i < length; i++) {
		uint8_t current_bit_index = start + i;
		uint8_t byte_index = current_bit_index / 8;
		uint8_t bit_offset_in_byte = current_bit_index % 8;
		uint8_t bit = (payload[byte_index] >> (7 - bit_offset_in_byte)) & 1;
		
		res |= (uint64_t)bit << (length - 1 - i);
	}

	return res;
}

void _insert_data_in_payload(uint8_t* payload, uint64_t data, uint8_t start, uint8_t length) {
	for (uint8_t i = start; i < start + length; i++) {
		uint8_t payload_index = i / 8;
		uint8_t shift_right = start + length - i - 1;
		uint8_t shift_left = 7 - (i % 8);

		payload[payload_index] |= ((data >> shift_right) & 1) << (shift_left);
	}
}

vera_err_t _decode_signal(
	vera_can_rx_frame_t*   frame,
	vera_signal_t*         signal,
	vera_decoded_signal_t* res
) {
	strcpy(res->name, signal->name);
	strcpy(res->unit, signal->unit);
	strcpy(res->topic, signal->topic);

	if (signal->start_bit >= frame->dlc * 8 || signal->start_bit + signal->dlc > frame->dlc * 8) {
		return vera_err_out_of_bounds;		
	}

	res->value = _get_payload_by_start_and_length(
		frame->data,
		signal->start_bit,
		signal->dlc
	);

	res->value *= signal->factor;
	res->value += signal->offset;
	if (res->value < signal->min)
		res->value = signal->min;
	if (res->value > signal->max)
		res->value = signal->max;

	return vera_err_ok;
}

vera_err_t _decode_message(
	vera_can_rx_frame_t*    frame,
	vera_message_t*         message,
	vera_signal_t*          signals,
	vera_decoding_result_t* result
) {
	if (!result->decoded_signals) return vera_err_null_arg;

	for (uint8_t i = 0; i < message->n_signals; i++) {
		vera_err_t err = _decode_signal(
			frame,
			signals + i,
			result->decoded_signals + i
		);
		if (err != vera_err_ok) {
			return err;
		}
		result->n_signals++;
	}

	return vera_err_ok;
}

vera_err_t vera_decode_can_frame(
	vera_can_rx_frame_t*    frame,
	vera_decoding_result_t* result
) {
	switch(frame->id) {
		case 0x1: {
			vera_message_t message = {
				.id = 0x1,
				.name = "Battery_S1_1",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S1_C1",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C1"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S1_C2",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C2"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S1_C3",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C3"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S1_C4",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C4"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S1_C5",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C5"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S1_C6",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C6"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S1_C7",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C7"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x2: {
			vera_message_t message = {
				.id = 0x2,
				.name = "Battery_S1_2",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S1_C8",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C8"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S1_C9",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C9"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S1_C10",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C10"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S1_C11",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C11"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S1_C12",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C12"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S1_C13",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C13"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S1_C14",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S1/Voltage_C14"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x3: {
			vera_message_t message = {
				.id = 0x3,
				.name = "Battery_S2_1",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S2_C1",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C1"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S2_C2",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C2"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S2_C3",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C3"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S2_C4",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C4"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S2_C5",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C5"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S2_C6",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C6"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S2_C7",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C7"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x4: {
			vera_message_t message = {
				.id = 0x4,
				.name = "Battery_S2_2",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S2_C8",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C8"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S2_C9",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C9"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S2_C10",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C10"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S2_C11",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C11"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S2_C12",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C12"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S2_C13",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C13"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S2_C14",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S2/Voltage_C14"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x5: {
			vera_message_t message = {
				.id = 0x5,
				.name = "Battery_S3_1",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S3_C1",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C1"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S3_C2",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C2"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S3_C3",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C3"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S3_C4",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C4"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S3_C5",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C5"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S3_C6",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C6"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S3_C7",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C7"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x6: {
			vera_message_t message = {
				.id = 0x6,
				.name = "Battery_S3_2",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S3_C8",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C8"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S3_C9",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C9"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S3_C10",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C10"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S3_C11",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C11"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S3_C12",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C12"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S3_C13",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C13"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S3_C14",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S3/Voltage_C14"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x7: {
			vera_message_t message = {
				.id = 0x7,
				.name = "Battery_S4_1",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S4_C1",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C1"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S4_C2",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C2"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S4_C3",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C3"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S4_C4",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C4"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S4_C5",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C5"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S4_C6",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C6"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S4_C7",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C7"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x8: {
			vera_message_t message = {
				.id = 0x8,
				.name = "Battery_S4_2",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S4_C8",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C8"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S4_C9",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C9"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S4_C10",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C10"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S4_C11",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C11"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S4_C12",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C12"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S4_C13",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C13"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S4_C14",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S4/Voltage_C14"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x9: {
			vera_message_t message = {
				.id = 0x9,
				.name = "Battery_S5_1",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S5_C1",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C1"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S5_C2",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C2"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S5_C3",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C3"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S5_C4",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C4"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S5_C5",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C5"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S5_C6",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C6"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S5_C7",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C7"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0xa: {
			vera_message_t message = {
				.id = 0xa,
				.name = "Battery_S5_2",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S5_C8",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C8"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S5_C9",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C9"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S5_C10",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C10"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S5_C11",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C11"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S5_C12",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C12"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S5_C13",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C13"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S5_C14",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S5/Voltage_C14"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0xb: {
			vera_message_t message = {
				.id = 0xb,
				.name = "Battery_S6_1",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S6_C1",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C1"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S6_C2",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C2"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S6_C3",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C3"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S6_C4",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C4"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S6_C5",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C5"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S6_C6",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C6"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S6_C7",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C7"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0xc: {
			vera_message_t message = {
				.id = 0xc,
				.name = "Battery_S6_2",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S6_C8",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C8"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S6_C9",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C9"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S6_C10",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C10"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S6_C11",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C11"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S6_C12",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C12"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S6_C13",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C13"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S6_C14",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S6/Voltage_C14"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0xd: {
			vera_message_t message = {
				.id = 0xd,
				.name = "Battery_S7_1",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S7_C1",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C1"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S7_C2",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C2"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S7_C3",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C3"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S7_C4",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C4"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S7_C5",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C5"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S7_C6",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C6"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S7_C7",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C7"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0xe: {
			vera_message_t message = {
				.id = 0xe,
				.name = "Battery_S7_2",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S7_C8",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C8"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S7_C9",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C9"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S7_C10",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C10"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S7_C11",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C11"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S7_C12",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C12"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S7_C13",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C13"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S7_C14",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S7/Voltage_C14"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0xf: {
			vera_message_t message = {
				.id = 0xf,
				.name = "Battery_S8_1",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S8_C1",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C1"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S8_C2",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C2"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S8_C3",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C3"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S8_C4",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C4"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S8_C5",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C5"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S8_C6",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C6"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S8_C7",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C7"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
		case 0x10: {
			vera_message_t message = {
				.id = 0x10,
				.name = "Battery_S8_2",
				.dlc = 7,
				.n_signals = 7
			};

			vera_signal_t signals[7];
			signals[0]	= (vera_signal_t){
				.name = "Voltage_S8_C8",
				.unit = "V",
				.start_bit = 0,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C8"
			};
			signals[1]	= (vera_signal_t){
				.name = "Voltage_S8_C9",
				.unit = "V",
				.start_bit = 8,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C9"
			};
			signals[2]	= (vera_signal_t){
				.name = "Voltage_S8_C10",
				.unit = "V",
				.start_bit = 16,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C10"
			};
			signals[3]	= (vera_signal_t){
				.name = "Voltage_S8_C11",
				.unit = "V",
				.start_bit = 24,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C11"
			};
			signals[4]	= (vera_signal_t){
				.name = "Voltage_S8_C12",
				.unit = "V",
				.start_bit = 32,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C12"
			};
			signals[5]	= (vera_signal_t){
				.name = "Voltage_S8_C13",
				.unit = "V",
				.start_bit = 40,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C13"
			};
			signals[6]	= (vera_signal_t){
				.name = "Voltage_S8_C14",
				.unit = "V",
				.start_bit = 48,
				.dlc = 8,
				.endianness = 1,
				.sign = false,
				.factor = 0.0100,
				.offset = 2.2000,
				.min = 0.0000,
				.max = 4.7500,
				.topic = "Battery/S8/Voltage_C14"
			};

			vera_err_t err = _decode_message(
				frame,
				&message,
				signals,
				result
			);
			if (err != vera_err_ok) {
				return err;
			}
			break;
		}
	}
}

vera_err_t vera_encode_Battery_S1_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S1_C1,
	uint64_t Voltage_S1_C2,
	uint64_t Voltage_S1_C3,
	uint64_t Voltage_S1_C4,
	uint64_t Voltage_S1_C5,
	uint64_t Voltage_S1_C6,
	uint64_t Voltage_S1_C7
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x1;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S1_C1, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C2, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C3, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C4, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C5, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C6, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C7, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S1_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S1_C8,
	uint64_t Voltage_S1_C9,
	uint64_t Voltage_S1_C10,
	uint64_t Voltage_S1_C11,
	uint64_t Voltage_S1_C12,
	uint64_t Voltage_S1_C13,
	uint64_t Voltage_S1_C14
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x2;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S1_C8, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C9, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C10, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C11, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C12, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C13, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S1_C14, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S2_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S2_C1,
	uint64_t Voltage_S2_C2,
	uint64_t Voltage_S2_C3,
	uint64_t Voltage_S2_C4,
	uint64_t Voltage_S2_C5,
	uint64_t Voltage_S2_C6,
	uint64_t Voltage_S2_C7
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x3;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S2_C1, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C2, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C3, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C4, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C5, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C6, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C7, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S2_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S2_C8,
	uint64_t Voltage_S2_C9,
	uint64_t Voltage_S2_C10,
	uint64_t Voltage_S2_C11,
	uint64_t Voltage_S2_C12,
	uint64_t Voltage_S2_C13,
	uint64_t Voltage_S2_C14
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x4;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S2_C8, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C9, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C10, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C11, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C12, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C13, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S2_C14, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S3_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S3_C1,
	uint64_t Voltage_S3_C2,
	uint64_t Voltage_S3_C3,
	uint64_t Voltage_S3_C4,
	uint64_t Voltage_S3_C5,
	uint64_t Voltage_S3_C6,
	uint64_t Voltage_S3_C7
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x5;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S3_C1, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C2, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C3, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C4, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C5, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C6, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C7, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S3_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S3_C8,
	uint64_t Voltage_S3_C9,
	uint64_t Voltage_S3_C10,
	uint64_t Voltage_S3_C11,
	uint64_t Voltage_S3_C12,
	uint64_t Voltage_S3_C13,
	uint64_t Voltage_S3_C14
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x6;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S3_C8, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C9, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C10, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C11, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C12, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C13, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S3_C14, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S4_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S4_C1,
	uint64_t Voltage_S4_C2,
	uint64_t Voltage_S4_C3,
	uint64_t Voltage_S4_C4,
	uint64_t Voltage_S4_C5,
	uint64_t Voltage_S4_C6,
	uint64_t Voltage_S4_C7
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x7;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S4_C1, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C2, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C3, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C4, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C5, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C6, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C7, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S4_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S4_C8,
	uint64_t Voltage_S4_C9,
	uint64_t Voltage_S4_C10,
	uint64_t Voltage_S4_C11,
	uint64_t Voltage_S4_C12,
	uint64_t Voltage_S4_C13,
	uint64_t Voltage_S4_C14
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x8;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S4_C8, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C9, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C10, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C11, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C12, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C13, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S4_C14, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S5_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S5_C1,
	uint64_t Voltage_S5_C2,
	uint64_t Voltage_S5_C3,
	uint64_t Voltage_S5_C4,
	uint64_t Voltage_S5_C5,
	uint64_t Voltage_S5_C6,
	uint64_t Voltage_S5_C7
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x9;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S5_C1, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C2, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C3, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C4, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C5, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C6, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C7, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S5_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S5_C8,
	uint64_t Voltage_S5_C9,
	uint64_t Voltage_S5_C10,
	uint64_t Voltage_S5_C11,
	uint64_t Voltage_S5_C12,
	uint64_t Voltage_S5_C13,
	uint64_t Voltage_S5_C14
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0xa;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S5_C8, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C9, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C10, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C11, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C12, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C13, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S5_C14, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S6_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S6_C1,
	uint64_t Voltage_S6_C2,
	uint64_t Voltage_S6_C3,
	uint64_t Voltage_S6_C4,
	uint64_t Voltage_S6_C5,
	uint64_t Voltage_S6_C6,
	uint64_t Voltage_S6_C7
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0xb;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S6_C1, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C2, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C3, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C4, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C5, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C6, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C7, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S6_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S6_C8,
	uint64_t Voltage_S6_C9,
	uint64_t Voltage_S6_C10,
	uint64_t Voltage_S6_C11,
	uint64_t Voltage_S6_C12,
	uint64_t Voltage_S6_C13,
	uint64_t Voltage_S6_C14
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0xc;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S6_C8, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C9, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C10, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C11, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C12, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C13, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S6_C14, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S7_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S7_C1,
	uint64_t Voltage_S7_C2,
	uint64_t Voltage_S7_C3,
	uint64_t Voltage_S7_C4,
	uint64_t Voltage_S7_C5,
	uint64_t Voltage_S7_C6,
	uint64_t Voltage_S7_C7
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0xd;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S7_C1, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C2, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C3, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C4, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C5, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C6, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C7, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S7_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S7_C8,
	uint64_t Voltage_S7_C9,
	uint64_t Voltage_S7_C10,
	uint64_t Voltage_S7_C11,
	uint64_t Voltage_S7_C12,
	uint64_t Voltage_S7_C13,
	uint64_t Voltage_S7_C14
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0xe;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S7_C8, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C9, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C10, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C11, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C12, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C13, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S7_C14, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S8_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S8_C1,
	uint64_t Voltage_S8_C2,
	uint64_t Voltage_S8_C3,
	uint64_t Voltage_S8_C4,
	uint64_t Voltage_S8_C5,
	uint64_t Voltage_S8_C6,
	uint64_t Voltage_S8_C7
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0xf;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S8_C1, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C2, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C3, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C4, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C5, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C6, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C7, 48, 8);
	return vera_err_ok;
}


vera_err_t vera_encode_Battery_S8_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S8_C8,
	uint64_t Voltage_S8_C9,
	uint64_t Voltage_S8_C10,
	uint64_t Voltage_S8_C11,
	uint64_t Voltage_S8_C12,
	uint64_t Voltage_S8_C13,
	uint64_t Voltage_S8_C14
) {
	if (!frame) return vera_err_null_arg;

	memset(frame->data, 0, sizeof(uint8_t)*8);
	frame->id = 0x10;
	frame->dlc = 7;	
	_insert_data_in_payload(frame->data, Voltage_S8_C8, 0, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C9, 8, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C10, 16, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C11, 24, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C12, 32, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C13, 40, 8);	
	_insert_data_in_payload(frame->data, Voltage_S8_C14, 48, 8);
	return vera_err_ok;
}

const size_t vera_n_signals_Battery_S1_1 = 7;
const size_t vera_n_signals_Battery_S1_2 = 7;
const size_t vera_n_signals_Battery_S2_1 = 7;
const size_t vera_n_signals_Battery_S2_2 = 7;
const size_t vera_n_signals_Battery_S3_1 = 7;
const size_t vera_n_signals_Battery_S3_2 = 7;
const size_t vera_n_signals_Battery_S4_1 = 7;
const size_t vera_n_signals_Battery_S4_2 = 7;
const size_t vera_n_signals_Battery_S5_1 = 7;
const size_t vera_n_signals_Battery_S5_2 = 7;
const size_t vera_n_signals_Battery_S6_1 = 7;
const size_t vera_n_signals_Battery_S6_2 = 7;
const size_t vera_n_signals_Battery_S7_1 = 7;
const size_t vera_n_signals_Battery_S7_2 = 7;
const size_t vera_n_signals_Battery_S8_1 = 7;
const size_t vera_n_signals_Battery_S8_2 = 7;
