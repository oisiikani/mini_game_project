//�@�c
#pragma once


const int PlayerSpeed = 8;						//�v���C���[�̑��x
const int PlayerSizeX = 100;					//�v���C���[�̉���
const int PlayerHalfSizeX = PlayerSizeX / 2;	//�v���C���[�̉����̔���
const int PlayerSizeY = 200;					//�v���C���[�̏c��
const int PlayerHalfSizeY = PlayerSizeY / 2;	//�v���C���[�̏c���̔���
const int PlayerNumber = 2;						//�v���C���[��
const int SmashGaugeMaxmum = 50;				//�X�}�b�V���Q�[�W�ő吔

class Player
{
protected:
	//���W(�v���C���[�̐�����)

	float m_x[PlayerNumber];
	float m_y[PlayerNumber];

	//�v���C���[�̃n���h��

	int Player1Hndl;
	int Player2Hndl;

public:

	Player() //�R���X�g���N�^
	{
			m_x[0] = 0.0f;
			m_y[0] = 0.0f;

			m_x[1] = 0.0f;
			m_y[1] = 0.0f;

			Player1Hndl = 0;
			Player2Hndl = 0;
	}

	void PlayerDebug(); //�f�o�b�N�̏���

	void InitPlayer();  //�v���C���[�̏���������

	void PlayerMove();  //�v���C���[�̈ړ�����

	void PlayerDraw();  //�v���C���[�̕`�揈��

	void PlayerFin();

	float GetPlayer1PosX() { return m_x[0]; }

	float GetPlayer1PosY() { return m_y[0]; }

	float GetPlayer2PosX() { return m_x[1]; }

	float GetPlayer2PosY() { return m_y[1]; }

};
