//�@�c

#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Common.h"

void Player::PlayerDebug()
{
	//1P�̏���===========================

	DrawBox((int)m_x[0], (int)m_y[0], (int)m_x[0] + PlayerSizeX, (int)m_y[0] + PlayerSizeY,
			GetColor(255, 0, 0), false);

	//2P�̏���===========================

	DrawBox((int)m_x[1], (int)m_y[1], (int)m_x[1] + PlayerSizeX, (int)m_y[1] + PlayerSizeY,
		GetColor(0, 0, 255), false);

	/*static int i = 0;
	if (i < 1)
	{
		printfDx("%d",Player1Hndl);
		i++;
	}*/


}

void Player::InitPlayer()
{
	//���W�̏�����

	m_x[0] = 100;
	m_y[0] = (SCREEN_SIZE_Y / 2) - PlayerHalfSizeY;

	m_x[1] = SCREEN_SIZE_X - (PlayerSizeX + 100);
	m_y[1] = (SCREEN_SIZE_Y / 2) - PlayerHalfSizeY;

	//�摜�̓ǂݍ���(���ɓǂݍ���ł����珈�����Ȃ�)

	if (Player1Hndl == 0)
	{
		Player1Hndl = LoadGraph("../Data/Player1.png");
	}

	if (Player2Hndl == 0)
	{
		Player2Hndl = LoadGraph("../Data/Player2.png");
	}

	if (StageHndl == 0)
	{
		StageHndl = LoadGraph("../Data/st (1).png");
	}

}

void Player::PlayerMove()
{

	//1P�̏���===========================

	if (IsKeyKeep(KEY_INPUT_A)) //���ړ�
	{
		m_x[0] -= PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_D)) //�E�ړ�
	{
		m_x[0] += PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_W)) //��ړ�
	{
		m_y[0] -= PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_S)) //���ړ�
	{
		m_y[0] += PlayerSpeed;

	}

	if (m_x[0] > (SCREEN_SIZE_X / 2 - PlayerSizeX))
	{
		m_x[0] = (SCREEN_SIZE_X / 2 - PlayerSizeX);
	}

	if (m_x[0] < 0)
	{
		m_x[0] = 0;
	}

	if (m_y[0] < 0)
	{
		m_y[0] = 0;
	}

	if (m_y[0] > SCREEN_SIZE_Y - PlayerSizeY)
	{
		m_y[0] = SCREEN_SIZE_Y - PlayerSizeY;
	}

	//2P�̏���===========================

	if (IsKeyKeep(KEY_INPUT_LEFT)) //���ړ�
	{
		m_x[1] -= PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_RIGHT)) //�E�ړ�
	{
		m_x[1] += PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_UP)) //��ړ�
	{
		m_y[1] -= PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_DOWN)) //���ړ�
	{
		m_y[1] += PlayerSpeed;
	}



	if (m_x[1] < SCREEN_SIZE_X / 2)
	{
		m_x[1] = SCREEN_SIZE_X / 2;
	}

	if (m_x[1] > SCREEN_SIZE_X - PlayerSizeX)
	{
		m_x[1] = SCREEN_SIZE_X - PlayerSizeX;
	}

	if (m_y[1] < 0)
	{
		m_y[1] = 0;
	}

	if (m_y[1] > SCREEN_SIZE_Y - PlayerSizeY)
	{
		m_y[1] = SCREEN_SIZE_Y - PlayerSizeY;
	}
	
}

void Player::PlayerDraw() //�v���C���[�̕`�揈��


{
	DrawGraph(0, 0, StageHndl, true);
	DrawGraph(m_x[0], m_y[0], Player1Hndl, true);
	DrawGraph(m_x[1], m_y[1], Player2Hndl, true);
	
}

void Player::PlayerFin()
{
	DeleteGraph(Player1Hndl);
	DeleteGraph(Player2Hndl);
}
