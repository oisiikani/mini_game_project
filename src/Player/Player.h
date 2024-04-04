//�@�c
#pragma once


const int PlayerSpeed = 5;        //�v���C���[�̑��x
const int PlayerSizeX = 100;      //�v���C���[�̉���
const int PlayerSizeY = 100;      //�v���C���[�̏c��
const int PlayerNumber = 2;       //�v���C���[��
const int SmashGaugeMaxmum = 50;  //�X�}�b�V���Q�[�W�ő吔

class Player
{
protected:
	//���W(�v���C���[�̐�����)
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

	void PlayerDebug(); //�f�o�b�N�̏���

	void PlayerMove();  //�v���C���[�̈ړ�����

	void PlayerDraw();  //�v���C���[�̕`�揈��

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
