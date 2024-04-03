#pragma once


const int PlayerSpeed = 5;     //プレイヤーの速度
const int PlayerSizeX = 100;   //プレイヤーの横幅
const int PlayerSizeY = 100;   //プレイヤーの縦幅
const int PlayerNumber = 2;    //プレイヤー数

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
};
