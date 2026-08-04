#ifndef VERA_H
#define VERA_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define CAN_MAX_DATA_LEN 8

typedef struct {
	uint32_t id;
	uint8_t  dlc;
	uint8_t  data[CAN_MAX_DATA_LEN];

	bool is_extended_id;
	bool is_rtr;
	bool is_fd;
	bool bit_rate_switch;
	bool error_state_indicator;

	uint64_t timestamp;
} vera_can_rx_frame_t;

typedef struct {
	uint32_t id;
	uint8_t  dlc;
	uint8_t  data[CAN_MAX_DATA_LEN];

	bool is_extended_id;
	bool is_rtr;
	bool is_fd;
	bool bit_rate_switch;
	bool error_state_indicator;

	uint64_t timestamp;
} vera_can_tx_frame_t;

typedef struct {
	char    name[32];
	uint8_t start_bit;
	uint8_t dlc;
	uint8_t endianness;
	bool    sign;
	uint8_t integer_figures;
	uint8_t decimal_figures;
	float   factor;
	float   offset;
	float   min;
	float   max;
	char    unit[32];
	char**  receivers;
	char    topic[32];
} vera_signal_t;

typedef struct {
	uint32_t       id;
	char           name[32];
	uint8_t        dlc;
	char*          transmitter;
	vera_signal_t* signals;
	uint8_t        n_signals;
} vera_message_t;

typedef struct {
	char     name[32];
	char     unit[32];
	float    value;
	uint64_t timestamp;
	char     topic[32];
} vera_decoded_signal_t;

typedef struct {
	uint8_t n_signals;
	vera_decoded_signal_t* decoded_signals;
} vera_decoding_result_t;

typedef enum {
	vera_err_ok,
	vera_err_allocation,
	vera_err_out_of_bounds,
	vera_err_null_arg
} vera_err_t;

vera_err_t vera_decode_can_frame(
	vera_can_rx_frame_t*   frame,
	vera_decoding_result_t* result
);

vera_err_t vera_encode_Battery_S1_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S1_C1,
	uint64_t Voltage_S1_C2,
	uint64_t Voltage_S1_C3,
	uint64_t Voltage_S1_C4,
	uint64_t Voltage_S1_C5,
	uint64_t Voltage_S1_C6,
	uint64_t Voltage_S1_C7
);

vera_err_t vera_encode_Battery_S1_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S1_C8,
	uint64_t Voltage_S1_C9,
	uint64_t Voltage_S1_C10,
	uint64_t Voltage_S1_C11,
	uint64_t Voltage_S1_C12,
	uint64_t Voltage_S1_C13,
	uint64_t Voltage_S1_C14
);

vera_err_t vera_encode_Battery_S2_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S2_C1,
	uint64_t Voltage_S2_C2,
	uint64_t Voltage_S2_C3,
	uint64_t Voltage_S2_C4,
	uint64_t Voltage_S2_C5,
	uint64_t Voltage_S2_C6,
	uint64_t Voltage_S2_C7
);

vera_err_t vera_encode_Battery_S2_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S2_C8,
	uint64_t Voltage_S2_C9,
	uint64_t Voltage_S2_C10,
	uint64_t Voltage_S2_C11,
	uint64_t Voltage_S2_C12,
	uint64_t Voltage_S2_C13,
	uint64_t Voltage_S2_C14
);

vera_err_t vera_encode_Battery_S3_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S3_C1,
	uint64_t Voltage_S3_C2,
	uint64_t Voltage_S3_C3,
	uint64_t Voltage_S3_C4,
	uint64_t Voltage_S3_C5,
	uint64_t Voltage_S3_C6,
	uint64_t Voltage_S3_C7
);

vera_err_t vera_encode_Battery_S3_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S3_C8,
	uint64_t Voltage_S3_C9,
	uint64_t Voltage_S3_C10,
	uint64_t Voltage_S3_C11,
	uint64_t Voltage_S3_C12,
	uint64_t Voltage_S3_C13,
	uint64_t Voltage_S3_C14
);

vera_err_t vera_encode_Battery_S4_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S4_C1,
	uint64_t Voltage_S4_C2,
	uint64_t Voltage_S4_C3,
	uint64_t Voltage_S4_C4,
	uint64_t Voltage_S4_C5,
	uint64_t Voltage_S4_C6,
	uint64_t Voltage_S4_C7
);

