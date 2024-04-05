//����:��c
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
void Pack::InitPack()		//�p�b�N�̏�����
{
	CurrentPosition = { 320.0f,240.0f,0.0f };
	NextPosition = { 320.0f,240.0f,0.0f };
	MoveVector = { 5.0f,5.0f,0.0f };
	PackRadius = 30.0f;
	PackSpeed = 5.0f;
}
void Pack::ResetPack()		//�p�b�N�̃��Z�b�g
{
	if (CurrentPosition.x < 0 || CurrentPosition.x > 1280 || CurrentPosition.y < 0 || CurrentPosition.y > 700) {
		InitPack();
	}
}
void Pack::UpdatePosition()	//���W���X�V����
{
	CurrentPosition = NextPosition;
}
void Pack::MovePosition()	//�X�V����W�𑀍�
{
	NextPosition.x = NextPosition.x + MoveVector.x;
	NextPosition.y = NextPosition.y + MoveVector.y;
	NextPosition.z = NextPosition.z + MoveVector.z;
}
bool Pack::HitPackline(float Line1_x, float Line1_y, float Line2_x, float Line2_y)//�p�b�N�Ɛ��̏Փˎ��̋O���C��
{
	//�ړ���̃p�b�N���I�u�W�F�N�g�ƏՓ˂��Ă��邩������
	if (Collision::IsHitCircle_Line(NextPosition.x, NextPosition.y, PackRadius, Line1_x, Line1_y, Line2_x, Line2_y)){
		//�Փˎ��A���X�s�[�h�ɂȂ�܂Ńp�b�N�̈ړ��X�s�[�h������
		if (PackSpeed <= 10.0f)
		{
			SetPackSpeed(PackSpeed += 0.1f);
		}

		if (Line1_x == Line2_x) {	//���̎n�_�ƏI�_��X���W�������ꍇ
			if (Line1_x >= CurrentPosition.x) {	//����X���W���p�b�N�̌��ݒn���傫���ꍇ
				//�p�b�N�̉E���ŏՓ˂����Ƃ݂Ȃ�
				NextPosition.x = NextPosition.x - PackRadius;
				MoveVector.x = -PackSpeed;//���֐i�ނ悤�ɋO���C��
				if (MoveVector.y > 0) {
					MoveVector.y = PackSpeed;
				}
				else {
					MoveVector.y = -PackSpeed;
				}
				return true;
			}
			else {	//����X���W���p�b�N�̌��ݒn��菬�����ꍇ
				//�p�b�N�̍����ŏՓ˂����Ƃ݂Ȃ�
				NextPosition.x = NextPosition.x + PackRadius;
				MoveVector.x = PackSpeed;//�E�֐i�ނ悤�ɋO���C��
				if (MoveVector.y > 0) {
					MoveVector.y = PackSpeed;
				}
				else {
					MoveVector.y = -PackSpeed;
				}
				return true;
			}
		}
		if (Line1_y == Line2_y) {	//���̎n�_�ƏI�_��Y���W�������ꍇ
			if (Line1_y >= CurrentPosition.y) {	//����Y���W���p�b�N�̌��ݒn���傫���ꍇ
				//�p�b�N�̉����ŏՓ˂����Ƃ݂Ȃ�
				NextPosition.y = NextPosition.y - PackRadius;
				MoveVector.y = -PackSpeed;//��֐i�ނ悤�ɋO���C��
				if (MoveVector.x > 0) {
					MoveVector.x = PackSpeed;
				}
				else {
					MoveVector.x = -PackSpeed;
				}
				return true;
			}
			else {	//����Y���W���p�b�N�̌��ݒn��菬�����ꍇ
				//�p�b�N�̏㑤�ŏՓ˂����Ƃ݂Ȃ�
				NextPosition.y = NextPosition.y + PackRadius;
				MoveVector.y = PackSpeed;//���֐i�ނ悤�ɋO���C��
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
int Pack::HitPackSquare(float Square_x, float Square_y, float Square_w, float Square_h)//�p�b�N�Ǝl�p�`�̏Փ�
{
	if (HitPackline(Square_x, Square_y, Square_x, Square_y + Square_h)) {//����
		DrawLine(Square_x, Square_y, Square_x, Square_y + Square_h, GetColor(255, 255, 0), 4);
		return 0;
	}
	if (HitPackline(Square_x, Square_y + Square_h, Square_x + Square_w, Square_y + Square_h)) {//����
		DrawLine(Square_x, Square_y + Square_h, Square_x + Square_w, Square_y + Square_h, GetColor(255, 255, 0), 4);
		return 1;
	}
	if (HitPackline(Square_x + Square_w, Square_y, Square_x + Square_w, Square_y + Square_h)) {//�E��
		DrawLine(Square_x + Square_w, Square_y, Square_x + Square_w, Square_y + Square_h, GetColor(255, 255, 0), 4);
		return 2;
	}
	if (HitPackline(Square_x, Square_y, Square_x + Square_w, Square_y)) {//���
		DrawLine(Square_x, Square_y, Square_x + Square_w, Square_y, GetColor(255, 255, 0), 4);
		return 3;
	}
}
void Pack::DrawPack()		//�p�b�N�̕`��
{
	DrawCircle(CurrentPosition.x, CurrentPosition.y, PackRadius, GetColor(255, 255, 0), 1, 1);
}

void Pack::SetPackSpeed(float NewSpeed) {//�p�b�N�̈ړ��X�s�[�h��ݒ�
	PackSpeed = NewSpeed;
}

void Pack::DebugMode()	//�f�o�b�O�p
{
	//���ݒn�\��
	DrawFormatString(0, 0, GetColor(255, 255, 0), "���ݒn\nX :%f\nY :%f", CurrentPosition.x, CurrentPosition.y);
	//���݂̃x�N�g��
	DrawFormatString(0, 60, GetColor(255, 255, 0), "�x�N�g��\nX :%f\nY :%f", MoveVector.x,MoveVector.y);
}