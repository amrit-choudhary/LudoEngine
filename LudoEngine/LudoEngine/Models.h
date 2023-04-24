#pragma once

namespace LudoEngine {

	const unsigned char bottomLeftPath[58] =
	{
		73,
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
		52, 53, 54, 55, 56,
		72
	};

	const unsigned char topLeftPath[58] =
	{
		74,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,
		57, 58, 59, 60, 61,
		72
	};

	const unsigned char topRightPath[58] =
	{
		75,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
		62, 63, 64, 65, 66,
		72
	};

	const unsigned char bottomRightPath[58] =
	{
		76,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
		67, 68, 69, 70, 71,
		72
	};

	enum Corner {
		None = 99,
		BottomLeft = 0,
		TopLeft = 1,
		TopRight = 2,
		BottomRight = 3
	};

	struct Peg
	{
	public:
		Corner corner = Corner::None;
		unsigned char steps = 0;
	};

	struct TurnReport {
	public:
		unsigned char diceRoll;
		unsigned char turnID;
		unsigned int turnCounter;
	};
}

