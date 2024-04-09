#include "Result.h"

Result::Result()
{
}

Result::~Result()
{
}

void Result::InitResult()
{
	ResultHndl = LoadGraph("Data/party_cracker_1173.png");
}

void Result::StepResult()
{
	
}
void Result::DrawResult()
{
	DrawBox(0,0,SCREEN_SIZE_X, SCREEN_SIZE_Y,GetColor(128,128,191),true);
}
void Result::FinResult() 
{
	DeleteGraph(ResultHndl);
}