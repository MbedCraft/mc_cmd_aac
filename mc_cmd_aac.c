/* ------------------------------------------------------------------------- *\
 * Espressif specific includes
 * ------------------------------------------------------------------------- */
#include "argtable3/argtable3.h"
#include "esp_console.h"

/* ------------------------------------------------------------------------- *\
 * MbedCraft includes
 * ------------------------------------------------------------------------- */
#include "mc_aac.h"
#include "mc_assert.h"
#include "mc_cmd_aac.h"

/* ------------------------------------------------------------------------- *\
 * Type definitions
 * ------------------------------------------------------------------------- */
static struct {
    struct arg_str *path;
    struct arg_end *end;
} aac_play_args;

/* ------------------------------------------------------------------------- *\
 * Private function definitions
 * ------------------------------------------------------------------------- */
static int __aac_play_cmd(int argc, char **argv);

/* ------------------------------------------------------------------------- *\
 * Public function implementations
 * ------------------------------------------------------------------------- */
void mc_cmd_aac_register(void) {
    aac_play_args.path = arg_str1(NULL, NULL, "<FILE>",
            "Decode and play the FILE");
    aac_play_args.end = arg_end(1);

    const esp_console_cmd_t ls_cmd = {
        .command = "aac_play",
        .help = "Play a sound file encoded with the AAC codec.\n",
        .hint = NULL,
        .func = &__aac_play_cmd,
        .argtable = &aac_play_args
    };

    ESP_ERROR_CHECK(esp_console_cmd_register(&ls_cmd));
}

/* ------------------------------------------------------------------------- *\
 * Private function implementations
 * ------------------------------------------------------------------------- */
static int __aac_play_cmd(int argc, char **argv) {
    ASSERTW_RET(2 == argc, -1, "Internal error");
    return mc_aac_play_file(argv[1]);
}
