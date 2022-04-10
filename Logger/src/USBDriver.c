#include "Core.h"
#include "USBDriver.h"
#include <stdbool.h>
#include "serial_api.h"
#include "Buffer.h"

#define USB_BUFFER_MAX (75)

static serial_t USBDriver_serial;
static uint8_t tx_data[USB_BUFFER_MAX];
static uint8_t rx_data[USB_BUFFER_MAX];
static BUFFER_T tx;
static BUFFER_T rx;

void USBDriver_Init(void) {}
void USBDriver_Exec(void) {}

bool USBDriver_Connected(void) { return FALSE; }
bool USBDriver_OkayToRead() { return FALSE; }
char USBDriver_GetChar(void) { return '!'; }
bool USBDriver_PutChar(char Val) { return FALSE; }

