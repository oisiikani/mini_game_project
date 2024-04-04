//　篠田
#pragma once


const int PlayerSpeed = 5;        //プレイヤーの速度
const int PlayerSizeX = 100;      //プレイヤーの横幅
const int PlayerSizeY = 100;      //プレイヤーの縦幅
const int PlayerNumber = 2;       //プレイヤー数
const int SmashGaugeMaxmum = 50;  //スマッシュゲージ最大数

class Player
{
protected:
	//座標(プレイヤーの数だけ)
	float m_x[PlayerNumber];
	float m_y[PlayerNumber];

public:

	Player()
	{
			m_x[0] = 0.0f;
			m_y[0] = 0.0f;

			m_x[1] = 0.0f;
			m_y[1] = 0.0f;
	}

	void PlayerDebug(); //デバックの処理

	void PlayerMove();  //プレイヤーの移動処理

	void PlayerDraw();  //プレイヤーの描画処理

	float GetPlayer1PosX()
	{
		return m_x[0];
	}

	float GetPlayer1PosY()
	{
		return m_x[0];
	}

	float GetPlayer2PosX()
	{
		return m_x[0];
	}

	float GetPlayer2PosY()
	{
		return m_x[0];
	}

};
