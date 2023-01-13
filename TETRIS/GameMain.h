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


	void DownMoveBlock(int color);		//ブロックの落下処理
	void LeftMoveBlock(int color);		//ブロックの左移動処理
	void RightMoveBlock(int color);		//ブロックの右移動処理
	void JumpBlock(int color);			//ブロックの一番下までの落下処理
	void CreatBlock();					//ブロックの生成処理
	void ClearBlock(int y);				//ブロックの削除処理
	void CheckRanding();				//ブロックの着地検知処理
	void SpinBlock();					//ブロックの回転処理
	void HoldBlock();					//ブロックのホールド処理
	bool GetGameOver() { return m_isGameOverFlag; }		//ゲームオーバーフラグ

private:

	Field m_field[10][22];		//盤面10×22
	Shape* m_shape;				//ブロックの形
	int m_color;				//ブロックの色
	int m_blockvec;				//ブロックの向き
	int m_blockX;				//現在操作中のブロックのX座標
	int m_blockY;				//現在操作中のブロックのY座標
	float m_movespeed;			//ブロックの落下スピード
	float m_waitStop;			//着地の待ち時間
	bool m_stopflag;			//ブロックが止まった時のフラグ
	int m_randShape[6];			//生成したブロックの種類
	bool m_isGameOverFlag;		//ゲームオーバーフラグ
	int m_holdShape;			//ホールドしているブロックの種類
	bool m_ishold;				//現在ホールドしているかフラグ
	bool m_isholded;			//ホールド操作したかフラグ
	int m_score;				//スコア
	int m_clearnum;				//消した列の数

};