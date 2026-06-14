#include <Windows.h>

//function def
void foo(void)
{
	// Output to debugger
	const char* Foo = "This is the first thing we have actually printed.\r\n";
	OutputDebugStringA(
		"This is the first thing we have actually printed.\n");
}

struct projectile
{
	//NOTE(sheehey): These are the members, or "fields of this structure!

	char unsigned IsThisOnFire; //NOTE(sheehey): 1 if it's on fire, 0 if it's not
	int Damage; // NOTE(sheehey): This is how much damage it does on impact
	int ParticlesPerSecond; // NOTE(sheehey): For special effects
	short HowManyCooks; // NOTE(sheehey): Too many cooks?

	// 1 byte + 4 bytes + 4 bytes + 2 bytes = 11 bytes
};

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

	

	unsigned short Test;

	Test = 500;

	// 0000 0001 1111 0100 = 500

	*/

	projectile Test;

	int SizeOfChar = sizeof(char unsigned);
	int SizeOfInt = sizeof(int);
	int SizeOfProjectile = sizeof(projectile);
	int SizeOfTest = sizeof(Test);

	Test.IsThisOnFire = 1;
	Test.Damage = 3249839 + Test.IsThisOnFire;
	Test.ParticlesPerSecond = 23490830;
	Test.HowManyCooks = 50;
	
	//projectile* ProjectilePointer = &Test;
	//unsigned short* MrPointerMan = (unsigned short*)&Test;

	projectile Projectiles[40];

	int WhichProjectile = 4;
	Projectiles[WhichProjectile];

	projectile *ProjectilePointer = Projectiles; // Here we are defining projectile pointer to be the starting address of Projectiles

	int SizeOfProjectiles = sizeof(Projectiles); // 16*40
	int SizeOfProjectilePointer = sizeof(ProjectilePointer); // 4

	// We see Projectiles is just an address to the start of the array but C also understands array 'size'

	Projectiles[30].Damage = 60;
	(ProjectilePointer + 30)->Damage = 100;
	((projectile *)((char *)ProjectilePointer + 30 * sizeof(projectile)))->Damage = 100; // These lines are the same but above is compiler helping

	// to see everything these are the operations
	char *BytePointer = (char *)ProjectilePointer;
	BytePointer = BytePointer + 30 * sizeof(projectile);
	projectile *Thirty = (projectile*)BytePointer;
	Thirty->Damage = 200;
	// this is the same as line 86.
	// We first cast our projectile pointer as a char * because it moves 1 byte at a time
	// Then we move it forward 30 times size of projectile bytes
	// last we change this address to a projectile * again and assign damage. 

	/* NOTE(sheehey): This is SUPER important. in C for pointer arithmetic say we had
	
	sizeof(projectile) == 40
	sizeof(projectile *) == 8 // starting address of the array and typically 8 bytes on 64-bit machine

	and ProjectilePointer contains address 1000

	then ProjectilePointer + 1 = 1040

	it DOES NOT mean 1000 + sizeof(projectile) = 1000 + 8 = 1008. This is incorrect and not what the compiler does!
	
	What the compiler is saying is this is type projectile so since this pointer points to projectiles, when I add one it should
	move to the next projectile. */






} 