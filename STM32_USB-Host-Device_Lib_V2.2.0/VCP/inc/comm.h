// Service type
#define 	SERVICE_TYPE_FILE			0x01
#define 	SERVICE_TYPE_CMD			0x02



//Msg type

// SERVICE_TYPE_FILE
#define		MSG_TYPE_FILE_READ_REQ			0x01
#define		MSG_TYPE_FILE_READ_RESP			0x01

#define		MSG_TYPE_FILE_WRITE_REQ			0x02
#define		MSG_TYPE_FILE_WRITE_RESP		0x02

// SERVICE_TYPE_CMD
#define		MSG_TYPE_CMD_RESET_REQ			0x01
#define		MSG_TYPE_CMD_RESET_RESP			0x01

#define		MSG_TYPE_CMD_SWITCH_SCREEN_REQ	0x02
#define		MSG_TYPE_CMD_SWITCH_SCREEN_RESP	0x02

#define		MSG_TYPE_CMD_TEST_RESULT_REQ	0x03
#define		MSG_TYPE_CMD_TEST_RESULT_RESP	0x03

#define		MSG_TYPE_CMD_GET_MCU_ID_REQ		0x04
#define		MSG_TYPE_CMD_GET_MCU_ID_RESP	0x04

#define		MSG_TYPE_CMD_START_TEST_REQ		0x05
#define		MSG_TYPE_CMD_START_TEST_RESP	0x05

#define		MSG_TYPE_CMD_WARN_REQ			0x06
#define		MSG_TYPE_CMD_WARN_RESP			0x06

#define		MSG_TYPE_CMD_BOOT_IN_IAP_MODE_REQ			0x07
#define		MSG_TYPE_CMD_BOOT_IN_IAP_MODE_RESP			0x07


#define		MSG_TYPE_CMD_BOOT_IN_SLEEP_MODE_REQ			0x08
#define		MSG_TYPE_CMD_BOOT_IN_SLEEP_MODE_RESP		0x08


#define		MSG_TYPE_CMD_CRYPT_REQ			0x09
#define		MSG_TYPE_CMD_CRYPT_RESP			0x09

#define		MSG_TYPE_CMD_WORK_CURRENT_REQ			0x0A
#define		MSG_TYPE_CMD_WORK_CURRENT_RESP			0x0A

#define		MSG_TYPE_CMD_SLEEP_CURRENT_REQ			0x0B
#define		MSG_TYPE_CMD_SLEEP_CURRENT_RESP			0x0B

#define		MSG_TYPE_CMD_TEST_STATUS_REQ			0x0C
#define		MSG_TYPE_CMD_TEST_STATUS_RESP			0x0C

#define		MSG_TYPE_CMD_TEST_MCU_CODE_REQ			0x0D
#define		MSG_TYPE_CMD_TEST_MCU_CODE_RESP			0x0D

#define		MSG_TYPE_CMD_TEST_MCU_CODE_RESTART			0x0E
#define		MSG_TYPE_CMD_TEST_MCU_CODE_RESTART_RESP			0x0E

#define 	MSG_TYPE_CMD_BEEP_SWITCH_CAN_REQ 					0x0F
#define 	MSG_TYPE_CMD_BEEP_SWITCH_CAN_RESP					0x0F

#define		MSG_TYPE_CMD_CAN_SENSOR_TEST_REQ 		0x10
#define		MSG_TYPE_CMD_CAN_SENSOR_TEST_RESP		0x10

#define		MSG_TYPE_CMD_TEST_WIFI_CODE_CONNECT_REQ 		0x11
#define		MSG_TYPE_CMD_TEST_WIFI_CODE_CONNECT_RESP		0x11

#define		MSG_TYPE_CMD_TEST_WIFI_CODE_ERASE_SRAM_REQ 		0x12
#define		MSG_TYPE_CMD_TEST_WIFI_CODE_ERASE_SRAM_RESP   0x12

