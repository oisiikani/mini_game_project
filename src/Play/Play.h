#pragma once

class Play
{
protected:

	//プレイヤーの体力

	int Player1HP;	
	int Player2HP;
	int HitGoal;
	

public:

	Play();

	void InitPlay();

	void StepPlay();

	void DrawPlay();

	void ScoreCalculation(); //スコア計算

	void StageLineCollision();

	void GameSet();
};