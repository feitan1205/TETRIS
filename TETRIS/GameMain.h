#include <DxLib.h>
#include "Field.h"

class InputState;
class Shape;
struct ShapeData;

class GameMain {

public:

	GameMain();
	~GameMain();
	void Init();
	void End();
	void Update(const InputState& input);
	void Draw();


	void DownMoveBlock(int color);		//�u���b�N�̗�������
	void LeftMoveBlock(int color);		//�u���b�N�̍��ړ�����
	void RightMoveBlock(int color);		//�u���b�N�̉E�ړ�����
	void JumpBlock(int color);			//�u���b�N�̈�ԉ��܂ł̗�������
	void CreatBlock();					//�u���b�N�̐�������
	void ClearBlock(int y);				//�u���b�N�̍폜����
	void CheckRanding();				//�u���b�N�̒��n���m����
	void SpinBlock();					//�u���b�N�̉�]����
	void HoldBlock();					//�u���b�N�̃z�[���h����
	bool GetGameOver() { return m_isGameOverFlag; }		//�Q�[���I�[�o�[�t���O

private:

	Field m_field[10][22];		//�Ֆ�10�~22
	Shape* m_shape;				//�u���b�N�̌`
	int m_color;				//�u���b�N�̐F
	int m_blockvec;				//�u���b�N�̌���
	int m_blockX;				//���ݑ��쒆�̃u���b�N��X���W
	int m_blockY;				//���ݑ��쒆�̃u���b�N��Y���W
	float m_movespeed;			//�u���b�N�̗����X�s�[�h
	float m_waitStop;			//���n�̑҂�����
	bool m_stopflag;			//�u���b�N���~�܂������̃t���O
	int m_randShape[6];			//���������u���b�N�̎��
	bool m_isGameOverFlag;		//�Q�[���I�[�o�[�t���O
	int m_holdShape;			//�z�[���h���Ă���u���b�N�̎��
	bool m_ishold;				//���݃z�[���h���Ă��邩�t���O
	bool m_isholded;			//�z�[���h���삵�����t���O
	int m_score;				//�X�R�A
	int m_clearnum;				//��������̐�

};