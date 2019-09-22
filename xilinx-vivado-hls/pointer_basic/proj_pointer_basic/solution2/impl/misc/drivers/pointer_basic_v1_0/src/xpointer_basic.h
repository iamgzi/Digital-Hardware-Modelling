// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XPOINTER_BASIC_H
#define XPOINTER_BASIC_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xpointer_basic_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Pointer_basic_io_BaseAddress;
} XPointer_basic_Config;
#endif

typedef struct {
    u32 Pointer_basic_io_BaseAddress;
    u32 IsReady;
} XPointer_basic;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XPointer_basic_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XPointer_basic_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XPointer_basic_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XPointer_basic_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XPointer_basic_Initialize(XPointer_basic *InstancePtr, u16 DeviceId);
XPointer_basic_Config* XPointer_basic_LookupConfig(u16 DeviceId);
int XPointer_basic_CfgInitialize(XPointer_basic *InstancePtr, XPointer_basic_Config *ConfigPtr);
#else
int XPointer_basic_Initialize(XPointer_basic *InstancePtr, const char* InstanceName);
int XPointer_basic_Release(XPointer_basic *InstancePtr);
#endif

void XPointer_basic_Start(XPointer_basic *InstancePtr);
u32 XPointer_basic_IsDone(XPointer_basic *InstancePtr);
u32 XPointer_basic_IsIdle(XPointer_basic *InstancePtr);
u32 XPointer_basic_IsReady(XPointer_basic *InstancePtr);
void XPointer_basic_EnableAutoRestart(XPointer_basic *InstancePtr);
void XPointer_basic_DisableAutoRestart(XPointer_basic *InstancePtr);

void XPointer_basic_Set_d_i(XPointer_basic *InstancePtr, u32 Data);
u32 XPointer_basic_Get_d_i(XPointer_basic *InstancePtr);
u32 XPointer_basic_Get_d_o(XPointer_basic *InstancePtr);
u32 XPointer_basic_Get_d_o_vld(XPointer_basic *InstancePtr);

void XPointer_basic_InterruptGlobalEnable(XPointer_basic *InstancePtr);
void XPointer_basic_InterruptGlobalDisable(XPointer_basic *InstancePtr);
void XPointer_basic_InterruptEnable(XPointer_basic *InstancePtr, u32 Mask);
void XPointer_basic_InterruptDisable(XPointer_basic *InstancePtr, u32 Mask);
void XPointer_basic_InterruptClear(XPointer_basic *InstancePtr, u32 Mask);
u32 XPointer_basic_InterruptGetEnabled(XPointer_basic *InstancePtr);
u32 XPointer_basic_InterruptGetStatus(XPointer_basic *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
