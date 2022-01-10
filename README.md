# DLL_Shared_Objects<br />
**Created Date:** 5/23/2006<br />
**Last Updated:** 5/21/2008<br />
**Description:** An example of using Synergy DLL API to call C routines in a Windows DLL and a UNIX shared object.<br />
**Platforms:** Windows; Unix; OpenVMS<br />
**Products:** Synergy DBL; DLL API<br />
**Minimum Version:** 8.1<br />
**Author:** Steve Ives
<hr>

**Additional Information:**
Discussion: This example contains the following files:

- power.c A C source file containing a routine called
"power" which raises one number to the power
of another and returns the resulting value.
The routine also makes a call to a Synergy
routine called SUB1 to demonstrate th ability
to have C routines call back into Synergy code.

- power.dbl A Synergy source file containing a test program
called "power". This program calls the C
routine described above. The SUB1 routine is
also defined in this file.

- mylib.bat A Windows batch file to compile and run the
demo.

- mylib.def This file is used in the process of building
the DLL on WIndows. It essentially defines
the externally visible C routines that are
"exported" by the DLL.

- mylib A UNIX shell script to compile and run the
demo. The demo was developed on Red Hat Linux
and has only been tested on that platform.

In order to use the demo you will need:

- Synergy/DE 8.1.1 or higher

- C compiler for your platform. On WIndows you would need
the Microsoft C/C++ compiler from the platform SDK or from
Visual Studio. The demo was created and tested with
Visual Studio .NET 2005.

To build and run the demo:

- Extract all of the files into a single folder on the system
you wish to use.

- On WIndows, if you are not using Visual Studio 2005, edit
the batch file mylib.bat and change the call statement to
call the appropriate Visual Studio environment setup batch
file for your version. Also, remove the "mt" statement, as
this is only required if using Visual Studio 2005.

- Execute the mylib.bat batch file (WIndows) or mylib script
file (UNIX). This file will compile the C routine, create
a Windows DLL or UNIX shared object, compile and link the
Synergy test program, and run it. If all is well you will
see output from the program that looks like this:

DBL: Calling C with xval=10.2 yval=2.1
C: xval=10.200000 yval=2.100000
C: result=131.238229
C: Calling back to DBL with result=131.238229
DBL: Called from C, result is 131.238229
C: Back from DBL call-back, returning to caller with result=131.238229
DBL: Back from C, result=131.238229
