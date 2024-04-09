#include "Play.h"
#include "../Player/Player.h"
#include "../noda_Pack/Pack.h"
#include "../Common.h"
#include "../scene.h"

Player player;
Pack pack;

Play::Play()
{
	Player1HP = 0;
	Player2HP = 0;
}

void Play::InitPlay()
{
	Player1HP = 100;
	Player2HP = 100;
	HitGoal = 0;


	pack.InitPack();//�p�b�N������
	player.InitPlayer(); //�v���C���[����������
}

void Play::StepPlay()
{

	player.PlayerMove();
	player.PlayerDraw();

	pack.MovePosition();//�p�b�N�̈ړ�
	if (pack.HitPackline(1, 150, 1, 550)) {	//P1�S�[���ɓ�����
		Sleep(1500);
		pack.InitPack();//�p�b�N���Z�b�g
		Player2Score += 1;
	}
	if (pack.HitPackline(SCREEN_SIZE_X - 1, 150, SCREEN_SIZE_X - 1, 550)) {	//P2�S�[���ɓ�����
		Sleep(1500);
		pack.InitPack();//�p�b�N���Z�b�g	
		Player1Score += 1;
	}
	pack.HitPackSquare(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y);//�p�b�N�Ɖ�ʂ̓����蔻��
	pack.HitPackSquare(player.GetPlayer1PosX(), player.GetPlayer1PosY(), (float)PlayerSizeX, (float)PlayerSizeY);//�p�b�N�ƃv���C���[1�̓����蔻��
	pack.HitPackSquare(player.GetPlayer2PosX(), player.GetPlayer2PosY(), (float)PlayerSizeX, (float)PlayerSizeY);//�p�b�N�ƃv���C���[2�̓����蔻��
	pack.UpdatePosition();//�p�b�N�̍��W���X�V
	pack.ResetPack();//�p�b�N����ʊO�ɏo��ƃ��Z�b�g����
	pack.DrawPack();//�p�b�N�̕`��

	if (Player1Score >= 5 || Player2Score >= 5) {
		sceneID = sceneID = SCENE_FIN_PLAY;
	}

	//�z�b�P�[�p�b�N�̍��W�ƃx�N�g����\���ł���
	pack.DebugMode();
	player.PlayerDebug();
}

void Play::DrawPlay()
{
	DrawBox(30, 50, 30 + Player1HP, 100,GetColor(255,0,0),true);
	DrawLine(SCREEN_SIZE_X / 2, 0, SCREEN_SIZE_X / 2, SCREEN_SIZE_Y, GetColor(255, 255, 255), true);
	DrawLine(0, 150, 0, 550, GetColor(255, 128, 0), 16);	//�S�[���`��
	DrawLine(SCREEN_SIZE_X, 150, SCREEN_SIZE_X, 550, GetColor(255, 128, 0), 16);
	DrawFormatString(490, 30, GetColor(255, 64, 64), "PLAYER-1:%d", Player1Score);//�X�R�A�`��
	DrawFormatString(740, 30, GetColor(64, 64, 255), "%d:PLAYER-2", Player2Score);
	DrawFormatString(628, 30, GetColor(255, 255, 255), "SCORE");
}

void Play::StageLineCollision()
{
	
}

void Play::ScoreCalculation()
{
	HitGoal = -1;
	HitGoal = pack.HitPackSquare(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y);

	switch (pack.HitPackSquare(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y))
	{

	case 0:
	{
		Player1HP - 10;
	}
		break;

	case 1:
	break;

	case 2:
	{
		Player2HP - 10;
	}
	break;

	case 3:
	break;

	default:
		break;
	}
}

void Play::GameSet()
{
}
