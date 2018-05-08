
#include "mqtt_client.h"

#define HOMIE_MAX_TOPIC_LEN (64)

#define HOMIE_MAX_MQTT_URI_LEN (64)
#define HOMIE_MAX_MQTT_USERNAME_LEN (32)
#define HOMIE_MAX_MQTT_PASSWORD_LEN (32)

#define HOMIE_MAX_DEVICE_ID_LEN (32)
#define HOMIE_MAX_DEVICE_NAME_LEN (32)
#define HOMIE_MAX_BASE_TOPIC_LEN (16)
#define HOMIE_MAX_FIRMWARE_NAME_LEN (32)
#define HOMIE_MAX_FIRMWARE_VERSION_LEN (8)



typedef struct {
    char mqtt_uri[HOMIE_MAX_MQTT_URI_LEN];
    char mqtt_username[HOMIE_MAX_MQTT_USERNAME_LEN];
    char mqtt_password[HOMIE_MAX_MQTT_PASSWORD_LEN];
    char device_id[HOMIE_MAX_DEVICE_ID_LEN];
    char device_name[HOMIE_MAX_DEVICE_NAME_LEN];
    char base_topic[HOMIE_MAX_BASE_TOPIC_LEN];
    char firmware_name[HOMIE_MAX_FIRMWARE_NAME_LEN];
    char firmware_version[HOMIE_MAX_FIRMWARE_VERSION_LEN];
    bool ota_enabled;
    void (*msg_handler)(char *, char *);
    void (*connected_handler)();
} homie_config_t;

void homie_init(homie_config_t *config);
void homie_subscribe(const char * subtopic);
void homie_publish(const char * subtopic, int qos, int retain, const char * payload);
void homie_publishf(const char * subtopic, int qos, int retain, const char * format, ...);
void homie_publish_int(const char * subtopic, int qos, int retain, const int payload);
void homie_publish_bool(const char * subtopic, int qos, int retain, const bool payload);
void homie_mktopic(char * topic, const char * subtopic);
