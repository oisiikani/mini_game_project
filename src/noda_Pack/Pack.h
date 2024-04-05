#include "DxLib.h"	//DXライブラリのインクルード
#ifndef __PACK__
#define __PACK__

class Pack
{
//private:
public:
	VECTOR CurrentPosition;	//パックの現在座標
	VECTOR NextPosition;	//パックの更新先座標
	VECTOR MoveVector;		//パックの移動方向
	float PackRadius;		//パックの半径
	float PackSpeed;		//パックの移動スピード
public:
	Pack();
	~Pack();
	void InitPack();		//パックの初期化
	void ResetPack();		//パックのリセット
	void UpdatePosition();	//座標を更新する
	void MovePosition();	//更新先座標を操作
	bool HitPackline(float Line1_x,float Line1_y,float Line2_x,float Line2_y);//パックと線の衝突時の軌道修正
	int HitPackSquare(float Square_x, float Square_y, float Square_w, float Spuare_h);//パックと四角形の衝突
	void DrawPack();		//パックの描画

	void SetPackSpeed(float NewSpeed);//パックの移動スピードを設定

	void DebugMode();	//デバッグ用
};

#endif // !__PACK__

