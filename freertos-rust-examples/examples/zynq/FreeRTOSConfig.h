/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>!AND MODIFIED BY!<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H
#include "hr_gettime.h"
/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

/*
 * The FreeRTOS Cortex-A port implements a full interrupt nesting model.
 *
 * Interrupts that are assigned a priority at or below
 * configMAX_API_CALL_INTERRUPT_PRIORITY (which counter-intuitively in the ARM
 * generic interrupt controller [GIC] means a priority that has a numerical
 * value above configMAX_API_CALL_INTERRUPT_PRIORITY) can call FreeRTOS safe API
 * functions and will nest.
 *
 * Interrupts that are assigned a priority above
 * configMAX_API_CALL_INTERRUPT_PRIORITY (which in the GIC means a numerical
 * value below configMAX_API_CALL_INTERRUPT_PRIORITY) cannot call any FreeRTOS
 * API functions, will nest, and will not be masked by FreeRTOS critical
 * sections (although it is necessary for interrupts to be globally disabled
 * extremely briefly as the interrupt mask is updated in the GIC).
 *
 * FreeRTOS functions that can be called from an interrupt are those that end in
 * "FromISR".  FreeRTOS maintains a separate interrupt safe API to enable
 * interrupt entry to be shorter, faster, simpler and smaller.
 *
 * The Zynq implements 256 unique interrupt priorities.  For the purpose of
 * setting configMAX_API_CALL_INTERRUPT_PRIORITY 255 represents the lowest
 * priority.
 */
#define configMAX_API_CALL_INTERRUPT_PRIORITY	18

// FreeRTOS Exception handler mapping to rust cortex-m-rt crate linker file naming
#define SVC_Handler SVCall
#define SysTick_Handler SysTick
#define PendSV_Handler PendSV

//extern uint32_t SystemCoreClock;

#define configRUN_FREERTOS_SECURE_ONLY  				1
#define configENABLE_TRUSTZONE  						0

#define configNUM_THREAD_LOCAL_STORAGE_POINTERS         1

/* Cortex M33 port configuration. */
#define configENABLE_MPU								0
#define configENABLE_FPU								1

#define configSUPPORT_DYNAMIC_ALLOCATION                1


#define configCPU_CLOCK_HZ						100000000UL
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	1
#define configUSE_TICKLESS_IDLE					0
#define configTICK_RATE_HZ						( ( TickType_t ) 1000 )
#define configPERIPHERAL_CLOCK_HZ  				( 33333000UL )
#define configUSE_PREEMPTION					1
#define configUSE_TIME_SLICING					1
#define configUSE_IDLE_HOOK						0
#define configUSE_TICK_HOOK						0
#define configMAX_PRIORITIES					( 7 )
#define configMINIMAL_STACK_SIZE				( ( unsigned short ) 200 )
#define configTOTAL_HEAP_SIZE					( 4 * 1024 * 1024 )
#define configMAX_TASK_NAME_LEN					( 16 )
#define configUSE_TRACE_FACILITY				1
#define configUSE_16_BIT_TICKS					0
#define configIDLE_SHOULD_YIELD							1
#define configUSE_16_BIT_TICKS							0 /* Only for 8 and 16-bit hardware. */

/* Constants that describe the hardware and memory usage. */
#ifdef OLD
#define configCPU_CLOCK_HZ								(64000000UL) // 64M // from HAL: SystemCoreClock
#define configMINIMAL_STACK_SIZE						( ( uint16_t ) 128 )
#define configMINIMAL_SECURE_STACK_SIZE					( 1024 )
#define configMAX_TASK_NAME_LEN							( 12 )
#define configTOTAL_HEAP_SIZE							( ( size_t ) ( 50 * 1024 ) )
#endif

