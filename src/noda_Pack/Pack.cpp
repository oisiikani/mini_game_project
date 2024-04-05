//製作:野田
#include "Pack.h"
#include "../Collision/Collision.h"
Pack::Pack()
{
	CurrentPosition = { 0.0f,0.0f,0.0f };
	NextPosition = { 0.0f,0.0f,0.0f };
	MoveVector = { 0.0f,0.0f,0.0f };
	PackRadius = 0.0f;
	PackSpeed = 0.0f;
}
Pack::~Pack()
{

}
void Pack::InitPack()		//パックの初期化
{
	CurrentPosition = { 320.0f,240.0f,0.0f };
	NextPosition = { 320.0f,240.0f,0.0f };
	MoveVector = { 5.0f,5.0f,0.0f };
	PackRadius = 30.0f;
	PackSpeed = 5.0f;
}
void Pack::ResetPack()		//パックのリセット
{
	if (CurrentPosition.x < 0 || CurrentPosition.x > 1280 || CurrentPosition.y < 0 || CurrentPosition.y > 700) {
		InitPack();
	}
}
void Pack::UpdatePosition()	//座標を更新する
{
	CurrentPosition = NextPosition;
}
void Pack::MovePosition()	//更新先座標を操作
{
	NextPosition.x = NextPosition.x + MoveVector.x;
	NextPosition.y = NextPosition.y + MoveVector.y;
	NextPosition.z = NextPosition.z + MoveVector.z;
}
bool Pack::HitPackline(float Line1_x, float Line1_y, float Line2_x, float Line2_y)//パックと線の衝突時の軌道修正
{
	//移動後のパックがオブジェクトと衝突しているかを検証
	if (Collision::IsHitCircle_Line(NextPosition.x, NextPosition.y, PackRadius, Line1_x, Line1_y, Line2_x, Line2_y)){
		//衝突時、一定スピードになるまでパックの移動スピードを加速
		if (PackSpeed <= 10.0f)
		{
			SetPackSpeed(PackSpeed += 0.1f);
		}

		if (Line1_x == Line2_x) {	//線の始点と終点のX座標が同じ場合
			if (Line1_x >= CurrentPosition.x) {	//線のX座標がパックの現在地より大きい場合
				//パックの右側で衝突したとみなす
				NextPosition.x = NextPosition.x - PackRadius;
				MoveVector.x = -PackSpeed;//左へ進むように軌道修正
				if (MoveVector.y > 0) {
					MoveVector.y = PackSpeed;
				}
				else {
					MoveVector.y = -PackSpeed;
				}
				return true;
			}
			else {	//線のX座標がパックの現在地より小さい場合
				//パックの左側で衝突したとみなす
				NextPosition.x = NextPosition.x + PackRadius;
				MoveVector.x = PackSpeed;//右へ進むように軌道修正
				if (MoveVector.y > 0) {
					MoveVector.y = PackSpeed;
				}
				else {
					MoveVector.y = -PackSpeed;
				}
				return true;
			}
		}
		if (Line1_y == Line2_y) {	//線の始点と終点のY座標が同じ場合
			if (Line1_y >= CurrentPosition.y) {	//線のY座標がパックの現在地より大きい場合
				//パックの下側で衝突したとみなす
				NextPosition.y = NextPosition.y - PackRadius;
				MoveVector.y = -PackSpeed;//上へ進むように軌道修正
				if (MoveVector.x > 0) {
					MoveVector.x = PackSpeed;
				}
				else {
					MoveVector.x = -PackSpeed;
				}
				return true;
			}
			else {	//線のY座標がパックの現在地より小さい場合
				//パックの上側で衝突したとみなす
				NextPosition.y = NextPosition.y + PackRadius;
				MoveVector.y = PackSpeed;//下へ進むように軌道修正
				if (MoveVector.x > 0) {
					MoveVector.x = PackSpeed;
				}
				else {
					MoveVector.x = -PackSpeed;
				}
				return true;
			}
		}
	}
	return false;
}
int Pack::HitPackSquare(float Square_x, float Square_y, float Square_w, float Square_h)//パックと四角形の衝突
{
	if (HitPackline(Square_x, Square_y, Square_x, Square_y + Square_h)) {//左辺
		DrawLine(Square_x, Square_y, Square_x, Square_y + Square_h, GetColor(255, 255, 0), 4);
		return 0;
	}
	if (HitPackline(Square_x, Square_y + Square_h, Square_x + Square_w, Square_y + Square_h)) {//下辺
		DrawLine(Square_x, Square_y + Square_h, Square_x + Square_w, Square_y + Square_h, GetColor(255, 255, 0), 4);
		return 1;
	}
	if (HitPackline(Square_x + Square_w, Square_y, Square_x + Square_w, Square_y + Square_h)) {//右辺
		DrawLine(Square_x + Square_w, Square_y, Square_x + Square_w, Square_y + Square_h, GetColor(255, 255, 0), 4);
		return 2;
	}
	if (HitPackline(Square_x, Square_y, Square_x + Square_w, Square_y)) {//上辺
		DrawLine(Square_x, Square_y, Square_x + Square_w, Square_y, GetColor(255, 255, 0), 4);
		return 3;
	}
}
void Pack::DrawPack()		//パックの描画
{
	DrawCircle(CurrentPosition.x, CurrentPosition.y, PackRadius, GetColor(255, 255, 0), 1, 1);
}

void Pack::SetPackSpeed(float NewSpeed) {//パックの移動スピードを設定
	PackSpeed = NewSpeed;
}

void Pack::DebugMode()	//デバッグ用
{
	//現在地表示
	DrawFormatString(0, 0, GetColor(255, 255, 0), "現在地\nX :%f\nY :%f", CurrentPosition.x, CurrentPosition.y);
	//現在のベクトル
	DrawFormatString(0, 60, GetColor(255, 255, 0), "ベクトル\nX :%f\nY :%f", MoveVector.x,MoveVector.y);
}