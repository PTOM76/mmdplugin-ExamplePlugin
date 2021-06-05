///////////////////////////////////////////////////////////////////////////
//   MMDExport.h  Ver.0.07  2010/10/22
//     MikuMikuDance �G�N�X�|�[�g�֐��p�w�b�_  
//
//     �o�͊֐��̃��C�u�����FMMDExport.lib
///////////////////////////////////////////////////////////////////////////
#ifndef __MMDEXPORT_H__								// �d���h�~
#define __MMDEXPORT_H__

/////////////// _EXPORT��`  //////////////////
#define		_EXPORT	__declspec(dllexport)			// MMD�{�̗p	(dll���ł̓R�����g�A�E�g���鎖)
//#define	_EXPORT	__declspec(dllimport)			// dll�p		(dll���ł̓R�����g�A�E�g���O����)


///////////// �G�N�X�|�[�g�֐� ////////////////
extern "C"{
	_EXPORT	float			ExpGetFrameTime();				// �t���[�����Ԃ̎擾(sec) �t���[��0��0sec�Ƃ��Č��ݏ������̎���
	_EXPORT	int				ExpGetPmdNum();					// PMD���f���̐�
	_EXPORT	char*			ExpGetPmdFilename(int);			// ����1��PMD���f���t�@�C����(�t���p�X)	����1��0�`GetPmdNum-1
	_EXPORT	int				ExpGetPmdOrder(int);			// ����1��PMD���f���`�揇��(��1)		����1��0�`GetPmdNum-1
	_EXPORT	int				ExpGetPmdMatNum(int);			// ����1��PMD���f���̍ގ���				����1��0�`GetPmdNum-1
	_EXPORT	D3DMATERIAL9	ExpGetPmdMaterial(int,int);		// ����1��PMD���f���̍ގ�				����1��0�`GetPmdNum-1,����2��0�`GetPmdMatNum(����1)-1
	_EXPORT	int				ExpGetPmdBoneNum(int);			// ����1��PMD���f���̃{�[����			����1��0�`GetPmdNum-1
	_EXPORT	char*			ExpGetPmdBoneName(int,int);		// ����1��PMD���f���̃{�[����			����1��0�`GetPmdNum-1,����2��0�`GetPmdBoneNum(����1)-1
	_EXPORT	D3DMATRIX		ExpGetPmdBoneWorldMat(int,int);	// ����1��PMD���ق��ް݂�World�s��(��2)	����1��0�`GetPmdNum-1,����2��0�`GetPmdBoneNum(����1)-1
	_EXPORT	int				ExpGetPmdMorphNum(int);			// ����1��PMD���f���̕\�				����1��0�`GetPmdNum-1
	_EXPORT	char*			ExpGetPmdMorphName(int,int);	// ����1��PMD���f���̕\�				����1��0�`GetPmdNum-1,����2��0�`GetPmdMorphNum(����1)-1
	_EXPORT	float			ExpGetPmdMorphValue(int,int);	// ����1��PMD���f���̕\��l				����1��0�`GetPmdNum-1,����2��0�`GetPmdMorphNum(����1)-1
	_EXPORT	bool			ExpGetPmdDisp(int);				// ����1��PMD���f���̕\�����(true:�\��)����1��0�`GetPmdNum-1
	_EXPORT	int				ExpGetPmdID(int);				// ����1��PMD���f��ID					����1��0�`GetPmdNum-1

	_EXPORT	int				ExpGetAcsNum();					// �A�N�Z�T���̐�
	_EXPORT	int				ExpGetPreAcsNum();				// ���f�����O�ɕ`�ʂ����A�N�Z�T���̐�
	_EXPORT	char*			ExpGetAcsFilename(int);			// ����1�̃A�N�Z�t�@�C����(�t���p�X)	����1��0�`GetAcsNum-1
	_EXPORT	int				ExpGetAcsOrder(int);			// ����1�̃A�N�Z�`�揇��(��1)			����1��0�`GetAcsNum-1
	_EXPORT	D3DMATRIX		ExpGetAcsWorldMat(int);			// ����1�̃A�N�Z��World�s��(��2)		����1��0�`GetAcsNum-1
	_EXPORT	float			ExpGetAcsX(int);				// ����1�̃A�N�Z�̈ʒuX(������ق�X)		����1��0�`GetAcsNum-1
	_EXPORT	float			ExpGetAcsY(int);				// ����1�̃A�N�Z�̈ʒuY(������ق�Y)		����1��0�`GetAcsNum-1
	_EXPORT	float			ExpGetAcsZ(int);				// ����1�̃A�N�Z�̈ʒuZ(������ق�Z)		����1��0�`GetAcsNum-1
	_EXPORT	float			ExpGetAcsRx(int);				// ����1�̃A�N�Z�̉�]X(������ق�Rx)	����1��0�`GetAcsNum-1
	_EXPORT	float			ExpGetAcsRy(int);				// ����1�̃A�N�Z�̉�]Y(������ق�Ry)	����1��0�`GetAcsNum-1
	_EXPORT	float			ExpGetAcsRz(int);				// ����1�̃A�N�Z�̉�]Z(������ق�Rz)	����1��0�`GetAcsNum-1
	_EXPORT	float			ExpGetAcsSi(int);				// ����1�̃A�N�Z�̃T�C�Y(������ق�Si)	����1��0�`GetAcsNum-1
	_EXPORT	float			ExpGetAcsTr(int);				// ����1�̃A�N�Z�̓����x(������ق�Tr)	����1��0�`GetAcsNum-1
	_EXPORT	bool			ExpGetAcsDisp(int);				// ����1�̃A�N�Z�̕\�����(true:�\��)	����1��0�`GetAcsNum-1
	_EXPORT	int				ExpGetAcsID(int);				// ����1�̃A�N�ZID						����1��0�`GetAcsNum-1
	_EXPORT	int				ExpGetAcsMatNum(int);			// ����1�̃A�N�Z�̍ގ���				����1��0�`GetAcsNum-1
	_EXPORT	D3DMATERIAL9	ExpGetAcsMaterial(int,int);		// ����1�̃A�N�Z�̍ގ�					����1��0�`GetAcsNum-1,����2��0�`GetAcsMatNum(����1)-1

	_EXPORT	int				ExpGetCurrentObject();			// ���ݏ������̃I�u�W�F�N�g(��1)
	_EXPORT	int				ExpGetCurrentMaterial();		// ���ݏ������̍ގ�(���R)
	_EXPORT	int				ExpGetCurrentTechnic();			// ���ݏ�������øƯ�(0:���̑� 1:�ʏ�`��i�Z���t�V���h�EOFF�j2:�ʏ�`��i�Z���t�V���h�EON�j
															// 3:�e�i��Z���t�V���h�E�̂��́j4:�G�b�W 5:�E�Z���t�V���h�E�pZ�o�b�t�@�v���b�g
	_EXPORT	void			ExpSetRenderRepeatCount(int);	// �����_�����O����������1�̉񐔌J��Ԃ�(���S)
	_EXPORT	int				ExpGetRenderRepeatCount();		// �����_�����O�����J��Ԃ���(���S)
	_EXPORT	bool			ExpGetEnglishMode();			// �p�ꃂ�[�h���ۂ�(true:�p�ꃂ�[�h false:���{�ꃂ�[�h)
}

