#pragma once

class Play
{
protected:

	//�v���C���[�̗̑�

	int Player1HP;	
	int Player2HP;
	int HitGoal;
	

public:

	Play();

	void InitPlay();

	void StepPlay();

	void DrawPlay();

	void ScoreCalculation(); //�X�R�A�v�Z

	void StageLineCollision();

	void GameSet();
};