#define		MSG_TYPE_CMD_TEST_WIFI_CODE_WRITE_SRAM_PATCH_REQ   0x13
#define		MSG_TYPE_CMD_TEST_WIFI_CODE_WRITE_SRAM_PATCH_RESP   0x13

#define		MSG_TYPE_CMD_TEST_WIFI_CODE_ERASE_FLASH_REQ   0x14
#define		MSG_TYPE_CMD_TEST_WIFI_CODE_ERASE_FLASH_RESP   0x14

#define		MSG_TYPE_CMD_TEST_WIFI_CODE_WRITE_FLASH_PATCH_REQ   0x15
#define		MSG_TYPE_CMD_TEST_WIFI_CODE_WRITE_FLASH_PATCH_RESP   0x15

#define		MSG_TYPE_CMD_TEST_WIFI_CODE_WRITE_FS_REQ   0x16
#define		MSG_TYPE_CMD_TEST_WIFI_CODE_WRITE_FS_RESP   0x16

#define		MSG_TYPE_CMD_TEST_WIFI_CODE_WRITE_CHUNK_REQ  	0x17
#define		MSG_TYPE_CMD_TEST_WIFI_CODE_WRITE_CHUNK_RESP  0x17

#define		MSG_TYPE_CMD_TEST_LOOK_FOR_COMM_REQ					0x18
#define		MSG_TYPE_CMD_TEST_LOOK_FOR_COMM_RESP				0x18

#define		MSG_TYPE_CMD_TEST_WIFI_TEST_REQ				0x19
#define		MSG_TYPE_CMD_TEST_WIFI_TEST_REQ				0x19

#define		MSG_TYPE_CMD_TEST_WIFI_RESTART_REQ   			0x1a
#define		MSG_TYPE_CMD_TEST_WIFI_RESTART_RESP   0x1a

#define   MSG_TYPE_CMD_TEST_WIFI_POWERON_REQ     0x1b
#define   MSG_TYPE_CMD_TEST_WIFI_POWERON_RESP     0x1b


#define   MSG_TYPE_WRITE_DEVICE_FILE_REQ			0x20
#define   MSG_TYPE_WRITE_DEVICE_FILE_RESP		0x20

#define   MSG_TYPE_WRITE_DEVICE_FILE_MORE_REQ			0x21
#define   MSG_TYPE_WRITE_DEVICE_FILE_MORE_RESP		0x21

#define   MSG_TYPE_CMD_TEST_LOOK_FOR_WIFI_REQ   0x22
#define   MSG_TYPE_CMD_TEST_LOOK_FOR_WIFI_RESP   0x22

//Tlv type
#define 	TEST_STATUS_LOADCODE					0x01
#define 	TEST_STATUS_REMOVE_RP					0x02
#define 	TEST_STATUS_ERASE						0x03




typedef struct 				//16 bytes
{
	u32 start_bytes;
	u16 msg_len;
	u8  msg_count;
	u8  resp;
	u16 seq;
	u8  service_type;
	u8  msg_type;
	u32 crc32;
}comm_head_t;


typedef struct
{
	u16 Type;
	u16 Len;
	u8  *buf;
}tlv_type_t;

typedef struct
{
	u32 ReplyType;
	u32 CpuID0;
	u32 CpuID1;
	u32 CpuID2;
	u8  TestResult0;
	u8  TestResult1;
	u8  TestResult2;
	u8  TestResult3;
	u16 Volatage0;
	u16 Volatage1;
	u16 Volatage2;
	u16 Volatage3;
	u16 Volatage4;
	u16 Volatage5;	
	u16 Volatage6;
	u16 Volatage7;
	u16 Volatage8;
	u16 Current0;
	u16 Current1;
	u8  Mode;
}tlv_reply_t;

typedef struct
{
	u16 type;
	u16 len;
	u16 test_result;
	u32 fpga_ver;
	u8  cpuid[12];
}tlv_test_t;


#define 	COMM_HEADER_LENGTH		sizeof(comm_head_t)
#define 	TLV_REPLY_LENGTH		sizeof(tlv_reply_t)

