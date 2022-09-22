# lib1000log

A smalll shared library to write log entries to small log files.
Each log file can only contain 1000 lines (messages).

## Installation

1. Get the code
1. Clone it to a folder
2. Download the compressed code and extract it to a folder
2. Install the library
1. Open a teminal window in the folder where is the code (where is Makefile)
2. write: $ make install

**Note:** You need to have root permissions in the last instruction.

The shared should now be installed in your machine.

## Usage

**Important:** The folder where log files will be stored must exists before library usage. 
The library will not create a folder.

A little example:

	#include <stdio.h>
	#include <lib100log.h>

	int	main(void)
	{
		char	path_to_folder[] = "logs";
		char	msg_type[] = "error";

		Log_Entry(path_to_folder, msg_type, "First error!");

		return 0; 
	}

Don't forget to use the **-l1000log** library flag to compile the code!