#endif	// __MMDEXPORT_H__


/*
��1	�`�揇�Ԃɂ���

MMD�ł́A

A.���f�����O�ɕ`�悳���A�N�Z�T���`��
B.���f���`��
C.���f������ɕ`�悳���A�N�Z�T���`��

�̏��Ԃŕ`�ʂ����B

ExpGetPmdOrder,ExpGetAcsOrder,ExpGetCurrentObject�֐��ł́AABC�ʂ����̔ԍ����Ԃ���邪�AA�̒l�̂݃}�C�i�X�ŕԂ����

��)�X�e�[�W.x negi.x �����~�N.pmd ��������.pmd ���C�gB.x ���C�gR.x �̏��ɕ`�悳���ꍇ��
  ExpGetPmdOrder,ExpGetAcsOrder,ExpGetCurrentObject�֐��̖߂�l

�X�e�[�W.x		-1
negi.x			-2
�����~�N.pmd	 3
��������.pmd	 4
���C�gB.x		 5
���C�gR.x		 6

ExpGetCurrentObject�ł́A���f���E�A�N�Z�T���`�掞�ȊO��0��Ԃ��܂��B
ExpGetCurrentObject�ł́A���f���E�A�N�Z�T���`�掞�́A�e�C�G�b�W�C�Z���t�V���h�E�pZ�o�b�t�@������L�l��Ԃ��܂��B


��2 world�s��ɂ���
MMD�̃J�����́A�R�c��ԓ��ł͋����݈̂ړ����āA�I�u�W�F�N�g���ړ��E��]����d�l�ɂȂ��Ă��܂��B
�܂�J�����̈ʒu�E��]�ɂ���āA�e�I�u�W�F�N�g��world�ϊ��s����ω����Ă��܂��܂��B
�G�N�X�|�[�g�p�֐���world�s��́A�J�����̈ʒu�E��]�v�f���|����O�̒i�K�̒l���o�͂���悤�ɂ��܂����B
�ł��̂ŁAD3DDevice->GetTransform(D3DTS_WORLD,&world)�œ�����world�s��Ƃ͒l���قȂ�܂��B
fx���Œ��_�v�Z��world�s��Ƃ��Ă��̒l��p����ƁA���m�Ȉʒu�ɕ\������܂���̂Œ��ӂ��ĉ������B

ExpGetPmdBoneWorldMat:�A�N�Z�T�������f���Ǐ]�ɂȂ��Ă���ꍇ�́A���f����world�s������łɊ|�����l�ƂȂ�܂��B


���R ExpGetCurrentMaterial�̖߂�l�ɂ���
�e�C�G�b�W�C�Z���t�V���h�E�pZ�o�b�t�@���������l��Ԃ��܂��B
��������L�̏ꍇ�A���ۂɂ͂��ׂĂ̍ގ��͖�������P��̃}�e���A���Ń����_�����O����܂����A
ExpGetCurrentMaterial�̖߂�l�͒ʏ�`�掞�ł������ꍇ�̍ގ��ԍ���Ԃ��܂��B


���S ExpSetRenderRepeatCount�ɂ���
ExpSetRenderRepeatCount��MMD�����̕ϐ��AExRepeat�̒l��ݒ肵�܂��B
ExpGetRenderRepeatCount��ExRepeat�̒l���擾���܂��B
1�t���[���̂����܂��ȃV�[�P���X�͈ȉ��̒ʂ�ł��B

{
	***���[���h�s�񓙐ݒ�***
	***�T�[�t�F�X�EZ�o�b�t�@�̃N���A***

	ExRepeat=1;
    if( SUCCEEDED( Dx3d->lpDevice->BeginScene() ) ) 
    {
		***�Z���t�V���h�E�pZ�o�b�t�@�`��***

		while(ExRepeat>0){
			ExRepeat--;
			***���f���E�A�N�Z�T���֘A�̃����_�����O����***
		}

		***��ʃL���v�`������(�X�N���[�������p)***
		***������{�[�����A��������(�\����)��e��X�v���C�g�\������(AVI�o�͎��͏ȗ�)***

		Dx3d->lpDevice->EndScene();
	}

	***AVI�o�͏���(AVI�o�͎�)***
	***���t���[���̃{�[���v�Z***
	***�������Z�v�Z***
	***���f���̒��_�ړ�***
	***�L�[���͏�����***

	Dx3d->lpDevice->Present();

	***�f�o�C�X���X�g�����A����***
}

DirectX�ł͂P��Present()�ɑ΂��A��΂�BeginScene()/EndScene()�����g���Ȃ�����
(�΂��ƂɃ����_�����O�^�[�Q�b�g���قȂ�ꍇ�͕����̑΂ł��ǂ�)�A��L�\���ɂ��܂����B

ExpSetRenderRepeatCount()�́A
�E�͂��߂ɁABeginScene()���t�b�N�����֐����Ń��s�[�g�񐔂�ݒ肵�Ă��܂�( ExpSetRenderRepeatCount(n) )
�Efx�����_�����O�������ɕK�v�ɉ�����ExpSetRenderRepeatCount(1)�𑗐M���邱�Ƃɂ��A�X�ɂ�������
 ***���f���E�A�N�Z�T���֘A�̃����_�����O����***�^�[���𔭐�������

�Ƃ����g�������ł��܂�(����)�B


***���f���E�A�N�Z�T���֘A�̃����_�����O����***�̃V�[�P���X
{
	***�w�iBMP�p�X�v���C�g�`��***
	***�w�iAVI�p�X�v���C�g�`��***
	***���W���`��***
	***���`��(����)***
	***���f�����O�ɕ`�ʂ����A�N�Z�T���ꎮ�`��***
	***�n�ʉe�`��***{
		�A�N�Z�T���ꎮ		// ExpGetAcsOrder�̏��Ƃ͌���Ȃ�
		���f���ꎮ
	}
	***���f���ꎮ�`��***
	***�G�b�W�ꎮ�`��***
	***���f������ɕ`�ʂ����A�N�Z�T���ꎮ�`��***
}
*/


