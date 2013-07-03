#ifndef CMD_H__
#define CMD_H__

#include <stdbool.h>
#include "common.h"

/* Fatal errors */
#define CMD_RETFATAL        (-1024)
#define CMD_RET_MEM         (CMD_RETFATAL)      /**< Memory allocation failure */
#define CMD_RET_UNKNOWN     (CMD_RETFATAL - 1)  /**< Unexpected failure */

/* Non-fatal errors */
#define CMD_RET_QUIT        (-1)    /**< Got request to quit */
#define CMD_RET_NOCMD       (-2)    /**< Non-existant command */
#define CMD_RET_MAX_ARGC    (-3)    /**< Maximum number of arguments reached */
#define CMD_RET_INVPARAM    (-4)    /**< Invalid parameters passed */
#define CMD_RET_LIBBLADERF  (-5)    /**< See cli_state for libladerf error */
#define CMD_RET_NODEV       (-6)    /**< No device is currently opened */
#define CMD_RET_NARGS       (-7)    /**< Invalid number of arguments provided */

/** Command OK */
#define CMD_RET_OK          0

/** Other state changes */
#define CMD_RET_CLEAR_TERM  1       /**< Clear the terminal */
#define CMD_RET_RUN_SCRIPT  2       /**< Run a script */

/**
 * Parse and execute the supplied command
 *
 * @return 0 on success, CMD_RET_ on failure/exceptional condition
 */
int cmd_handle(struct cli_state *s, const char *line);

/**
 * @return true if provided return code is fatal, false otherwise
 */
static inline bool cmd_fatal(int status) { return status <= CMD_RETFATAL; }

/**
 * @param   error       CMD_RET_* error
 * @param   lib_error   BLADERF_ERR_* - only used if error is CMD_RET_LIBBLADERF
 *
 * @return A string represntation of the provided errors
 */
const char * cmd_strerror(int error, int lib_error);

#endif
