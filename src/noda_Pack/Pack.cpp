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
	MoveVector = { 2.0f,2.0f,0.0f };
	PackRadius = 20.0f;
	PackSpeed = 2.0f;
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
void Pack::HitPackline(float Line1_x, float Line1_y, float Line2_x, float Line2_y)//�p�b�N�Ɛ��̏Փˎ��̋O���C��
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
				MoveVector.x = -PackSpeed;//���֐i�ނ悤�ɋO���C��
				if (MoveVector.y > 0) {
					MoveVector.y = PackSpeed;
				}
				else {
					MoveVector.y = -PackSpeed;
				}
			}
			else {	//����X���W���p�b�N�̌��ݒn��菬�����ꍇ
				//�p�b�N�̍����ŏՓ˂����Ƃ݂Ȃ�
				MoveVector.x = PackSpeed;//�E�֐i�ނ悤�ɋO���C��
				if (MoveVector.y > 0) {
					MoveVector.y = PackSpeed;
				}
				else {
					MoveVector.y = -PackSpeed;
				}
			}
		}
		if (Line1_y == Line2_y) {	//���̎n�_�ƏI�_��Y���W�������ꍇ
			if (Line1_y >= CurrentPosition.y) {	//����Y���W���p�b�N�̌��ݒn���傫���ꍇ
				//�p�b�N�̉����ŏՓ˂����Ƃ݂Ȃ�
				MoveVector.y = -PackSpeed;//��֐i�ނ悤�ɋO���C��
				if (MoveVector.x > 0) {
					MoveVector.x = PackSpeed;
				}
				else {
					MoveVector.x = -PackSpeed;
				}
			}
			else {	//����Y���W���p�b�N�̌��ݒn��菬�����ꍇ
				//�p�b�N�̏㑤�ŏՓ˂����Ƃ݂Ȃ�
				MoveVector.y = PackSpeed;//���֐i�ނ悤�ɋO���C��
				if (MoveVector.x > 0) {
					MoveVector.x = PackSpeed;
				}
				else {
					MoveVector.x = -PackSpeed;
				}
			}
		}
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