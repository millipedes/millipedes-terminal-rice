# Terminal Startup Rice
### My Vision of The Tool
This tool is meant to greet the user of a terminal emulator with a pleasant picture and message that they can personalize.

In order to accomplish this, the user needs only put the quotes (each separated by a newline character) and ascii art they wish to see printed into a text file then change the file path in constants.h:
```
12 #define PATH_TO_QUOTES "config/quotes/quotes_test.txt"
13 #define PATH_TO_ART "config/ascii_art/picture_test.txt"
```
This code will now take in your quotes and art and generate the art (atm with a pre-determined set of colors), and a random quote from the quotes file, centered to 80 characters on your terminal.

Now note, this will make the binary associated with the test quote/art, so if you would like to customize those, do so then run `sudo make install` (also if you run it multiple times it's alright, it will just recompile pointing at the new PATH's).

### Installation
The prerequisites for this installation should only be gcc, make, and sudo (or your C compiler of choice, you would just have to edit the `CC` variable in the Makefile).  Once you have cloned the poject, you should just need to run: `sudo make install` and add the following line to your .bashrc: `terminal_startup_rice`.

### On the Radar to be Updated
- Changing Ascii Art based off time (i.e. holiday themes in December).
- Changing the color system to provide a better user experience.
