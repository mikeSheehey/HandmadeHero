# HandmadeHero
This repo is what I will be using to host my journey through the Handmade Hero course for game dev on Windows. I will also be learning and using Neovim for the first time and throughout this whole project. I plan to complete 1 lecture a day as well as read at least one document from the vim user manual. 

17MAR26 - Im not sure how I will be making notes yet so for now all will be done here on the readme. The original project is documented by the legendary Casey Muratori. The original looks like it has been retired but assests and source code can still be purchased. 

18MAR26 - A concern I have for this project is what has changed since the start of the series is almost ten years old. Even going throught the first episode the first WinMain funtion has been changed and the original dev site hosted from microsoft (MSDN) doesnt appear to exist anymore and now falls under Microsoft learn. There will probably be a lot of adapting to make some of the practices work. 

First thing to notice, the "in" on the syntax for WinMain is used to indicate information is being passed to Microsoft's OS and if there was an "out" it would be giving something back. This notation shows direction that could be processed in some other systems but should not be included when compiling with gcc. The random letters in front of our parameters "HINSTANCE" represents hungarian notation that was adopted to help describe the objects being used when programming. Casey finds them useless. 

First mistake from my end is that I cant compile with gcc or use WSL (without pain in the ass workarounds) if I am dealing with Windows machine dependent headers "Windows.h" so I am going to take a detour and figure out how to install Neovim natively. 

After a bit of research I think the best solution will be to use Mingw for our builds. It looks like the modern version is not limiting. 

20MAR25 - So after a lot of searching there is a few ways to go about working in nvim and building in Windows. The best way I think I have found and will run with is to download VisualStudio so I have access to the powershell developer tools and then can compile there and as for NVIM I dont necessarily need to be in Linux. I have ditched WSL and install NVIM on Windows using a package manager called Chocolatey. Tomorrow i'll give a small "Hello World" program a try and then if all goes well ill continue Casey's series like that. 

21MAR25 - Ive got a test program that compiled with no errors and executed correctly so were back in business. 

Today I will be starting to work through the intro C series since I am not too familiar with the language. When explaining more VS essentials we wrote a funtion that included a Windows funtion called OutputDebugStringA(). When running this I didn't see any output in our powershell window and realized that this execution wouldn't contain output from the debugger. I can debug in VS but if I dont want to open VS everytime I debug I can use a sysinternals tool (Dbgview.exe) to display the debug buffer. 

17MAY25 - Starting day 002 off with learning how the Visual Studio debugger functions. So far we are learning a beginner friendly way to set break points in the debugger mode so that when the program is ran it will halt everything being executed at that given breakpoint. Had to move back to day 001 because I needed to learn VS basics. It looks like I will be needing to use VS more than anticipated just for debugging tools but we'll see if Casey has a different approach when switching to EMACS. More issues...Microsoft has settings for its linker and if you start with an empty project it sets the linker to console. this can be changed through project > properties > linker > system > subsystem and setting to windows instead of console. After this I got a clean build.    

26MAY26 - I am remaking this repo from scratch so that way it runs smoothly with VisualStudio community. Microsoft has set this software up for bigger teams and using it to do smaller tasks is a little annoying but I am learning it now to be able to follow along with the series without as many breaks and then implement it with NVIM later. I am learning how to set up a .gitignore file so that github ignores many of the garbage files produced from the solution build. We are now learning the basics of the debugger and are currently discussing the watch window. We can inspect elements and see what these objects are as well as set breaks to see exactly what the program is doing at the time of execution.
<img width="939" height="635" alt="image" src="https://github.com/user-attachments/assets/630e8301-259b-46f5-8d47-39a2dd032f56" />

There are a ton of tiny details to work through just because of how things how changed over the years. For instance in C++ I can no longer have the line of code char* Foo = "string"; <- still not even sure what this is and now it must be changed to const char* Foo = "string"; as this is safe vs the unsafe older code. There are also tiny changes with the debugger and Visual Studio functionalitly that can be frustrating to deal with.

30MAY26 - Today we are learning about variables and are also deving deeper into the watch window. An important thing mentioned is that when setting a breakpoint and viewing in VS watch window the code executes UP TO that line. It does not execute the line that has the break point set at. When declaring a variable if it isnt initialized to some value then all the compiler will do is reserve space for it. It is completely random what will be there until there is an assignment made giving it some value. You can see this process in the debugger (kind of) by stepping over some basic math arithmetic. 'char' is a short var for 8-bit, 'short' is a medium for 16-bit and 'int' is a long for 32-bit. When running tests to see what happends when assigning 255 to an unsigned char the value assigns because that is the upper limit of the 8-bit unsigned char but when trying to add one to that same test value we wrap to 0. This is because you cannot go higher than the max 255 range for the 8-bit unsigned char. 

We went over disassembling and how to read basic assembly commands in our program. This will be much more useful further down the line. 
<img width="1880" height="276" alt="image" src="https://github.com/user-attachments/assets/f6654488-fb88-4801-bcb1-c6474701b89e" />





