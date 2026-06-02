#include <Windows.h>

//function def
void foo(void)
{
	// Output to debugger
	const char* Foo = "This is the first thing we have actually printed.\r\n";
	OutputDebugStringA(
		"This is the first thing we have actually printed.\n");
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{

	/*
	char SmallS; // 8-bit signed [-128, 127]
	char unsigned SmallU; // 8-bit unsigned [0, 255] 

	short MediumS; // 16-bit signed 65536
	short unsigned MediumU; 

	int LargeS; // 32-bit 4 billion
	int unsigned LargeU;

	int Integer;

	Integer = 5;
	Integer = Integer + 5;
	Integer = 3;

	*/

	char unsigned Test;
	char unsigned *TestPointer;

	TestPointer = &Test;

	Test = 255;
	Test = Test + 1;

	foo();
}