/*
�X�V����
Ver.0.08 (2013/06/30)
�EExpGetEnglishMode�֐���ǉ�(true���p�ꃂ�[�h)

Ver.0.07 (2010/10/22)
�EExpGetCurrentMaterial()�̃o�O�C��

Ver.0.06 (2010/10/21)
�EExpGetPmdOrder(),ExpGetCurrentObject()�̃o�O�C��

Ver.0.05 (2010/10/07)
�EExpGetRenderRepeatCount�֐���ǉ�
�E�����_�����O���[�v����Z���t�V���h�E�pZ�o�b�t�@�`�ʂ��O��

Ver.0.04 (2010/10/06)
�E�ȉ��̊֐���ǉ�
  ExpGetCurrentTechnic,ExpSetRenderRepeatCount
�EExpGetCurrentObject,ExpGetCurrentMaterial�̖߂�l���A�e�E�G�b�W�`�掞�����
 �Z���t�V���h�E�pZ�o�b�t�@�v���b�g���ɂ��A�������̃I�u�W�F�N�g�ԍ����ގ��ԍ����Ԃ�d�l�ɕύX
�EMMD���j���[�ŃZ���t�V���h�Eoff����ExpGetCurrentObject,ExpGetCurrentMaterial�̒l���Ԃ�Ȃ��o�O�C��

Ver.0.03 (2010/09/29)
�E�ȉ��̊֐���ǉ�
  ExpGetPmdBoneNum,ExpGetPmdBoneName,ExpGetPmdBoneWorldMat,ExpGetPmdMorphNum,ExpGetPmdMorphName,
  ExpGetPmdMorphValue,ExpGetPmdDisp,ExpGetPmdID,ExpGetAcsDisp,ExpGetAcsID,ExpGetAcsMatNum,
  ExpGetAcsMaterial,ExpGetCurrentMaterial
�EExpGetCurrentObject�̖߂�l���A�A�N�Z�E���f�����ȊO��0�ɂȂ�悤�ύX

Ver.0.02 (2010/09/28)
�EEXPORT��`��ectern "C"�ň͂�

*/
