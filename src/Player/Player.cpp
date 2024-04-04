//�@�c
#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

void Player::PlayerDebug()
{
	//1P�̏���===========================

	DrawBox((int)m_x[0], (int)m_y[0], (int)m_x[0] + PlayerSizeX, (int)m_y[0] + PlayerSizeY,
			GetColor(255, 0, 0), false);

	//2P�̏���===========================

	DrawBox((int)m_x[1], (int)m_y[1], (int)m_x[1] + PlayerSizeX, (int)m_y[1] + PlayerSizeY,
		GetColor(0, 0, 255), false);

}

void Player::PlayerMove()
{

	//1P�̏���===========================

	if (CheckHitKey(KEY_INPUT_A)) //���ړ�
	{
		m_x[0] -= PlayerSpeed;
	}

	if (CheckHitKey(KEY_INPUT_D)) //�E�ړ�
	{
		m_x[0] += PlayerSpeed;
	}

	if (CheckHitKey(KEY_INPUT_W)) //��ړ�
	{
		m_y[0] -= PlayerSpeed;
	}

	if (CheckHitKey(KEY_INPUT_S)) //���ړ�
	{
		m_y[0] += PlayerSpeed;
	}

	//2P�̏���===========================

	if (CheckHitKey(KEY_INPUT_LEFT)) //���ړ�
	{
		m_x[1] -= PlayerSpeed;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT)) //�E�ړ�
	{
		m_x[1] += PlayerSpeed;
	}

	if (CheckHitKey(KEY_INPUT_UP)) //��ړ�
	{
		m_y[1] -= PlayerSpeed;
	}

	if (CheckHitKey(KEY_INPUT_DOWN)) //���ړ�
	{
		m_y[1] += PlayerSpeed;
	}
}

void Player::PlayerDraw() //�v���C���[�̕`�揈��
{

}