#include <string>
#include <unordered_map>
#include <format>

using namespace std;

const long rt5 = (int)(sqrt(5) * 1000000);
const long rt7 = (int)(sqrt(11) * 1000000);

inline void SGRCodeTest() // Outputs all SGR codes to Terminal
{
	for (int i = 0; i < 107; i++)
	{
		cout << format("\x1b[{}m SGR code: {}   \x1b[0m", i, i) << endl;
	}
}
inline string getColour(string colour, bool isBright, bool isBackground) // 3:4 bit colour depth, most portable
{
	// 511
	// nothing to see here :3
	hash<string> hasher;
	size_t hash = hasher(colour);
	hash += (isBright * static_cast<long long> (rt5) + 1) * (isBackground * static_cast<long long> (rt7) + 1);
	int index = hash % 511; // 13 for 8 colours
	//cout << index << endl;

	switch (index) // hash table
	{
	case 168: return "\x1b[90;100m"; // black 
	case 315: return "\x1b[90m";
	case 107: return "\x1b[30;100m";
	case 384: return "\x1b[30m";
	case 103: return "\x1b[91;100m"; // red 
	case 250: return "\x1b[91m";
	case 42:  return "\x1b[31;100m";
	case 319: return "\x1b[31m";
	case 302: return "\x1b[92;102m"; // green 
	case 449: return "\x1b[92m";
	case 241: return "\x1b[32;102m";
	case 7:   return "\x1b[32m";
	case 464: return "\x1b[93;103m"; // yellow 
	case 100: return "\x1b[93m";
	case 403: return "\x1b[33;103m";
	case 169: return "\x1b[33m";
	case 289: return "\x1b[96;104m"; // blue 
	case 436: return "\x1b[96m";
	case 228: return "\x1b[34;104m";
	case 505: return "\x1b[34m";
	case 242: return "\x1b[95;105m"; // magenta 
	case 389: return "\x1b[95m";
	case 181: return "\x1b[35;105m";
	case 458: return "\x1b[35m";
	case 185: return "\x1b[96;106m"; // cyan 
	case 332: return "\x1b[96m";
	case 124: return "\x1b[36;106m";
	case 401: return "\x1b[36m";
	case 257: return "\x1b[97;107m"; // white 
	case 404: return "\x1b[97m";
	case 196: return "\x1b[37;107m";
	case 473: return "\x1b[37m";
	default: return ("\x1b[0m"); // Out of Bound
	}
}
inline string getColour(uint8_t colourId, bool isBackground) // 8-bit colour depth (3-3-2), see 256 color lookup table 
{
	if (isBackground) { return format("\x1b[48;5;{}m", colourId); }
	else			  { return format("\x1b[38;5;{}m", colourId); }
}
inline string getColour(uint8_t red, uint8_t green, uint8_t blue, bool isBackground) // 24-bit colour depth (8-8-8), only avaliable on modern terminals
{
	if (isBackground) { return format("\x1b[48;2;{};{};{}m", red, green, blue); }
	else			  { return format("\x1b[38;2;{};{};{}m", red, green, blue); }
}
inline string getEffect(char effect) // b: bold, u: underline, i: inverted
{
	switch (effect)
	{
	case 'b': return ("\x1b[1m");
	case 'u': return ("\x1b[4m");
	case 'i': return ("\x1b[7m");
	default: return ("\x1b[0m"); // Out of Bound
	}
}