#include "Result.h"

Result::Result()
{
}

Result::~Result()
{
}

void Result::InitResult()
{
	ResultHndl = LoadGraph("../Data/party_cracker_1173.png");
}

void Result::StepResult()
{
	
}
void Result::DrawResult()
{
	if (Player1Score > Player2Score) {
		DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(191, 128, 128), true);
		DrawFormatString2F(618, 100, GetColor(255, 255, 255), GetColor(255, 0, 0), "PLAYER-1 WIN");
	}
	else {
		DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(128, 128, 191), true);
		DrawFormatString2F(618, 100, GetColor(255, 255, 255), GetColor(0, 0, 255), "PLAYER-2 WIN");
	}
	DrawGraph(0, 0, ResultHndl, true);
}
void Result::FinResult() 
{
	DeleteGraph(ResultHndl);
}