#include "sensor_storage.h"
#include <string.h>
#include <stdbool.h>

// RAM - Sensor values (zero-initialized)
float g_sensor_values[SENSOR_COUNT] = {0};

// Section name strings (Flash)

const char g_section_name_0[] = "Battery";


// Module name strings (Flash)

const char g_module_name_0[] = "S1";

const char g_module_name_1[] = "S2";

const char g_module_name_2[] = "S3";

const char g_module_name_3[] = "S4";

const char g_module_name_4[] = "S5";

const char g_module_name_5[] = "S6";

const char g_module_name_6[] = "S7";

const char g_module_name_7[] = "S8";


// Sensor name strings (Flash)

const char g_sensor_name_0[] = "Voltage_C1";

const char g_sensor_name_1[] = "Voltage_C2";

const char g_sensor_name_2[] = "Voltage_C3";

const char g_sensor_name_3[] = "Voltage_C4";

const char g_sensor_name_4[] = "Voltage_C5";

const char g_sensor_name_5[] = "Voltage_C6";

const char g_sensor_name_6[] = "Voltage_C7";

const char g_sensor_name_7[] = "Voltage_C8";

const char g_sensor_name_8[] = "Voltage_C9";

const char g_sensor_name_9[] = "Voltage_C10";

const char g_sensor_name_10[] = "Voltage_C11";

const char g_sensor_name_11[] = "Voltage_C12";

const char g_sensor_name_12[] = "Voltage_C13";

const char g_sensor_name_13[] = "Voltage_C14";

const char g_sensor_name_14[] = "Voltage_C1";

const char g_sensor_name_15[] = "Voltage_C2";

const char g_sensor_name_16[] = "Voltage_C3";

const char g_sensor_name_17[] = "Voltage_C4";

const char g_sensor_name_18[] = "Voltage_C5";

const char g_sensor_name_19[] = "Voltage_C6";

const char g_sensor_name_20[] = "Voltage_C7";

const char g_sensor_name_21[] = "Voltage_C8";

const char g_sensor_name_22[] = "Voltage_C9";

const char g_sensor_name_23[] = "Voltage_C10";

const char g_sensor_name_24[] = "Voltage_C11";

const char g_sensor_name_25[] = "Voltage_C12";

const char g_sensor_name_26[] = "Voltage_C13";

const char g_sensor_name_27[] = "Voltage_C14";

const char g_sensor_name_28[] = "Voltage_C1";

const char g_sensor_name_29[] = "Voltage_C2";

const char g_sensor_name_30[] = "Voltage_C3";

const char g_sensor_name_31[] = "Voltage_C4";

const char g_sensor_name_32[] = "Voltage_C5";

const char g_sensor_name_33[] = "Voltage_C6";

const char g_sensor_name_34[] = "Voltage_C7";

const char g_sensor_name_35[] = "Voltage_C8";

const char g_sensor_name_36[] = "Voltage_C9";

const char g_sensor_name_37[] = "Voltage_C10";

const char g_sensor_name_38[] = "Voltage_C11";

const char g_sensor_name_39[] = "Voltage_C12";

const char g_sensor_name_40[] = "Voltage_C13";

const char g_sensor_name_41[] = "Voltage_C14";

const char g_sensor_name_42[] = "Voltage_C1";

const char g_sensor_name_43[] = "Voltage_C2";

const char g_sensor_name_44[] = "Voltage_C3";

const char g_sensor_name_45[] = "Voltage_C4";

const char g_sensor_name_46[] = "Voltage_C5";

const char g_sensor_name_47[] = "Voltage_C6";

const char g_sensor_name_48[] = "Voltage_C7";

const char g_sensor_name_49[] = "Voltage_C8";

const char g_sensor_name_50[] = "Voltage_C9";

const char g_sensor_name_51[] = "Voltage_C10";

const char g_sensor_name_52[] = "Voltage_C11";

const char g_sensor_name_53[] = "Voltage_C12";

const char g_sensor_name_54[] = "Voltage_C13";

const char g_sensor_name_55[] = "Voltage_C14";