vera_err_t vera_encode_Battery_S4_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S4_C8,
	uint64_t Voltage_S4_C9,
	uint64_t Voltage_S4_C10,
	uint64_t Voltage_S4_C11,
	uint64_t Voltage_S4_C12,
	uint64_t Voltage_S4_C13,
	uint64_t Voltage_S4_C14
);

vera_err_t vera_encode_Battery_S5_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S5_C1,
	uint64_t Voltage_S5_C2,
	uint64_t Voltage_S5_C3,
	uint64_t Voltage_S5_C4,
	uint64_t Voltage_S5_C5,
	uint64_t Voltage_S5_C6,
	uint64_t Voltage_S5_C7
);

vera_err_t vera_encode_Battery_S5_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S5_C8,
	uint64_t Voltage_S5_C9,
	uint64_t Voltage_S5_C10,
	uint64_t Voltage_S5_C11,
	uint64_t Voltage_S5_C12,
	uint64_t Voltage_S5_C13,
	uint64_t Voltage_S5_C14
);

vera_err_t vera_encode_Battery_S6_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S6_C1,
	uint64_t Voltage_S6_C2,
	uint64_t Voltage_S6_C3,
	uint64_t Voltage_S6_C4,
	uint64_t Voltage_S6_C5,
	uint64_t Voltage_S6_C6,
	uint64_t Voltage_S6_C7
);

vera_err_t vera_encode_Battery_S6_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S6_C8,
	uint64_t Voltage_S6_C9,
	uint64_t Voltage_S6_C10,
	uint64_t Voltage_S6_C11,
	uint64_t Voltage_S6_C12,
	uint64_t Voltage_S6_C13,
	uint64_t Voltage_S6_C14
);

vera_err_t vera_encode_Battery_S7_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S7_C1,
	uint64_t Voltage_S7_C2,
	uint64_t Voltage_S7_C3,
	uint64_t Voltage_S7_C4,
	uint64_t Voltage_S7_C5,
	uint64_t Voltage_S7_C6,
	uint64_t Voltage_S7_C7
);

vera_err_t vera_encode_Battery_S7_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S7_C8,
	uint64_t Voltage_S7_C9,
	uint64_t Voltage_S7_C10,
	uint64_t Voltage_S7_C11,
	uint64_t Voltage_S7_C12,
	uint64_t Voltage_S7_C13,
	uint64_t Voltage_S7_C14
);

vera_err_t vera_encode_Battery_S8_1(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S8_C1,
	uint64_t Voltage_S8_C2,
	uint64_t Voltage_S8_C3,
	uint64_t Voltage_S8_C4,
	uint64_t Voltage_S8_C5,
	uint64_t Voltage_S8_C6,
	uint64_t Voltage_S8_C7
);

vera_err_t vera_encode_Battery_S8_2(
	vera_can_tx_frame_t* frame,
	uint64_t Voltage_S8_C8,
	uint64_t Voltage_S8_C9,
	uint64_t Voltage_S8_C10,
	uint64_t Voltage_S8_C11,
	uint64_t Voltage_S8_C12,
	uint64_t Voltage_S8_C13,
	uint64_t Voltage_S8_C14
);
extern const size_t vera_n_signals_Battery_S1_1;
extern const size_t vera_n_signals_Battery_S1_2;
extern const size_t vera_n_signals_Battery_S2_1;
extern const size_t vera_n_signals_Battery_S2_2;
extern const size_t vera_n_signals_Battery_S3_1;
extern const size_t vera_n_signals_Battery_S3_2;
extern const size_t vera_n_signals_Battery_S4_1;
extern const size_t vera_n_signals_Battery_S4_2;
extern const size_t vera_n_signals_Battery_S5_1;
extern const size_t vera_n_signals_Battery_S5_2;
extern const size_t vera_n_signals_Battery_S6_1;
extern const size_t vera_n_signals_Battery_S6_2;
extern const size_t vera_n_signals_Battery_S7_1;
extern const size_t vera_n_signals_Battery_S7_2;
extern const size_t vera_n_signals_Battery_S8_1;
extern const size_t vera_n_signals_Battery_S8_2;

#endif // VERA_H