/* Constants that build features in or out. */
#define configUSE_MUTEXES								1
#define configUSE_TICKLESS_IDLE							0
#define configUSE_APPLICATION_TASK_TAG					0
#define configUSE_NEWLIB_REENTRANT						0
#define configUSE_CO_ROUTINES							0
#define configUSE_COUNTING_SEMAPHORES					1
#define configUSE_RECURSIVE_MUTEXES						1
#define configUSE_QUEUE_SETS							0
#define configUSE_TASK_NOTIFICATIONS					1
#define configUSE_TRACE_FACILITY						1

/* Constants that define which hook (callback) functions should be used. */
#define configUSE_IDLE_HOOK								0
#define configUSE_TICK_HOOK								0
#define configUSE_MALLOC_FAILED_HOOK					0

/* Constants provided for debugging and optimisation assistance. */
#define configCHECK_FOR_STACK_OVERFLOW					2

extern void vAssertCalled(const char *file, int linenum);

#define configASSERT(x)     if( ( x ) == 0 ) vAssertCalled( __FILE__, __LINE__ )
#define configQUEUE_REGISTRY_SIZE						0
/* Software timer definitions. */
#define configUSE_TIMERS						1
#define configTIMER_TASK_PRIORITY				( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH				5
#define configTIMER_TASK_STACK_DEPTH			( configMINIMAL_STACK_SIZE * 2 )

/* Have FreeRTOS provide an errno variable in task handle.
 * We need errno for bsd_lib */
#define configUSE_POSIX_ERRNO							1

/* Have FreeRTOS provide an errno variable in task handle.
 * We need errno for bsd_lib */
#define configUSE_POSIX_ERRNO							1

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet				1
#define INCLUDE_uxTaskPriorityGet				1
#define INCLUDE_vTaskDelete						1
#define INCLUDE_vTaskCleanUpResources			1
#define INCLUDE_vTaskSuspend					1
#define INCLUDE_vTaskDelayUntil					1
#define INCLUDE_vTaskDelay						1
#define INCLUDE_uxTaskGetStackHighWaterMark		0
#define INCLUDE_xTaskGetIdleTaskHandle			0
#define INCLUDE_eTaskGetState							1
#define INCLUDE_xTaskResumeFromISR						0
#define INCLUDE_xTaskGetCurrentTaskHandle				1
#define INCLUDE_xTaskGetSchedulerState					1
#define INCLUDE_xSemaphoreGetMutexHolder				0
#define INCLUDE_xTimerPendFunctionCall					1

#define INCLUDE_pcTaskGetTaskName				1

/* This demo makes use of one or more example stats formatting functions.  These
format the raw data provided by the uxTaskGetSystemState() function in to human
readable ASCII form.  See the notes in the implementation of vTaskList() within
FreeRTOS/Source/tasks.c for limitations. */
#define configUSE_STATS_FORMATTING_FUNCTIONS	1
#define configGENERATE_RUN_TIME_STATS 			1
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()
#define portGET_RUN_TIME_COUNTER_VALUE()			(ullGetHighResolutionTime()/1000L) // msec

/* The size of the global output buffer that is available for use when there
are multiple command interpreters running at once (for example, one on a UART
and one on TCP/IP).  This is done to prevent an output buffer being defined by
each implementation - which would waste RAM.  In this case, there is only one
command interpreter running. */
#define configCOMMAND_INT_MAX_OUTPUT_SIZE 2096

/* Interrupt priority configuration follows...................... */

/* If configTASK_RETURN_ADDRESS is not defined then a task that attempts to
return from its implementing function will end up in a "task exit error"
function - which contains a call to configASSERT().  However this can give GCC
some problems when it tries to unwind the stack, as the exit error function has
nothing to return to.  To avoid this define configTASK_RETURN_ADDRESS to 0.  */
#define configTASK_RETURN_ADDRESS	NULL

/* Use the system definition, if there is one. */
#ifdef __NVIC_PRIO_BITS
#define configPRIO_BITS								__NVIC_PRIO_BITS
#else
#define configPRIO_BITS								3	 /* 8 priority levels. */
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
 * function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			0x07

/* The highest interrupt priority that can be used by any interrupt service
 * routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT
 * CALL INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A
 * HIGHER PRIORITY THAN THIS! (higher priorities are lower numeric values). */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	2