const char g_sensor_name_56[] = "Voltage_C1";

const char g_sensor_name_57[] = "Voltage_C2";

const char g_sensor_name_58[] = "Voltage_C3";

const char g_sensor_name_59[] = "Voltage_C4";

const char g_sensor_name_60[] = "Voltage_C5";

const char g_sensor_name_61[] = "Voltage_C6";

const char g_sensor_name_62[] = "Voltage_C7";

const char g_sensor_name_63[] = "Voltage_C8";

const char g_sensor_name_64[] = "Voltage_C9";

const char g_sensor_name_65[] = "Voltage_C10";

const char g_sensor_name_66[] = "Voltage_C11";

const char g_sensor_name_67[] = "Voltage_C12";

const char g_sensor_name_68[] = "Voltage_C13";

const char g_sensor_name_69[] = "Voltage_C14";

const char g_sensor_name_70[] = "Voltage_C1";

const char g_sensor_name_71[] = "Voltage_C2";

const char g_sensor_name_72[] = "Voltage_C3";

const char g_sensor_name_73[] = "Voltage_C4";

const char g_sensor_name_74[] = "Voltage_C5";

const char g_sensor_name_75[] = "Voltage_C6";

const char g_sensor_name_76[] = "Voltage_C7";

const char g_sensor_name_77[] = "Voltage_C8";

const char g_sensor_name_78[] = "Voltage_C9";

const char g_sensor_name_79[] = "Voltage_C10";

const char g_sensor_name_80[] = "Voltage_C11";

const char g_sensor_name_81[] = "Voltage_C12";

const char g_sensor_name_82[] = "Voltage_C13";

const char g_sensor_name_83[] = "Voltage_C14";

const char g_sensor_name_84[] = "Voltage_C1";

const char g_sensor_name_85[] = "Voltage_C2";

const char g_sensor_name_86[] = "Voltage_C3";

const char g_sensor_name_87[] = "Voltage_C4";

const char g_sensor_name_88[] = "Voltage_C5";

const char g_sensor_name_89[] = "Voltage_C6";

const char g_sensor_name_90[] = "Voltage_C7";

const char g_sensor_name_91[] = "Voltage_C8";

const char g_sensor_name_92[] = "Voltage_C9";

const char g_sensor_name_93[] = "Voltage_C10";

const char g_sensor_name_94[] = "Voltage_C11";

const char g_sensor_name_95[] = "Voltage_C12";

const char g_sensor_name_96[] = "Voltage_C13";

const char g_sensor_name_97[] = "Voltage_C14";

const char g_sensor_name_98[] = "Voltage_C1";

const char g_sensor_name_99[] = "Voltage_C2";

const char g_sensor_name_100[] = "Voltage_C3";

const char g_sensor_name_101[] = "Voltage_C4";

const char g_sensor_name_102[] = "Voltage_C5";

const char g_sensor_name_103[] = "Voltage_C6";

const char g_sensor_name_104[] = "Voltage_C7";

const char g_sensor_name_105[] = "Voltage_C8";

const char g_sensor_name_106[] = "Voltage_C9";

const char g_sensor_name_107[] = "Voltage_C10";

const char g_sensor_name_108[] = "Voltage_C11";

const char g_sensor_name_109[] = "Voltage_C12";

const char g_sensor_name_110[] = "Voltage_C13";

const char g_sensor_name_111[] = "Voltage_C14";


// Flash - Section metadata array
const section_meta_t g_sections[SECTION_COUNT] = {

    { 0, 8, g_section_name_0 },

};

// Flash - Module metadata array
const module_meta_t g_modules[MODULE_COUNT] = {

    { 0, 0, 14, g_module_name_0 },

    { 0, 14, 14, g_module_name_1 },

    { 0, 28, 14, g_module_name_2 },

    { 0, 42, 14, g_module_name_3 },

    { 0, 56, 14, g_module_name_4 },

    { 0, 70, 14, g_module_name_5 },

    { 0, 84, 14, g_module_name_6 },

    { 0, 98, 14, g_module_name_7 },

};

