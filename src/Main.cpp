//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "Input/Input.h"
#include "Player/Player.h"
#include "noda_Pack/Pack.h"

// define
#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	700	// Y�����̉�ʃT�C�Y���w��

//�ݒ�t���[�����[�g (60FPS)
#define FRAME_RATE (60)

//1�t���[���̎��� (�~���b)
#define FRAME_TIME (1000/FRAME_RATE)


struct FrameRateInfo
{
	int currentTime;    //���݂̎���
	int lastFrameTime;  //�O��̃t���[�����s���̎���
	int count;          //�t���[���J�E���g�p
	int calcFpsTime;    //FPS���v�Z��������
	float fps;          //�v������FPS (�\���p)
};

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo;

//FPS�v�Z
void CalcFPS();

//FPS�\�� (�f�o�b�N�p)
void DrawFPS();

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	Player player;
	Pack pack;

	pack.InitPack();//�p�b�N������

	//���͐��䏉����
	InitInput();

	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{

		Sleep(1);  //�V�X�e���ɏ�����Ԃ�

		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}


		//���݂̎��Ԃ��A�O��̃t���[�������
		//1000/60�~���b(1/60�b)�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			StepInput();

			//-----------------------------------------
			//��������Q�[���̖{�̂��������ƂɂȂ�
			//-----------------------------------------

			player.PlayerDebug();
			player.PlayerMove();

			pack.MovePosition();//�p�b�N�̈ړ�
			pack.HitPackSquare(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y);//�p�b�N�Ɖ�ʂ̓����蔻��
			pack.HitPackSquare(player.GetPlayer1PosX(), player.GetPlayer1PosY(), (float)PlayerSizeX, (float)PlayerSizeY);//�p�b�N�ƃv���C���[1�̓����蔻��
			pack.HitPackSquare(player.GetPlayer2PosX(), player.GetPlayer2PosY(), (float)PlayerSizeX, (float)PlayerSizeY);//�p�b�N�ƃv���C���[2�̓����蔻��
			pack.UpdatePosition();//�p�b�N�̍��W���X�V
			pack.ResetPack();//�p�b�N����ʊO�ɏo��ƃ��Z�b�g����
			pack.DrawPack();//�p�b�N�̕`��
			
			//�z�b�P�[�p�b�N�̍��W�ƃx�N�g����\���ł���
			pack.DebugMode();

			//-----------------------------------------

			//FPS�v�Z
			CalcFPS();

			//FPS�\��
			DrawFPS();


			//���[�v�̏I����
			//�t���b�v�֐�
			ScreenFlip();
		}
	}

	

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

	void CalcFPS()
	{
		//�O���FPS���v�Z�������Ԃ���̌o�ߎ��Ԃ����߂�
		int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

		//�O���FPS���v�Z�������Ԃ���
		//1�b�ȏ�o�߂��Ă�����FPS���v�Z����
		if (difTime > 1000)
		{
			//�t���[���񐔂��~���b�ɍ��킹��
			//�����܂ŏo�������̂�float�ɃL���X�g
			float frameCount = (float)(frameRateInfo.count * 1000.0f);

			//FPS�����߂�
			//���z�̐��l�� 60000 / 1000 �� 60 �ƂȂ�
			frameRateInfo.fps = frameCount / difTime;

			//�t���[�����[�g�J�E���g���N���A
			frameRateInfo.fps = frameCount / difTime;

			//�t���[�����[�g�J�E���g���N���A
			frameRateInfo.count = 0;

			//FPS���v�Z�������Ԃ��X�V
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
		}
	}

	//FPS�\�� (�f�o�b�N�p)
	void DrawFPS()
	{
		unsigned int color = GetColor(255, 30, 30);
		DrawFormatString(1100, 600, color, "FPS[%.2f]", frameRateInfo.fps);

	}

