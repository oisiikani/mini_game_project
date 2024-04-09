//　篠田

#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Common.h"

void Player::PlayerDebug()
{
	//1Pの処理===========================

	DrawBox((int)m_x[0], (int)m_y[0], (int)m_x[0] + PlayerSizeX, (int)m_y[0] + PlayerSizeY,
			GetColor(255, 0, 0), false);

	//2Pの処理===========================

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
	//座標の初期化

	m_x[0] = 100;
	m_y[0] = (SCREEN_SIZE_Y / 2) - PlayerHalfSizeY;

	m_x[1] = SCREEN_SIZE_X - (PlayerSizeX + 100);
	m_y[1] = (SCREEN_SIZE_Y / 2) - PlayerHalfSizeY;

	//画像の読み込み(既に読み込んでいたら処理しない)

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

void Player::PlayerDraw() //プレイヤーの描画処理


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
