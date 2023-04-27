#pragma once

namespace LudoEngine {
	// 1 byte unsigned int (0 - 255)
	typedef unsigned char uint8;

	const uint8 pegsCount = 16;
	const uint8 cellsCount = 77;
	const uint8 maxSteps = 58;
	const uint8 goalPos = 72;
	const uint8 bottomLeftHomePos = 73;
	const uint8 topLeftHomePos = 74;
	const uint8 topRightHomePos = 75;
	const uint8 bottomRightHomePos = 76;

	const uint8 bottomLeftPath[maxSteps] =
	{
		bottomLeftHomePos,
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
		52, 53, 54, 55, 56,
		goalPos
	};

	const uint8 topLeftPath[maxSteps] =
	{
		topLeftHomePos,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,
		57, 58, 59, 60, 61,
		goalPos
	};

	const uint8 topRightPath[maxSteps] =
	{
		topRightHomePos,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
		62, 63, 64, 65, 66,
		goalPos
	};

	const uint8 bottomRightPath[maxSteps] =
	{
		bottomRightHomePos,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
		67, 68, 69, 70, 71,
		goalPos
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
		const uint8 cornerID = 0;
		uint8 steps = 0;
	};

	struct TurnReport {
	public:
		uint8 diceRoll;
		uint8 turnID;
		unsigned int turnCounter;
	};

	const uint8 pegCheckSeq[24 * 4] =
	{
		0, 1, 2, 3,
		0, 1, 3, 2,
		0, 2, 1, 3,
		0, 2, 3, 1,
		0, 3, 1, 2,
		0, 3, 2, 1,

		1, 0, 2, 3,
		1, 0, 3, 2,
		1, 2, 0, 3,
		1, 2, 3, 0,
		1, 3, 0, 2,
		1, 3, 2, 0,

		2, 1, 0, 3,
		2, 1, 3, 0,
		2, 0, 1, 3,
		2, 0, 3, 1,
		2, 3, 1, 0,
		2, 3, 0, 1,

		3, 1, 2, 0,
		3, 1, 0, 2,
		3, 2, 1, 0,
		3, 2, 0, 1,
		3, 0, 1, 2,
		3, 0, 2, 1,
	};
}

