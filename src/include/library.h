/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <quackmore-ff@yahoo.com> wrote this file.  As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think this stuff is worth it, you can buy me a beer in return. Quackmore
 * ----------------------------------------------------------------------------
 */
#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#ifdef ESPBOT

#include "c_types.h"
// these are espbot_2.0 memory management methods
// https://github.com/quackmore/espbot_2.0
void *call_espbot_zalloc(size_t size);
void call_espbot_free(void *addr);

#define PRINT_FATAL(...) esplog.fatal(__VA_ARGS__)
#define PRINT_ERROR(...) esplog.error(__VA_ARGS__)
#define PRINT_WARN(...) esplog.warn(__VA_ARGS__)
#define PRINT_INFO(...) esplog.info(__VA_ARGS__)
#define PRINT_DEBUG(...) esplog.debug(__VA_ARGS__)
#define PRINT_TRACE(...) esplog.trace(__VA_ARGS__)
#define PRINT_ALL(...) esplog.all(__VA_ARGS__)
#define getTimestamp() esp_sntp.get_timestamp();

char *f2str(char *str, float value, int decimals);

#else

#define call_espbot_zalloc(a) os_zalloc(a)
#define call_espbot_free(a) os_free(a)
#define getTimestamp() system_get_time();

#define PRINT_FATAL(...) os_printf(__VA_ARGS__)
#define PRINT_ERROR(...) os_printf(__VA_ARGS__)
#define PRINT_WARN(...) os_printf(__VA_ARGS__)
#define PRINT_INFO(...) os_printf(__VA_ARGS__)
#define PRINT_DEBUG(...) os_printf(__VA_ARGS__)
#define PRINT_TRACE(...) os_printf(__VA_ARGS__)
#define PRINT_ALL(...) os_printf(__VA_ARGS__)

char *f2str(char *str, float value, int decimals);

#endif

#endif