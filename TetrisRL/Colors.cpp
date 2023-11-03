#include "Colors.h"

const Color darkGrey	= { 26,		31,		41,		255 };		// 0
const Color green		= { 47,		230,	23,		255 };		// 1
const Color red			= { 232,	18,		18,		255 };		// 2
const Color orange		= { 226,	116,	17,		255 };		// 3
const Color yellow		= { 237,	234,	4,		255 };		// 4
const Color purple		= { 166,	0,		247,	255 };		// 5
const Color cyan		= { 21,		204,	209,	255 };		// 6
const Color blue		= { 13,		64,		216,	255 };		// 7
const Color lightBlue	= { 59,		85,		162,	255 };		// 8
const Color darkBlue	= { 44,		44,		128,	255 };		// 9


std::vector<Color> GetCellColors()
{
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue, lightBlue, darkBlue };
}