// Flash - Sensor metadata array
const sensor_meta_t g_sensors[SENSOR_COUNT] = {

    { 0, 0, 8, 0.010000f, 2.200000f, g_sensor_name_0 },

    { 1, 8, 8, 0.010000f, 2.200000f, g_sensor_name_1 },

    { 2, 16, 8, 0.010000f, 2.200000f, g_sensor_name_2 },

    { 3, 24, 8, 0.010000f, 2.200000f, g_sensor_name_3 },

    { 4, 32, 8, 0.010000f, 2.200000f, g_sensor_name_4 },

    { 5, 40, 8, 0.010000f, 2.200000f, g_sensor_name_5 },

    { 6, 48, 8, 0.010000f, 2.200000f, g_sensor_name_6 },

    { 7, 0, 8, 0.010000f, 2.200000f, g_sensor_name_7 },

    { 8, 8, 8, 0.010000f, 2.200000f, g_sensor_name_8 },

    { 9, 16, 8, 0.010000f, 2.200000f, g_sensor_name_9 },

    { 10, 24, 8, 0.010000f, 2.200000f, g_sensor_name_10 },

    { 11, 32, 8, 0.010000f, 2.200000f, g_sensor_name_11 },

    { 12, 40, 8, 0.010000f, 2.200000f, g_sensor_name_12 },

    { 13, 48, 8, 0.010000f, 2.200000f, g_sensor_name_13 },

    { 14, 0, 8, 0.010000f, 2.200000f, g_sensor_name_14 },

    { 15, 8, 8, 0.010000f, 2.200000f, g_sensor_name_15 },

    { 16, 16, 8, 0.010000f, 2.200000f, g_sensor_name_16 },

    { 17, 24, 8, 0.010000f, 2.200000f, g_sensor_name_17 },

    { 18, 32, 8, 0.010000f, 2.200000f, g_sensor_name_18 },

    { 19, 40, 8, 0.010000f, 2.200000f, g_sensor_name_19 },

    { 20, 48, 8, 0.010000f, 2.200000f, g_sensor_name_20 },

    { 21, 0, 8, 0.010000f, 2.200000f, g_sensor_name_21 },

    { 22, 8, 8, 0.010000f, 2.200000f, g_sensor_name_22 },

    { 23, 16, 8, 0.010000f, 2.200000f, g_sensor_name_23 },

    { 24, 24, 8, 0.010000f, 2.200000f, g_sensor_name_24 },

    { 25, 32, 8, 0.010000f, 2.200000f, g_sensor_name_25 },

    { 26, 40, 8, 0.010000f, 2.200000f, g_sensor_name_26 },

    { 27, 48, 8, 0.010000f, 2.200000f, g_sensor_name_27 },

    { 28, 0, 8, 0.010000f, 2.200000f, g_sensor_name_28 },

    { 29, 8, 8, 0.010000f, 2.200000f, g_sensor_name_29 },

    { 30, 16, 8, 0.010000f, 2.200000f, g_sensor_name_30 },

    { 31, 24, 8, 0.010000f, 2.200000f, g_sensor_name_31 },

    { 32, 32, 8, 0.010000f, 2.200000f, g_sensor_name_32 },

    { 33, 40, 8, 0.010000f, 2.200000f, g_sensor_name_33 },

    { 34, 48, 8, 0.010000f, 2.200000f, g_sensor_name_34 },

    { 35, 0, 8, 0.010000f, 2.200000f, g_sensor_name_35 },

    { 36, 8, 8, 0.010000f, 2.200000f, g_sensor_name_36 },

    { 37, 16, 8, 0.010000f, 2.200000f, g_sensor_name_37 },

    { 38, 24, 8, 0.010000f, 2.200000f, g_sensor_name_38 },

    { 39, 32, 8, 0.010000f, 2.200000f, g_sensor_name_39 },

    { 40, 40, 8, 0.010000f, 2.200000f, g_sensor_name_40 },

    { 41, 48, 8, 0.010000f, 2.200000f, g_sensor_name_41 },

    { 42, 0, 8, 0.010000f, 2.200000f, g_sensor_name_42 },

    { 43, 8, 8, 0.010000f, 2.200000f, g_sensor_name_43 },

    { 44, 16, 8, 0.010000f, 2.200000f, g_sensor_name_44 },

    { 45, 24, 8, 0.010000f, 2.200000f, g_sensor_name_45 },

    { 46, 32, 8, 0.010000f, 2.200000f, g_sensor_name_46 },

    { 47, 40, 8, 0.010000f, 2.200000f, g_sensor_name_47 },

    { 48, 48, 8, 0.010000f, 2.200000f, g_sensor_name_48 },

    { 49, 0, 8, 0.010000f, 2.200000f, g_sensor_name_49 },

    { 50, 8, 8, 0.010000f, 2.200000f, g_sensor_name_50 },

    { 51, 16, 8, 0.010000f, 2.200000f, g_sensor_name_51 },

    { 52, 24, 8, 0.010000f, 2.200000f, g_sensor_name_52 },

    { 53, 32, 8, 0.010000f, 2.200000f, g_sensor_name_53 },

    { 54, 40, 8, 0.010000f, 2.200000f, g_sensor_name_54 },

    { 55, 48, 8, 0.010000f, 2.200000f, g_sensor_name_55 },

    { 56, 0, 8, 0.010000f, 2.200000f, g_sensor_name_56 },

    { 57, 8, 8, 0.010000f, 2.200000f, g_sensor_name_57 },

    { 58, 16, 8, 0.010000f, 2.200000f, g_sensor_name_58 },

    { 59, 24, 8, 0.010000f, 2.200000f, g_sensor_name_59 },

    { 60, 32, 8, 0.010000f, 2.200000f, g_sensor_name_60 },

    { 61, 40, 8, 0.010000f, 2.200000f, g_sensor_name_61 },

    { 62, 48, 8, 0.010000f, 2.200000f, g_sensor_name_62 },

    { 63, 0, 8, 0.010000f, 2.200000f, g_sensor_name_63 },

    { 64, 8, 8, 0.010000f, 2.200000f, g_sensor_name_64 },

    { 65, 16, 8, 0.010000f, 2.200000f, g_sensor_name_65 },

    { 66, 24, 8, 0.010000f, 2.200000f, g_sensor_name_66 },

    { 67, 32, 8, 0.010000f, 2.200000f, g_sensor_name_67 },

    { 68, 40, 8, 0.010000f, 2.200000f, g_sensor_name_68 },

    { 69, 48, 8, 0.010000f, 2.200000f, g_sensor_name_69 },

    { 70, 0, 8, 0.010000f, 2.200000f, g_sensor_name_70 },

    { 71, 8, 8, 0.010000f, 2.200000f, g_sensor_name_71 },

    { 72, 16, 8, 0.010000f, 2.200000f, g_sensor_name_72 },

    { 73, 24, 8, 0.010000f, 2.200000f, g_sensor_name_73 },

    { 74, 32, 8, 0.010000f, 2.200000f, g_sensor_name_74 },

    { 75, 40, 8, 0.010000f, 2.200000f, g_sensor_name_75 },

    { 76, 48, 8, 0.010000f, 2.200000f, g_sensor_name_76 },

    { 77, 0, 8, 0.010000f, 2.200000f, g_sensor_name_77 },

    { 78, 8, 8, 0.010000f, 2.200000f, g_sensor_name_78 },

    { 79, 16, 8, 0.010000f, 2.200000f, g_sensor_name_79 },

    { 80, 24, 8, 0.010000f, 2.200000f, g_sensor_name_80 },

    { 81, 32, 8, 0.010000f, 2.200000f, g_sensor_name_81 },

    { 82, 40, 8, 0.010000f, 2.200000f, g_sensor_name_82 },

    { 83, 48, 8, 0.010000f, 2.200000f, g_sensor_name_83 },

    { 84, 0, 8, 0.010000f, 2.200000f, g_sensor_name_84 },

    { 85, 8, 8, 0.010000f, 2.200000f, g_sensor_name_85 },

    { 86, 16, 8, 0.010000f, 2.200000f, g_sensor_name_86 },

    { 87, 24, 8, 0.010000f, 2.200000f, g_sensor_name_87 },

    { 88, 32, 8, 0.010000f, 2.200000f, g_sensor_name_88 },

    { 89, 40, 8, 0.010000f, 2.200000f, g_sensor_name_89 },

    { 90, 48, 8, 0.010000f, 2.200000f, g_sensor_name_90 },

    { 91, 0, 8, 0.010000f, 2.200000f, g_sensor_name_91 },

    { 92, 8, 8, 0.010000f, 2.200000f, g_sensor_name_92 },

    { 93, 16, 8, 0.010000f, 2.200000f, g_sensor_name_93 },

    { 94, 24, 8, 0.010000f, 2.200000f, g_sensor_name_94 },

    { 95, 32, 8, 0.010000f, 2.200000f, g_sensor_name_95 },

    { 96, 40, 8, 0.010000f, 2.200000f, g_sensor_name_96 },

    { 97, 48, 8, 0.010000f, 2.200000f, g_sensor_name_97 },

    { 98, 0, 8, 0.010000f, 2.200000f, g_sensor_name_98 },

    { 99, 8, 8, 0.010000f, 2.200000f, g_sensor_name_99 },

    { 100, 16, 8, 0.010000f, 2.200000f, g_sensor_name_100 },

    { 101, 24, 8, 0.010000f, 2.200000f, g_sensor_name_101 },

    { 102, 32, 8, 0.010000f, 2.200000f, g_sensor_name_102 },

    { 103, 40, 8, 0.010000f, 2.200000f, g_sensor_name_103 },

    { 104, 48, 8, 0.010000f, 2.200000f, g_sensor_name_104 },

    { 105, 0, 8, 0.010000f, 2.200000f, g_sensor_name_105 },

    { 106, 8, 8, 0.010000f, 2.200000f, g_sensor_name_106 },

    { 107, 16, 8, 0.010000f, 2.200000f, g_sensor_name_107 },

    { 108, 24, 8, 0.010000f, 2.200000f, g_sensor_name_108 },

    { 109, 32, 8, 0.010000f, 2.200000f, g_sensor_name_109 },

    { 110, 40, 8, 0.010000f, 2.200000f, g_sensor_name_110 },

    { 111, 48, 8, 0.010000f, 2.200000f, g_sensor_name_111 },

};

