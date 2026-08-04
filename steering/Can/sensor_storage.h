#ifndef SENSOR_STORAGE_H
#define SENSOR_STORAGE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct {
    uint16_t module_start;
    uint16_t module_count;
    const char* name;
} section_meta_t;

typedef struct {
    uint16_t section_idx;
    uint16_t sensor_start;
    uint16_t sensor_count;
    const char* name;
} module_meta_t;

typedef struct {
    uint16_t global_idx;
    uint8_t start_bit;
    uint8_t bit_length;
    float factor;
    float offset;
    const char* name;
} sensor_meta_t;

// Count constants
#define SENSOR_COUNT 112
#define MODULE_COUNT 8
#define SECTION_COUNT 1

// Extern declarations for Flash metadata arrays
extern const section_meta_t g_sections[SECTION_COUNT];
extern const module_meta_t g_modules[MODULE_COUNT];
extern const sensor_meta_t g_sensors[SENSOR_COUNT];

// RAM - Sensor values array
extern float g_sensor_values[SENSOR_COUNT];

// Inline accessor functions
static inline float sensor_get_value(uint16_t idx) {
    return (idx < SENSOR_COUNT) ? g_sensor_values[idx] : 0.0f;
}

static inline void sensor_set_value(uint16_t idx, float value) {
    if (idx < SENSOR_COUNT) {
        g_sensor_values[idx] = value;
    }
}

// Lookup functions - return index or -1 if not found
int section_find_by_name(const char* name);
int module_find_by_name(int section_idx, const char* name);
int sensor_find_by_name(int module_idx, const char* name);

// Convenience: set value by full topic "Section/Module/Sensor"
// Returns true on success, false if topic not found
bool sensor_set_value_by_topic(const char* topic, float value);

// Name string declarations (separate const char arrays in Flash)

extern const char g_section_name_0[];


extern const char g_module_name_0[];

extern const char g_module_name_1[];

extern const char g_module_name_2[];

extern const char g_module_name_3[];

extern const char g_module_name_4[];

extern const char g_module_name_5[];

extern const char g_module_name_6[];

extern const char g_module_name_7[];


extern const char g_sensor_name_0[];

extern const char g_sensor_name_1[];

extern const char g_sensor_name_2[];

extern const char g_sensor_name_3[];

extern const char g_sensor_name_4[];

extern const char g_sensor_name_5[];

extern const char g_sensor_name_6[];

extern const char g_sensor_name_7[];

extern const char g_sensor_name_8[];

extern const char g_sensor_name_9[];

extern const char g_sensor_name_10[];

extern const char g_sensor_name_11[];

extern const char g_sensor_name_12[];

extern const char g_sensor_name_13[];

extern const char g_sensor_name_14[];

extern const char g_sensor_name_15[];

extern const char g_sensor_name_16[];

extern const char g_sensor_name_17[];

extern const char g_sensor_name_18[];

extern const char g_sensor_name_19[];

extern const char g_sensor_name_20[];

extern const char g_sensor_name_21[];

extern const char g_sensor_name_22[];

extern const char g_sensor_name_23[];

extern const char g_sensor_name_24[];

extern const char g_sensor_name_25[];

extern const char g_sensor_name_26[];

extern const char g_sensor_name_27[];

extern const char g_sensor_name_28[];

extern const char g_sensor_name_29[];

extern const char g_sensor_name_30[];

extern const char g_sensor_name_31[];

extern const char g_sensor_name_32[];

extern const char g_sensor_name_33[];

extern const char g_sensor_name_34[];

extern const char g_sensor_name_35[];

extern const char g_sensor_name_36[];

extern const char g_sensor_name_37[];

extern const char g_sensor_name_38[];

extern const char g_sensor_name_39[];

extern const char g_sensor_name_40[];

extern const char g_sensor_name_41[];

extern const char g_sensor_name_42[];

extern const char g_sensor_name_43[];

extern const char g_sensor_name_44[];

extern const char g_sensor_name_45[];

extern const char g_sensor_name_46[];

extern const char g_sensor_name_47[];

extern const char g_sensor_name_48[];

extern const char g_sensor_name_49[];

extern const char g_sensor_name_50[];

extern const char g_sensor_name_51[];

extern const char g_sensor_name_52[];

extern const char g_sensor_name_53[];

extern const char g_sensor_name_54[];

extern const char g_sensor_name_55[];

extern const char g_sensor_name_56[];

extern const char g_sensor_name_57[];

extern const char g_sensor_name_58[];

extern const char g_sensor_name_59[];

extern const char g_sensor_name_60[];

extern const char g_sensor_name_61[];

extern const char g_sensor_name_62[];

extern const char g_sensor_name_63[];

extern const char g_sensor_name_64[];

extern const char g_sensor_name_65[];

extern const char g_sensor_name_66[];

extern const char g_sensor_name_67[];

extern const char g_sensor_name_68[];

extern const char g_sensor_name_69[];

extern const char g_sensor_name_70[];

extern const char g_sensor_name_71[];

extern const char g_sensor_name_72[];

extern const char g_sensor_name_73[];

extern const char g_sensor_name_74[];

extern const char g_sensor_name_75[];

extern const char g_sensor_name_76[];

extern const char g_sensor_name_77[];

extern const char g_sensor_name_78[];

extern const char g_sensor_name_79[];

extern const char g_sensor_name_80[];

extern const char g_sensor_name_81[];

extern const char g_sensor_name_82[];

extern const char g_sensor_name_83[];

extern const char g_sensor_name_84[];

extern const char g_sensor_name_85[];

extern const char g_sensor_name_86[];

extern const char g_sensor_name_87[];

extern const char g_sensor_name_88[];

extern const char g_sensor_name_89[];

extern const char g_sensor_name_90[];

extern const char g_sensor_name_91[];

extern const char g_sensor_name_92[];

extern const char g_sensor_name_93[];

extern const char g_sensor_name_94[];

extern const char g_sensor_name_95[];

extern const char g_sensor_name_96[];

extern const char g_sensor_name_97[];

extern const char g_sensor_name_98[];

extern const char g_sensor_name_99[];

extern const char g_sensor_name_100[];

extern const char g_sensor_name_101[];

extern const char g_sensor_name_102[];

extern const char g_sensor_name_103[];

extern const char g_sensor_name_104[];

extern const char g_sensor_name_105[];

extern const char g_sensor_name_106[];

extern const char g_sensor_name_107[];

extern const char g_sensor_name_108[];

extern const char g_sensor_name_109[];

extern const char g_sensor_name_110[];

extern const char g_sensor_name_111[];

#ifdef __cplusplus
}
#endif

#endif // SENSOR_STORAGE_H
