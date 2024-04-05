//　篠田
#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

void Player::PlayerDebug()
{
	//1Pの処理===========================

	DrawBox((int)m_x[0], (int)m_y[0], (int)m_x[0] + PlayerSizeX, (int)m_y[0] + PlayerSizeY,
			GetColor(255, 0, 0), false);

	//2Pの処理===========================

	DrawBox((int)m_x[1], (int)m_y[1], (int)m_x[1] + PlayerSizeX, (int)m_y[1] + PlayerSizeY,
		GetColor(0, 0, 255), false);


}

void Player::InitPlayer()
{
	m_x[0] = 0.0f;
	m_y[0] = 0.0f;

	m_x[1] = 0.0f;
	m_y[1] = 0.0f;

	Player1Hndl = LoadGraph("Data/Player1.png");
	Player2Hndl = LoadGraph("Data/Player2.png");
}

void Player::PlayerMove()
{

	//1Pの処理===========================

	if (IsKeyKeep(KEY_INPUT_A)) //左移動
	{
		m_x[0] -= PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_D)) //右移動
	{
		m_x[0] += PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_W)) //上移動
	{
		m_y[0] -= PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_S)) //下移動
	{
		m_y[0] += PlayerSpeed;
	}

	//2Pの処理===========================

	if (IsKeyKeep(KEY_INPUT_LEFT)) //左移動
	{
		m_x[1] -= PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_RIGHT)) //右移動
	{
		m_x[1] += PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_UP)) //上移動
	{
		m_y[1] -= PlayerSpeed;
	}

	if (IsKeyKeep(KEY_INPUT_DOWN)) //下移動
	{
		m_y[1] += PlayerSpeed;
	}
}

void Player::PlayerDraw() //プレイヤーの描画処理
{
	DrawGraph(m_x[0], m_y[0], Player1Hndl, true);
	DrawGraph(m_x[1], m_y[1], Player2Hndl, true);
	
}