// Lookup function implementations

int section_find_by_name(const char* name) {
    for (int i = 0; i < SECTION_COUNT; i++) {
        if (strcmp(g_sections[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int module_find_by_name(int section_idx, const char* name) {
    if (section_idx < 0 || section_idx >= SECTION_COUNT) return -1;
    
    int start = g_sections[section_idx].module_start;
    int count = g_sections[section_idx].module_count;
    
    for (int i = start; i < start + count; i++) {
        if (strcmp(g_modules[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int sensor_find_by_name(int module_idx, const char* name) {
    if (module_idx < 0 || module_idx >= MODULE_COUNT) return -1;
    
    int start = g_modules[module_idx].sensor_start;
    int count = g_modules[module_idx].sensor_count;
    
    for (int i = start; i < start + count; i++) {
        if (strcmp(g_sensors[i].name, name) == 0) {
            return g_sensors[i].global_idx;
        }
    }
    return -1;
}

bool sensor_set_value_by_topic(const char* topic, float value) {
    char buf[64];
    strncpy(buf, topic, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    
    char* section = strtok(buf, "/");
    char* module = strtok(NULL, "/");
    char* sensor = strtok(NULL, "/");
    
    if (!section || !module || !sensor) return false;
    
    int sec_idx = section_find_by_name(section);
    if (sec_idx < 0) return false;
    
    int mod_idx = module_find_by_name(sec_idx, module);
    if (mod_idx < 0) return false;
    
    int sensor_idx = sensor_find_by_name(mod_idx, sensor);
    if (sensor_idx < 0) return false;
    
    g_sensor_values[sensor_idx] = value;
    return true;
}