/* Interrupt priorities used by the kernel port layer itself.  These are generic
 * to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY					( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
 * See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY			( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/* The #ifdef guards against the file being included from IAR assembly files. */
#ifndef __IASMARM__

#define configTICK_RATE_HZ							( ( TickType_t ) 1000 )

/****** Hardware specific settings. *******************************************/

/*
 * The application must provide a function that configures a peripheral to
 * create the FreeRTOS tick interrupt, then define configSETUP_TICK_INTERRUPT()
 * in FreeRTOSConfig.h to call the function.  This file contains a function
 * that is suitable for use on the Zynq MPU.  FreeRTOS_Tick_Handler() must
 * be installed as the peripheral's interrupt handler.
 */
void vConfigureTickInterrupt( void );
#define configSETUP_TICK_INTERRUPT() vConfigureTickInterrupt()

void vClearTickInterrupt( void );
#define configCLEAR_TICK_INTERRUPT() vClearTickInterrupt()

#endif

/* The following constant describe the hardware, and are correct for the
Zynq MPU. */
#define configINTERRUPT_CONTROLLER_BASE_ADDRESS 	( 0xF8F01000U )
#define configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET ( -0xf00 )
#define configUNIQUE_INTERRUPT_PRIORITIES		32


/****** TCP demo settings. ****************************************************/

/* Default MAC address configuration.  */
#define configMAC_ADDR0		0x00
#define configMAC_ADDR1		0x11
#define configMAC_ADDR2		0x22
#define configMAC_ADDR3		0x33
#define configMAC_ADDR4		0x44
#define configMAC_ADDR5		0x49

/* Default IP address configuration.  Used in ipconfigUSE_DHCP is set to 0, or
ipconfigUSE_DHCP is set to 1 but a DHCP server cannot be contacted. */
#define configIP_ADDR0		192
#define configIP_ADDR1		168
#define configIP_ADDR2		1
#define configIP_ADDR3		10

/* Default gateway IP address configuration.  Used in ipconfigUSE_DHCP is set to
0, or ipconfigUSE_DHCP is set to 1 but a DHCP server cannot be contacted. */
#define configGATEWAY_ADDR0	192
#define configGATEWAY_ADDR1	168
#define configGATEWAY_ADDR2	1
#define configGATEWAY_ADDR3	1

/* Default DNS server configuration.  OpenDNS addresses are 208.67.222.222 and
208.67.220.220.  Used in ipconfigUSE_DHCP is set to 0, or ipconfigUSE_DHCP is set
to 1 but a DHCP server cannot be contacted.*/
#define configDNS_SERVER_ADDR0 	208
#define configDNS_SERVER_ADDR1 	67
#define configDNS_SERVER_ADDR2 	222
#define configDNS_SERVER_ADDR3 	222

/* Default netmask configuration.  Used in ipconfigUSE_DHCP is set to 0, or
ipconfigUSE_DHCP is set to 1 but a DHCP server cannot be contacted. */
#define configNET_MASK0		255
#define configNET_MASK1		255
#define configNET_MASK2		255
#define configNET_MASK3		0

/****** Demo settings. *************************************************/

/* The directory used as the root of the webserver. */
#define configHTTP_ROOT 					"/ram/websrc"

/* Optional CLI commands to include. */
#define configINCLUDE_QUERY_HEAP_COMMAND 	0
#define configINCLUDE_DEMO_DEBUG_STATS 		0
#define configINCLUDE_DEMO_NET_STATS		0
#define configINCLUDE_ECHO_COMMANDS			0

/****** UDP logging settings. *************************************************
See http://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_TCP/UDP_Logging.html */

/* If set to 1 then each message sent via the UDP logging facility will end
with \r\n.  If set to 0 then each message sent via the UDP logging facility will
end with \n. */
#define configUDP_LOGGING_NEEDS_CR_LF  ( 1 )

