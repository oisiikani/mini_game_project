#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#ifndef __PACK__
#define __PACK__

class Pack
{
//private:
public:
	VECTOR CurrentPosition;	//�p�b�N�̌��ݍ��W
	VECTOR NextPosition;	//�p�b�N�̍X�V����W
	VECTOR MoveVector;		//�p�b�N�̈ړ�����
	float PackRadius;		//�p�b�N�̔��a
	float PackSpeed;		//�p�b�N�̈ړ��X�s�[�h
public:
	Pack();
	~Pack();
	void InitPack();		//�p�b�N�̏�����
	void ResetPack();		//�p�b�N�̃��Z�b�g
	void UpdatePosition();	//���W���X�V����
	void MovePosition();	//�X�V����W�𑀍�
	bool HitPackline(float Line1_x,float Line1_y,float Line2_x,float Line2_y);//�p�b�N�Ɛ��̏Փˎ��̋O���C��
	int HitPackSquare(float Square_x, float Square_y, float Square_w, float Spuare_h);//�p�b�N�Ǝl�p�`�̏Փ�
	void DrawPack();		//�p�b�N�̕`��

	void SetPackSpeed(float NewSpeed);//�p�b�N�̈ړ��X�s�[�h��ݒ�

	void DebugMode();	//�f�o�b�O�p
};

#endif // !__PACK__

