#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "memoryContext.h"
#include "macros.h"
#include "types.h"
#include "misc.h"
#include "dictionary.h"
#include "sqlcommands.h"
#include "database.h"

#include "interface/y.tab.h"


db_connected connected;

int main(){
    dbInit(NULL);
    
    printf("uffsdb (16.2).\nType \"help\" for help or \"implement\" for seeing what is or not is implemented in this project.\n\n");
    
    DEBUG_PRINT("UFFS DB Debugging mode.");
    
    interface();
    
    return 0;
}
