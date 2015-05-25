#include "task.h"
#include "setup.h"

keyboard KB;




void readTask(void) 
{
#ifdef NONBLOCK
	dataIn = 0;
	while (dataIn == 0) {
		dataIn = hid_read(hHID, buffer, sizeof(buffer));
		if (KB.kbhit())
			return;
	}
#else
	dataIn = hid_read(hHID, buffer, sizeof(buffer));
#endif
	for (int i = 0; i < dataIn/2; i++) {
		printf("%04x\n", buffer[2*i]<<8|buffer[2*i+1]);
		fprintf(fOutput, "%04x\n", buffer[2*i]<<8|buffer[2*i+1]);
	}
	printf("\n");
	fprintf(fOutput, "\n");
}
