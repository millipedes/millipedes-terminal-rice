# Terminal Startup Rice
### My Vision of The Tool
This tool is meant to greet the user of a terminal emulator with a pleasant picture and message that they can personalize.

In order to accomplish this, the user needs only put the quotes they wish to see printed into a text file then change the file path in constants.h:
```
12 #define PATH_TO_QUOTES "config/quotes/quotes_test.txt"
13 #define PATH_TO_ART "config/ascii_art/picture_test.txt"
```

This tool is meant to be called on the initiation of a new terminal emulator via the .bashrc file.  For this reason fish etc. alternatives to BASH are not yet supported.

### On the Radar to be Updated
- Changing Ascii Art based off time (i.e. holiday themes in December).
- Changing the color system to provide a better user experience.
