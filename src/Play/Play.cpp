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

	Player1Score = 0;
	Player2Score = 0;

	pack.InitPack();//パック初期化
	player.InitPlayer(); //プレイヤー初期化処理
}

void Play::StepPlay()
{

	player.PlayerMove();
	player.PlayerDraw();

	pack.MovePosition();//パックの移動
	if (pack.HitPackline(1, 150, 1, 550)) {	//P1ゴールに入った
		Sleep(1500);
		pack.InitPack();//パックリセット
		Player2Score += 1;
	}
	if (pack.HitPackline(SCREEN_SIZE_X - 1, 150, SCREEN_SIZE_X - 1, 550)) {	//P2ゴールに入った
		Sleep(1500);
		pack.InitPack();//パックリセット	
		Player1Score += 1;
	}
	pack.HitPackSquare(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y);//パックと画面の当たり判定
	pack.HitPackSquare(player.GetPlayer1PosX(), player.GetPlayer1PosY(), (float)PlayerSizeX, (float)PlayerSizeY);//パックとプレイヤー1の当たり判定
	pack.HitPackSquare(player.GetPlayer2PosX(), player.GetPlayer2PosY(), (float)PlayerSizeX, (float)PlayerSizeY);//パックとプレイヤー2の当たり判定
	pack.UpdatePosition();//パックの座標を更新
	pack.ResetPack();//パックが画面外に出るとリセットする
	pack.DrawPack();//パックの描画

	if (Player1Score >= 5 || Player2Score >= 5) {
		sceneID = SCENE_FIN_PLAY;
	}

	//ホッケーパックの座標とベクトルを表示できる
	pack.DebugMode();
	player.PlayerDebug();
}

void Play::DrawPlay()
{
	DrawLine(SCREEN_SIZE_X / 2, 0, SCREEN_SIZE_X / 2, SCREEN_SIZE_Y, GetColor(255, 255, 255), true);
	DrawLine(0, 150, 0, 550, GetColor(255, 128, 0), 16);	//ゴール描画
	DrawLine(SCREEN_SIZE_X, 150, SCREEN_SIZE_X, 550, GetColor(255, 128, 0), 16);
	DrawFormatString(490, 30, GetColor(255, 64, 64), "PLAYER-1:%d", Player1Score);//スコア描画
	DrawFormatString(740, 30, GetColor(64, 64, 255), "%d:PLAYER-2", Player2Score);
	DrawFormatString(628, 30, GetColor(191,191,191), "SCORE");
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