/* Sets the maximum length for a string sent via the UDP logging facility. */
#define configUDP_LOGGING_STRING_LENGTH	( 200 )

/* The UDP logging facility buffers messages until the UDP logging task is able
to transmit them.  configUDP_LOGGING_MAX_MESSAGES_IN_BUFFER sets the maximum
number of messages that can be buffered at any one time. */
#define	configUDP_LOGGING_MAX_MESSAGES_IN_BUFFER	( 20 )

/* The UDP logging facility creates a task to send buffered messages to the UDP
port.  configUDP_LOGGING_TASK_STACK_SIZE sets the task's stack size. */
#define	configUDP_LOGGING_TASK_STACK_SIZE  	( 512 )

/* The UDP logging facility creates a task to send buffered messages to the UDP
port.  configUDP_LOGGING_TASK_PRIORITY sets the task's priority.  It is
suggested to give the task a low priority to ensure it does not adversely effect
the performance of other TCP/IP stack activity. */
#define configUDP_LOGGING_TASK_PRIORITY   	( tskIDLE_PRIORITY )

/* The UDP port to which the UDP logging facility sends messages. */
#define configUDP_LOGGING_PORT_LOCAL	1499
#define configUDP_LOGGING_PORT_REMOTE	1500

/* The IP address to which the UDP logging facility sends messages.  If not
defined then the local broadcast address will be used - although some switches
and routers will not pass broadcast messages. */
//#define configUDP_LOGGING_ADDR0	192
//#define configUDP_LOGGING_ADDR1	168
//#define configUDP_LOGGING_ADDR2	1
//#define configUDP_LOGGING_ADDR3	1

/****** LEO message settings. *************************************************/
/* The LEO message facility receives commands.  configLEO_CMD_MAX_MESSAGES_IN_QUEUE
 * sets the maximum number of commands that can be buffered at any one time. */
#define	configLEO_CMD_MAX_MESSAGES_IN_QUEUE	( 5 )

/* The LEO message facility queues messages until the LEOmessage sending task is able
to transmit them.  configLEO_MESSAGE_MAX_MESSAGES_IN_QUEUE sets the maximum
number of messages that can be buffered at any one time. */
#define	configLEO_MESSAGE_MAX_MESSAGES_IN_QUEUE	( 255 )

/* The LEO message facility creates a task to send buffered messages to the UDP
port.  configLEO_MESSAGE_TASK_STACK_SIZE sets the task's stack size. */
#define	configLEO_MESSAGE_TASK_STACK_SIZE  	( 512 )

/* The LEO message facility creates a task to send buffered messages to the UDP
port.  configLEO_MESSAGE_TASK_PRIORITY sets the task's priority.  It is
suggested to give the task a low priority to ensure it does not adversely effect
the performance of other TCP/IP stack activity. */
#define configLEO_MESSAGE_TASK_PRIORITY   	( tskIDLE_PRIORITY )

/* The UDP port to which the LEO message facility sends messages.
 * if configLEO_MESSAGE_PORT_LOCAL is not set, or 0 it will be random
 */
#define configLEO_MESSAGE_PORT_LOCAL	0
#define configLEO_MESSAGE_PORT_REMOTE	21021

/* The IP address to which the LEO message facility sends messages.  If not
defined then the local broadcast address will be used - although some switches
and routers will not pass broadcast messages. */
//#define configLEO_MESSAGE_ADDR0	192
//#define configLEO_MESSAGE_ADDR1	168
//#define configLEO_MESSAGE_ADDR2	1
//#define configLEO_MESSAGE_ADDR3	1

/* The address of an echo server that will be used by the two echo client tasks.
http://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_TCP/TCP_Echo_Clients.html
http://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_TCP/UDP_Echo_Clients.html */
#define configECHO_SERVER_ADDR0	192
#define configECHO_SERVER_ADDR1 168
#define configECHO_SERVER_ADDR2 1
#define configECHO_SERVER_ADDR3 1

#endif /* FREERTOS_CONFIG_H */
