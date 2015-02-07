#include "file_browser/browse.h"

#include "../../core/emu.h"
#include "../../core/serial_io.h"

#include <pspkernel.h>
#include <pspdebug.h>
#include "common/callback.h"
#include <pspctrl.h>
#include <pspdisplay.h>

#define VERS    1 //Talk about this
#define REVS    0

//PSP_MODULE_INFO("Gameboy", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER); 
PSP_HEAP_SIZE_MAX();

int main(int argc, char* argv[]) {
    
    char file_name[0xFF];
    int debug = 0;
   
    ClientOrServer cs = NO_CONNECT;
    
    if (!get_gb_file(file_name)) {
        return 1;
    }

    if (!init(file_name, debug, cs)) {
        return 1;
    }

    run();
    return 0;
}
