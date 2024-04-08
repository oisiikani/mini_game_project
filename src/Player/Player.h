//　篠田
#pragma once


const int PlayerSpeed = 8;						//プレイヤーの速度
const int PlayerSizeX = 100;					//プレイヤーの横幅
const int PlayerHalfSizeX = PlayerSizeX / 2;	//プレイヤーの横幅の半分
const int PlayerSizeY = 200;					//プレイヤーの縦幅
const int PlayerHalfSizeY = PlayerSizeY / 2;	//プレイヤーの縦幅の半分
const int PlayerNumber = 2;						//プレイヤー数
const int SmashGaugeMaxmum = 50;				//スマッシュゲージ最大数

class Player
{
protected:
	//座標(プレイヤーの数だけ)

	float m_x[PlayerNumber];
	float m_y[PlayerNumber];

	//プレイヤーのハンドル

	int Player1Hndl;
	int Player2Hndl;

public:

	Player() //コンストラクタ
	{
			m_x[0] = 0.0f;
			m_y[0] = 0.0f;

			m_x[1] = 0.0f;
			m_y[1] = 0.0f;

			Player1Hndl = 0;
			Player2Hndl = 0;
	}

	void PlayerDebug(); //デバックの処理

	void InitPlayer();  //プレイヤーの初期化処理

	void PlayerMove();  //プレイヤーの移動処理

	void PlayerDraw();  //プレイヤーの描画処理

	void PlayerFin();

	float GetPlayer1PosX() { return m_x[0]; }

	float GetPlayer1PosY() { return m_y[0]; }

	float GetPlayer2PosX() { return m_x[1]; }

	float GetPlayer2PosY() { return m_y[1]; }

};
