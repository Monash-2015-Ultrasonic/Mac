#include "setup.h"
#include "task.h"


int main(int argc, char* argv[])
{
	//==================================================//
    // Check to make sure enough arguments are input:   //
    //==================================================//    
    if (argumentCheck(argc, argv) != 0) {
        return -1;
    }

	//==================================================//
    // Open USB HID:		                            //
    //==================================================//
    if (hidOpen() != 0) {
        return -1;
    }

	//==================================================//
    // Create Log File:                                 //
    //==================================================//
    if (logSetup(argv) != 0) {
        return -1;
    }

	//==================================================//
    // System ready...                                  //
    //==================================================//
    printf("\nREADY! Now logging...\n\n");

    //==================================================//
    // Run until error or user-terminated:              //
    //==================================================//
    int run = 1;
	while (run) {
		readTask();
		run = KB.kbhit() ? 0 : 1;
	}

	//==================================================//
    // Closing house-keeping tasks:                     //
    //==================================================//
	hid_close(hHID);
	fclose(fOutput);
	hid_exit();

	return EXIT_SUCCESS;
}
