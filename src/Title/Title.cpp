#include "Title.h"

Title::Title() 
{

}
Title::~Title() 
{

}
void Title::InitTitle()
{
	TitleHndl = LoadGraph("../Data/game_air_hockey.png");
}
void Title::StepTitle()
{
	
}
void Title::DrawTitle()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(128, 128, 191), true);
	DrawGraph(0, 0, TitleHndl, true);
}
void Title::FinTitle()
{
	DeleteGraph(TitleHndl);
}